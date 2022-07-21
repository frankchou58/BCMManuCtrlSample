#pragma once


// SMDFixDescDlg 對話方塊

class SMDFixDescDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SMDFixDescDlg)

public:
	SMDFixDescDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SMDFixDescDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMDFixDescDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
