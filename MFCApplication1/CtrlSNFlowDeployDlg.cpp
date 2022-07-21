// CtrlSNFlowDeployDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CtrlSNFlowDeployDlg.h"
#include "afxdialogex.h"
#include "AddFlowDeployDlg.h"

// CtrlSNFlowDeployDlg 對話方塊

IMPLEMENT_DYNAMIC(CtrlSNFlowDeployDlg, CDialogEx)

CtrlSNFlowDeployDlg::CtrlSNFlowDeployDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CtrlSNFlowDeployDlg, pParent)
{

}

CtrlSNFlowDeployDlg::~CtrlSNFlowDeployDlg()
{
}

void CtrlSNFlowDeployDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDOK, m_BtnSure);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowCtrlSnDeployList);
	//  DDX_Control(pDX, IDC_SHOW_TEMP_DEPLOY_LIST, m_ShowCtrlSnDeployList);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlSnFlowDeploy);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlSnFlowDeploy);
	DDX_Control(pDX, IDC_SHOW_TEMP_DEPLOY_LIST, m_ShowCtrlSnDeployList);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_EDIT6, m_ShowCtrlSnFlowDeployIndex);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT2, m_ShowParentMType);
	DDX_Control(pDX, IDC_EDIT3, m_ShowParentMNo);
	DDX_Control(pDX, IDC_EDIT10, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT11, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_EDIT_TEMP_FLOW_DEPLOY_NAME, m_ShowCtrlSnFlowDeployName);
}


BEGIN_MESSAGE_MAP(CtrlSNFlowDeployDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CtrlSNFlowDeployDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_MNO, &CtrlSNFlowDeployDlg::OnEnChangeEditMno)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_ADD_CTRLSN_FLOW_DEPLOY, &CtrlSNFlowDeployDlg::OnAddCtrlsnFlowDeploy)
END_MESSAGE_MAP()


// CtrlSNFlowDeployDlg 訊息處理常式
typedef struct FlowDeploy_Tag
{
	CHAR 	FlowDeployIndex[100];
	CHAR	FlowDeployName[200];
	CHAR	CurrentStation[200];
	CHAR	NextStation[200];
}FlowDeploy_T, * PFlowDeploy_T;
static FlowDeploy_T FlowDeployList[] =
{
	{"M210913003", "標準流程1", "生管(28)", "SMD(15)"},
	{"M210913003", "標準流程1", "SMD(15)", "SMD半成品倉(23)"},
	{"M210913003", "標準流程1", "SMD半成品倉(23)", "SMD維修(34)"},
	{"M210913003", "標準流程1", "SMD維修(34)", "維修(8)"},
	{"M210913003", "標準流程1", "SMD半成品倉(23)", "外包(14)"},
	{"M210913003", "標準流程1", "SMD維修(34)", "SMD半成品倉(23)"},
	{"M210913003", "標準流程1", "維修(8)", "SMD半成品倉(23)"},
	{"M210913003", "標準流程1", "外包(14)", "DIP半成品倉(4)"},
	{"M210913003", "標準流程1", "DIP半成品倉(4)", "測試燒MAC(3)"},
	{"M210913003", "標準流程1", "測試燒MAC(3)", "FT1(36)"},
	{"M210913003", "標準流程1", "FT1(36)", "維修(8)"},
	{"M210913003", "標準流程1", "維修(8)", "測試燒MAC(3)"},
	{"M210913003", "標準流程1", "FT1(36)", "待包裝倉(16)"},
	{"M210913003", "標準流程1", "待包裝倉(16)", "包裝(5)"},
	{"M210913003", "標準流程1", "包裝(5)", "成品倉(6)"},
};



BOOL CtrlSNFlowDeployDlg::OnInitDialog()
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
	m_ShowCtrlSnDeployList.SetFont(m_MessageFont, 1);
	m_MType.SetCurSel(0);

	//for (int i = 0; i < 2; i++)
	//{
	//	m_SelectIndexTempDeploy.AddString(Name[i]);
	//}

	//m_SelectIndexTempDeploy.SetCurSel(0);
	//m_EditFlowDeployName.EnableWindow(TRUE);

	ListView_SetExtendedListViewStyle(m_ListCtrlSnFlowDeploy.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ListCtrlSnFlowDeploy.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListCtrlSnFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_INDEX, "內控流程部屬索引碼", LVCFMT_CENTER);
	m_ListCtrlSnFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_NAME, "內控流程部屬名稱", LVCFMT_CENTER);
	m_ListCtrlSnFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, "目前站台名稱", LVCFMT_LEFT);
	m_ListCtrlSnFlowDeploy.InsertColumn(ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, "下一個站台名稱", LVCFMT_LEFT);

	m_ListCtrlSnFlowDeploy.SetColumnWidth(ID_LIST_ID, 50);
	m_ListCtrlSnFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_INDEX, 200);
	m_ListCtrlSnFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_NAME, 200);
	m_ListCtrlSnFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, 200);
	m_ListCtrlSnFlowDeploy.SetColumnWidth(ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, 200);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void CtrlSNFlowDeployDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}


void CtrlSNFlowDeployDlg::OnEnChangeEditMno()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString MNo;
	m_EditMNo.GetWindowTextA(MNo);
	int Len = MNo.GetLength();
	if (Len == 9)
	{
		m_ShowParentMType.SetWindowTextA("M");
		m_ShowParentMNo.SetWindowTextA("210913003");
		m_ShowParentMQty.SetWindowTextA("32");
		m_ShowParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
		m_ShowCtrlSnFlowDeployIndex.SetWindowTextA("M210913003");
		m_ShowCtrlSnFlowDeployName.SetWindowTextA("標準流程1");

		PCtrlSNList_T pCtrlSNList;

		m_ListCtrlSnFlowDeploy.DeleteAllItems();
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
			m_ListCtrlSnFlowDeploy.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ListCtrlSnFlowDeploy.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 200, pFlowDeploy->FlowDeployIndex);
			m_ListCtrlSnFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_INDEX, StrBuff);
			sprintf_s(StrBuff, 200, pFlowDeploy->FlowDeployName);
			m_ListCtrlSnFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NAME, StrBuff);
			strcpy_s(StrBuff, 2000, pFlowDeploy->CurrentStation);
			m_ListCtrlSnFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_CURRENT_STATION_NAME, StrBuff);
			strcpy_s(StrBuff, 2000, pFlowDeploy->NextStation);
			m_ListCtrlSnFlowDeploy.SetItemText(ListIndex, ID_LIST_FLOW_DEPLOY_NEXT_STATION_NAME, StrBuff);

			ListIndex++;
		}
	}
}


void CtrlSNFlowDeployDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListCtrlSnFlowDeploy.GetWindowRect(Rect);
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
	m_nItemIdx = m_ListCtrlSnFlowDeploy.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListCtrlSnFlowDeploy.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_DEL_TEMP_FLOW_DEPLOY);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		CString MNo;
		m_EditMNo.GetWindowTextA(MNo);
		if (MNo.GetLength() == 9)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_CTRLSN_FLOW_DEPLOY);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
}


void CtrlSNFlowDeployDlg::OnAddCtrlsnFlowDeploy()
{
	// TODO: 在此加入您的命令處理常式程式碼
	AddFlowDeployDlg AddFlowDeployDlg;
	AddFlowDeployDlg.DoModal();
}
