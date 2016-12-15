#if !defined(AFX_PROPDLG_H__28A00755_F406_4E7A_8B5D_62A70AA5CCBA__INCLUDED_)
#define AFX_PROPDLG_H__28A00755_F406_4E7A_8B5D_62A70AA5CCBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropDlg dialog

class CPropDlg : public CDialog
{
// Construction
public:
	void SetDlgData(void);
	CPropDlg(CWnd* pParent = NULL);   // standard constructor
	CPropDlg(CObArray *pArray,CWnd* pParent = NULL);

// Dialog Data
	//{{AFX_DATA(CPropDlg)
	enum { IDD = IDD_DIALOG_PROPERTIES };
	CString	m_strRadLen;
	CString	m_strDeltaX;
	CString	m_strDeltaY;
	CString	m_strVelocity;
	CString	m_strEditRadLen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CObArray *m_pArray;

	// Generated message map functions
	//{{AFX_MSG(CPropDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeComboFigure();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPDLG_H__28A00755_F406_4E7A_8B5D_62A70AA5CCBA__INCLUDED_)
