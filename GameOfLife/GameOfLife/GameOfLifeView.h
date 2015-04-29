
// GameOfLifeView.h : interface of the CGameOfLifeView class
//

#pragma once

#include "resource.h"


class CGameOfLifeView : public CFormView
{
protected: // create from serialization only
	CGameOfLifeView();
	DECLARE_DYNCREATE(CGameOfLifeView)

public:
	enum{ IDD = IDD_GAMEOFLIFE_FORM };

// Attributes
public:
	CGameOfLifeDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual void OnDraw(CDC* pDC);

// Implementation
public:
	virtual ~CGameOfLifeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	int rownum;
	int colnum;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // debug version in GameOfLifeView.cpp
inline CGameOfLifeDoc* CGameOfLifeView::GetDocument() const
   { return reinterpret_cast<CGameOfLifeDoc*>(m_pDocument); }
#endif

