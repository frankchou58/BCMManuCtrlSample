#pragma once


// MakeCtrlSnDlg 對話方塊

class MakeCtrlSnDlg : public CDialogEx
{
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
		ID_LIST_CTRL_PWA,
		ID_LIST_CTRL_PWB,
		ID_LIST_CTRL_BIOS_VER,
		ID_LIST_CTRL_FLOW_DEPLOY_INDEX,
		ID_LIST_CTRL_SHIPPING_NO_DEF_INDEX,
		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_I_NO,
	};
	DECLARE_DYNAMIC(MakeCtrlSnDlg)

public:
	MakeCtrlSnDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~MakeCtrlSnDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MakeCtrlSnDlg };
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
//	CButton m_BtnFont;
	CButton m_BtnSure;
	CStatic m_ShowStationName;
//	CListCtrl m_ShowCtrlList;
//	CListCtrl m_ShowCtrlSnList2;
	CStatic m_ShowCtrlList;
	CStatic m_ShowCtrlSnList2;
	CStatic m_ShowCtrlSnListMark;
	CListCtrl m_ListCtrlNo;
	CListCtrl m_ListCtrlNo2;
	CComboBox m_FlowDeployIndex;
	CComboBox m_ShippingNoIndex;
	CComboBox m_MType;
	CButton m_BatchCtrlSn;
	afx_msg void OnEnChangeEditMno();
	CEdit m_AllowCtrlSnListNumber;
	CEdit m_EditMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	CEdit m_ShowParentMINo;
	CEdit m_EditPWA;
	CEdit m_EditPWB;
	CEdit m_EditBIOSVer;
	afx_msg void OnBnClickedOk();
};
