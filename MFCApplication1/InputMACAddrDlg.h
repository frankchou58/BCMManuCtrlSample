#pragma once


// InputMACAddrDlg 對話方塊

class InputMACAddrDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InputMACAddrDlg)

public:
	InputMACAddrDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~InputMACAddrDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_InputMACAddrDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CEdit m_InputMAC1Addr;
	CEdit m_InputMAC2Addr;
	afx_msg void OnEnChangeEdit2();
//	CButton m_Ok;
//	CButton m_OK;
//	CButton m_OK;
	afx_msg void OnBnClickedOk();
//	CButton m_OK;
	afx_msg void OnBnClickedButtonOk();
	int GetMacAddress(PCHAR pMac1, PCHAR pMac2);
	CString m_Mac1;
	CString m_Mac2;
	int GetResult();
	afx_msg void OnBnClickedCancel();
	int m_Result;
	PCHAR m_pFoundR;
	PCHAR m_pFoundN;
};
