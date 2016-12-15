// SingleDoc.cpp : implementation of the CSingleDoc class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"
#include "SingleView.h"
#include "Ball.h"
#include "Cube.h"
#include "Step1Dlg.h"
#include "Step2Dlg.h"
#include "Step3Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc

IMPLEMENT_DYNCREATE(CSingleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDoc, CDocument)
	//{{AFX_MSG_MAP(CSingleDoc)
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc construction/destruction

CSingleDoc::CSingleDoc():m_dlgProp(&m_arrayFigures),m_bFirst(TRUE)
{
	// TODO: add one-time construction code here
	srand((unsigned)time(NULL));

}

CSingleDoc::~CSingleDoc()
{
}

BOOL CSingleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	CRect clientRect;
	POSITION pos=GetFirstViewPosition();
	CSingleView *pView=(CSingleView *)GetNextView(pos);

	if (pView!=NULL)
		pView->GetClientRect(&clientRect);

	CStep1Dlg stepPage1;
	CStep2Dlg stepPage2;
	CStep3Dlg stepPage3(&stepPage1,clientRect);
	CPropertySheet stepsSheet;
	stepsSheet.AddPage(&stepPage1);
	stepsSheet.AddPage(&stepPage2);
	stepsSheet.AddPage(&stepPage3);
	stepsSheet.SetWizardMode();
	DWORD bResult=stepsSheet.DoModal();
	if (bResult==IDCANCEL&&m_bFirst)
	{
		m_bFirst=FALSE;
		return TRUE;
	}
	if (bResult==IDCANCEL&&!m_bFirst)
		return FALSE;

	FLOAT fDeltaX=(FLOAT)rand()/RAND_MAX;
		FLOAT fDeltaY=(FLOAT)rand()/RAND_MAX;
		FLOAT fNorm=(FLOAT)sqrt(fDeltaX*fDeltaX+fDeltaY*fDeltaY);

	if (stepPage1.GetType())
	{
		CBall *pBall=new CBall(
			stepPage3.GetRadLen(),
			stepPage3.GetCenterX(),
			stepPage3.GetCenterY(),
			stepPage3.GetVelocity(),
			fDeltaX/fNorm,
			fDeltaY/fNorm,
			*stepPage2.GetColor());
		AddFigure(pBall);
		pView->SetTimer(1,(UINT)(1000.0f/pBall->GetVelocity()),NULL);
	}
	else
	{
		CCube *pCube=new CCube(
			stepPage3.GetRadLen(),
			stepPage3.GetCenterX(),
			stepPage3.GetCenterY(),
			stepPage3.GetVelocity(),
			fDeltaX/fNorm,
			fDeltaY/fNorm,
			*stepPage2.GetColor());
		AddFigure(pCube);
		pView->SetTimer(1,(UINT)(1000.0f/pCube->GetVelocity()),NULL);
	}

	SetModifiedFlag();

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CSingleDoc serialization

void CSingleDoc::Serialize(CArchive& ar)
{
	m_arrayFigures.Serialize(ar);
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc diagnostics

#ifdef _DEBUG
void CSingleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSingleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSingleDoc commands

CObArray * CSingleDoc::GetArray()
{
	return &m_arrayFigures;
}

INT CSingleDoc::GetArraySize()
{
	return m_arrayFigures.GetSize();
}

void CSingleDoc::AddFigure(CObject *pFigure)
{
	m_arrayFigures.Add(pFigure);
}

CObject * CSingleDoc::GetElementAt(const UINT uiIndex)
{
	return m_arrayFigures.GetAt(uiIndex);
}

void CSingleDoc::RemoveElementAt(const UINT uiIndex)
{
	m_arrayFigures.RemoveAt(uiIndex);
}

void CSingleDoc::DeleteContents() 
{
	// TODO: Add your specialized code here and/or call the base class
	POSITION pos=GetFirstViewPosition();
	CSingleView *pView=(CSingleView *)GetNextView(pos);

	if (pView!=NULL)
		pView->KillAllTimers();

	INT i;
	for (i=0; i<m_arrayFigures.GetSize(); i++)
	{
		CObject *pObject=m_arrayFigures[i];
		delete pObject;
	}

	m_arrayFigures.RemoveAll();

	if (pView!=NULL)
		pView->Invalidate();
	
	CDocument::DeleteContents();
}

BOOL CSingleDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	POSITION pos=GetFirstViewPosition();
	CSingleView *pView=(CSingleView *)GetNextView(pos);

	INT i;
	for (i=0; i<m_arrayFigures.GetSize(); i++)
	{
		CObject* pObject=m_arrayFigures[i];
		if (pObject->IsKindOf(RUNTIME_CLASS(CBall)))
			pView->SetTimer(i+1,(UINT)(1000.0f/((CBall *)pObject)->GetVelocity()),NULL);
		if (pObject->IsKindOf(RUNTIME_CLASS(CCube)))
			pView->SetTimer(i+1,(UINT)(1000.0f/((CCube *)pObject)->GetVelocity()),NULL);

	}
	
	return TRUE;
}

void CSingleDoc::OnEditProperties() 
{
	// TODO: Add your command handler code here
	m_dlgProp.SetDlgData();
	m_dlgProp.ShowWindow(SW_SHOWNORMAL);
}

CPropDlg *CSingleDoc::GetDlg(void)
{
	return &m_dlgProp;
}
