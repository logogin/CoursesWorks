#pragma once


// CCrclDlg dialog

class CCrclDlg : public CDialog
{
	DECLARE_DYNAMIC(CCrclDlg)

public:
	CCrclDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CCrclDlg();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int CircleNo;
	int Radius;
	float Velocity;
	float DeltaX;
	float DeltaY;
	virtual BOOL OnInitDialog();
	void CloseDialog(void);
protected:
	virtual void OnOK();
	virtual void OnCancel();
};
