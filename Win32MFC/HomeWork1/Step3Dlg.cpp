// Step3Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "Step3Dlg.h"
#include "Step1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStep3Dlg property page

IMPLEMENT_DYNCREATE(CStep3Dlg, CPropertyPage)
CStep3Dlg::CStep3Dlg() : CPropertyPage(CStep3Dlg::IDD)
{
//	//{{AFX_DATA_INIT(CStep3Dlg)
//	m_strRadlen = _T("");
//	m_fVelocity = 0.0f;
//	m_fRadLen = 0.0f;
//	m_fCenterX = 0.0f;
//	m_fCenterY = 0.0f;
//	//}}AFX_DATA_INIT
}

CStep3Dlg::CStep3Dlg(CStep1Dlg *pStep1Dlg,const CRect &rect) : CPropertyPage(CStep3Dlg::IDD),
	m_pStep1Dlg(pStep1Dlg),m_rectClient(rect)
{
	//{{AFX_DATA_INIT(CStep3Dlg)
	m_strRadLen = _T("");
	m_fVelocity = 50.0f;
	m_fRadLen = 10.0f;
	m_fCenterX = 0.0f;
	m_fCenterY = 0.0f;
	//}}AFX_DATA_INIT
}

CStep3Dlg::~CStep3Dlg()
{
}

void CStep3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStep3Dlg)
	DDX_Text(pDX, IDC_STATIC_RADLEN, m_strRadLen);
	DDX_Text(pDX, IDC_EDIT_VELOCITY, m_fVelocity);
	DDV_MinMaxFloat(pDX, m_fVelocity, 50.f, 200.f);
	DDX_Text(pDX, IDC_EDIT_RADLEN, m_fRadLen);
	DDV_MinMaxFloat(pDX, m_fRadLen, 10.f, 100.f);
	DDX_Text(pDX, IDC_EDIT_CENTERX, m_fCenterX);
	DDX_Text(pDX, IDC_EDIT_CENTERY, m_fCenterY);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStep3Dlg, CPropertyPage)
	//{{AFX_MSG_MAP(CStep3Dlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStep3Dlg message handlers

BOOL CStep3Dlg::OnSetActive() 
{
	// TODO: Add your specialized code here and/or call the base class
	((CPropertySheet *)GetParent())->SetWizardButtons(PSWIZB_BACK | PSWIZB_FINISH);
	
	return CPropertyPage::OnSetActive();
}

BOOL CStep3Dlg::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here
	if (m_pStep1Dlg->GetType())
		m_strRadLen=_T("Radius");
	else
		m_strRadLen=_T("Length");
	UpdateData(FALSE);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CStep3Dlg::OnWizardFinish() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	BOOL bIsValid=UpdateData(TRUE);
	if (!bIsValid)
		return FALSE;
	if (m_fCenterX+m_fRadLen>m_rectClient.right||
		m_fCenterX-m_fRadLen<m_rectClient.left||
		m_fCenterY-m_fRadLen<m_rectClient.top||
		m_fCenterY+m_fRadLen>m_rectClient.bottom)
	{
		AfxMessageBox(_T("Center is not in bounds!!!"),MB_OK);
		return FALSE;
	}

	return CPropertyPage::OnWizardFinish();
}

FLOAT CStep3Dlg::GetRadLen()
{
	return m_fRadLen;
}

FLOAT CStep3Dlg::GetVelocity()
{
	return m_fVelocity;
}

FLOAT CStep3Dlg::GetCenterX()
{
	return m_fCenterX;
}

FLOAT CStep3Dlg::GetCenterY()
{
	return m_fCenterY;
}
