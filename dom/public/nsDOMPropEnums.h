/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public
 * License Version 1.1 (the "License"); you may not use this file
 * except in compliance with the License. You may obtain a copy of
 * the License at http://www.mozilla.org/NPL/
 *
 * Software distributed under the License is distributed on an "AS
 * IS" basis, WITHOUT WARRANTY OF ANY KIND, either express or
 * implied. See the License for the specific language governing
 * rights and limitations under the License.
 *
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1999 Netscape Communications Corporation. All
 * Rights Reserved.
 *
 * Contributor(s): 
 * Norris Boyd
 */

/* nsDOMPropEnums.h -- an enumeration of all DOM properties used to provide 
**                     per-property security policies 
*/

#ifndef nsDOMPropEnums_h__
#define nsDOMPropEnums_h__

// Be sure to keep this list in sync with the list of strings 
// in mozilla/caps/src/nsScriptSecurityManager.cpp

enum nsDOMProp {
    NS_DOM_PROP_APPCORESMANAGER_ADD,
    NS_DOM_PROP_APPCORESMANAGER_FIND,
    NS_DOM_PROP_APPCORESMANAGER_REMOVE,
    NS_DOM_PROP_APPCORESMANAGER_SHUTDOWN,
    NS_DOM_PROP_APPCORESMANAGER_STARTUP,
    NS_DOM_PROP_ATTR_NAME, 
    NS_DOM_PROP_ATTR_SPECIFIED, 
    NS_DOM_PROP_ATTR_VALUE, 
    NS_DOM_PROP_BARPROP_VISIBLE, 
    NS_DOM_PROP_BASEAPPCORE_ID,
    NS_DOM_PROP_BASEAPPCORE_INIT,
    NS_DOM_PROP_BASEAPPCORE_SETDOCUMENTCHARSET,
    NS_DOM_PROP_CHARACTERDATA_APPENDDATA, 
    NS_DOM_PROP_CHARACTERDATA_DATA, 
    NS_DOM_PROP_CHARACTERDATA_DELETEDATA, 
    NS_DOM_PROP_CHARACTERDATA_INSERTDATA, 
    NS_DOM_PROP_CHARACTERDATA_LENGTH, 
    NS_DOM_PROP_CHARACTERDATA_REPLACEDATA, 
    NS_DOM_PROP_CHARACTERDATA_SUBSTRINGDATA, 
    NS_DOM_PROP_CSS2PROPERTIES_AZIMUTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUND, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUNDATTACHMENT, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUNDCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUNDIMAGE, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUNDPOSITION, 
    NS_DOM_PROP_CSS2PROPERTIES_BACKGROUNDREPEAT, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDER, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERBOTTOM, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERBOTTOMCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERBOTTOMSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERBOTTOMWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERCOLLAPSE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERLEFT, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERLEFTCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERLEFTSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERLEFTWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERRIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERRIGHTCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERRIGHTSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERRIGHTWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERSPACING, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERTOP, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERTOPCOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERTOPSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERTOPWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BORDERWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_BOTTOM, 
    NS_DOM_PROP_CSS2PROPERTIES_CAPTIONSIDE, 
    NS_DOM_PROP_CSS2PROPERTIES_CLEAR, 
    NS_DOM_PROP_CSS2PROPERTIES_CLIP, 
    NS_DOM_PROP_CSS2PROPERTIES_COLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_CONTENT, 
    NS_DOM_PROP_CSS2PROPERTIES_COUNTERINCREMENT, 
    NS_DOM_PROP_CSS2PROPERTIES_COUNTERRESET, 
    NS_DOM_PROP_CSS2PROPERTIES_CSSFLOAT, 
    NS_DOM_PROP_CSS2PROPERTIES_CUE, 
    NS_DOM_PROP_CSS2PROPERTIES_CUEAFTER, 
    NS_DOM_PROP_CSS2PROPERTIES_CUEBEFORE, 
    NS_DOM_PROP_CSS2PROPERTIES_CURSOR, 
    NS_DOM_PROP_CSS2PROPERTIES_DIRECTION, 
    NS_DOM_PROP_CSS2PROPERTIES_DISPLAY, 
    NS_DOM_PROP_CSS2PROPERTIES_ELEVATION, 
    NS_DOM_PROP_CSS2PROPERTIES_EMPTYCELLS, 
    NS_DOM_PROP_CSS2PROPERTIES_FONT, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTFAMILY, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTSIZE, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTSIZEADJUST, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTSTRETCH, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTVARIANT, 
    NS_DOM_PROP_CSS2PROPERTIES_FONTWEIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_HEIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_LEFT, 
    NS_DOM_PROP_CSS2PROPERTIES_LETTERSPACING, 
    NS_DOM_PROP_CSS2PROPERTIES_LINEHEIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_LISTSTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_LISTSTYLEIMAGE, 
    NS_DOM_PROP_CSS2PROPERTIES_LISTSTYLEPOSITION, 
    NS_DOM_PROP_CSS2PROPERTIES_LISTSTYLETYPE, 
    NS_DOM_PROP_CSS2PROPERTIES_MARGIN, 
    NS_DOM_PROP_CSS2PROPERTIES_MARGINBOTTOM, 
    NS_DOM_PROP_CSS2PROPERTIES_MARGINLEFT, 
    NS_DOM_PROP_CSS2PROPERTIES_MARGINRIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_MARGINTOP, 
    NS_DOM_PROP_CSS2PROPERTIES_MARKEROFFSET, 
    NS_DOM_PROP_CSS2PROPERTIES_MARKS, 
    NS_DOM_PROP_CSS2PROPERTIES_MAXHEIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_MAXWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_MINHEIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_MINWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_OPACITY, 
    NS_DOM_PROP_CSS2PROPERTIES_ORPHANS, 
    NS_DOM_PROP_CSS2PROPERTIES_OUTLINE, 
    NS_DOM_PROP_CSS2PROPERTIES_OUTLINECOLOR, 
    NS_DOM_PROP_CSS2PROPERTIES_OUTLINESTYLE, 
    NS_DOM_PROP_CSS2PROPERTIES_OUTLINEWIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_OVERFLOW, 
    NS_DOM_PROP_CSS2PROPERTIES_PADDING, 
    NS_DOM_PROP_CSS2PROPERTIES_PADDINGBOTTOM, 
    NS_DOM_PROP_CSS2PROPERTIES_PADDINGLEFT, 
    NS_DOM_PROP_CSS2PROPERTIES_PADDINGRIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_PADDINGTOP, 
    NS_DOM_PROP_CSS2PROPERTIES_PAGE, 
    NS_DOM_PROP_CSS2PROPERTIES_PAGEBREAKAFTER, 
    NS_DOM_PROP_CSS2PROPERTIES_PAGEBREAKBEFORE, 
    NS_DOM_PROP_CSS2PROPERTIES_PAGEBREAKINSIDE, 
    NS_DOM_PROP_CSS2PROPERTIES_PAUSE, 
    NS_DOM_PROP_CSS2PROPERTIES_PAUSEAFTER, 
    NS_DOM_PROP_CSS2PROPERTIES_PAUSEBEFORE, 
    NS_DOM_PROP_CSS2PROPERTIES_PITCH, 
    NS_DOM_PROP_CSS2PROPERTIES_PITCHRANGE, 
    NS_DOM_PROP_CSS2PROPERTIES_PLAYDURING, 
    NS_DOM_PROP_CSS2PROPERTIES_POSITION, 
    NS_DOM_PROP_CSS2PROPERTIES_QUOTES, 
    NS_DOM_PROP_CSS2PROPERTIES_RICHNESS, 
    NS_DOM_PROP_CSS2PROPERTIES_RIGHT, 
    NS_DOM_PROP_CSS2PROPERTIES_SIZE, 
    NS_DOM_PROP_CSS2PROPERTIES_SPEAK, 
    NS_DOM_PROP_CSS2PROPERTIES_SPEAKHEADER, 
    NS_DOM_PROP_CSS2PROPERTIES_SPEAKNUMERAL, 
    NS_DOM_PROP_CSS2PROPERTIES_SPEAKPUNCTUATION, 
    NS_DOM_PROP_CSS2PROPERTIES_SPEECHRATE, 
    NS_DOM_PROP_CSS2PROPERTIES_STRESS, 
    NS_DOM_PROP_CSS2PROPERTIES_TABLELAYOUT, 
    NS_DOM_PROP_CSS2PROPERTIES_TEXTALIGN, 
    NS_DOM_PROP_CSS2PROPERTIES_TEXTDECORATION, 
    NS_DOM_PROP_CSS2PROPERTIES_TEXTINDENT, 
    NS_DOM_PROP_CSS2PROPERTIES_TEXTSHADOW, 
    NS_DOM_PROP_CSS2PROPERTIES_TEXTTRANSFORM, 
    NS_DOM_PROP_CSS2PROPERTIES_TOP, 
    NS_DOM_PROP_CSS2PROPERTIES_UNICODEBIDI, 
    NS_DOM_PROP_CSS2PROPERTIES_VERTICALALIGN, 
    NS_DOM_PROP_CSS2PROPERTIES_VISIBILITY, 
    NS_DOM_PROP_CSS2PROPERTIES_VOICEFAMILY, 
    NS_DOM_PROP_CSS2PROPERTIES_VOLUME, 
    NS_DOM_PROP_CSS2PROPERTIES_WHITESPACE, 
    NS_DOM_PROP_CSS2PROPERTIES_WIDOWS, 
    NS_DOM_PROP_CSS2PROPERTIES_WIDTH, 
    NS_DOM_PROP_CSS2PROPERTIES_WORDSPACING, 
    NS_DOM_PROP_CSS2PROPERTIES_ZINDEX, 
    NS_DOM_PROP_CSSFONTFACERULE_STYLE, 
    NS_DOM_PROP_CSSIMPORTRULE_HREF, 
    NS_DOM_PROP_CSSIMPORTRULE_MEDIA, 
    NS_DOM_PROP_CSSIMPORTRULE_STYLESHEET, 
    NS_DOM_PROP_CSSMEDIARULE_CSSRULES, 
    NS_DOM_PROP_CSSMEDIARULE_DELETERULE, 
    NS_DOM_PROP_CSSMEDIARULE_INSERTRULE, 
    NS_DOM_PROP_CSSMEDIARULE_MEDIATYPES, 
    NS_DOM_PROP_CSSPAGERULE_NAME, 
    NS_DOM_PROP_CSSPAGERULE_STYLE, 
    NS_DOM_PROP_CSSRULE_CSSTEXT, 
    NS_DOM_PROP_CSSRULE_SHEET, 
    NS_DOM_PROP_CSSRULE_TYPE, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_CSSTEXT, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_GETPROPERTYPRIORITY, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_GETPROPERTYVALUE, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_ITEM, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_LENGTH, 
    NS_DOM_PROP_CSSSTYLEDECLARATION_SETPROPERTY, 
    NS_DOM_PROP_CSSSTYLERULE_SELECTORTEXT, 
    NS_DOM_PROP_CSSSTYLERULE_STYLE, 
    NS_DOM_PROP_CSSSTYLERULECOLLECTION_ITEM, 
    NS_DOM_PROP_CSSSTYLERULECOLLECTION_LENGTH, 
    NS_DOM_PROP_CSSSTYLESHEET_CSSRULES, 
    NS_DOM_PROP_CSSSTYLESHEET_DELETERULE, 
    NS_DOM_PROP_CSSSTYLESHEET_HREF, 
    NS_DOM_PROP_CSSSTYLESHEET_INSERTRULE, 
    NS_DOM_PROP_CSSSTYLESHEET_MEDIA, 
    NS_DOM_PROP_CSSSTYLESHEET_OWNINGNODE, 
    NS_DOM_PROP_CSSSTYLESHEET_PARENTSTYLESHEET, 
    NS_DOM_PROP_CSSSTYLESHEET_TITLE, 
    NS_DOM_PROP_DOCUMENT_CREATEATTRIBUTE, 
    NS_DOM_PROP_DOCUMENT_CREATECDATASECTION, 
    NS_DOM_PROP_DOCUMENT_CREATECOMMENT, 
    NS_DOM_PROP_DOCUMENT_CREATEDOCUMENTFRAGMENT, 
    NS_DOM_PROP_DOCUMENT_CREATEELEMENT, 
    NS_DOM_PROP_DOCUMENT_CREATEENTITYREFERENCE, 
    NS_DOM_PROP_DOCUMENT_CREATEPROCESSINGINSTRUCTION, 
    NS_DOM_PROP_DOCUMENT_CREATETEXTNODE, 
    NS_DOM_PROP_DOCUMENT_DOCTYPE, 
    NS_DOM_PROP_DOCUMENT_DOCUMENTELEMENT, 
    NS_DOM_PROP_DOCUMENT_GETELEMENTSBYTAGNAME, 
    NS_DOM_PROP_DOCUMENT_IMPLEMENTATION, 
    NS_DOM_PROP_DOCUMENTTYPE_ENTITIES, 
    NS_DOM_PROP_DOCUMENTTYPE_NAME, 
    NS_DOM_PROP_DOCUMENTTYPE_NOTATIONS, 
    NS_DOM_PROP_DOMEXCEPTION_CODE, 
    NS_DOM_PROP_DOMEXCEPTION_MESSAGE, 
    NS_DOM_PROP_DOMEXCEPTION_NAME, 
    NS_DOM_PROP_DOMEXCEPTION_RESULT, 
    NS_DOM_PROP_DOMEXCEPTION_TOSTRING, 
    NS_DOM_PROP_DOMIMPLEMENTATION_HASFEATURE, 
    NS_DOM_PROP_ELEMENT_GETATTRIBUTE, 
    NS_DOM_PROP_ELEMENT_GETATTRIBUTENODE, 
    NS_DOM_PROP_ELEMENT_GETELEMENTSBYTAGNAME, 
    NS_DOM_PROP_ELEMENT_NORMALIZE, 
    NS_DOM_PROP_ELEMENT_REMOVEATTRIBUTE, 
    NS_DOM_PROP_ELEMENT_REMOVEATTRIBUTENODE, 
    NS_DOM_PROP_ELEMENT_SETATTRIBUTE, 
    NS_DOM_PROP_ELEMENT_SETATTRIBUTENODE, 
    NS_DOM_PROP_ELEMENT_TAGNAME, 
    NS_DOM_PROP_ENTITY_NOTATIONNAME, 
    NS_DOM_PROP_ENTITY_PUBLICID, 
    NS_DOM_PROP_ENTITY_SYSTEMID, 
    NS_DOM_PROP_EVENT_BUBBLES, 
    NS_DOM_PROP_EVENT_CANCELABLE, 
    NS_DOM_PROP_EVENT_CURRENTNODE, 
    NS_DOM_PROP_EVENT_EVENTPHASE, 
    NS_DOM_PROP_EVENT_INITEVENT, 
    NS_DOM_PROP_EVENT_PREVENTBUBBLE, 
    NS_DOM_PROP_EVENT_PREVENTCAPTURE, 
    NS_DOM_PROP_EVENT_PREVENTDEFAULT, 
    NS_DOM_PROP_EVENT_TARGET, 
    NS_DOM_PROP_EVENT_TYPE, 
    NS_DOM_PROP_EVENTTARGET_ADDEVENTLISTENER, 
    NS_DOM_PROP_EVENTTARGET_REMOVEEVENTLISTENER, 
    NS_DOM_PROP_HISTORY_BACK, 
    NS_DOM_PROP_HISTORY_CURRENT, 
    NS_DOM_PROP_HISTORY_FORWARD, 
    NS_DOM_PROP_HISTORY_GO, 
    NS_DOM_PROP_HISTORY_LENGTH, 
    NS_DOM_PROP_HISTORY_NEXT, 
    NS_DOM_PROP_HISTORY_PREVIOUS, 
    NS_DOM_PROP_HTMLANCHORELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLANCHORELEMENT_BLUR, 
    NS_DOM_PROP_HTMLANCHORELEMENT_CHARSET, 
    NS_DOM_PROP_HTMLANCHORELEMENT_COORDS, 
    NS_DOM_PROP_HTMLANCHORELEMENT_FOCUS, 
    NS_DOM_PROP_HTMLANCHORELEMENT_HREF, 
    NS_DOM_PROP_HTMLANCHORELEMENT_HREFLANG, 
    NS_DOM_PROP_HTMLANCHORELEMENT_NAME, 
    NS_DOM_PROP_HTMLANCHORELEMENT_REL, 
    NS_DOM_PROP_HTMLANCHORELEMENT_REV, 
    NS_DOM_PROP_HTMLANCHORELEMENT_SHAPE, 
    NS_DOM_PROP_HTMLANCHORELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLANCHORELEMENT_TARGET, 
    NS_DOM_PROP_HTMLANCHORELEMENT_TYPE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_ALT, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_ARCHIVE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_CODE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_CODEBASE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_HSPACE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_NAME, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_OBJECT, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_VSPACE, 
    NS_DOM_PROP_HTMLAPPLETELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLAREAELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLAREAELEMENT_ALT, 
    NS_DOM_PROP_HTMLAREAELEMENT_COORDS, 
    NS_DOM_PROP_HTMLAREAELEMENT_HREF, 
    NS_DOM_PROP_HTMLAREAELEMENT_NOHREF, 
    NS_DOM_PROP_HTMLAREAELEMENT_SHAPE, 
    NS_DOM_PROP_HTMLAREAELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLAREAELEMENT_TARGET, 
    NS_DOM_PROP_HTMLBASEELEMENT_HREF, 
    NS_DOM_PROP_HTMLBASEELEMENT_TARGET, 
    NS_DOM_PROP_HTMLBASEFONTELEMENT_COLOR, 
    NS_DOM_PROP_HTMLBASEFONTELEMENT_FACE, 
    NS_DOM_PROP_HTMLBASEFONTELEMENT_SIZE, 
    NS_DOM_PROP_HTMLBLOCKQUOTEELEMENT_CITE, 
    NS_DOM_PROP_HTMLBODYELEMENT_ALINK, 
    NS_DOM_PROP_HTMLBODYELEMENT_BACKGROUND, 
    NS_DOM_PROP_HTMLBODYELEMENT_BGCOLOR, 
    NS_DOM_PROP_HTMLBODYELEMENT_LINK, 
    NS_DOM_PROP_HTMLBODYELEMENT_TEXT, 
    NS_DOM_PROP_HTMLBODYELEMENT_VLINK, 
    NS_DOM_PROP_HTMLBRELEMENT_CLEAR, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_FORM, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_NAME, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_TYPE, 
    NS_DOM_PROP_HTMLBUTTONELEMENT_VALUE, 
    NS_DOM_PROP_HTMLCOLLECTION_ITEM, 
    NS_DOM_PROP_HTMLCOLLECTION_LENGTH, 
    NS_DOM_PROP_HTMLCOLLECTION_NAMEDITEM, 
    NS_DOM_PROP_HTMLDIRECTORYELEMENT_COMPACT, 
    NS_DOM_PROP_HTMLDIVELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLDLISTELEMENT_COMPACT, 
    NS_DOM_PROP_HTMLDOCUMENT_ANCHORS, 
    NS_DOM_PROP_HTMLDOCUMENT_APPLETS, 
    NS_DOM_PROP_HTMLDOCUMENT_BODY, 
    NS_DOM_PROP_HTMLDOCUMENT_CLOSE, 
    NS_DOM_PROP_HTMLDOCUMENT_COOKIE, 
    NS_DOM_PROP_HTMLDOCUMENT_DOMAIN, 
    NS_DOM_PROP_HTMLDOCUMENT_FORMS, 
    NS_DOM_PROP_HTMLDOCUMENT_GETELEMENTBYID, 
    NS_DOM_PROP_HTMLDOCUMENT_GETELEMENTSBYNAME, 
    NS_DOM_PROP_HTMLDOCUMENT_IMAGES, 
    NS_DOM_PROP_HTMLDOCUMENT_LINKS, 
    NS_DOM_PROP_HTMLDOCUMENT_REFERRER, 
    NS_DOM_PROP_HTMLDOCUMENT_TITLE, 
    NS_DOM_PROP_HTMLDOCUMENT_URL, 
    NS_DOM_PROP_HTMLELEMENT_CLASSNAME, 
    NS_DOM_PROP_HTMLELEMENT_DIR, 
    NS_DOM_PROP_HTMLELEMENT_ID, 
    NS_DOM_PROP_HTMLELEMENT_LANG, 
    NS_DOM_PROP_HTMLELEMENT_STYLE, 
    NS_DOM_PROP_HTMLELEMENT_TITLE, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_NAME, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_SRC, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_TYPE, 
    NS_DOM_PROP_HTMLEMBEDELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLFIELDSETELEMENT_FORM, 
    NS_DOM_PROP_HTMLFONTELEMENT_COLOR, 
    NS_DOM_PROP_HTMLFONTELEMENT_FACE, 
    NS_DOM_PROP_HTMLFONTELEMENT_SIZE, 
    NS_DOM_PROP_HTMLFORMELEMENT_ACCEPTCHARSET, 
    NS_DOM_PROP_HTMLFORMELEMENT_ACTION, 
    NS_DOM_PROP_HTMLFORMELEMENT_ELEMENTS, 
    NS_DOM_PROP_HTMLFORMELEMENT_ENCTYPE, 
    NS_DOM_PROP_HTMLFORMELEMENT_LENGTH, 
    NS_DOM_PROP_HTMLFORMELEMENT_METHOD, 
    NS_DOM_PROP_HTMLFORMELEMENT_NAME, 
    NS_DOM_PROP_HTMLFORMELEMENT_RESET, 
    NS_DOM_PROP_HTMLFORMELEMENT_SUBMIT, 
    NS_DOM_PROP_HTMLFORMELEMENT_TARGET, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_FRAMEBORDER, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_LONGDESC, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_MARGINHEIGHT, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_MARGINWIDTH, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_NAME, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_NORESIZE, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_SCROLLING, 
    NS_DOM_PROP_HTMLFRAMEELEMENT_SRC, 
    NS_DOM_PROP_HTMLFRAMESETELEMENT_COLS, 
    NS_DOM_PROP_HTMLFRAMESETELEMENT_ROWS, 
    NS_DOM_PROP_HTMLHEADELEMENT_PROFILE, 
    NS_DOM_PROP_HTMLHEADINGELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLHRELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLHRELEMENT_NOSHADE, 
    NS_DOM_PROP_HTMLHRELEMENT_SIZE, 
    NS_DOM_PROP_HTMLHRELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLHTMLELEMENT_VERSION, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_FRAMEBORDER, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_LONGDESC, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_MARGINHEIGHT, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_MARGINWIDTH, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_NAME, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_SCROLLING, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_SRC, 
    NS_DOM_PROP_HTMLIFRAMEELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_ALT, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_BORDER, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_HSPACE, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_ISMAP, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_LONGDESC, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_LOWSRC, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_NAME, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_SRC, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_USEMAP, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_VSPACE, 
    NS_DOM_PROP_HTMLIMAGEELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLINPUTELEMENT_ACCEPT, 
    NS_DOM_PROP_HTMLINPUTELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLINPUTELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLINPUTELEMENT_ALT, 
    NS_DOM_PROP_HTMLINPUTELEMENT_AUTOCOMPLETE, 
    NS_DOM_PROP_HTMLINPUTELEMENT_BLUR, 
    NS_DOM_PROP_HTMLINPUTELEMENT_CHECKED, 
    NS_DOM_PROP_HTMLINPUTELEMENT_CLICK,
    NS_DOM_PROP_HTMLINPUTELEMENT_CONTROLLERS,
    NS_DOM_PROP_HTMLINPUTELEMENT_DEFAULTCHECKED, 
    NS_DOM_PROP_HTMLINPUTELEMENT_DEFAULTVALUE, 
    NS_DOM_PROP_HTMLINPUTELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLINPUTELEMENT_FOCUS, 
    NS_DOM_PROP_HTMLINPUTELEMENT_FORM, 
    NS_DOM_PROP_HTMLINPUTELEMENT_MAXLENGTH, 
    NS_DOM_PROP_HTMLINPUTELEMENT_NAME, 
    NS_DOM_PROP_HTMLINPUTELEMENT_READONLY, 
    NS_DOM_PROP_HTMLINPUTELEMENT_SELECT, 
    NS_DOM_PROP_HTMLINPUTELEMENT_SIZE, 
    NS_DOM_PROP_HTMLINPUTELEMENT_SRC, 
    NS_DOM_PROP_HTMLINPUTELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLINPUTELEMENT_TYPE, 
    NS_DOM_PROP_HTMLINPUTELEMENT_USEMAP, 
    NS_DOM_PROP_HTMLINPUTELEMENT_VALUE, 
    NS_DOM_PROP_HTMLISINDEXELEMENT_FORM, 
    NS_DOM_PROP_HTMLISINDEXELEMENT_PROMPT, 
    NS_DOM_PROP_HTMLLABELELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLLABELELEMENT_FORM, 
    NS_DOM_PROP_HTMLLABELELEMENT_HTMLFOR, 
    NS_DOM_PROP_HTMLLAYERELEMENT_BACKGROUND, 
    NS_DOM_PROP_HTMLLAYERELEMENT_BGCOLOR, 
    NS_DOM_PROP_HTMLLAYERELEMENT_DOCUMENT, 
    NS_DOM_PROP_HTMLLAYERELEMENT_LEFT, 
    NS_DOM_PROP_HTMLLAYERELEMENT_NAME, 
    NS_DOM_PROP_HTMLLAYERELEMENT_TOP, 
    NS_DOM_PROP_HTMLLAYERELEMENT_VISIBILITY, 
    NS_DOM_PROP_HTMLLAYERELEMENT_ZINDEX, 
    NS_DOM_PROP_HTMLLEGENDELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLLEGENDELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLLEGENDELEMENT_FORM, 
    NS_DOM_PROP_HTMLLIELEMENT_TYPE, 
    NS_DOM_PROP_HTMLLIELEMENT_VALUE, 
    NS_DOM_PROP_HTMLLINKELEMENT_CHARSET, 
    NS_DOM_PROP_HTMLLINKELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLLINKELEMENT_HREF, 
    NS_DOM_PROP_HTMLLINKELEMENT_HREFLANG, 
    NS_DOM_PROP_HTMLLINKELEMENT_MEDIA, 
    NS_DOM_PROP_HTMLLINKELEMENT_REL, 
    NS_DOM_PROP_HTMLLINKELEMENT_REV, 
    NS_DOM_PROP_HTMLLINKELEMENT_TARGET, 
    NS_DOM_PROP_HTMLLINKELEMENT_TYPE, 
    NS_DOM_PROP_HTMLMAPELEMENT_AREAS, 
    NS_DOM_PROP_HTMLMAPELEMENT_NAME, 
    NS_DOM_PROP_HTMLMENUELEMENT_COMPACT, 
    NS_DOM_PROP_HTMLMETAELEMENT_CONTENT, 
    NS_DOM_PROP_HTMLMETAELEMENT_HTTPEQUIV, 
    NS_DOM_PROP_HTMLMETAELEMENT_NAME, 
    NS_DOM_PROP_HTMLMETAELEMENT_SCHEME, 
    NS_DOM_PROP_HTMLMODELEMENT_CITE, 
    NS_DOM_PROP_HTMLMODELEMENT_DATETIME, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_ARCHIVE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_BORDER, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_CODE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_CODEBASE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_CODETYPE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_DATA, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_DECLARE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_FORM, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_HSPACE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_NAME, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_STANDBY, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_TYPE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_USEMAP, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_VSPACE, 
    NS_DOM_PROP_HTMLOBJECTELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLOLISTELEMENT_COMPACT, 
    NS_DOM_PROP_HTMLOLISTELEMENT_START, 
    NS_DOM_PROP_HTMLOLISTELEMENT_TYPE, 
    NS_DOM_PROP_HTMLOPTGROUPELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLOPTGROUPELEMENT_LABEL, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_DEFAULTSELECTED, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_FORM, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_INDEX, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_LABEL, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_SELECTED, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_TEXT, 
    NS_DOM_PROP_HTMLOPTIONELEMENT_VALUE, 
    NS_DOM_PROP_HTMLPARAGRAPHELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLPARAMELEMENT_NAME, 
    NS_DOM_PROP_HTMLPARAMELEMENT_TYPE, 
    NS_DOM_PROP_HTMLPARAMELEMENT_VALUE, 
    NS_DOM_PROP_HTMLPARAMELEMENT_VALUETYPE, 
    NS_DOM_PROP_HTMLPREELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLQUOTEELEMENT_CITE, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_CHARSET, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_DEFER, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_EVENT, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_HTMLFOR, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_SRC, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_TEXT, 
    NS_DOM_PROP_HTMLSCRIPTELEMENT_TYPE, 
    NS_DOM_PROP_HTMLSELECTELEMENT_ADD, 
    NS_DOM_PROP_HTMLSELECTELEMENT_BLUR, 
    NS_DOM_PROP_HTMLSELECTELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLSELECTELEMENT_FOCUS, 
    NS_DOM_PROP_HTMLSELECTELEMENT_FORM, 
    NS_DOM_PROP_HTMLSELECTELEMENT_LENGTH, 
    NS_DOM_PROP_HTMLSELECTELEMENT_MULTIPLE, 
    NS_DOM_PROP_HTMLSELECTELEMENT_NAME, 
    NS_DOM_PROP_HTMLSELECTELEMENT_OPTIONS, 
    NS_DOM_PROP_HTMLSELECTELEMENT_REMOVE, 
    NS_DOM_PROP_HTMLSELECTELEMENT_SELECTEDINDEX, 
    NS_DOM_PROP_HTMLSELECTELEMENT_SIZE, 
    NS_DOM_PROP_HTMLSELECTELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLSELECTELEMENT_TYPE, 
    NS_DOM_PROP_HTMLSELECTELEMENT_VALUE, 
    NS_DOM_PROP_HTMLSTYLEELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLSTYLEELEMENT_MEDIA, 
    NS_DOM_PROP_HTMLSTYLEELEMENT_TYPE, 
    NS_DOM_PROP_HTMLTABLECAPTIONELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_ABBR, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_AXIS, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_BGCOLOR, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_CELLINDEX, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_CH, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_CHOFF, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_COLSPAN, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_HEADERS, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_HEIGHT, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_NOWRAP, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_ROWSPAN, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_SCOPE, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_VALIGN, 
    NS_DOM_PROP_HTMLTABLECELLELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_CH, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_CHOFF, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_SPAN, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_VALIGN, 
    NS_DOM_PROP_HTMLTABLECOLELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLTABLEELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLEELEMENT_BGCOLOR, 
    NS_DOM_PROP_HTMLTABLEELEMENT_BORDER, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CAPTION, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CELLPADDING, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CELLSPACING, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CREATECAPTION, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CREATETFOOT, 
    NS_DOM_PROP_HTMLTABLEELEMENT_CREATETHEAD, 
    NS_DOM_PROP_HTMLTABLEELEMENT_DELETECAPTION, 
    NS_DOM_PROP_HTMLTABLEELEMENT_DELETEROW, 
    NS_DOM_PROP_HTMLTABLEELEMENT_DELETETFOOT, 
    NS_DOM_PROP_HTMLTABLEELEMENT_DELETETHEAD, 
    NS_DOM_PROP_HTMLTABLEELEMENT_FRAME, 
    NS_DOM_PROP_HTMLTABLEELEMENT_INSERTROW, 
    NS_DOM_PROP_HTMLTABLEELEMENT_ROWS, 
    NS_DOM_PROP_HTMLTABLEELEMENT_RULES, 
    NS_DOM_PROP_HTMLTABLEELEMENT_SUMMARY, 
    NS_DOM_PROP_HTMLTABLEELEMENT_TBODIES, 
    NS_DOM_PROP_HTMLTABLEELEMENT_TFOOT, 
    NS_DOM_PROP_HTMLTABLEELEMENT_THEAD, 
    NS_DOM_PROP_HTMLTABLEELEMENT_WIDTH, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_BGCOLOR, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_CELLS, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_CH, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_CHOFF, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_DELETECELL, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_INSERTCELL, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_ROWINDEX, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_SECTIONROWINDEX, 
    NS_DOM_PROP_HTMLTABLEROWELEMENT_VALIGN, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_ALIGN, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_CH, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_CHOFF, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_DELETEROW, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_INSERTROW, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_ROWS, 
    NS_DOM_PROP_HTMLTABLESECTIONELEMENT_VALIGN, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_ACCESSKEY, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_BLUR, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_COLS, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_CONTROLLERS,
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_DEFAULTVALUE, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_DISABLED, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_FOCUS, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_FORM, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_NAME, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_READONLY, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_ROWS, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_SELECT, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_TABINDEX, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_TYPE, 
    NS_DOM_PROP_HTMLTEXTAREAELEMENT_VALUE, 
    NS_DOM_PROP_HTMLTITLEELEMENT_TEXT, 
    NS_DOM_PROP_HTMLULISTELEMENT_COMPACT, 
    NS_DOM_PROP_HTMLULISTELEMENT_TYPE, 
    NS_DOM_PROP_KEYEVENT_ALTKEY, 
    NS_DOM_PROP_KEYEVENT_CHARCODE, 
    NS_DOM_PROP_KEYEVENT_CTRLKEY, 
    NS_DOM_PROP_KEYEVENT_INITKEYEVENT, 
    NS_DOM_PROP_KEYEVENT_KEYCODE, 
    NS_DOM_PROP_KEYEVENT_METAKEY, 
    NS_DOM_PROP_KEYEVENT_SHIFTKEY, 
    NS_DOM_PROP_LOCATION_HASH, 
    NS_DOM_PROP_LOCATION_HOST, 
    NS_DOM_PROP_LOCATION_HOSTNAME, 
    NS_DOM_PROP_LOCATION_PATHNAME, 
    NS_DOM_PROP_LOCATION_PORT, 
    NS_DOM_PROP_LOCATION_PROTOCOL, 
    NS_DOM_PROP_LOCATION_SEARCH, 
    NS_DOM_PROP_LOCATION_TOSTRING, 
    NS_DOM_PROP_MIMETYPE_DESCRIPTION, 
    NS_DOM_PROP_MIMETYPE_ENABLEDPLUGIN, 
    NS_DOM_PROP_MIMETYPE_SUFFIXES, 
    NS_DOM_PROP_MIMETYPE_TYPE, 
    NS_DOM_PROP_MIMETYPEARRAY_ITEM, 
    NS_DOM_PROP_MIMETYPEARRAY_LENGTH, 
    NS_DOM_PROP_MIMETYPEARRAY_NAMEDITEM, 
    NS_DOM_PROP_MOUSEEVENT_BUTTON, 
    NS_DOM_PROP_MOUSEEVENT_CLICKCOUNT, 
    NS_DOM_PROP_MOUSEEVENT_CLIENTX, 
    NS_DOM_PROP_MOUSEEVENT_CLIENTY, 
    NS_DOM_PROP_MOUSEEVENT_INITMOUSEEVENT, 
    NS_DOM_PROP_MOUSEEVENT_RELATEDNODE, 
    NS_DOM_PROP_MOUSEEVENT_SCREENX, 
    NS_DOM_PROP_MOUSEEVENT_SCREENY, 
    NS_DOM_PROP_NAMEDNODEMAP_GETNAMEDITEM, 
    NS_DOM_PROP_NAMEDNODEMAP_ITEM, 
    NS_DOM_PROP_NAMEDNODEMAP_LENGTH, 
    NS_DOM_PROP_NAMEDNODEMAP_REMOVENAMEDITEM, 
    NS_DOM_PROP_NAMEDNODEMAP_SETNAMEDITEM, 
    NS_DOM_PROP_NAVIGATOR_APPCODENAME, 
    NS_DOM_PROP_NAVIGATOR_APPNAME, 
    NS_DOM_PROP_NAVIGATOR_APPVERSION, 
    NS_DOM_PROP_NAVIGATOR_JAVAENABLED, 
    NS_DOM_PROP_NAVIGATOR_LANGUAGE, 
    NS_DOM_PROP_NAVIGATOR_MIMETYPES, 
    NS_DOM_PROP_NAVIGATOR_PLATFORM, 
    NS_DOM_PROP_NAVIGATOR_PLUGINS, 
    NS_DOM_PROP_NAVIGATOR_PREFERENCE, 
    NS_DOM_PROP_NAVIGATOR_SECURITYPOLICY, 
    NS_DOM_PROP_NAVIGATOR_TAINTENABLED, 
    NS_DOM_PROP_NAVIGATOR_USERAGENT, 
    NS_DOM_PROP_NODE_APPENDCHILD, 
    NS_DOM_PROP_NODE_ATTRIBUTES, 
    NS_DOM_PROP_NODE_CHILDNODES, 
    NS_DOM_PROP_NODE_CLONENODE, 
    NS_DOM_PROP_NODE_FIRSTCHILD, 
    NS_DOM_PROP_NODE_HASCHILDNODES, 
    NS_DOM_PROP_NODE_INSERTBEFORE, 
    NS_DOM_PROP_NODE_LASTCHILD, 
    NS_DOM_PROP_NODE_NEXTSIBLING, 
    NS_DOM_PROP_NODE_NODENAME, 
    NS_DOM_PROP_NODE_NODETYPE, 
    NS_DOM_PROP_NODE_NODEVALUE, 
    NS_DOM_PROP_NODE_OWNERDOCUMENT, 
    NS_DOM_PROP_NODE_PARENTNODE, 
    NS_DOM_PROP_NODE_PREVIOUSSIBLING, 
    NS_DOM_PROP_NODE_REMOVECHILD, 
    NS_DOM_PROP_NODE_REPLACECHILD, 
    NS_DOM_PROP_NODELIST_ITEM, 
    NS_DOM_PROP_NODELIST_LENGTH, 
    NS_DOM_PROP_NOTATION_PUBLICID, 
    NS_DOM_PROP_NOTATION_SYSTEMID, 
    NS_DOM_PROP_NSDOCUMENT_CREATEELEMENTWITHNAMESPACE, 
    NS_DOM_PROP_NSDOCUMENT_CREATERANGE, 
    NS_DOM_PROP_NSDOCUMENT_HEIGHT, 
    NS_DOM_PROP_NSDOCUMENT_STYLESHEETS, 
    NS_DOM_PROP_NSDOCUMENT_WIDTH, 
    NS_DOM_PROP_NSHTMLBUTTONELEMENT_BLUR, 
    NS_DOM_PROP_NSHTMLBUTTONELEMENT_FOCUS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_ALINKCOLOR, 
    NS_DOM_PROP_NSHTMLDOCUMENT_BGCOLOR, 
    NS_DOM_PROP_NSHTMLDOCUMENT_CAPTUREEVENTS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_EMBEDS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_FGCOLOR, 
    NS_DOM_PROP_NSHTMLDOCUMENT_GETSELECTION, 
    NS_DOM_PROP_NSHTMLDOCUMENT_LASTMODIFIED, 
    NS_DOM_PROP_NSHTMLDOCUMENT_LAYERS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_LINKCOLOR, 
    NS_DOM_PROP_NSHTMLDOCUMENT_NAMEDITEM, 
    NS_DOM_PROP_NSHTMLDOCUMENT_OPEN, 
    NS_DOM_PROP_NSHTMLDOCUMENT_PLUGINS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_RELEASEEVENTS, 
    NS_DOM_PROP_NSHTMLDOCUMENT_ROUTEEVENT, 
    NS_DOM_PROP_NSHTMLDOCUMENT_VLINKCOLOR, 
    NS_DOM_PROP_NSHTMLDOCUMENT_WRITE, 
    NS_DOM_PROP_NSHTMLDOCUMENT_WRITELN, 
    NS_DOM_PROP_NSHTMLFORMELEMENT_ENCODING, 
    NS_DOM_PROP_NSHTMLFORMELEMENT_ITEM, 
    NS_DOM_PROP_NSHTMLFORMELEMENT_NAMEDITEM, 
    NS_DOM_PROP_NSHTMLINPUTELEMENT_CONTROLLERS,
    NS_DOM_PROP_NSHTMLSELECTELEMENT_ITEM, 
    NS_DOM_PROP_NSHTMLTEXTAREAELEMENT_CONTROLLERS,
    NS_DOM_PROP_NSLOCATION_RELOAD, 
    NS_DOM_PROP_NSLOCATION_REPLACE, 
    NS_DOM_PROP_NSRANGE_CREATECONTEXTUALFRAGMENT, 
    NS_DOM_PROP_NSRANGE_ISVALIDFRAGMENT, 
    NS_DOM_PROP_NSUIEVENT_CANCELBUBBLE, 
    NS_DOM_PROP_NSUIEVENT_ISCHAR, 
    NS_DOM_PROP_NSUIEVENT_LAYERX, 
    NS_DOM_PROP_NSUIEVENT_LAYERY, 
    NS_DOM_PROP_NSUIEVENT_PAGEX, 
    NS_DOM_PROP_NSUIEVENT_PAGEY, 
    NS_DOM_PROP_NSUIEVENT_RANGEOFFSET, 
    NS_DOM_PROP_NSUIEVENT_RANGEPARENT, 
    NS_DOM_PROP_NSUIEVENT_WHICH, 
    NS_DOM_PROP_PLUGIN_DESCRIPTION, 
    NS_DOM_PROP_PLUGIN_FILENAME, 
    NS_DOM_PROP_PLUGIN_ITEM, 
    NS_DOM_PROP_PLUGIN_LENGTH, 
    NS_DOM_PROP_PLUGIN_NAME, 
    NS_DOM_PROP_PLUGIN_NAMEDITEM, 
    NS_DOM_PROP_PLUGINARRAY_ITEM, 
    NS_DOM_PROP_PLUGINARRAY_LENGTH, 
    NS_DOM_PROP_PLUGINARRAY_NAMEDITEM, 
    NS_DOM_PROP_PLUGINARRAY_REFRESH, 
    NS_DOM_PROP_PROCESSINGINSTRUCTION_DATA, 
    NS_DOM_PROP_PROCESSINGINSTRUCTION_TARGET, 
    NS_DOM_PROP_RANGE_CLONE, 
    NS_DOM_PROP_RANGE_CLONECONTENTS, 
    NS_DOM_PROP_RANGE_COLLAPSE, 
    NS_DOM_PROP_RANGE_COMMONPARENT, 
    NS_DOM_PROP_RANGE_COMPAREENDPOINTS, 
    NS_DOM_PROP_RANGE_DELETECONTENTS, 
    NS_DOM_PROP_RANGE_ENDOFFSET, 
    NS_DOM_PROP_RANGE_ENDPARENT, 
    NS_DOM_PROP_RANGE_EXTRACTCONTENTS, 
    NS_DOM_PROP_RANGE_INSERTNODE, 
    NS_DOM_PROP_RANGE_ISCOLLAPSED, 
    NS_DOM_PROP_RANGE_SELECTNODE, 
    NS_DOM_PROP_RANGE_SELECTNODECONTENTS, 
    NS_DOM_PROP_RANGE_SETEND, 
    NS_DOM_PROP_RANGE_SETENDAFTER, 
    NS_DOM_PROP_RANGE_SETENDBEFORE, 
    NS_DOM_PROP_RANGE_SETSTART, 
    NS_DOM_PROP_RANGE_SETSTARTAFTER, 
    NS_DOM_PROP_RANGE_SETSTARTBEFORE, 
    NS_DOM_PROP_RANGE_STARTOFFSET, 
    NS_DOM_PROP_RANGE_STARTPARENT, 
    NS_DOM_PROP_RANGE_SURROUNDCONTENTS, 
    NS_DOM_PROP_RANGE_TOSTRING, 
    NS_DOM_PROP_SCREEN_AVAILHEIGHT, 
    NS_DOM_PROP_SCREEN_AVAILLEFT, 
    NS_DOM_PROP_SCREEN_AVAILTOP, 
    NS_DOM_PROP_SCREEN_AVAILWIDTH, 
    NS_DOM_PROP_SCREEN_COLORDEPTH, 
    NS_DOM_PROP_SCREEN_HEIGHT, 
    NS_DOM_PROP_SCREEN_PIXELDEPTH, 
    NS_DOM_PROP_SCREEN_WIDTH, 
    NS_DOM_PROP_SELECTION_ADDRANGE, 
    NS_DOM_PROP_SELECTION_ADDSELECTIONLISTENER, 
    NS_DOM_PROP_SELECTION_ANCHORNODE, 
    NS_DOM_PROP_SELECTION_ANCHOROFFSET, 
    NS_DOM_PROP_SELECTION_CLEARSELECTION, 
    NS_DOM_PROP_SELECTION_COLLAPSE, 
    NS_DOM_PROP_SELECTION_COLLAPSETOEND, 
    NS_DOM_PROP_SELECTION_COLLAPSETOSTART, 
    NS_DOM_PROP_SELECTION_CONTAINSNODE, 
    NS_DOM_PROP_SELECTION_DELETEFROMDOCUMENT, 
    NS_DOM_PROP_SELECTION_ENDBATCHCHANGES, 
    NS_DOM_PROP_SELECTION_EXTEND, 
    NS_DOM_PROP_SELECTION_FOCUSNODE, 
    NS_DOM_PROP_SELECTION_FOCUSOFFSET, 
    NS_DOM_PROP_SELECTION_GETRANGEAT, 
    NS_DOM_PROP_SELECTION_ISCOLLAPSED, 
    NS_DOM_PROP_SELECTION_RANGECOUNT, 
    NS_DOM_PROP_SELECTION_REMOVESELECTIONLISTENER, 
    NS_DOM_PROP_SELECTION_STARTBATCHCHANGES, 
    NS_DOM_PROP_SELECTION_TOSTRING, 
    NS_DOM_PROP_SELECTIONLISTENER_NOTIFYSELECTIONCHANGED, 
    NS_DOM_PROP_STYLESHEET_DISABLED, 
    NS_DOM_PROP_STYLESHEET_READONLY, 
    NS_DOM_PROP_STYLESHEET_TYPE, 
    NS_DOM_PROP_STYLESHEETCOLLECTION_ITEM, 
    NS_DOM_PROP_STYLESHEETCOLLECTION_LENGTH, 
    NS_DOM_PROP_TEXT_SPLITTEXT, 
    NS_DOM_PROP_TEXTRANGE_RANGEEND, 
    NS_DOM_PROP_TEXTRANGE_RANGESTART, 
    NS_DOM_PROP_TEXTRANGE_RANGETYPE, 
    NS_DOM_PROP_TEXTRANGELIST_ITEM, 
    NS_DOM_PROP_TEXTRANGELIST_LENGTH, 
    NS_DOM_PROP_TOOLKITCORE_CLOSEWINDOW,
    NS_DOM_PROP_TOOLKITCORE_SHOWDIALOG,
    NS_DOM_PROP_TOOLKITCORE_SHOWMODALDIALOG,
    NS_DOM_PROP_TOOLKITCORE_SHOWWINDOW,
    NS_DOM_PROP_TOOLKITCORE_SHOWWINDOWWITHARGS,
    NS_DOM_PROP_UIEVENT_DETAIL, 
    NS_DOM_PROP_UIEVENT_INITUIEVENT, 
    NS_DOM_PROP_UIEVENT_VIEW, 
    NS_DOM_PROP_WINDOW_ALERT, 
    NS_DOM_PROP_WINDOW_BACK, 
    NS_DOM_PROP_WINDOW_BLUR, 
    NS_DOM_PROP_WINDOW_CAPTUREEVENTS, 
    NS_DOM_PROP_WINDOW_CLEARINTERVAL, 
    NS_DOM_PROP_WINDOW_CLEARTIMEOUT, 
    NS_DOM_PROP_WINDOW_CLOSE, 
    NS_DOM_PROP_WINDOW_CLOSED, 
    NS_DOM_PROP_WINDOW_CONFIRM, 
    NS_DOM_PROP_WINDOW_CONTENT, 
    NS_DOM_PROP_WINDOW_CONTROLLERS, 
    NS_DOM_PROP_WINDOW_CREATEPOPUP, 
    NS_DOM_PROP_WINDOW_DEFAULTSTATUS, 
    NS_DOM_PROP_WINDOW_DIRECTORIES, 
    NS_DOM_PROP_WINDOW_DISABLEEXTERNALCAPTURE, 
    NS_DOM_PROP_WINDOW_DOCUMENT, 
    NS_DOM_PROP_WINDOW_DUMP, 
    NS_DOM_PROP_WINDOW_ENABLEEXTERNALCAPTURE, 
    NS_DOM_PROP_WINDOW_FOCUS, 
    NS_DOM_PROP_WINDOW_FORWARD, 
    NS_DOM_PROP_WINDOW_FRAMES, 
    NS_DOM_PROP_WINDOW_HISTORY, 
    NS_DOM_PROP_WINDOW_HOME, 
    NS_DOM_PROP_WINDOW_INNERHEIGHT, 
    NS_DOM_PROP_WINDOW_INNERWIDTH, 
    NS_DOM_PROP_WINDOW_LOCATIONBAR, 
    NS_DOM_PROP_WINDOW_MENUBAR, 
    NS_DOM_PROP_WINDOW_MOVEBY, 
    NS_DOM_PROP_WINDOW_MOVETO, 
    NS_DOM_PROP_WINDOW_NAME, 
    NS_DOM_PROP_WINDOW_NAVIGATOR, 
    NS_DOM_PROP_WINDOW_OPEN, 
    NS_DOM_PROP_WINDOW_OPENDIALOG, 
    NS_DOM_PROP_WINDOW_OPENER, 
    NS_DOM_PROP_WINDOW_OUTERHEIGHT, 
    NS_DOM_PROP_WINDOW_OUTERWIDTH, 
    NS_DOM_PROP_WINDOW_PAGEXOFFSET, 
    NS_DOM_PROP_WINDOW_PAGEYOFFSET, 
    NS_DOM_PROP_WINDOW_PARENT, 
    NS_DOM_PROP_WINDOW_PERSONALBAR, 
    NS_DOM_PROP_WINDOW_PRINT, 
    NS_DOM_PROP_WINDOW_PROMPT, 
    NS_DOM_PROP_WINDOW_RELEASEEVENTS, 
    NS_DOM_PROP_WINDOW_RESIZEBY, 
    NS_DOM_PROP_WINDOW_RESIZETO, 
    NS_DOM_PROP_WINDOW_ROUTEEVENT, 
    NS_DOM_PROP_WINDOW_SCREEN, 
    NS_DOM_PROP_WINDOW_SCREENX, 
    NS_DOM_PROP_WINDOW_SCREENY, 
    NS_DOM_PROP_WINDOW_SCROLL,
    NS_DOM_PROP_WINDOW_SCROLLBARS, 
    NS_DOM_PROP_WINDOW_SCROLLBY, 
    NS_DOM_PROP_WINDOW_SCROLLTO, 
    NS_DOM_PROP_WINDOW_SCROLLX, 
    NS_DOM_PROP_WINDOW_SCROLLY, 
    NS_DOM_PROP_WINDOW_SELF, 
    NS_DOM_PROP_WINDOW_SETINTERVAL, 
    NS_DOM_PROP_WINDOW_SETTIMEOUT, 
    NS_DOM_PROP_WINDOW_SIZETOCONTENT, 
    NS_DOM_PROP_WINDOW_STATUS, 
    NS_DOM_PROP_WINDOW_STATUSBAR, 
    NS_DOM_PROP_WINDOW_STOP, 
    NS_DOM_PROP_WINDOW_TOOLBAR, 
    NS_DOM_PROP_WINDOW_TOP, 
    NS_DOM_PROP_WINDOW_WINDOW, 
    NS_DOM_PROP_WINDOWCOLLECTION_ITEM, 
    NS_DOM_PROP_WINDOWCOLLECTION_LENGTH, 
    NS_DOM_PROP_WINDOWCOLLECTION_NAMEDITEM, 
    NS_DOM_PROP_XULCOMMANDDISPATCHER_ADDCOMMANDUPDATER,
    NS_DOM_PROP_XULCOMMANDDISPATCHER_FOCUSEDNODE,
    NS_DOM_PROP_XULCOMMANDDISPATCHER_GETCONTROLLERFORCOMMAND,
    NS_DOM_PROP_XULCOMMANDDISPATCHER_GETCONTROLLERS,
    NS_DOM_PROP_XULCOMMANDDISPATCHER_REMOVECOMMANDUPDATER,
    NS_DOM_PROP_XULCOMMANDDISPATCHER_UPDATECOMMANDS,
    NS_DOM_PROP_XULDOCUMENT_COMMANDDISPATCHER,
    NS_DOM_PROP_XULDOCUMENT_GETELEMENTBYID,
    NS_DOM_PROP_XULDOCUMENT_GETELEMENTSBYATTRIBUTE,
    NS_DOM_PROP_XULDOCUMENT_PERSIST,
    NS_DOM_PROP_XULDOCUMENT_POPUPNODE,
    NS_DOM_PROP_XULDOCUMENT_TOOLTIPNODE,
    NS_DOM_PROP_XULEDITORELEMENT_EDITORSHELL,
    NS_DOM_PROP_XULELEMENT_ADDBROADCASTLISTENER,
    NS_DOM_PROP_XULELEMENT_CLASSNAME,
    NS_DOM_PROP_XULELEMENT_CONTROLLERS,
    NS_DOM_PROP_XULELEMENT_DATABASE,
    NS_DOM_PROP_XULELEMENT_DOCOMMAND,
    NS_DOM_PROP_XULELEMENT_GETELEMENTSBYATTRIBUTE,
    NS_DOM_PROP_XULELEMENT_ID,
    NS_DOM_PROP_XULELEMENT_REMOVEBROADCASTLISTENER,
    NS_DOM_PROP_XULELEMENT_RESOURCE,
    NS_DOM_PROP_XULELEMENT_STYLE,
    NS_DOM_PROP_XULTREEELEMENT_ADDCELLTOSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_ADDITEMTOSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_CLEARCELLSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_CLEARITEMSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_INVERTSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_REMOVECELLFROMSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_REMOVEITEMFROMSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_SELECTALL,
    NS_DOM_PROP_XULTREEELEMENT_SELECTCELL,
    NS_DOM_PROP_XULTREEELEMENT_SELECTCELLRANGE,
    NS_DOM_PROP_XULTREEELEMENT_SELECTEDCELLS,
    NS_DOM_PROP_XULTREEELEMENT_SELECTEDITEMS,
    NS_DOM_PROP_XULTREEELEMENT_SELECTITEM,
    NS_DOM_PROP_XULTREEELEMENT_SELECTITEMRANGE,
    NS_DOM_PROP_XULTREEELEMENT_TOGGLECELLSELECTION,
    NS_DOM_PROP_XULTREEELEMENT_TOGGLEITEMSELECTION,
    NS_DOM_PROP_MAX
};

#endif // nsDOMPropEnums_h__
