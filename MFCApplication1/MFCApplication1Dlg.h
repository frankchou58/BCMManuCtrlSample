
// MFCApplication1Dlg.h: 標頭檔
//

#pragma once
// CMFCApplication1Dlg 對話方塊
class CMFCApplication1Dlg : public CDialogEx
{
// 建構
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
//	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
//	afx_msg void OnPaint();
//	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
		ID_LIST_CTRL_M_TYPE,
		ID_LIST_CTRL_M_NO,
		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_I_NO,
	};

	//	CButton m_Text;
	CEdit m_Edit1;
	CListCtrl m_ListCtrlNo;
	CStatic m_ShowStationName;
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	CButton m_RadioBatch;
	CButton m_RadioOne;
	afx_msg void OnBnClickedRadioOne();
	CEdit m_EditCtrlNo;
	afx_msg void OnBnClickedRadioBatch();
	CButton m_BtnSure;
	CEdit m_MNo;
	CComboBox m_MType;
	CStatic m_ShowDesc;
	CStatic m_ShowINo;
	CStatic m_ShowCtrlList;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowParentMNo;
	afx_msg void OnStationSelect();
	int m_OpenCounter;
//	CStatic m_ShowMType;
	CStatic m_ShowParentMType;
	afx_msg void OnStation1();
	afx_msg void OnStation3();
	afx_msg void OnStation4();
	afx_msg void OnDestroy();
	CStatic m_ShowParentDesc;
	afx_msg void OnStation23();
	afx_msg void OnStation25();
//	virtual INT_PTR DoModal();
//	virtual INT_PTR DoModal();
};
