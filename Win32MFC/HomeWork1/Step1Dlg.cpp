// Step1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "Step1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep1Dlg property page

IMPLEMENT_DYNCREATE(CStep1Dlg, CPropertyPage)

CStep1Dlg::CStep1Dlg() : CPropertyPage(CStep1Dlg::IDD),m_bCircle(TRUE)
{
	//{{AFX_DATA_INIT(CStep1Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CStep1Dlg::~CStep1Dlg()
{
}

void CStep1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStep1Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep1Dlg, CPropertyPage)
	//{{AFX_MSG_MAP(CStep1Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep1Dlg message handlers

BOOL CStep1Dlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	// TODO: Add extra initialization here

	((CButton *)GetDlgItem(IDC_RADIO_CIRCLE))->SetCheck(1);
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CStep1Dlg::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet *)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	
	return CPropertyPage::OnSetActive();
}

LRESULT CStep1Dlg::OnWizardNext() 
{
	// TODO: Add your specialized code here and/or call the base class
	if (((CButton *)GetDlgItem(IDC_RADIO_CIRCLE))->GetCheck())
		m_bCircle=TRUE;
	else
		m_bCircle=FALSE;
	
	return CPropertyPage::OnWizardNext();
}

BOOL CStep1Dlg::GetType()
{
	return m_bCircle;
}
