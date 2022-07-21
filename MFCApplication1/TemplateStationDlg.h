#pragma once


// TemplateStationDlg 對話方塊

class TemplateStationDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TemplateStationDlg)
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_CTRL_NO,
		ID_LIST_CTRL_M_TYPE,
		ID_LIST_CTRL_M_NO,
		ID_LIST_CTRL_DESC,
		ID_LIST_CTRL_I_NO,
	};

public:
	TemplateStationDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~TemplateStationDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TemplateStationDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_TempShowStationName;
//	CComboBox m_TempMType;
	CComboBox m_TempSelectMType;
//	CEdit m_TempInputMNo;
	CEdit m_TempShowParentMType;
	CEdit m_TempShowParentMNo;
	CEdit m_TempShowParentMQty;
	CEdit m_TempShowParentMDesc;
	CEdit m_TempInputMNo;
	CEdit m_TempInputCtrlNo;
	CEdit m_TempShowCtrlNoMType;
	CEdit m_TempShowCtrlNoMNo;
	CEdit m_TempShowCtrlNoMDesc;
	CButton m_TempRadioBatch;
	CButton m_TempRadioOne;
	CEdit m_TempShowPrevCtrlNoNumbers;
	CEdit m_TempShowThisCtrlNoNumbers;
	CStatic m_TempShowPrevCtrlNoListMsg;
	CStatic m_TempShowThisCtrlNoListMsg;
	CStatic m_TempShowCtrlNoListSignMsg;
	CListCtrl m_TempShowPrevCtrlNoList;
	CListCtrl m_TempShowThisCtrlNoList;
	virtual BOOL OnInitDialog();
	int m_MessageFontHeight;
	int m_MessageFontWidth;
	CFont* m_MessageFont;
	int m_BtnFontHeight;
	int m_BtnFontWidth;
	CFont* m_BtnFont;
	CButton m_BtnSure;
	afx_msg void OnEnChangeEditMno();
	afx_msg void OnEnChangeEditCtrlNo();
	afx_msg void OnBnClickedOk();
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	int ShowCtrlNoList();
};

extern StationData_T g_StationData[20];
