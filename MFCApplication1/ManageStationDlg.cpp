// ManageStationDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "ManageStationDlg.h"
#include "afxdialogex.h"


// ManageStationDlg 對話方塊

IMPLEMENT_DYNAMIC(ManageStationDlg, CDialogEx)

ManageStationDlg::ManageStationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ManageStationDlg, pParent)
{

}

ManageStationDlg::~ManageStationDlg()
{
}

void ManageStationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STATION, m_ListStation);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_TEMP_STATION, m_ShowStationMsg);
	DDX_Control(pDX, IDC_COMBO1, m_SelectStationId);
	DDX_Control(pDX, IDC_EDIT1, m_InputStationName);
	DDX_Control(pDX, IDC_RADIO1, m_SelectedBatch);
	DDX_Control(pDX, IDC_RADIO2, m_SelectedOne);
	DDX_Control(pDX, IDC_RADIO3, m_SelectedNormal);
	DDX_Control(pDX, IDC_RADIO4, m_SelectedException);
}


BEGIN_MESSAGE_MAP(ManageStationDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ManageStationDlg::OnBnClickedOk)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_STATION, &ManageStationDlg::OnEditStation)
	ON_COMMAND(ID_ADD_STATION, &ManageStationDlg::OnAddStation)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST_STATION, &ManageStationDlg::OnLButtonClkInListView)
END_MESSAGE_MAP()


// ManageStationDlg 訊息處理常式


BOOL ManageStationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
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
	m_ShowStationMsg.SetFont(m_MessageFont, 1);

	m_SelectStationId.EnableWindow(FALSE);
	m_InputStationName.EnableWindow(FALSE);
	m_SelectedBatch.EnableWindow(FALSE);
	m_SelectedOne.EnableWindow(FALSE);
	m_SelectedNormal.EnableWindow(FALSE);
	m_SelectedException.EnableWindow(FALSE);


	ListView_SetExtendedListViewStyle(m_ListStation.m_hWnd, LVS_EX_FULLROWSELECT/* | LVS_SHOWSELALWAYS*/);
	m_ListStation.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListStation.InsertColumn(ID_LIST_STATION_ID, "站台編號", LVCFMT_CENTER);
	m_ListStation.InsertColumn(ID_LIST_STATION_NAME, "站台名稱", LVCFMT_CENTER);
	m_ListStation.InsertColumn(ID_LIST_STATION_METHOD, "初始批量/單筆", LVCFMT_CENTER);
	m_ListStation.InsertColumn(ID_LIST_STATION_EXCEPTION, "類型", LVCFMT_CENTER);

	m_ListStation.SetColumnWidth(ID_LIST_ID, 50);
	m_ListStation.SetColumnWidth(ID_LIST_STATION_ID, 100);
	m_ListStation.SetColumnWidth(ID_LIST_STATION_NAME, 300);
	m_ListStation.SetColumnWidth(ID_LIST_STATION_METHOD, 150);
	m_ListStation.SetColumnWidth(ID_LIST_STATION_EXCEPTION, 150);

	PStationData_T pStationData = NULL;
	m_ListStation.DeleteAllItems();
	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = 0;
	CHAR StrBuff[2000];
	int Number = sizeof(g_StationData) / sizeof(StationData_T);
	for (int i = 0; i < Number; i++)
	{
		pStationData = &g_StationData[i];
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ListStation.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ListStation.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, "%d", pStationData->StationId);
		m_ListStation.SetItemText(ListIndex, ID_LIST_STATION_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pStationData->StationName);
		m_ListStation.SetItemText(ListIndex, ID_LIST_STATION_NAME, StrBuff);
		if(pStationData->bIsStationCtrlSnBatch)
			sprintf_s(StrBuff, 2000, "單筆");
		else
			sprintf_s(StrBuff, 2000, "批次");
		m_ListStation.SetItemText(ListIndex, ID_LIST_STATION_METHOD, StrBuff);
		if (pStationData->bIsStationException)
			sprintf_s(StrBuff, 2000, "例外站");
		else
			sprintf_s(StrBuff, 2000, "正常站");
		m_ListStation.SetItemText(ListIndex, ID_LIST_STATION_EXCEPTION, StrBuff);

		ListIndex++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void ManageStationDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}


void ManageStationDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListStation.GetWindowRect(Rect);
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
	m_nItemIdx = m_ListStation.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListStation.GetSelectedCount();
		if (m_uSelectedCount)
		{
			//m_PopMenuForMonitor.LoadMenu(IDR_MENU_EDIT_STATION);
			//pop = m_PopMenuForMonitor.GetSubMenu(0);
			//pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_STATION);
		pop = m_PopMenuForMonitor.GetSubMenu(0);
		pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}


void ManageStationDlg::OnEditStation()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_SelectStationId.EnableWindow(FALSE);
	m_InputStationName.EnableWindow(TRUE);
	m_SelectedBatch.EnableWindow(TRUE);
	m_SelectedOne.EnableWindow(TRUE);
	m_SelectedNormal.EnableWindow(TRUE);
	m_SelectedException.EnableWindow(TRUE);

	PStationData_T pStationData;
	pStationData = &g_StationData[m_nItemIdx];
	CHAR StrBuff[2000];
	sprintf_s(StrBuff, 2000, "%d", pStationData->StationId);
	m_SelectStationId.SetWindowTextA(StrBuff);
	m_InputStationName.SetWindowTextA(pStationData->StationName);
	if (pStationData->bIsStationCtrlSnBatch)
	{
		m_SelectedBatch.SetCheck(0);
		m_SelectedOne.SetCheck(1);
	}
	else
	{
		m_SelectedBatch.SetCheck(1);
		m_SelectedOne.SetCheck(0);
	}
	if (pStationData->bIsStationException)
	{
		m_SelectedException.SetCheck(1);
		m_SelectedNormal.SetCheck(0);
	}
	else
	{
		m_SelectedException.SetCheck(0);
		m_SelectedNormal.SetCheck(1);
	}
}


void ManageStationDlg::OnAddStation()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_SelectStationId.EnableWindow(TRUE);
	m_InputStationName.EnableWindow(TRUE);
	m_SelectedBatch.EnableWindow(TRUE);
	m_SelectedOne.EnableWindow(TRUE);
	m_SelectedNormal.EnableWindow(TRUE);
	m_SelectedException.EnableWindow(TRUE);
	m_InputStationName.SetWindowTextA("");

	int Index = 0;
	BOOL Found = FALSE;
	CHAR StrBuff[2000];
	PStationData_T pStationData = NULL;
	int Number = sizeof(g_StationData) / sizeof(StationData_T);
	for (int j = 50; j <= 200; j++)
	{
		Found = FALSE;
		for (int i = 0; i < Number; i++)
		{
			pStationData = &g_StationData[i];
			if (pStationData->StationId == j)
			{
				Found = TRUE;
				break;
			}
		}
		if(Found == FALSE)
		{
			sprintf_s(StrBuff, 2000, "%d", j);
			m_SelectStationId.AddString(StrBuff);
		}
		Index++;
	}
	m_SelectStationId.SetCurSel(0);
}

void ManageStationDlg::OnLButtonClkInListView(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pLVCD = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	m_nItemIdx = m_ListStation.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_SelectStationId.EnableWindow(FALSE);
		m_InputStationName.EnableWindow(TRUE);
		m_SelectedBatch.EnableWindow(TRUE);
		m_SelectedOne.EnableWindow(TRUE);
		m_SelectedNormal.EnableWindow(TRUE);
		m_SelectedException.EnableWindow(TRUE);

		PStationData_T pStationData;
		pStationData = &g_StationData[m_nItemIdx];
		CHAR StrBuff[2000];
		sprintf_s(StrBuff, 2000, "%d", pStationData->StationId);
		m_SelectStationId.SetWindowTextA(StrBuff);
		m_InputStationName.SetWindowTextA(pStationData->StationName);
		if (pStationData->bIsStationCtrlSnBatch)
		{
			m_SelectedBatch.SetCheck(0);
			m_SelectedOne.SetCheck(1);
		}
		else
		{
			m_SelectedBatch.SetCheck(1);
			m_SelectedOne.SetCheck(0);
		}
		if (pStationData->bIsStationException)
		{
			m_SelectedException.SetCheck(1);
			m_SelectedNormal.SetCheck(0);
		}
		else
		{
			m_SelectedException.SetCheck(0);
			m_SelectedNormal.SetCheck(1);
		}
	}
}
