#pragma once
#include "MakeCtrlSnDlg.h"
#include "EditCtrlSnDlg.h"

// ProductionCtrlDlg 對話方塊

class ProductionCtrlDlg : public CDialogEx
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
	DECLARE_DYNAMIC(ProductionCtrlDlg)

public:
	ProductionCtrlDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~ProductionCtrlDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ProductionCtrlDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
//	int m_MessageFontHeight;
//	int m_MessageFontWidth;
//	CFont* m_MessageFont;
//	int m_BtnFontHeight;
//	int m_BtnFontWidth;
//	CFont* m_BtnFont;
//	CComboBox m_MType;
//	CComboBox m_FlowDeployIndex;
//	CComboBox m_ShippingNoIndex;
//	CButton m_BtnSure;
//	CStatic m_ShowStationName;
//	CStatic m_ShowCtrlList;
//	CListCtrl m_ListCtrlNo;
//	CEdit m_EditMNo;
//	afx_msg void OnEnChangeEditMno();
//	CEdit m_ShowParentMQty;
//	CEdit m_ShowParentMDesc;
//	CEdit m_ShowParentMINo;
//	CEdit m_EditPWA;
//	CEdit m_EditPWB;
//	CEdit m_EditBIOSVer;
//	CStatic m_ShowCtrlSnListMark;
//	CStatic m_ShowCtrlSnList2;
//	CListCtrl m_ListCtrlNo2;
//	CButton m_BatchCtrlSn;
//	CEdit m_AllowCtrlSnListNumber;
	afx_msg void OnCbnSelchangeCombo1();
	MakeCtrlSnDlg m_CtrlSNMakeDlg;
	EditCtrlSnDlg m_CtrlSNEditDlg;
	CWnd* m_pWndModleDlg[6];
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
//	CTabCtrl m_TabCtrl;
	CTabCtrl m_TabCtrl;
};

enum MyEnum
{
	CTRL_ID_CTRL_SN_MAKE_DLG = 0,
	CTRL_ID_CTRL_SN_EDIT_DLG,
};

