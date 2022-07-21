// BusinessDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "BusinessDlg.h"
#include "afxdialogex.h"


// BusinessDlg 對話方塊

IMPLEMENT_DYNAMIC(BusinessDlg, CDialogEx)

BusinessDlg::BusinessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BusinessDlg, pParent)
{

}

BusinessDlg::~BusinessDlg()
{
}

void BusinessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDOK, m_BtnFont);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDC_SHOW_TEMP_DEPLOY_LIST, m_ShowShippingNoDefineList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListShippingNoDefine);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_EDIT1, m_EditCustomerName);
	DDX_Control(pDX, IDC_EDIT2, m_EditPrefix);
	DDX_Control(pDX, IDC_EDIT4, m_EditFormat);
	DDX_Control(pDX, IDC_STATIC_SHOW_DEF_NO, m_ShowShippingNoDefIndex);
}


BEGIN_MESSAGE_MAP(BusinessDlg, CDialogEx)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_SHIPPING_NO_DEF, &BusinessDlg::OnEditShippingNoDef)
	ON_COMMAND(ID_ADD_SHIPPING_NO_DEF, &BusinessDlg::OnAddShippingNoDef)
END_MESSAGE_MAP()


// BusinessDlg 訊息處理常式


BOOL BusinessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	CWnd* This = AfxGetMainWnd();
	This->SetWindowTextA("BCM生產履歷APP");

	LOGFONT lf;

	m_MessageFontHeight = 25;
	m_MessageFontWidth = m_MessageFontHeight * 0.5;
	m_MessageFont = new CFont();
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = m_MessageFontHeight;
	lf.lfWeight = 700;
	lf.lfWidth = m_MessageFontWidth;
	_tcscpy_s(lf.lfFaceName, "標楷體");
	m_MessageFont->CreateFontIndirect(&lf);

	m_BtnFontHeight = 100;
	m_BtnFontWidth = m_BtnFontHeight * 0.5;
	m_BtnFont = new CFont();
	memset(&lf, 0, sizeof(LOGFONT));
	lf.lfHeight = m_BtnFontHeight;
	lf.lfWeight = 700;
	lf.lfWidth = m_BtnFontWidth;
	_tcscpy_s(lf.lfFaceName, "標楷體");
	m_BtnFont->CreateFontIndirect(&lf);

	m_ShowStationName.SetFont(m_MessageFont, 1);
	m_BtnSure.SetFont(m_BtnFont, 1);
	m_ShowShippingNoDefineList.SetFont(m_MessageFont, 1);
	m_ShowShippingNoDefIndex.SetWindowTextA("");

	ListView_SetExtendedListViewStyle(m_ListShippingNoDefine.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ListShippingNoDefine.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListShippingNoDefine.InsertColumn(ID_LIST_SHIPPING_NO_DEF_INDEX, "索引碼", LVCFMT_CENTER);
	m_ListShippingNoDefine.InsertColumn(ID_LIST_SHIPPING_NO_DEF_NAME, "客戶名稱", LVCFMT_CENTER);
	m_ListShippingNoDefine.InsertColumn(ID_LIST_SHIPPING_NO_DEF_PREFIX, "前置碼", LVCFMT_LEFT);
	m_ListShippingNoDefine.InsertColumn(ID_LIST_SHIPPING_NO_DEF_FORMAT, "格式", LVCFMT_LEFT);

	m_ListShippingNoDefine.SetColumnWidth(ID_LIST_ID, 50);
	m_ListShippingNoDefine.SetColumnWidth(ID_LIST_SHIPPING_NO_DEF_INDEX, 200);
	m_ListShippingNoDefine.SetColumnWidth(ID_LIST_SHIPPING_NO_DEF_NAME, 200);
	m_ListShippingNoDefine.SetColumnWidth(ID_LIST_SHIPPING_NO_DEF_PREFIX, 200);
	m_ListShippingNoDefine.SetColumnWidth(ID_LIST_SHIPPING_NO_DEF_FORMAT, 300);

	ShippingNoDefList[0] = { 2, "安科", "ANCA", "{YY}Y{MM}{DD}{????}" };
	ShippingNoDefList[1] = { 3, "安勤", "AVA", "{YY}-{WW}{???}" };
	ShippingNoDefList[2] = { 6, "光寶", "LTC", "{YYYY}-{MM}-{DD}-{???}" };

	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = 0;
	CHAR StrBuff[2000];
	PShippingNoDef_T pShippingNoDef;
	int Number = sizeof(ShippingNoDefList) / sizeof(ShippingNoDef_T);
	for (int i = 0; i < Number; i++)
	{
		pShippingNoDef = &ShippingNoDefList[i];
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ListShippingNoDefine.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ListShippingNoDefine.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 200, "%d", pShippingNoDef->ShippingNoDefIndex);
		m_ListShippingNoDefine.SetItemText(ListIndex, ID_LIST_SHIPPING_NO_DEF_INDEX, StrBuff);
		sprintf_s(StrBuff, 200, pShippingNoDef->ShippingNoDefName);
		m_ListShippingNoDefine.SetItemText(ListIndex, ID_LIST_SHIPPING_NO_DEF_NAME, StrBuff);
		strcpy_s(StrBuff, 2000, pShippingNoDef->ShippingNoDefPrefix);
		m_ListShippingNoDefine.SetItemText(ListIndex, ID_LIST_SHIPPING_NO_DEF_PREFIX, StrBuff);
		strcpy_s(StrBuff, 2000, pShippingNoDef->ShippingNoDefFormat);
		m_ListShippingNoDefine.SetItemText(ListIndex, ID_LIST_SHIPPING_NO_DEF_FORMAT, StrBuff);

		ListIndex++;
	}


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void BusinessDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListShippingNoDefine.GetWindowRect(Rect);
	if (point.x < Rect.left || point.x > Rect.right)
	{
		return;
	}

	if (point.y < Rect.top || point.y > Rect.bottom)
	{
		return;
	}

	CMenu m_PopMenuForMonitor;
	CMenu* pop;
	m_nItemIdx = m_ListShippingNoDefine.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListShippingNoDefine.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_EDIT_SHIPPING_NO_DEF);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_SHIPPING_NO_DEF);
		pop = m_PopMenuForMonitor.GetSubMenu(0);
		pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}


void BusinessDlg::OnEditShippingNoDef()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_EditCustomerName.EnableWindow(TRUE);
	m_EditPrefix.EnableWindow(TRUE);
	m_EditFormat.EnableWindow(TRUE);
	CHAR Buff[100];

	PShippingNoDef_T pShippingNoDef = &ShippingNoDefList[m_nItemIdx];
	sprintf_s(Buff, 100, "%d", pShippingNoDef->ShippingNoDefIndex);
	m_ShowShippingNoDefIndex.SetWindowTextA(Buff);
	m_EditCustomerName.SetWindowTextA(pShippingNoDef->ShippingNoDefName);
	m_EditPrefix.SetWindowTextA(pShippingNoDef->ShippingNoDefPrefix);
	m_EditFormat.SetWindowTextA(pShippingNoDef->ShippingNoDefFormat);
}


void BusinessDlg::OnAddShippingNoDef()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_EditCustomerName.EnableWindow(TRUE);
	m_EditPrefix.EnableWindow(TRUE);
	m_EditFormat.EnableWindow(TRUE);
	m_ShowShippingNoDefIndex.SetWindowTextA("");
	m_EditCustomerName.SetWindowTextA("");
	m_EditPrefix.SetWindowTextA("");
	m_EditFormat.SetWindowTextA("");
}
