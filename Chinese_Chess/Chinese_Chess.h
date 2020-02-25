
// Chinese_Chess.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CChineseChessApp:
// See Chinese_Chess.cpp for the implementation of this class
//

class CChineseChessApp : public CWinApp
{
public:
	CChineseChessApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CChineseChessApp theApp;
