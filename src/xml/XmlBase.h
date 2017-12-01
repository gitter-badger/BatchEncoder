﻿// Copyright (c) Wiesław Šoltés. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#include <afxstr.h>
#include <afxtempl.h>
#include "tinyxml2\tinyxml2.h" // https://github.com/leethomason/tinyxml2
#include "utilities\UnicodeUtf8.h"
#include "utilities\Utf8String.h"

class XmlBase : protected tinyxml2::XMLDocument
{
public:
    const char *m_Utf8DocumentDeclaration = "xml version=\"1.0\" encoding=\"UTF-8\"";
public:
    XmlBase()
    {
    }
    virtual ~XmlBase()
    {
    }
private:
    const LPCTSTR m_True = _T("true");
    const LPCTSTR m_False = _T("false");
protected:
#ifdef _UNICODE
    CString ToCString(const char *pszUtf8)
    {
        if (pszUtf8 == NULL)
            return _T("");
        if (strlen(pszUtf8) == 0)
            return _T("");
        wchar_t *pszUnicode = MakeUnicodeString((unsigned char *)pszUtf8);
        CString szBuff = pszUnicode;
        free(pszUnicode);
        return szBuff;
    }
#else
    CString ToCString(const char *pszUtf8)
    {
        if (pszUtf8 == NULL)
            return _T("");
        if (strlen(pszUtf8) == 0)
            return _T("");
        char *pszAnsi;
        Utf8Decode(pszUtf8, &pszAnsi);
        CString szBuff = pszAnsi;
        free(pszAnsi);
        return szBuff;
    }
#endif
    bool ToBool(const char *pszUtf8)
    {
        return ToCString(pszUtf8).CompareNoCase(m_True) == 0;
    }
    int ToInt(const char *pszUtf8)
    {
        return _tstoi(ToCString(pszUtf8));
    }
    CString ToCString(const int nValue)
    {
        CString rValue;
        rValue.Format(_T("%d\0"), nValue);
        return rValue;
    }
    CString ToCString(const bool bValue)
    {
        CString rValue;
        rValue.Format(_T("%s\0"), bValue ? m_True : m_False);
        return rValue;
    }
public:
    bool Open(CString szFileName);
    bool Save(CString szFileName);
};