#pragma once


// MaterialCtrlDlg 對話方塊

class MaterialCtrlDlg : public CDialogEx
{
	enum
	{
		ID_LIST_COMPOENT_NEED_ID = 0,
		ID_LIST_COMPOENT_NEED_TYPE,
		ID_LIST_COMPOENT_NEED_INO,
		ID_LIST_COMPOENT_NEED_DESC,
	};
	enum
	{
		ID_LIST_COMPOENT_STATUS_ID = 0,
		ID_LIST_COMPOENT_STATUS_M_TYPE,
		ID_LIST_COMPOENT_STATUS_M_NO,
		ID_LIST_COMPOENT_STATUS_M_INO,
		ID_LIST_COMPOENT_STATUS_M_DESC,
		ID_LIST_COMPOENT_STATUS_S_INO,
		ID_LIST_COMPOENT_STATUS_S_DESC,
		ID_LIST_COMPOENT_STATUS_DATE_CODE,
		ID_LIST_COMPOENT_STATUS_DC_QTY,
		ID_LIST_COMPOENT_STATUS_LOT_NO,
		ID_LIST_COMPOENT_STATUS_BIN_CODE,
		ID_LIST_COMPOENT_STATUS_CREATE_DATE,
		ID_LIST_COMPOENT_STATUS_CREATE_ID,
	};
	DECLARE_DYNAMIC(MaterialCtrlDlg)

public:
	MaterialCtrlDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~MaterialCtrlDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MaterialCtrlDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_ShowCompoentNeed;
	CStatic m_ShowCompoentStatus;
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowStationName;
	CButton m_BtnSure;
	CListCtrl m_ShowCompoentNeedList;
	CListCtrl m_ShowCompoentStatusList;
	CComboBox m_MType;
	CEdit m_EditMNo;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	afx_msg void OnDblClickCompoentNeedList(NMHDR* pNMHDR, LRESULT* pResult);
	int m_SelectedCompoentNeedIndex;
	afx_msg void OnMenuAddCompoentStatus();
	afx_msg void OnMenuDelCompoentStatus();
	CEdit m_ShowParentMType;
	CEdit m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	afx_msg void OnEnChangeEditMno();
};
