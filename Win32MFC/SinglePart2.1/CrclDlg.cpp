// CrclDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Single.h"
#include "CrclDlg.h"
#include ".\crcldlg.h"
#include "SingleDoc.h"
#include "SingleView.h"
#include "Ball.h"


// CCrclDlg dialog

IMPLEMENT_DYNAMIC(CCrclDlg, CDialog)
CCrclDlg::CCrclDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCrclDlg::IDD, pParent)
	, CircleNo(0)
	, Radius(0)
	, Velocity(0)
	, DeltaX(0)
	, DeltaY(0)
{
}

CCrclDlg::~CCrclDlg()
{
}

void CCrclDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_COMBO1, CircleNo);
	DDX_Text(pDX, IDC_EDIT1, Radius);
	DDX_Text(pDX, IDC_EDIT4, Velocity);
	DDX_Text(pDX, IDC_EDIT2, DeltaX);
	DDX_Text(pDX, IDC_EDIT3, DeltaY);
}


BEGIN_MESSAGE_MAP(CCrclDlg, CDialog)
END_MESSAGE_MAP()


// CCrclDlg message handlers

BOOL CCrclDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CSingleDoc *pDoc = ((CSingleView *) m_pParentWnd) ->GetDocument();
	CComboBox *pCB = (CComboBox *) GetDlgItem(IDC_COMBO1);
	CString str;
	for(int i=0;i<pDoc->arrayBall.GetSize();i++)
	{
		str.Format("circle %d",i+1);
		pCB->AddString(str);
	}
	pCB->SetCurSel(CircleNo);
	SetDlgData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
CCrclDlg::SetDlgData()
{
		CSingleDoc *pDoc = ((CSingleView *) m_pParentWnd) ->GetDocument();
		if(pDoc->arrayBall.GetSize()>0)
		{
			CBall *pBall =(CBall *) pDoc->arrayBall[CircleNo];
			DeltaX = pBall->DeltaX;
			DeltaY = pBall->DeltaY;
			Radius = pBall->Radius;
			Velocity = pBall->Velocity;
			UpdateData(false);
		}
}








void CCrclDlg::CloseDialog(void)
{
    CComboBox *pCB = (CComboBox *) GetDlgItem(IDC_COMBO1);
	pCB->ResetContent();
	CircleNo=0;
	DestroyWindow();
	((CSingleView *)m_pParentWnd)->DlgState = 0;
}

void CCrclDlg::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CloseDialog();
}

void CCrclDlg::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class
CloseDialog();
	
}
