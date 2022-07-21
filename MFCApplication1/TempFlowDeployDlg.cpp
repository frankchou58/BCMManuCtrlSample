// TempFlowDeployDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "TempFlowDeployDlg.h"
#include "afxdialogex.h"
#include "AddFlowDeployDlg.h"
#include "LoginDlg.h"

// TempFlowDeployDlg 對話方塊

IMPLEMENT_DYNAMIC(TempFlowDeployDlg, CDialogEx)

TempFlowDeployDlg::TempFlowDeployDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TempFlowDeployDlg, pParent)
{

}

TempFlowDeployDlg::~TempFlowDeployDlg()
{
}

void TempFlowDeployDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_TEMP_DEPLOY_LIST, m_ShowTempDeployList);
	DDX_Control(pDX, IDC_COMBO_INDEX_TEMP_FLOW_DEPLOY, m_SelectIndexTempDeploy);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListTempFlowDeploy);
	DDX_Control(pDX, IDC_EDIT_TEMP_FLOW_DEPLOY_NAME, m_EditFlowDeployName);
	//  DDX_Control(pDX, IDC_STATIC_INDEX, m_ShowTempFlowDeployIndex);
	//  DDX_Control(pDX, IDC_EDIT1, m_ShowTempFlowDeployIndex);
	DDX_Control(pDX, IDC_EDIT1, m_ShowTempFlowDeployIndex);
}


BEGIN_MESSAGE_MAP(TempFlowDeployDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_INDEX_TEMP_FLOW_DEPLOY, &TempFlowDeployDlg::OnCbnSelchangeComboIndexTempFlowDeploy)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ADD_FLOW_DEPLOY, &TempFlowDeployDlg::OnAddFlowDeploy)
	//ON_BN_CLICKED(IDC_BUTTON1, &TempFlowDeployDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &TempFlowDeployDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_CHANGE_NAME, &TempFlowDeployDlg::OnBnClickedButtonChangeName)
	ON_COMMAND(ID_DEL_TEMP_FLOW_DEPLOY, &TempFlowDeployDlg::OnDelTempFlowDeploy)
END_MESSAGE_MAP()


// TempFlowDeployDlg 訊息處理常式

static CHAR Name[2][100] = { "新增",  "標準流程1" };

typedef struct FlowDeploy_Tag
{
	INT		FlowDeployIndex;
	CHAR	FlowDeployName[200];
	CHAR	CurrentStation[200];
	CHAR	NextStation[200];
}FlowDeploy_T, * PFlowDeploy_T;
static FlowDeploy_T FlowDeployList[] =
{
	{13, "標準流程1", "生管(28)", "SMD(15)"},
	{13, "標準流程1", "SMD(15)", "SMD半成品倉(23)"},
	{13, "標準流程1", "SMD半成品倉(23)", "SMD維修(34)"},
	{13, "標準流程1", "SMD維修(34)", "維修(8)"},
	{13, "標準流程1", "SMD半成品倉(23)", "外包(14)"},
	{13, "標準流程1", "SMD維修(34)", "SMD半成品倉(23)"},
	{13, "標準流程1", "維修(8)", "SMD半成品倉(23)"},
	{13, "標準流程1", "外包(14)", "DIP半成品倉(4)"},
	{13, "標準流程1", "DIP半成品倉(4)", "測試燒MAC(3)"},
	{13, "標準流程1", "測試燒MAC(3)", "FT1(36)"},
	{13, "標準流程1", "FT1(36)", "維修(8)"},
	{13, "標準流程1", "維修(8)", "測試燒MAC(3)"},
	{13, "標準流程1", "FT1(36)", "待包裝倉(16)"},
	{13, "標準流程1", "待包裝倉(16)", "包裝(5)"},
	{13, "標準流程1", "包裝(5)", "成品倉(6)"},
};


BOOL TempFlowDeployDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
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
	m_ShowTempDeployList.SetFont(m_MessageFont, 1);

	for (int i = 0; i < 2; i++)
	{
		m_SelectIndexTempDeploy.AddString(Name[i]);
	}

	m_SelectIndexTempDeploy.SetCurSel(0);
	m_EditFlowDeployName.EnableWindow(TRUE);

	ListView_SetExtendedListViewStyle(m_ListTempFlowDeploy.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ListTempFlowDeploy.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListTempFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_INDEX, "樣板流程部屬索引碼", LVCFMT_CENTER);
	m_ListTempFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_NAME, "樣板流程部屬名稱", LVCFMT_CENTER);
	m_ListTempFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, "目前站台名稱", LVCFMT_LEFT);
	m_ListTempFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, "下一個站台名稱", LVCFMT_LEFT);

	m_ListTempFlowDeploy.SetColumnWidth(ID_LIST_ID, 50);
	m_ListTempFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_INDEX, 200);
	m_ListTempFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_NAME, 200);
	m_ListTempFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, 200);
	m_ListTempFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, 200);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}

void TempFlowDeployDlg::OnCbnSelchangeComboIndexTempFlowDeploy()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int SelectedIndex = m_SelectIndexTempDeploy.GetCurSel();
	m_ShowTempFlowDeployIndex.SetWindowTextA("14");
	if (SelectedIndex != 0)
	{
		m_EditFlowDeployName.SetWindowTextA("標準流程1");
		m_ShowTempFlowDeployIndex.SetWindowTextA("13");
		m_ListTempFlowDeploy.DeleteAllItems();
		LVITEM	lvI;
		lvI.mask = LVIF_TEXT;
		int ListIndex = 0;
		CHAR StrBuff[2000];
		PFlowDeploy_T pFlowDeploy;
		int Number = sizeof(FlowDeployList) / sizeof(FlowDeploy_T);
		for (int i = 0; i < Number; i++)
		{
			pFlowDeploy = &FlowDeployList[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ListTempFlowDeploy.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 200, "%d", pFlowDeploy->FlowDeployIndex);
			m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_INDEX, StrBuff);
			sprintf_s(StrBuff, 200, pFlowDeploy->FlowDeployName);
			m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NAME, StrBuff);
			strcpy_s(StrBuff, 2000, pFlowDeploy->CurrentStation);
			m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, StrBuff);
			strcpy_s(StrBuff, 2000, pFlowDeploy->NextStation);
			m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, StrBuff);

			ListIndex++;
		}
	}
	else
	{
		m_EditFlowDeployName.SetWindowTextA("");
		m_ShowTempFlowDeployIndex.SetWindowTextA("");
		m_ListTempFlowDeploy.DeleteAllItems();
	}
}


void TempFlowDeployDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListTempFlowDeploy.GetWindowRect(Rect);
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
	m_nItemIdx = m_ListTempFlowDeploy.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListTempFlowDeploy.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_DEL_TEMP_FLOW_DEPLOY);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		CString TempFlowDeployName;
		m_EditFlowDeployName.GetWindowTextA(TempFlowDeployName);
		if (TempFlowDeployName.GetLength() > 0)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_FLOW_DEPLOY);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}

}


void TempFlowDeployDlg::OnAddFlowDeploy()
{
	// TODO: 在此加入您的命令處理常式程式碼
	AddFlowDeployDlg AddFlowDeployDlg;
	AddFlowDeployDlg.DoModal();
}

#include "AddCompoentStatusDlg.h"
//void TempFlowDeployDlg::OnBnClickedButton1()
//{
//	// TODO: 在此加入控制項告知處理常式程式碼
//	AddCompoentStatusDlg AddCompoentStatusDlg;
//	AddCompoentStatusDlg.DoModal();
//}


void TempFlowDeployDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}


void TempFlowDeployDlg::OnBnClickedButtonChangeName()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int Count = m_SelectIndexTempDeploy.GetCount();
	for(int i = 0; i < Count; i++)
		m_SelectIndexTempDeploy.DeleteString(0);

	CString DeployName;
	m_EditFlowDeployName.GetWindowTextA(DeployName);
	strcpy_s(Name[1], 100, DeployName.GetBuffer());
	for (int i = 0; i < 2; i++)
	{
		m_SelectIndexTempDeploy.AddString(Name[i]);
	}

	m_SelectIndexTempDeploy.SetCurSel(1);
}


void TempFlowDeployDlg::OnDelTempFlowDeploy()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_ListTempFlowDeploy.DeleteAllItems();
	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = 0;
	CHAR StrBuff[2000];
	PFlowDeploy_T pFlowDeploy;
	int Number = sizeof(FlowDeployList) / sizeof(FlowDeploy_T);
	for (int i = 0; i < Number; i++)
	{
		if (i == 9 || i == 10 || i == 12)
			continue;
		pFlowDeploy = &FlowDeployList[i];
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ListTempFlowDeploy.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 200, "%d", pFlowDeploy->FlowDeployIndex);
		m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_INDEX, StrBuff);
		sprintf_s(StrBuff, 200, pFlowDeploy->FlowDeployName);
		m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NAME, StrBuff);
		strcpy_s(StrBuff, 2000, pFlowDeploy->CurrentStation);
		m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, StrBuff);
		strcpy_s(StrBuff, 2000, pFlowDeploy->NextStation);
		m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, StrBuff);

		ListIndex++;
	}
}


void TempFlowDeployDlg::OnBnClickedAddTempFlowDeploy()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = m_ListTempFlowDeploy.GetItemCount();
	CHAR StrBuff[2000];
	PFlowDeploy_T pFlowDeploy;
	pFlowDeploy = &FlowDeployList[0];

	lvI.iItem = ListIndex;
	lvI.iSubItem = 0;
	lvI.pszText = "1";
	lvI.cchTextMax = 60;
	m_ListTempFlowDeploy.InsertItem(&lvI);
	sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
	m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
	sprintf_s(StrBuff, 200, "%d", pFlowDeploy->FlowDeployIndex);
	m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_INDEX, StrBuff);
	sprintf_s(StrBuff, 200, pFlowDeploy->FlowDeployName);
	m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NAME, StrBuff);
	strcpy_s(StrBuff, 2000, "測試燒MAC(3)");
	m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, StrBuff);
	strcpy_s(StrBuff, 2000, "待包裝倉(16)");
	m_ListTempFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, StrBuff);
}
