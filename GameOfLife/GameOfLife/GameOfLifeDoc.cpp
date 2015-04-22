
// GameOfLifeDoc.cpp : implementation of the CGameOfLifeDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "GameOfLife.h"
#endif

#include "GameOfLifeDoc.h"

#include <propkey.h>
#include <cstdlib>
#include <iostream>
#include <ctime>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CGameOfLifeDoc

IMPLEMENT_DYNCREATE(CGameOfLifeDoc, CDocument)

BEGIN_MESSAGE_MAP(CGameOfLifeDoc, CDocument)
END_MESSAGE_MAP()


// CGameOfLifeDoc construction/destruction

CGameOfLifeDoc::CGameOfLifeDoc() : table(DEFSIZE)
{
	// TODO: add one-time construction code here

}

const CSize CGameOfLifeDoc::DEFSIZE = CSize(15,15);

CGameOfLifeDoc::~CGameOfLifeDoc()
{
}

BOOL CGameOfLifeDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	std::srand(std::time(0)); // use current time as seed for random generator
	// TODO: set size
	for (int i = 0; i < table.getSize().cx; i++){
		for (int j = 0; j < table.getSize().cy; j++){

			int random_variable = std::rand();
			if (random_variable % 100 < 20){
				table.at(i, j).setState(Cell::State::DEAD);
			} else{
				table.at(i, j).setState(Cell::State::LIVING);
			}

		}
	}

	return TRUE;
}




// CGameOfLifeDoc serialization

void CGameOfLifeDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		table.Serialize(ar);
		// TODO: add storing code here
	}
	else
	{
		table.Serialize(ar);
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CGameOfLifeDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CGameOfLifeDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data. 
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CGameOfLifeDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CGameOfLifeDoc diagnostics

#ifdef _DEBUG
void CGameOfLifeDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGameOfLifeDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

Table& CGameOfLifeDoc::getTable(){
	return table;
}
// CGameOfLifeDoc commands
