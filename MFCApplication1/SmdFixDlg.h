#pragma once


// SmdFixDlg 對話方塊

class SmdFixDlg : public CDialogEx
{
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
		ID_LIST_CTRL_M_TYPE,
		ID_LIST_CTRL_M_NO,
		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_I_NO,
	};
	DECLARE_DYNAMIC(SmdFixDlg)

public:
	SmdFixDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SmdFixDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SmdFixDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CButton m_BtnSure;
	CStatic m_ShowStationName;
//	CStatic m_ShowCtrlList;
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CButton m_RadioOne;
	CComboBox m_MType;
//	CListCtrl m_ListCtrlNo;
	afx_msg void OnEnChangeEditMno();
	CEdit m_EditMNo;
	CEdit m_ShowParentMType;
//	CStatic m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	CEdit m_ShowParentMNo;
	CEdit m_EditCtrlSN;
	afx_msg void OnEnChangeEditCtrlNo();
	CEdit m_ShowCtrlSNParentMType;
	CEdit m_ShowCtrlSNParentMNo;
//	CStatic m_ShowCtrlSNParentMDesc;
	CEdit m_ShowCtrlSNParentMDesc;
//	CEdit m_ShowListCtrlSNNumbers;
	CStatic m_ShowPrevCtrlNoListMsg;
//	CStatic m_TempShowCtrlNoListSignMsg;
	CStatic m_ShowCtrlNoListSignMsg;
	CStatic m_ShowThisCtrlNoListMsg;
	CListCtrl m_ShowPrevCtrlNoList;
	CListCtrl m_ShowThisCtrlNoList;
	int ShowCtrlNoList();
	CEdit m_ShowPrevCtrlNoNumbers;
	CEdit m_ShowThisCtrlNoNumbers;
};
