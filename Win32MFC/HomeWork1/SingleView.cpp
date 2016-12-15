// SingleView.cpp : implementation of the CSingleView class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"
#include "SingleView.h"
#include "Ball.h"
#include "Cube.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleView

IMPLEMENT_DYNCREATE(CSingleView, CView)

BEGIN_MESSAGE_MAP(CSingleView, CView)
	//{{AFX_MSG_MAP(CSingleView)
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleView construction/destruction

CSingleView::CSingleView()
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

/////////////////////////////////////////////////////////////////////////////
// CSingleView drawing

void CSingleView::OnDraw(CDC* pDC)
{
	CSingleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	INT i;
	CObArray *pArray=pDoc->GetArray();

	for (i=0; i<pDoc->GetArraySize(); i++)
	{
		CObject *pObject=pArray->GetAt(i);
		if (pObject->IsKindOf(RUNTIME_CLASS(CBall)))
		{
			CBall *pBall=(CBall *)pObject;
			pDC->SelectObject(pBall->GetColor());
			pDC->Ellipse(pBall->GetRect());
			pDC->SelectStockObject(BLACK_PEN);
		}
		if (pObject->IsKindOf(RUNTIME_CLASS(CCube)))
		{
			CCube *pCube=(CCube *)pObject;
			pDC->SelectObject(pCube->GetColor());
			pDC->Rectangle(pCube->GetRect());
			pDC->SelectStockObject(BLACK_PEN);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////
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

CSingleDoc* CSingleView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSingleDoc)));
	return (CSingleDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleView message handlers

void CSingleView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	FLOAT fRadius=10.0f+rand()%91;
	FLOAT fDeltaX=(FLOAT)rand()/RAND_MAX;
	FLOAT fDeltaY=(FLOAT)rand()/RAND_MAX;
	FLOAT fNorm=(FLOAT)sqrt(fDeltaX*fDeltaX+fDeltaY*fDeltaY);
	
	CBall *pBall= new CBall(fRadius,fRadius,fRadius,50.0f+rand()%201,
		fDeltaX/fNorm,fDeltaY/fNorm,CPen(PS_SOLID,0,RGB(0,0,0)));

	CSingleDoc *pDoc=GetDocument();
	pDoc->AddFigure(pBall);
	SetTimer(pDoc->GetArraySize(),(UINT)(1000/pBall->GetVelocity()),NULL);

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
	CSingleDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CBall *pBall=(CBall *)pDoc->GetElementAt(nIDEvent-1);

	CRect wndRect;
	GetClientRect(&wndRect);
	pBall->Move(wndRect);

	Invalidate();
	
	CView::OnTimer(nIDEvent);
}

void CSingleView::KillAllTimers()
{
	CSingleDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	INT i;
	for (i=0; i<pDoc->GetArraySize(); i++)
		KillTimer(i+1);
}

void CSingleView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	CSingleDoc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	UINT uiSize=pDoc->GetArraySize();
	KillTimer(uiSize);
	if (uiSize)
	{
		CObject *pObject=pDoc->GetElementAt(uiSize-1);
		delete pObject;
		pDoc->RemoveElementAt(uiSize-1);
	}
	
	pDoc->SetModifiedFlag();
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


int CSingleView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if (!GetDocument()->GetDlg()->Create(IDD_DIALOG_PROPERTIES))
		
	{
		TRACE0("Failed to create dialog bar\n");
		return -1;      // fail to create
	} 
	
	return 0;
}
