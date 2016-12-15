// SingleView.h : interface of the CSingleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEVIEW_H__F7AABADC_FF79_40A1_95B1_36FF4C2619A0__INCLUDED_)
#define AFX_SINGLEVIEW_H__F7AABADC_FF79_40A1_95B1_36FF4C2619A0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSingleView : public CView
{
protected: // create from serialization only
	CSingleView();
	DECLARE_DYNCREATE(CSingleView)

// Attributes
public:
	CSingleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSingleView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void KillAllTimers(void);
	virtual ~CSingleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSingleView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SingleView.cpp
inline CSingleDoc* CSingleView::GetDocument()
   { return (CSingleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEVIEW_H__F7AABADC_FF79_40A1_95B1_36FF4C2619A0__INCLUDED_)
