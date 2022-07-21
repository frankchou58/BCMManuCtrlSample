#pragma once


// BusinessDlg 對話方塊
class BusinessDlg : public CDialogEx
{
	enum
	{
		ID_LIST_ID = 0,
		ID_LIST_SHIPPING_NO_DEF_INDEX,
		ID_LIST_SHIPPING_NO_DEF_NAME,
		ID_LIST_SHIPPING_NO_DEF_PREFIX,
		ID_LIST_SHIPPING_NO_DEF_FORMAT,
	};
	typedef struct ShippingNoDef_Tag
	{
		INT		ShippingNoDefIndex;
		CHAR	ShippingNoDefName[200];
		CHAR	ShippingNoDefPrefix[200];
		CHAR	ShippingNoDefFormat[200];
	}ShippingNoDef_T, * PShippingNoDef_T;


	DECLARE_DYNAMIC(BusinessDlg)

public:
	BusinessDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~BusinessDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BusinessDlg };
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
	CStatic m_ShowShippingNoDefineList;
	CListCtrl m_ListShippingNoDefine;
	CButton m_BtnSure;
	afx_msg void OnContextMenu(CWnd* /*pWnd*/, CPoint /*point*/);
	int m_nItemIdx;
	int m_uSelectedCount;
	CEdit m_EditCustomerName;
	CEdit m_EditPrefix;
	CEdit m_EditFormat;
	afx_msg void OnEditShippingNoDef();
	ShippingNoDef_T ShippingNoDefList[3];
	afx_msg void OnAddShippingNoDef();
	CStatic m_ShowShippingNoDefIndex;
};
