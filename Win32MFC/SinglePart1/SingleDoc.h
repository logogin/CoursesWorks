// SingleDoc.h : interface of the CSingleDoc class
//


#pragma once
#include "afxcoll.h"

class CSingleDoc : public CDocument
{
protected: // create from serialization only
	CSingleDoc();
	DECLARE_DYNCREATE(CSingleDoc)

// Attributes
public:

// Operations
public:

// Overrides
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSingleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CObArray arrayBall;
};


