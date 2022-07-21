#pragma once


// AddCustomerMACDlg 對話方塊

class AddCustomerMACDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddCustomerMACDlg)

public:
	AddCustomerMACDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~AddCustomerMACDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddCustomerMACDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
