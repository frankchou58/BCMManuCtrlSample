#pragma once


// AddFlowDeployDlg 對話方塊

class AddFlowDeployDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AddFlowDeployDlg)

public:
	AddFlowDeployDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~AddFlowDeployDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AddFlowDeployDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
