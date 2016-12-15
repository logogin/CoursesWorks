// calcDlg.h : header file
//

#pragma once


// CcalcDlg dialog
class CcalcDlg : public CDialog
{
// Construction
public:
	CcalcDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CALC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedRadio1();
	float m_firstOp;
	float m_secondOp;
	int m_nRadio;
	float m_fResult;
};
