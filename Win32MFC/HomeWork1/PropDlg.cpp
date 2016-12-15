// PropDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "PropDlg.h"
#include "Ball.h"
#include "Cube.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropDlg dialog


CPropDlg::CPropDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropDlg::IDD, pParent),m_pArray(NULL)
{
//	//{{AFX_DATA_INIT(CPropDlg)
//	m_fRadius = 0.0f;
//	m_fDeltaX = 0.0f;
//	m_fDeltaY = 0.0f;
//	m_fVelocity = 0.0f;
//	m_strRadLen = _T("");
//	//}}AFX_DATA_INIT
}

CPropDlg::CPropDlg(CObArray *pArray,CWnd* pParent) 
	: CDialog(CPropDlg::IDD, pParent),m_pArray(pArray)
{
	//{{AFX_DATA_INIT(CPropDlg)
	m_strRadLen = _T("");
	m_strDeltaX = _T("");
	m_strDeltaY = _T("");
	m_strVelocity = _T("");
	m_strEditRadLen = _T("");
	//}}AFX_DATA_INIT
}

void CPropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropDlg)
	DDX_Text(pDX, IDC_STATIC_RADLEN, m_strRadLen);
	DDX_Text(pDX, IDC_EDIT_DELTAX, m_strDeltaX);
	DDX_Text(pDX, IDC_EDIT_DELTAY, m_strDeltaY);
	DDX_Text(pDX, IDC_EDIT_VELOCITY, m_strVelocity);
	DDX_Text(pDX, IDC_EDIT_RADLEN, m_strEditRadLen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropDlg, CDialog)
	//{{AFX_MSG_MAP(CPropDlg)
	ON_CBN_SELCHANGE(IDC_COMBO_FIGURE, OnSelchangeComboFigure)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropDlg message handlers

BOOL CPropDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPropDlg::SetDlgData()
{
	INT i;
	CString choice;
	CComboBox *pCombo=(CComboBox *)GetDlgItem(IDC_COMBO_FIGURE);
	pCombo->ResetContent();
	m_strRadLen = _T("");
	m_strDeltaX = _T("");
	m_strDeltaY = _T("");
	m_strEditRadLen = _T("");
	m_strVelocity = _T("");
	for (i=0; i<m_pArray->GetSize(); i++)
	{
		CObject *pObject=m_pArray->GetAt(i);
		if (pObject->IsKindOf(RUNTIME_CLASS(CBall)))
			choice.Format(_T("Circle %d"),i+1);
		if (pObject->IsKindOf(RUNTIME_CLASS(CCube)))
			choice.Format(_T("Square %d"),i+1);
		pCombo->AddString(choice);
		
	}
	pCombo->SetCurSel(0);
	OnSelchangeComboFigure();

	UpdateData(FALSE);
}

void CPropDlg::OnSelchangeComboFigure() 
{
	// TODO: Add your control notification handler code here
	INT iCurSel=((CComboBox *)GetDlgItem(IDC_COMBO_FIGURE))->GetCurSel();
	if (iCurSel!=CB_ERR)
	{
		CObject *pObject=m_pArray->GetAt(iCurSel);
		if (pObject->IsKindOf(RUNTIME_CLASS(CBall)))
		{
			CBall *pBall=(CBall *)pObject;
			m_strRadLen=_T("Radius");
			m_strEditRadLen.Format(_T("%.2f"),pBall->GetRadius());
			m_strVelocity.Format(_T("%.2f"),pBall->GetVelocity());
			m_strDeltaX.Format(_T("%.2f"),pBall->GetDeltaX());
			m_strDeltaY.Format(_T("%.2f"),pBall->GetDeltaY());
		}
		if (pObject->IsKindOf(RUNTIME_CLASS(CCube)))
		{
			CCube *pCube=(CCube *)pObject;
			m_strRadLen=_T("Length");
			m_strEditRadLen.Format(_T("%.2f"),pCube->GetRadius());
			m_strVelocity.Format(_T("%.2f"),pCube->GetVelocity());
			m_strDeltaX.Format(_T("%.2f"),pCube->GetDeltaX());
			m_strDeltaY.Format(_T("%.2f"),pCube->GetDeltaY());
		}
		
	}
	UpdateData(FALSE);
}
