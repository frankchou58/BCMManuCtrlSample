#pragma once
#include "InputMACAddrDlg.h"


// BurnMACDlg 對話方塊

class BurnMACDlg : public CDialogEx
{
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
//		ID_LIST_CTRL_M_TYPE,
//		ID_LIST_CTRL_M_NO,
//		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_MAC_1,
		ID_LIST_CTRL_MAC_BURNED_1,
	};
	DECLARE_DYNAMIC(BurnMACDlg)

public:
	BurnMACDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~BurnMACDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BurnMACDlg };
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
//	CButton m_BtnSure;
	CButton m_RadioBatch;
	CButton m_RadioOne;
//	CListCtrl m_ShowCtrlList;
	CComboBox m_MType;
	CEdit m_ShowParentMType;
//	CListCtrl m_ListCtrlNo;
//	CStatic m_ShowCtrlList;
	CEdit m_ShowMACNumber;
	afx_msg void OnEnChangeEditCtrlNo();
//	afx_msg void OnBnClickedOk();
	CEdit m_EditCtrlSN;
	afx_msg void OnEnChangeEditMno();
	CEdit m_EditMNo;
	CEdit m_ShowCtrlSNParentMType;
	CEdit m_ShowCtrlSNParentMNo;
	CEdit m_ShowCtrlSNParentMDesc;
	CEdit m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	CStatic m_ShowPrevCtrlNoListMsg;
	CStatic m_ShowCtrlNoListSignMsg;
	CStatic m_ShowThisCtrlNoListMsg;
	int ShowCtrlNoList();
	CEdit m_ShowThisCtrlNoNumbers;
	CEdit m_ShowPrevCtrlNoNumbers;
	CListCtrl m_ShowPrevCtrlNoList;
	CListCtrl m_ShowThisCtrlNoList;
	CHAR m_Mac1[100];
	CHAR m_Mac2[100];
	int PutMacAddress(PCHAR pMac1, PCHAR pMac2);
	afx_msg void OnBnClickedOk();
	int m_FoundIndex;
	int m_ListIndexInStation;
	CButton m_BtnSure;
	afx_msg void OnBnClickedButton1();
	InputMACAddrDlg m_InputMACAddrDlg;
	CStatic m_MessageBox;
	CStatic m_TitleMessageBox;
};
