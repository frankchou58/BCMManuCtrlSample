#pragma once


// LoginDlg 對話方塊

class LoginDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDlg)

public:
	LoginDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~LoginDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LoginDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
//	virtual void OnFinalRelease();
	virtual BOOL OnInitDialog();
	int m_OpenCounter;
	CComboBox m_ListStation;
	afx_msg void OnBnClickedOk();
};

extern StationData_T g_StationData[20];
