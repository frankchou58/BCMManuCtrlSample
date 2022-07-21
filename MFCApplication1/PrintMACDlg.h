#pragma once


// PrintMACDlg 對話方塊

class PrintMACDlg : public CDialogEx
{
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
		ID_LIST_CTRL_M_TYPE,
		ID_LIST_CTRL_M_NO,
		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_I_NO,
		ID_LIST_CTRL_MAC_1,
		ID_LIST_CTRL_MAC_OUT_1,
	};
	DECLARE_DYNAMIC(PrintMACDlg)

public:
	PrintMACDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~PrintMACDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PrintMACDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_SelectCustomerMAC;
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowStationName;
	CStatic m_ShowCtrlList;
	CButton m_BtnSure;
	CButton m_RadioBatch;
	CListCtrl m_ListCtrlNo;
	CComboBox m_MType;
	CEdit m_ShowParentMType;
	CComboBox m_SelectMACsPerOne;
	CButton m_BtnRePrintMAC;
	afx_msg void OnCbnSelchangeComboMacsPerOne();
	afx_msg void OnBnClickedOk();
	afx_msg void OnCbnSelchangeComboCustomerMac();
//	CEdit m_ShowLastMAC;
	CEdit m_CtrlSNMtype;
	CEdit m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_CtrlSNParentMSN;
//	CEdit m_ShowMDesc;
	CEdit m_CtrlSNParentMDesc;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	afx_msg void OnEnChangeEditMno();
	CEdit m_EditMNo;
	CEdit m_ShowParentMDesc;
	CEdit m_EditCtrlSN;
	CEdit m_ShowListCtrlSNNumbers;
//	CButton m_TitleLastMAC;
	CStatic m_TitleLastMAC;
	CEdit m_ShowLastMAC;
	CEdit m_InputEndMAC;
	CEdit m_InputStartMAC;
	CStatic m_TitleMark;
	CStatic m_TitleMACRange;
	afx_msg void OnEnChangeEditStartMac();
	afx_msg void OnEnChangeEditEndMac();
};
