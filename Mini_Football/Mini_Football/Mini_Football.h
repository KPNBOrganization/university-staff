
// Mini_Football.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMiniFootballApp:
// See Mini_Football.cpp for the implementation of this class
//

class CMiniFootballApp : public CWinApp
{
public:
	CMiniFootballApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMiniFootballApp theApp;
