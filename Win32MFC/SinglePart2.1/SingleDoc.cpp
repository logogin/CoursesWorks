// SingleDoc.cpp : implementation of the CSingleDoc class
//

#include "stdafx.h"
#include "Single.h"

#include "SingleDoc.h"
#include "SingleView.h"

#include "Ball.h"
#include ".\singledoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSingleDoc

IMPLEMENT_DYNCREATE(CSingleDoc, CDocument)

BEGIN_MESSAGE_MAP(CSingleDoc, CDocument)
END_MESSAGE_MAP()


// CSingleDoc construction/destruction

CSingleDoc::CSingleDoc()
{
	// TODO: add one-time construction code here

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

	return TRUE;
}




// CSingleDoc serialization

void CSingleDoc::Serialize(CArchive& ar)
{
	arrayBall.Serialize(ar);

	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


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


// CSingleDoc commands

void CSingleDoc::DeleteContents()
{
	// TODO: Add your specialized code here and/or call the base class
	POSITION pos = GetFirstViewPosition();
	CSingleView *pView = (CSingleView*) GetNextView(pos);
	// At the end of the program this method is called when View class
	// is already destoroyed, check if it exists
	if (pView) pView->KillAllTimers();

	for (int i = 0; i < arrayBall.GetSize(); i++)
	{
   		CBall* pBall = (CBall*) arrayBall[i];
		delete pBall;
	}

	arrayBall.RemoveAll();

	if (pView) pView->Invalidate();

	CDocument::DeleteContents();
}

BOOL CSingleDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  Add your specialized creation code here
	POSITION pos = GetFirstViewPosition();
	CSingleView *pView = (CSingleView*) GetNextView(pos);

	for (int i = 0; i < arrayBall.GetSize(); i++)
	{
   		CBall* pBall = (CBall*) arrayBall[i];
		pView->SetTimer(i+1, (int) 1000 / pBall->Velocity, NULL);
	}

	return TRUE;
}
