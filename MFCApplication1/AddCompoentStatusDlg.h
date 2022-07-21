#pragma once


// AddCompoentStatusDlg 對話方塊

class AddCompoentStatusDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCompoentStatusDlg)

public:
	AddCompoentStatusDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~AddCompoentStatusDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddCompoentStatusDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
//	int GetMacAddress(PCHAR pMac1, PCHAR pMac2);
};
