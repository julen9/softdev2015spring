
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
	ON_BN_CLICKED(IDC_BUTTON1, &CGameOfLifeView::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &CGameOfLifeView::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CGameOfLifeView::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON2, &CGameOfLifeView::OnBnClickedButton2)
END_MESSAGE_MAP()

// CGameOfLifeView construction/destruction

CGameOfLifeView::CGameOfLifeView()
	: CFormView(CGameOfLifeView::IDD)
	, rownum(0)
	, colnum(0)
{
	// TODO: add construction code here

}

CGameOfLifeView::~CGameOfLifeView()
{
}

void CGameOfLifeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, rownum);
	DDV_MinMaxInt(pDX, rownum, 0, 20);
	DDX_Text(pDX, IDC_EDIT2, colnum);
	DDV_MinMaxInt(pDX, colnum, 0, 20);
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


void CGameOfLifeView::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
}
#define RECT_WIDTH 15
#define RECT_HEIGHT 15
void CGameOfLifeView::OnDraw(CDC* pDC){
	CGameOfLifeDoc *doc = GetDocument();

	CBrush livingBrush(RGB(255, 0, 255));
	CBrush deadBrush(RGB(255, 255, 0));
	CBrush* oldBrush;

	for (int i = 0; i < doc->getTable().getSize().cx; i++){
		for (int j = 0; j < doc->getTable().getSize().cy; j++){

			if (doc->getTable().at(i, j).is(Cell::State::LIVING)){
				oldBrush = pDC->SelectObject(&livingBrush);	
			} else {
				oldBrush = pDC->SelectObject(&deadBrush);
			}

			pDC->Rectangle(i * RECT_WIDTH, j*RECT_HEIGHT, i * RECT_WIDTH + RECT_WIDTH, j * RECT_HEIGHT + RECT_HEIGHT);
			pDC->SelectObject(oldBrush);

		}
	}

}

void CGameOfLifeView::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if (UpdateData()) {
		CGameOfLifeDoc *doc = GetDocument();
		CSize size(colnum, rownum);
		doc->CreateNewTable(size);
		InvalidateRect(NULL, TRUE);
		UpdateWindow();
	}
}


void CGameOfLifeView::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	if (UpdateData()) {
		CGameOfLifeDoc *doc = GetDocument();
		CSize size(colnum, rownum);
		doc->CreateNewTable(size);
		InvalidateRect(NULL, TRUE);
		UpdateWindow();
	}
}


void CGameOfLifeView::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here

}
