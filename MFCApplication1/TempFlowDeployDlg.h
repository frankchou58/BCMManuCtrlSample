#pragma once


// TempFlowDeployDlg 對話方塊

class TempFlowDeployDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TempFlowDeployDlg)

public:
	TempFlowDeployDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~TempFlowDeployDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TempFlowDeployDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_FLOW_DEPLOY_INDEX,
		ID_LIST_FLOW_DEPLOY_NAME,
		ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME,
		ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME,
	};
public:
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowStationName;
	CButton m_BtnSure;
	CStatic m_ShowTempDeployList;
	CComboBox m_SelectIndexTempDeploy;
	CListCtrl m_ListTempFlowDeploy;
	afx_msg void OnCbnSelchangeComboIndexTempFlowDeploy();
	CEdit m_EditFlowDeployName;
//	CStatic m_ShowTempFlowDeployIndex;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	afx_msg void OnAddFlowDeploy();
//	afx_msg void OnBnClickedButton1();
//	CEdit m_ShowTempFlowDeployIndex;
	CEdit m_ShowTempFlowDeployIndex;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonChangeName();
	afx_msg void OnDelTempFlowDeploy();
	void OnBnClickedAddTempFlowDeploy();
};
