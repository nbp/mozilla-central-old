/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1999 Netscape Communications Corporation.  All Rights
 * Reserved.
*/

#include "msgCore.h"
#include "nsLocalUtils.h"
#include "nsIServiceManager.h"
#include "prsystem.h"
#include "nsCOMPtr.h"

// stuff for temporary root folder hack
#include "nsIMsgMailSession.h"
#include "nsIMsgIncomingServer.h"
#include "nsIPop3IncomingServer.h"


static NS_DEFINE_CID(kMsgMailSessionCID, NS_MSGMAILSESSION_CID);

//utilities
static char *gMailboxRoot = nsnull;

nsresult
nsGetMailboxRoot(nsFileSpec &result)
{
  nsresult rv = NS_OK;

  // temporary stuff. for now get everything from the mail session
  if (gMailboxRoot == nsnull) {
    NS_WITH_SERVICE(nsIMsgMailSession, session, kMsgMailSessionCID, &rv);
    
    if (NS_SUCCEEDED(rv)) {
      nsCOMPtr<nsIMsgIncomingServer> server;
      rv = session->GetCurrentServer(getter_AddRefs(server));
      
      if (NS_SUCCEEDED(rv))
          rv = server->GetLocalPath(&gMailboxRoot);
    }
  } /* if (gMailboxRoot == nsnull) .. */
  result = gMailboxRoot;
  return rv;
}

nsresult
nsLocalURI2Path(const char* rootURI, const char* uriStr, nsFileSpec& pathResult)
{
  nsresult rv;

  
  nsAutoString sep;
  sep += PR_GetDirectorySeparator();

  nsAutoString sbdSep;
  rv = nsGetMailFolderSeparator(sbdSep);
  if (NS_FAILED(rv)) return rv;

  nsAutoString uri = uriStr;
  if (uri.Find(rootURI) != 0)     // if doesn't start with rootURI
    return NS_ERROR_FAILURE;

  if ((strcmp(rootURI, kMailboxRootURI) == 0) || 
           (strcmp(rootURI, kMailboxMessageRootURI) == 0)) {
    // local mail case
    rv = nsGetMailboxRoot(pathResult);
	}
  else {
    rv = NS_ERROR_FAILURE; 
  }

  if (NS_FAILED(rv)) {
    pathResult = nsnull;
    return rv;
  }
 
  nsAutoString path="";
  uri.Cut(0, nsCRT::strlen(rootURI));

  PRInt32 uriLen = uri.Length();
  PRInt32 pos;
  while(uriLen > 0) {
    nsAutoString folderName;

    PRInt32 leadingPos;
    // if it's the first character then remove it.
    while ((leadingPos = uri.Find('/')) == 0) {
      uri.Cut(0, 1);
      uriLen--;
    }

    if (uriLen == 0)
      break;

    pos = uri.Find('/');
    if (pos < 0)
      pos = uriLen;


    PRInt32 leftRes = uri.Left(folderName, pos);

    NS_ASSERTION(leftRes == pos,
                 "something wrong with nsString");
	//We only want to add this after the first time around.
	if(path.Length() > 0)
	{
		path += sep;
		path += PR_GetDirectorySeparator();
	}
    // the first time around the separator is special because
    // the root mail folder doesn't end with .sbd
    sep = sbdSep;

    path += folderName;
    uri.Cut(0, pos);
    uriLen -= pos;
  }

  if(path.Length() > 0)
	  pathResult +=path;

  return NS_OK;
}

nsresult
nsPath2LocalURI(const char* rootURI, const nsFileSpec& spec, char **uri)
{
  nsresult rv;


  nsAutoString sep;
  /* sspitzer: is this ok for mail and news? */
  rv = nsGetMailFolderSeparator(sep);
  if (NS_FAILED(rv)) return rv;

  PRUint32 sepLen = sep.Length();

  nsFileSpec root;
  // local mail case
   rv = nsGetMailboxRoot(root);
  if (NS_FAILED(rv)) return rv;

  const char *path = spec;
  nsAutoString pathStr(path);
  path = root;
  nsAutoString rootStr(path);
  
  PRInt32 pos = pathStr.Find(rootStr);
  if (pos != 0)     // if doesn't start with root path
    return NS_ERROR_FAILURE;

  nsAutoString uriStr(rootURI);

  PRUint32 rootStrLen = rootStr.Length();
  pathStr.Cut(0, rootStrLen);
  PRInt32 pathStrLen = pathStr.Length();

  char dirSep = PR_GetDirectorySeparator();
  
  while (pathStrLen > 0) {
    nsAutoString folderName;
    
    PRInt32 leadingPos;
    // if it's the first character then remove it.
    while ((leadingPos = pathStr.Find(dirSep)) == 0) {
      pathStr.Cut(0, 1);
      pathStrLen--;
    }
    if (pathStrLen == 0)
      break;

    pos = pathStr.Find(sep);
    if (pos < 0) 
      pos = pathStrLen;

    PRInt32 leftRes = pathStr.Left(folderName, pos);
    NS_ASSERTION(leftRes == pos,
                 "something wrong with nsString");

    pathStr.Cut(0, pos + sepLen);
    pathStrLen -= pos + sepLen;

    uriStr += '/';
    uriStr += folderName;
  }
  *uri = uriStr.ToNewCString();
  return NS_OK;
}

nsresult
nsLocalURI2Name(const char* rootURI, char* uriStr, nsString& name)
{
  nsAutoString uri = uriStr;
  if (uri.Find(rootURI) != 0)     // if doesn't start with rootURI
    return NS_ERROR_FAILURE;
  PRInt32 pos = uri.RFind("/");
  PRInt32 length = uri.Length();
  PRInt32 count = length - (pos + 1);
  return uri.Right(name, count);
}

/* parses LocalMessageURI */
nsresult nsParseLocalMessageURI(const char* uri, nsString& folderURI, PRUint32 *key)
{
	if(!key)
		return NS_ERROR_NULL_POINTER;

	nsAutoString uriStr = uri;
	PRInt32 keySeparator = uriStr.Find('#');
	if(keySeparator != -1)
	{
		nsAutoString folderPath;
		uriStr.Left(folderURI, keySeparator);

		nsAutoString keyStr;
		uriStr.Right(keyStr, uriStr.Length() - (keySeparator + 1));
		PRInt32 errorCode;
		*key = keyStr.ToInteger(&errorCode);

		return errorCode;
	}
	return NS_ERROR_FAILURE;

}

nsresult nsBuildLocalMessageURI(const nsFileSpec& path, PRUint32 key, char** uri)
{
	
	if(!uri)
		return NS_ERROR_NULL_POINTER;

	char *folderURI;

	nsPath2LocalURI(kMailboxMessageRootURI, path, &folderURI);

	*uri = PR_smprintf("%s#%d", folderURI, key);

	delete[] folderURI;

	return NS_OK;
}
