#pragma once


// ManageStationDlg 對話方塊

class ManageStationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ManageStationDlg)
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_STATION_ID,
		ID_LIST_STATION_NAME,
		ID_LIST_STATION_METHOD,
		ID_LIST_STATION_EXCEPTION,
	};
public:
	ManageStationDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~ManageStationDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ManageStationDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ListStation;
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
	afx_msg void OnBnClickedOk();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	CComboBox m_SelectStationId;
	CEdit m_InputStationName;
	CButton m_SelectedBatch;
	CButton m_SelectedOne;
	CButton m_SelectedNormal;
	CButton m_SelectedException;
	afx_msg void OnEditStation();
	afx_msg void OnAddStation();
	afx_msg void OnLButtonClkInListView(NMHDR* pNMHDR, LRESULT* pResult);
};

extern StationData_T g_StationData[20];
