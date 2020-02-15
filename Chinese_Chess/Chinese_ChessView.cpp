
// Chinese_ChessView.cpp : implementation of the CChineseChessView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Chinese_Chess.h"
#endif

#include "Chinese_ChessDoc.h"
#include "Chinese_ChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChineseChessView

IMPLEMENT_DYNCREATE(CChineseChessView, CView)

BEGIN_MESSAGE_MAP(CChineseChessView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChineseChessView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CChineseChessView construction/destruction

CChineseChessView::CChineseChessView() noexcept
{
	// TODO: add construction code here

}

CChineseChessView::~CChineseChessView()
{
}

BOOL CChineseChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CChineseChessView drawing

void CChineseChessView::OnDraw(CDC* /*pDC*/)
{
	CChineseChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CChineseChessView printing


void CChineseChessView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CChineseChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CChineseChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CChineseChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CChineseChessView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CChineseChessView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CChineseChessView diagnostics

#ifdef _DEBUG
void CChineseChessView::AssertValid() const
{
	CView::AssertValid();
}

void CChineseChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CChineseChessDoc* CChineseChessView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CChineseChessDoc)));
	return (CChineseChessDoc*)m_pDocument;
}
#endif //_DEBUG


// CChineseChessView message handlers
