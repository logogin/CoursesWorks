// Step2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "Step2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep2Dlg property page

IMPLEMENT_DYNCREATE(CStep2Dlg, CPropertyPage)

CStep2Dlg::CStep2Dlg() : CPropertyPage(CStep2Dlg::IDD)
{
	m_penColor.CreatePen(PS_SOLID,0,RGB(255,0,0));
	//{{AFX_DATA_INIT(CStep2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CStep2Dlg::~CStep2Dlg()
{
}

void CStep2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStep2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep2Dlg, CPropertyPage)
	//{{AFX_MSG_MAP(CStep2Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep2Dlg message handlers

BOOL CStep2Dlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBO_COLOR);
	pCombo->AddString(_T("Red"));
	pCombo->AddString(_T("Green"));
	pCombo->AddString(_T("Blue"));
	pCombo->SetCurSel(0);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CStep2Dlg::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet *)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

LRESULT CStep2Dlg::OnWizardNext() 
{
	// TODO: Add your specialized code here and/or call the base class
	switch (((CComboBox *)GetDlgItem(IDC_COMBO_COLOR))->GetCurSel())
	{
	case 0:
		m_penColor.DeleteObject();
		m_penColor.CreatePen(PS_SOLID,0,RGB(255,0,0));
		break;
	case 1:
		m_penColor.DeleteObject();
		m_penColor.CreatePen(PS_SOLID,0,RGB(0,255,0));
		break;
	case 2:
		m_penColor.DeleteObject();
		m_penColor.CreatePen(PS_SOLID,0,RGB(0,0,255));
		break;
	}
	return CPropertyPage::OnWizardNext();
}

CPen *CStep2Dlg::GetColor()
{
	return &m_penColor;
}
