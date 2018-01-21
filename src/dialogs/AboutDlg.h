﻿// Copyright (c) Wiesław Šoltés. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full license information.

#pragma once

#include <afxcmn.h>
#include <afxwin.h>
#include "configuration\Configuration.h"
#include "controls\MyHyperlink.h"
#include "controls\MyButton.h"
#include "controls\MyStatic.h"
#include "controls\MyDialogEx.h"

class CAboutDlg : public CMyDialogEx
{
    DECLARE_DYNAMIC(CAboutDlg)
public:
    CAboutDlg(CWnd* pParent = nullptr);
    virtual ~CAboutDlg();
    enum { IDD = IDD_DIALOG_ABOUT };
protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
protected:
    virtual void OnOK();
    virtual void OnCancel();
public:
    config::CConfiguration *pConfig;
public:
    CMyButton m_BtnOK;
    CMyStatic m_StcMainAppName;
    CMyHyperlink m_StcWebsite;
    CMyHyperlink m_StcEmail;
    CMyStatic m_StcLicense;
public:
    afx_msg void OnClose();
    afx_msg void OnBnClickedOk();
public:
    void SetLanguage();
};
