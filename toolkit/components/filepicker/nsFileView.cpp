/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nsIFileView.h"
#include "nsITreeView.h"
#include "mozilla/ModuleUtils.h"
#include "nsITreeSelection.h"
#include "nsITreeColumns.h"
#include "nsITreeBoxObject.h"
#include "nsIFile.h"
#include "nsString.h"
#include "nsReadableUtils.h"
#include "nsCRT.h"
#include "prmem.h"
#include "nsPrintfCString.h"
#include "nsIDateTimeFormat.h"
#include "nsDateTimeFormatCID.h"
#include "nsQuickSort.h"
#include "nsIAtom.h"
#include "nsIAutoCompleteResult.h"
#include "nsIAutoCompleteSearch.h"
#include "nsISimpleEnumerator.h"
#include "nsAutoPtr.h"
#include "nsIMutableArray.h"
#include "nsTArray.h"
#include "mozilla/Attributes.h"

#include "nsWildCard.h"

class nsIDOMDataTransfer;
 
#define NS_FILECOMPLETE_CID { 0xcb60980e, 0x18a5, 0x4a77, \
                            { 0x91, 0x10, 0x81, 0x46, 0x61, 0x4c, 0xa7, 0xf0 } }
#define NS_FILECOMPLETE_CONTRACTID "@mozilla.org/autocomplete/search;1?name=file"

class nsFileResult MOZ_FINAL : public nsIAutoCompleteResult
{
public:
  // aSearchString is the text typed into the autocomplete widget
  // aSearchParam is the picker's currently displayed directory
  nsFileResult(const nsAString& aSearchString, const nsAString& aSearchParam);

  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETERESULT

  nsTArray<nsString> mValues;
  nsAutoString mSearchString;
  uint16_t mSearchResult;
};

NS_IMPL_ISUPPORTS1(nsFileResult, nsIAutoCompleteResult)

nsFileResult::nsFileResult(const nsAString& aSearchString,
                           const nsAString& aSearchParam):
  mSearchString(aSearchString)
{
  if (aSearchString.IsEmpty())
    mSearchResult = RESULT_IGNORED;
  else {
    int32_t slashPos = mSearchString.RFindChar('/');
    mSearchResult = RESULT_FAILURE;
    nsCOMPtr<nsIFile> directory;
    nsDependentSubstring parent(Substring(mSearchString, 0, slashPos + 1));
    if (!parent.IsEmpty() && parent.First() == '/')
      NS_NewLocalFile(parent, true, getter_AddRefs(directory));
    if (!directory) {
      if (NS_FAILED(NS_NewLocalFile(aSearchParam, true, getter_AddRefs(directory))))
        return;
      if (slashPos > 0)
        directory->AppendRelativePath(Substring(mSearchString, 0, slashPos));
    }
    nsCOMPtr<nsISimpleEnumerator> dirEntries;
    if (NS_FAILED(directory->GetDirectoryEntries(getter_AddRefs(dirEntries))))
      return;
    mSearchResult = RESULT_NOMATCH;
    bool hasMore = false;
    nsDependentSubstring prefix(Substring(mSearchString, slashPos + 1));
    while (NS_SUCCEEDED(dirEntries->HasMoreElements(&hasMore)) && hasMore) {
      nsCOMPtr<nsISupports> nextItem;
      dirEntries->GetNext(getter_AddRefs(nextItem));
      nsCOMPtr<nsIFile> nextFile(do_QueryInterface(nextItem));
      nsAutoString fileName;
      nextFile->GetLeafName(fileName);
      if (StringBeginsWith(fileName, prefix)) {
        fileName.Insert(parent, 0);
        mValues.AppendElement(fileName);
        if (mSearchResult == RESULT_NOMATCH && fileName.Equals(mSearchString))
          mSearchResult = RESULT_IGNORED;
        else
          mSearchResult = RESULT_SUCCESS;
      }
    }
    mValues.Sort();
  }
}

NS_IMETHODIMP nsFileResult::GetSearchString(nsAString & aSearchString)
{
  aSearchString.Assign(mSearchString);
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetSearchResult(uint16_t *aSearchResult)
{
  NS_ENSURE_ARG_POINTER(aSearchResult);
  *aSearchResult = mSearchResult;
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetDefaultIndex(int32_t *aDefaultIndex)
{
  NS_ENSURE_ARG_POINTER(aDefaultIndex);
  *aDefaultIndex = -1;
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetErrorDescription(nsAString & aErrorDescription)
{
  aErrorDescription.Truncate();
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetMatchCount(uint32_t *aMatchCount)
{
  NS_ENSURE_ARG_POINTER(aMatchCount);
  *aMatchCount = mValues.Length();
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetTypeAheadResult(bool *aTypeAheadResult)
{
  NS_ENSURE_ARG_POINTER(aTypeAheadResult);
  *aTypeAheadResult = false;
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetValueAt(int32_t index, nsAString & aValue)
{
  aValue = mValues[index];
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetLabelAt(int32_t index, nsAString & aValue)
{
  return GetValueAt(index, aValue);
}

NS_IMETHODIMP nsFileResult::GetCommentAt(int32_t index, nsAString & aComment)
{
  aComment.Truncate();
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetStyleAt(int32_t index, nsAString & aStyle)
{
  aStyle.Truncate();
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::GetImageAt(int32_t index, nsAString & aImage)
{
  aImage.Truncate();
  return NS_OK;
}

NS_IMETHODIMP nsFileResult::RemoveValueAt(int32_t rowIndex, bool removeFromDb)
{
  return NS_OK;
}

class nsFileComplete MOZ_FINAL : public nsIAutoCompleteSearch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAUTOCOMPLETESEARCH
};

NS_IMPL_ISUPPORTS1(nsFileComplete, nsIAutoCompleteSearch)

NS_IMETHODIMP
nsFileComplete::StartSearch(const nsAString& aSearchString,
                            const nsAString& aSearchParam,
                            nsIAutoCompleteResult *aPreviousResult,
                            nsIAutoCompleteObserver *aListener)
{
  NS_ENSURE_ARG_POINTER(aListener);
  nsRefPtr<nsFileResult> result = new nsFileResult(aSearchString, aSearchParam);
  NS_ENSURE_TRUE(result, NS_ERROR_OUT_OF_MEMORY);
  return aListener->OnSearchResult(this, result);
}

NS_IMETHODIMP
nsFileComplete::StopSearch()
{
  return NS_OK;
}

#define NS_FILEVIEW_CID { 0xa5570462, 0x1dd1, 0x11b2, \
                         { 0x9d, 0x19, 0xdf, 0x30, 0xa2, 0x7f, 0xbd, 0xc4 } }

class nsFileView : public nsIFileView,
                   public nsITreeView
{
public:
  nsFileView();
  nsresult Init();

  NS_DECL_ISUPPORTS
  NS_DECL_NSIFILEVIEW
  NS_DECL_NSITREEVIEW
  
protected:
  virtual ~nsFileView();
  
  void FilterFiles();
  void ReverseArray(nsISupportsArray* aArray);
  void SortArray(nsISupportsArray* aArray);
  void SortInternal();

  nsCOMPtr<nsISupportsArray> mFileList;
  nsCOMPtr<nsISupportsArray> mDirList;
  nsCOMPtr<nsISupportsArray> mFilteredFiles;

  nsCOMPtr<nsIFile> mDirectoryPath;
  nsCOMPtr<nsITreeBoxObject> mTree;
  nsCOMPtr<nsITreeSelection> mSelection;
  nsCOMPtr<nsIAtom> mDirectoryAtom;
  nsCOMPtr<nsIAtom> mFileAtom;
  nsCOMPtr<nsIDateTimeFormat> mDateFormatter;

  int16_t mSortType;
  int32_t mTotalRows;

  nsTArray<PRUnichar*> mCurrentFilters;

  bool mShowHiddenFiles;
  bool mDirectoryFilter;
  bool mReverseSort;
};

// Factory constructor
NS_GENERIC_FACTORY_CONSTRUCTOR(nsFileComplete)
NS_GENERIC_FACTORY_CONSTRUCTOR_INIT(nsFileView, Init)
NS_DEFINE_NAMED_CID(NS_FILECOMPLETE_CID);
NS_DEFINE_NAMED_CID(NS_FILEVIEW_CID);

static const mozilla::Module::CIDEntry kFileViewCIDs[] = {
  { &kNS_FILECOMPLETE_CID, false, NULL, nsFileCompleteConstructor },
  { &kNS_FILEVIEW_CID, false, NULL, nsFileViewConstructor },
  { NULL }
};

static const mozilla::Module::ContractIDEntry kFileViewContracts[] = {
  { NS_FILECOMPLETE_CONTRACTID, &kNS_FILECOMPLETE_CID },
  { NS_FILEVIEW_CONTRACTID, &kNS_FILEVIEW_CID },
  { NULL }
};

static const mozilla::Module kFileViewModule = {
  mozilla::Module::kVersion,
  kFileViewCIDs,
  kFileViewContracts
};

NSMODULE_DEFN(nsFileViewModule) = &kFileViewModule;

nsFileView::nsFileView() :
  mSortType(-1),
  mTotalRows(0),
  mShowHiddenFiles(false),
  mDirectoryFilter(false),
  mReverseSort(false)
{
}

nsFileView::~nsFileView()
{
  uint32_t count = mCurrentFilters.Length();
  for (uint32_t i = 0; i < count; ++i)
    NS_Free(mCurrentFilters[i]);
}

nsresult
nsFileView::Init()
{
  mDirectoryAtom = do_GetAtom("directory");
  if (!mDirectoryAtom)
    return NS_ERROR_OUT_OF_MEMORY;

  mFileAtom = do_GetAtom("file");
  if (!mFileAtom)
    return NS_ERROR_OUT_OF_MEMORY;

  NS_NewISupportsArray(getter_AddRefs(mFileList));
  if (!mFileList)
    return NS_ERROR_OUT_OF_MEMORY;

  NS_NewISupportsArray(getter_AddRefs(mDirList));
  if (!mDirList)
    return NS_ERROR_OUT_OF_MEMORY;

  NS_NewISupportsArray(getter_AddRefs(mFilteredFiles));
  if (!mFilteredFiles)
    return NS_ERROR_OUT_OF_MEMORY;

  mDateFormatter = do_CreateInstance(NS_DATETIMEFORMAT_CONTRACTID);
  if (!mDateFormatter)
    return NS_ERROR_OUT_OF_MEMORY;

  return NS_OK;
}

// nsISupports implementation

NS_IMPL_ISUPPORTS2(nsFileView, nsITreeView, nsIFileView)

// nsIFileView implementation

NS_IMETHODIMP
nsFileView::SetShowHiddenFiles(bool aShowHidden)
{
  if (aShowHidden != mShowHiddenFiles) {
    mShowHiddenFiles = aShowHidden;

    // This could be better optimized, but since the hidden
    // file functionality is not currently used, this will be fine.
    SetDirectory(mDirectoryPath);
  }
    
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetShowHiddenFiles(bool* aShowHidden)
{
  *aShowHidden = mShowHiddenFiles;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetShowOnlyDirectories(bool aOnlyDirs)
{
  if (aOnlyDirs == mDirectoryFilter)
    return NS_OK;

  mDirectoryFilter = aOnlyDirs;
  uint32_t dirCount;
  mDirList->Count(&dirCount);
  if (mDirectoryFilter) {
    int32_t rowDiff = mTotalRows - dirCount;

    mFilteredFiles->Clear();
    mTotalRows = dirCount;
    if (mTree)
      mTree->RowCountChanged(mTotalRows, -rowDiff);
  } else {
    // Run the filter again to get the file list back
    FilterFiles();

    SortArray(mFilteredFiles);
    if (mReverseSort)
      ReverseArray(mFilteredFiles);

    if (mTree)
      mTree->RowCountChanged(dirCount, mTotalRows - dirCount);
  }

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetShowOnlyDirectories(bool* aOnlyDirs)
{
  *aOnlyDirs = mDirectoryFilter;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetSortType(int16_t* aSortType)
{
  *aSortType = mSortType;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetReverseSort(bool* aReverseSort)
{
  *aReverseSort = mReverseSort;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::Sort(int16_t aSortType, bool aReverseSort)
{
  if (aSortType == mSortType) {
    if (aReverseSort == mReverseSort)
      return NS_OK;

    mReverseSort = aReverseSort;
    ReverseArray(mDirList);
    ReverseArray(mFilteredFiles);
  } else {
    mSortType = aSortType;
    mReverseSort = aReverseSort;
    SortInternal();
  }

  if (mTree)
    mTree->Invalidate();

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetDirectory(nsIFile* aDirectory)
{
  NS_ENSURE_ARG_POINTER(aDirectory);

  nsCOMPtr<nsISimpleEnumerator> dirEntries;
  aDirectory->GetDirectoryEntries(getter_AddRefs(dirEntries));

  if (!dirEntries) {
    // Couldn't read in the directory, this can happen if the user does not
    // have permission to list it.
    return NS_ERROR_FAILURE;
  }

  mDirectoryPath = aDirectory;
  mFileList->Clear();
  mDirList->Clear();

  bool hasMore = false;

  while (NS_SUCCEEDED(dirEntries->HasMoreElements(&hasMore)) && hasMore) {
    nsCOMPtr<nsISupports> nextItem;
    dirEntries->GetNext(getter_AddRefs(nextItem));
    nsCOMPtr<nsIFile> theFile = do_QueryInterface(nextItem);

    bool isDirectory = false;
    if (theFile) {
      theFile->IsDirectory(&isDirectory);

      if (isDirectory) {
        bool isHidden;
        theFile->IsHidden(&isHidden);
        if (mShowHiddenFiles || !isHidden) {
          mDirList->AppendElement(theFile);
        }
      }
      else {
        mFileList->AppendElement(theFile);
      }
    }
  }

  if (mTree) {
    mTree->BeginUpdateBatch();
    mTree->RowCountChanged(0, -mTotalRows);
  }

  FilterFiles();
  SortInternal();

  if (mTree) {
    mTree->EndUpdateBatch();
    mTree->ScrollToRow(0);
  }

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetFilter(const nsAString& aFilterString)
{
  uint32_t filterCount = mCurrentFilters.Length();
  for (uint32_t i = 0; i < filterCount; ++i)
    NS_Free(mCurrentFilters[i]);
  mCurrentFilters.Clear();

  nsAString::const_iterator start, iter, end;
  aFilterString.BeginReading(iter);
  aFilterString.EndReading(end);

  while (true) {
    // skip over delimiters
    while (iter != end && (*iter == ';' || *iter == ' '))
      ++iter;

    if (iter == end)
      break;

    start = iter; // start of a filter

    // we know this is neither ';' nor ' ', skip to next char
    ++iter;

    // find next delimiter or end of string
    while (iter != end && (*iter != ';' && *iter != ' '))
      ++iter;

    PRUnichar* filter = ToNewUnicode(Substring(start, iter));
    if (!filter)
      return NS_ERROR_OUT_OF_MEMORY;

    if (!mCurrentFilters.AppendElement(filter)) {
      NS_Free(filter);
      return NS_ERROR_OUT_OF_MEMORY;
    }

    if (iter == end)
      break;

    ++iter; // we know this is either ';' or ' ', skip to next char
  }

  if (mTree) {
    mTree->BeginUpdateBatch();
    uint32_t count;
    mDirList->Count(&count);
    mTree->RowCountChanged(count, count - mTotalRows);
  }

  mFilteredFiles->Clear();

  FilterFiles();

  SortArray(mFilteredFiles);
  if (mReverseSort)
    ReverseArray(mFilteredFiles);

  if (mTree)
    mTree->EndUpdateBatch();

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetSelectedFiles(nsIArray** aFiles)
{
  *aFiles = nullptr;
  if (!mSelection)
    return NS_OK;

  int32_t numRanges;
  mSelection->GetRangeCount(&numRanges);

  uint32_t dirCount;
  mDirList->Count(&dirCount);

  nsCOMPtr<nsIMutableArray> fileArray =
    do_CreateInstance(NS_ARRAY_CONTRACTID);
  NS_ENSURE_STATE(fileArray);

  for (int32_t range = 0; range < numRanges; ++range) {
    int32_t rangeBegin, rangeEnd;
    mSelection->GetRangeAt(range, &rangeBegin, &rangeEnd);

    for (int32_t itemIndex = rangeBegin; itemIndex <= rangeEnd; ++itemIndex) {
      nsCOMPtr<nsIFile> curFile;

      if (itemIndex < (int32_t) dirCount)
        curFile = do_QueryElementAt(mDirList, itemIndex);
      else {
        if (itemIndex < mTotalRows)
          curFile = do_QueryElementAt(mFilteredFiles, itemIndex - dirCount);
      }

      if (curFile)
        fileArray->AppendElement(curFile, false);
    }
  }

  NS_ADDREF(*aFiles = fileArray);
  return NS_OK;
}


// nsITreeView implementation

NS_IMETHODIMP
nsFileView::GetRowCount(int32_t* aRowCount)
{
  *aRowCount = mTotalRows;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetSelection(nsITreeSelection** aSelection)
{
  *aSelection = mSelection;
  NS_IF_ADDREF(*aSelection);
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetSelection(nsITreeSelection* aSelection)
{
  mSelection = aSelection;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetRowProperties(int32_t aIndex,
                             nsISupportsArray* aProperties)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetCellProperties(int32_t aRow, nsITreeColumn* aCol,
                              nsISupportsArray* aProperties)
{
  uint32_t dirCount;
  mDirList->Count(&dirCount);

  if (aRow < (int32_t) dirCount)
    aProperties->AppendElement(mDirectoryAtom);
  else if (aRow < mTotalRows)
    aProperties->AppendElement(mFileAtom);

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetColumnProperties(nsITreeColumn* aCol,
                                nsISupportsArray* aProperties)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsContainer(int32_t aIndex, bool* aIsContainer)
{
  *aIsContainer = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsContainerOpen(int32_t aIndex, bool* aIsOpen)
{
  *aIsOpen = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsContainerEmpty(int32_t aIndex, bool* aIsEmpty)
{
  *aIsEmpty = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsSeparator(int32_t aIndex, bool* aIsSeparator)
{
  *aIsSeparator = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsSorted(bool* aIsSorted)
{
  *aIsSorted = (mSortType >= 0);
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::CanDrop(int32_t aIndex, int32_t aOrientation,
                    nsIDOMDataTransfer* dataTransfer, bool* aCanDrop)
{
  *aCanDrop = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::Drop(int32_t aRow, int32_t aOrientation, nsIDOMDataTransfer* dataTransfer)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetParentIndex(int32_t aRowIndex, int32_t* aParentIndex)
{
  *aParentIndex = -1;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::HasNextSibling(int32_t aRowIndex, int32_t aAfterIndex, 
                           bool* aHasSibling)
{
  *aHasSibling = (aAfterIndex < (mTotalRows - 1));
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetLevel(int32_t aIndex, int32_t* aLevel)
{
  *aLevel = 0;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetImageSrc(int32_t aRow, nsITreeColumn* aCol,
                        nsAString& aImageSrc)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetProgressMode(int32_t aRow, nsITreeColumn* aCol,
                            int32_t* aProgressMode)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetCellValue(int32_t aRow, nsITreeColumn* aCol,
                         nsAString& aCellValue)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::GetCellText(int32_t aRow, nsITreeColumn* aCol,
                        nsAString& aCellText)
{
  uint32_t dirCount, fileCount;
  mDirList->Count(&dirCount);
  mFilteredFiles->Count(&fileCount);

  bool isDirectory;
  nsCOMPtr<nsIFile> curFile;

  if (aRow < (int32_t) dirCount) {
    isDirectory = true;
    curFile = do_QueryElementAt(mDirList, aRow);
  } else if (aRow < mTotalRows) {
    isDirectory = false;
    curFile = do_QueryElementAt(mFilteredFiles, aRow - dirCount);
  } else {
    // invalid row
    aCellText.SetCapacity(0);
    return NS_OK;
  }

  const PRUnichar* colID;
  aCol->GetIdConst(&colID);
  if (NS_LITERAL_STRING("FilenameColumn").Equals(colID)) {
    curFile->GetLeafName(aCellText);
  } else if (NS_LITERAL_STRING("LastModifiedColumn").Equals(colID)) {
    PRTime lastModTime;
    curFile->GetLastModifiedTime(&lastModTime);
    // XXX FormatPRTime could take an nsAString&
    nsAutoString temp;
    mDateFormatter->FormatPRTime(nullptr, kDateFormatShort, kTimeFormatSeconds,
                                 lastModTime * 1000, temp);
    aCellText = temp;
  } else {
    // file size
    if (isDirectory)
      aCellText.SetCapacity(0);
    else {
      int64_t fileSize;
      curFile->GetFileSize(&fileSize);
      CopyUTF8toUTF16(nsPrintfCString("%lld", fileSize), aCellText);
    }
  }

  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetTree(nsITreeBoxObject* aTree)
{
  mTree = aTree;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::ToggleOpenState(int32_t aIndex)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::CycleHeader(nsITreeColumn* aCol)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SelectionChanged()
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::CycleCell(int32_t aRow, nsITreeColumn* aCol)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsEditable(int32_t aRow, nsITreeColumn* aCol,
                       bool* aIsEditable)
{
  *aIsEditable = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::IsSelectable(int32_t aRow, nsITreeColumn* aCol,
                         bool* aIsSelectable)
{
  *aIsSelectable = false;
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetCellValue(int32_t aRow, nsITreeColumn* aCol,
                         const nsAString& aValue)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::SetCellText(int32_t aRow, nsITreeColumn* aCol,
                        const nsAString& aValue)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::PerformAction(const PRUnichar* aAction)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::PerformActionOnRow(const PRUnichar* aAction, int32_t aRow)
{
  return NS_OK;
}

NS_IMETHODIMP
nsFileView::PerformActionOnCell(const PRUnichar* aAction, int32_t aRow,
                                nsITreeColumn* aCol)
{
  return NS_OK;
}

// Private methods

void
nsFileView::FilterFiles()
{
  uint32_t count = 0;
  mDirList->Count(&count);
  mTotalRows = count;
  mFileList->Count(&count);
  mFilteredFiles->Clear();
  uint32_t filterCount = mCurrentFilters.Length();

  nsCOMPtr<nsIFile> file;
  for (uint32_t i = 0; i < count; ++i) {
    file = do_QueryElementAt(mFileList, i);
    bool isHidden = false;
    if (!mShowHiddenFiles)
      file->IsHidden(&isHidden);
    
    nsAutoString ucsLeafName;
    if(NS_FAILED(file->GetLeafName(ucsLeafName))) {
      // need to check return value for GetLeafName()
      continue;
    }
    
    if (!isHidden) {
      for (uint32_t j = 0; j < filterCount; ++j) {
        bool matched = false;
        if (!nsCRT::strcmp(mCurrentFilters.ElementAt(j),
                           NS_LITERAL_STRING("..apps").get()))
        {
          file->IsExecutable(&matched);
        } else
          matched = (NS_WildCardMatch(ucsLeafName.get(),
                                      mCurrentFilters.ElementAt(j),
                                      true) == MATCH);

        if (matched) {
          mFilteredFiles->AppendElement(file);
          ++mTotalRows;
          break;
        }
      }
    }
  }
}

void
nsFileView::ReverseArray(nsISupportsArray* aArray)
{
  uint32_t count;
  aArray->Count(&count);
  for (uint32_t i = 0; i < count/2; ++i) {
    nsCOMPtr<nsISupports> element = dont_AddRef(aArray->ElementAt(i));
    nsCOMPtr<nsISupports> element2 = dont_AddRef(aArray->ElementAt(count-i-1));
    aArray->ReplaceElementAt(element2, i);
    aArray->ReplaceElementAt(element, count-i-1);
  }
}

static int
SortNameCallback(const void* aElement1, const void* aElement2, void* aContext)
{
  nsIFile* file1 = *static_cast<nsIFile* const *>(aElement1);
  nsIFile* file2 = *static_cast<nsIFile* const *>(aElement2);
  
  nsAutoString leafName1, leafName2;
  file1->GetLeafName(leafName1);
  file2->GetLeafName(leafName2);

  return Compare(leafName1, leafName2);
}

static int
SortSizeCallback(const void* aElement1, const void* aElement2, void* aContext)
{
  nsIFile* file1 = *static_cast<nsIFile* const *>(aElement1);
  nsIFile* file2 = *static_cast<nsIFile* const *>(aElement2);

  int64_t size1, size2;
  file1->GetFileSize(&size1);
  file2->GetFileSize(&size2);

  if (LL_EQ(size1, size2))
    return 0;

  return (LL_CMP(size1, <, size2) ? -1 : 1);
}

static int
SortDateCallback(const void* aElement1, const void* aElement2, void* aContext)
{
  nsIFile* file1 = *static_cast<nsIFile* const *>(aElement1);
  nsIFile* file2 = *static_cast<nsIFile* const *>(aElement2);

  PRTime time1, time2;
  file1->GetLastModifiedTime(&time1);
  file2->GetLastModifiedTime(&time2);

  if (LL_EQ(time1, time2))
    return 0;

  return (LL_CMP(time1, <, time2) ? -1 : 1);
}

void
nsFileView::SortArray(nsISupportsArray* aArray)
{
  // We assume the array to be in filesystem order, which
  // for our purposes, is completely unordered.

  int (*compareFunc)(const void*, const void*, void*);

  switch (mSortType) {
  case sortName:
    compareFunc = SortNameCallback;
    break;
  case sortSize:
    compareFunc = SortSizeCallback;
    break;
  case sortDate:
    compareFunc = SortDateCallback;
    break;
  default:
    return;
  }

  uint32_t count;
  aArray->Count(&count);

  // each item will have an additional refcount while
  // the array is alive.
  nsIFile** array = new nsIFile*[count];
  uint32_t i;
  for (i = 0; i < count; ++i)
    aArray->QueryElementAt(i, NS_GET_IID(nsIFile), (void**)&(array[i]));

  NS_QuickSort(array, count, sizeof(nsIFile*), compareFunc, nullptr);

  for (i = 0; i < count; ++i) {
    aArray->ReplaceElementAt(array[i], i);
    NS_RELEASE(array[i]);
  }

  delete[] array;
}

void
nsFileView::SortInternal()
{
  SortArray(mDirList);
  SortArray(mFilteredFiles);

  if (mReverseSort) {
    ReverseArray(mDirList);
    ReverseArray(mFilteredFiles);
  }
}
