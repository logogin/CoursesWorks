// Single.h : main header file for the Single application
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CSingleApp:
// See Single.cpp for the implementation of this class
//

class CSingleApp : public CWinApp
{
public:
	CSingleApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSingleApp theApp;