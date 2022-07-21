#pragma once


// SmdDlg 對話方塊

class SmdDlg : public CDialogEx
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
	DECLARE_DYNAMIC(SmdDlg)

public:
	SmdDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~SmdDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SmdDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
//	CButton m_BtnSure;
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CStatic m_ShowStationName;
	CComboBox m_MType;
//	CStatic m_ShowCtrlNo;
	CStatic m_ShowCtrlList;
	CListCtrl m_ListCtrlNo;
//	CButton m_RadioBatch;
//	CButton m_RadioOne;
	CButton m_RadioBatch;
	CEdit m_ShowListCtrlSNNumbers;
	afx_msg void OnEnChangeEditMno();
	CEdit m_ShowParentMType;
	CEdit m_ShowParentMNo;
	CEdit m_ShowParentMQty;
	CEdit m_ShowParentMDesc;
	CEdit m_EditMNo;
	CEdit m_EditCtrlSN;
	afx_msg void OnEnChangeEditCtrlNo();
	CEdit m_ShowCtrlSNParentMType;
	CEdit m_ShowCtrlSNParentMNo;
	CEdit m_ShowCtrlSNParentMDesc;
	CButton m_BtnSure;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
};
