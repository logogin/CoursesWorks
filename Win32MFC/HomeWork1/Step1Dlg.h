#if !defined(AFX_STEP1DLG_H__B42AD2B6_9E71_42B7_BA5D_1B1AC74F7D8E__INCLUDED_)
#define AFX_STEP1DLG_H__B42AD2B6_9E71_42B7_BA5D_1B1AC74F7D8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Step1Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStep1Dlg dialog

class CStep1Dlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CStep1Dlg)

// Construction
public:
	BOOL GetType(void);
	CStep1Dlg();
	~CStep1Dlg();

// Dialog Data
	//{{AFX_DATA(CStep1Dlg)
	enum { IDD = IDD_PROPPAGE_STEP1 };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStep1Dlg)
	public:
	virtual BOOL OnSetActive();
	virtual LRESULT OnWizardNext();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bCircle;
	// Generated message map functions
	//{{AFX_MSG(CStep1Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP1DLG_H__B42AD2B6_9E71_42B7_BA5D_1B1AC74F7D8E__INCLUDED_)
