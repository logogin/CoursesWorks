// SingleDoc.h : interface of the CSingleDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEDOC_H__D222B999_74E5_45FB_A76E_3DC280AC54F3__INCLUDED_)
#define AFX_SINGLEDOC_H__D222B999_74E5_45FB_A76E_3DC280AC54F3__INCLUDED_

#include "PropDlg.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


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
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	CPropDlg * GetDlg(void);
	void RemoveElementAt(const UINT uiIndex);
	CObject * GetElementAt(const UINT uiIndex);
	void AddFigure(CObject *pFigure);
	INT GetArraySize(void);
	CObArray * GetArray(void);
	virtual ~CSingleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	BOOL m_bFirst;
	CPropDlg m_dlgProp;
	CObArray m_arrayFigures;
	//{{AFX_MSG(CSingleDoc)
	afx_msg void OnEditProperties();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEDOC_H__D222B999_74E5_45FB_A76E_3DC280AC54F3__INCLUDED_)
