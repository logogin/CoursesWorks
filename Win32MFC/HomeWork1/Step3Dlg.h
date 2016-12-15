#if !defined(AFX_STEP3DLG_H__1DA3479A_F5D2_48DB_AF5A_8690EBC9DD78__INCLUDED_)
#define AFX_STEP3DLG_H__1DA3479A_F5D2_48DB_AF5A_8690EBC9DD78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Step3Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStep3Dlg dialog
class CStep1Dlg;

class CStep3Dlg : public CPropertyPage
{
	DECLARE_DYNCREATE(CStep3Dlg)

// Construction
public:
	FLOAT GetCenterY(void);
	FLOAT GetCenterX(void);
	FLOAT GetVelocity();
	FLOAT GetRadLen(void);
	CStep3Dlg();
	CStep3Dlg(CStep1Dlg *pStep1Dlg,const CRect &rect);
	~CStep3Dlg();

// Dialog Data
	//{{AFX_DATA(CStep3Dlg)
	enum { IDD = IDD_PROPPAGE_STEP3 };
	CString	m_strRadLen;
	float	m_fVelocity;
	float	m_fRadLen;
	float	m_fCenterX;
	float	m_fCenterY;
	//}}AFX_DATA


// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CStep3Dlg)
	public:
	virtual BOOL OnSetActive();
	virtual BOOL OnWizardFinish();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CRect m_rectClient;
	CStep1Dlg * m_pStep1Dlg;
	// Generated message map functions
	//{{AFX_MSG(CStep3Dlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STEP3DLG_H__1DA3479A_F5D2_48DB_AF5A_8690EBC9DD78__INCLUDED_)
