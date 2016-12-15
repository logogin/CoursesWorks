// calcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include ".\calcdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalcDlg dialog



CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalcDlg::IDD, pParent)
	, m_firstOp(0)
	, m_secondOp(0)
	, m_nRadio(0)
	, m_fResult(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_firstOp);
	DDX_Text(pDX, IDC_EDIT2, m_secondOp);
	DDX_Radio(pDX, IDC_RADIO1, m_nRadio);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
END_MESSAGE_MAP()


// CcalcDlg message handlers

BOOL CcalcDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CcalcDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CcalcDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	UpdateData( TRUE );
	switch (m_nRadio)
	{
	case 0:
		m_fResult = m_firstOp + m_secondOp;
		break;
	case 1:
		m_fResult = m_firstOp - m_secondOp;
		break;
	case 2:
		m_fResult = m_firstOp * m_secondOp;
		break;
	case 3:
		m_fResult = m_firstOp / m_secondOp;
		break;
	}
	CString ResStr;
	ResStr.Format("%f",m_fResult);
	AfxMessageBox(ResStr);
}

void CcalcDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
}
