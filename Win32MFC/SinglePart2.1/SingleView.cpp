// SingleView.cpp : implementation of the CSingleView class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"
#include "SingleView.h"
#include ".\singleview.h"

#include "Ball.h"
#include <math.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleView

IMPLEMENT_DYNCREATE(CSingleView, CView)

BEGIN_MESSAGE_MAP(CSingleView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSingleView construction/destruction

CSingleView::CSingleView():DlgState(false),Dlg(this)
{
	// TODO: add construction code here

}

CSingleView::~CSingleView()
{
}

BOOL CSingleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSingleView drawing

void CSingleView::OnDraw(CDC* pDC)
{
	CSingleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	for (int i = 0; i < pDoc -> arrayBall.GetSize(); i++)
	{
		CBall *pBall = (CBall*) pDoc -> arrayBall[i];
		pDC->Ellipse(pBall->CenterX - pBall->Radius,
			pBall->CenterY - pBall->Radius,
			pBall->CenterX + pBall->Radius,
			pBall->CenterY + pBall->Radius);
		/*CPoint *pPoint = (CPoint*) pDoc -> arrayBall[i];
		pDC->Ellipse(pPoint->x - 15, pPoint->y - 15,
			pPoint->x + 15, pPoint->y + 15);*/
	}
}


// CSingleView printing

BOOL CSingleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSingleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSingleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSingleView diagnostics

#ifdef _DEBUG
void CSingleView::AssertValid() const
{
	CView::AssertValid();
}

void CSingleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSingleDoc* CSingleView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDoc)));
	return (CSingleDoc*)m_pDocument;
}
#endif //_DEBUG


// CSingleView message handlers

void CSingleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CBall *pBall = new CBall();
	pBall->Radius = pBall->CenterX = pBall->CenterY = 10 + rand()%90; // max radius 100;
	pBall->DeltaX = (float) rand() / RAND_MAX;
	pBall->DeltaY = (float) rand() / RAND_MAX;
	float DeltaLength = sqrt(pBall->DeltaX * pBall->DeltaX +
		pBall->DeltaY * pBall->DeltaY);
	pBall->DeltaX = pBall->DeltaX / DeltaLength;
	pBall->DeltaY = pBall->DeltaY / DeltaLength;
	pBall->Velocity = (float) (1+rand()%200); // max velocity 200;

	CSingleDoc *pDoc = GetDocument();
	pDoc->arrayBall.Add(pBall);

	SetTimer(pDoc->arrayBall.GetSize(),(int) 1000 / pBall->Velocity, NULL);

	pDoc->SetModifiedFlag();

	CView::OnLButtonDown(nFlags, point);
}

void CSingleView::OnDestroy()
{
	CView::OnDestroy();

	// TODO: Add your message handler code here
	KillAllTimers();
}

void CSingleView::OnTimer(UINT nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	CSingleDoc *pDoc = GetDocument();
	CBall *pBall = (CBall*) pDoc -> arrayBall[nIDEvent-1];

	pBall->CenterX += pBall->DeltaX;
	pBall->CenterY += pBall->DeltaY;

	CRect WinRect;
	GetClientRect( &WinRect );
	if ( pBall->CenterX < WinRect.left + pBall->Radius ||
		pBall->CenterX > WinRect.right - pBall->Radius)
			pBall->DeltaX *= -1;
	if ( pBall->CenterY < WinRect.top + pBall->Radius ||
		pBall->CenterY > WinRect.bottom - pBall->Radius)
			pBall->DeltaY *= -1;

	Invalidate();

	CView::OnTimer(nIDEvent);
}

void CSingleView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CSingleDoc *pDoc = GetDocument();
    KillTimer(pDoc->arrayBall.GetSize());
	CBall *pBall = (CBall*) pDoc -> arrayBall[pDoc->arrayBall.GetSize()-1];
	delete pBall;
	pDoc -> arrayBall.RemoveAt(pDoc->arrayBall.GetSize()-1);
    Invalidate();

	pDoc->SetModifiedFlag();

	CView::OnRButtonDown(nFlags, point);
}

void CSingleView::KillAllTimers(void)
{
	CSingleDoc *pDoc = GetDocument();
	for (int i = 0; i < pDoc -> arrayBall.GetSize(); i++)
        KillTimer(i+1);
}
