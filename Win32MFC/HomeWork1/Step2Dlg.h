#if !defined(AFX_STEP2DLG_H__BB83999C_CD21_458C_86AE_9023EF203BB9__INCLUDED_)
#define AFX_STEP2DLG_H__BB83999C_CD21_458C_86AE_9023EF203BB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Step2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStep2Dlg dialog

class CStep2Dlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CStep2Dlg)

// Construction
public:
	CPen *GetColor(void);
	CStep2Dlg();
	~CStep2Dlg();

// Dialog Data
	//{{AFX_DATA(CStep2Dlg)
	enum { IDD = IDD_PROPPAGE_STEP2 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStep2Dlg)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CPen m_penColor;
	// Generated message map functions
	//{{AFX_MSG(CStep2Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP2DLG_H__BB83999C_CD21_458C_86AE_9023EF203BB9__INCLUDED_)
