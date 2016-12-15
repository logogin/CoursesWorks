// SingleView.h : interface of the CSingleView class
//


#pragma once


class CSingleView : public CView
{
protected: // create from serialization only
	CSingleView();
	DECLARE_DYNCREATE(CSingleView)

// Attributes
public:
	CSingleDoc* GetDocument() const;

// Operations
public:

// Overrides
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CSingleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	void KillAllTimers(void);
};

#ifndef _DEBUG  // debug version in SingleView.cpp
inline CSingleDoc* CSingleView::GetDocument() const
   { return reinterpret_cast<CSingleDoc*>(m_pDocument); }
#endif

