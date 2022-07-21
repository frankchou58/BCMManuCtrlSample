#pragma once


// ManageErrorCodeDlg 對話方塊

class ManageErrorCodeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ManageErrorCodeDlg)
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_ERROR_QID,
		ID_LIST_ERROR_DESC_ENG,
		ID_LIST_ERROR_DESC_CHN,
	};

public:
	ManageErrorCodeDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~ManageErrorCodeDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ManageErrorCodeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowStationName;
	CButton m_BtnSure;
	CStatic m_ShowStationMsg;
//	CEdit m_InputQID;
	CEdit m_InputQDescEng;
	CEdit m_InputQDescChn;
	CListCtrl m_ListErrorCode;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	afx_msg void OnEditErrorCode();
	CComboBox m_InputQID;
	afx_msg void OnAddErrorCode();
	afx_msg void OnLButtonClkInListView(NMHDR* pNMHDR, LRESULT* pResult);
//	afx_msg void OnNMClickListStation(NMHDR* pNMHDR, LRESULT* pResult);
};
