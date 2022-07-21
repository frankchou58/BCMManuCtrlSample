#pragma once


// CtrlSNFlowDeployDlg 對話方塊

class CtrlSNFlowDeployDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CtrlSNFlowDeployDlg)
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_FLOW_DEPLOY_INDEX,
		ID_LIST_FLOW_DEPLOY_NAME,
		ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME,
		ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME,
	};

public:
	CtrlSNFlowDeployDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~CtrlSNFlowDeployDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CtrlSNFlowDeployDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
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
//	CListCtrl m_ShowCtrlSnDeployList;
//	CStatic m_ShowCtrlSnDeployList;
//	CListCtrl m_ListCtrlSnFlowDeploy;
	CListCtrl m_ListCtrlSnFlowDeploy;
	CStatic m_ShowCtrlSnDeployList;
	CComboBox m_MType;
	CEdit m_ShowCtrlSnFlowDeployIndex;
	afx_msg void OnBnClickedOk();
	CEdit m_EditMNo;
	afx_msg void OnEnChangeEditMno();
	CEdit m_ShowParentMType;
	CEdit m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	CEdit m_ShowCtrlSnFlowDeployName;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	afx_msg void OnAddCtrlsnFlowDeploy();
};
