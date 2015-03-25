
// GameOfLife.h : main header file for the GameOfLife application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CGameOfLifeApp:
// See GameOfLife.cpp for the implementation of this class
//

class CGameOfLifeApp : public CWinApp
{
public:
	CGameOfLifeApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CGameOfLifeApp theApp;
