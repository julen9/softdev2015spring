
// GameOfLifeView.cpp : implementation of the CGameOfLifeView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GameOfLife.h"
#endif

#include "GameOfLifeDoc.h"
#include "GameOfLifeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGameOfLifeView

IMPLEMENT_DYNCREATE(CGameOfLifeView, CFormView)

BEGIN_MESSAGE_MAP(CGameOfLifeView, CFormView)
END_MESSAGE_MAP()

// CGameOfLifeView construction/destruction

CGameOfLifeView::CGameOfLifeView()
	: CFormView(CGameOfLifeView::IDD)
{
	// TODO: add construction code here

}

CGameOfLifeView::~CGameOfLifeView()
{
}

void CGameOfLifeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CGameOfLifeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CGameOfLifeView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CGameOfLifeView diagnostics

#ifdef _DEBUG
void CGameOfLifeView::AssertValid() const
{
	CFormView::AssertValid();
}

void CGameOfLifeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CGameOfLifeDoc* CGameOfLifeView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGameOfLifeDoc)));
	return (CGameOfLifeDoc*)m_pDocument;
}
#endif //_DEBUG


// CGameOfLifeView message handlers
