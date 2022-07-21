// ManageErrorCodeDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "ManageErrorCodeDlg.h"
#include "afxdialogex.h"


// ManageErrorCodeDlg 對話方塊

IMPLEMENT_DYNAMIC(ManageErrorCodeDlg, CDialogEx)

ManageErrorCodeDlg::ManageErrorCodeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ManageErrorCodeDlg, pParent)
{

}

ManageErrorCodeDlg::~ManageErrorCodeDlg()
{
}

void ManageErrorCodeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_TEMP_STATION, m_ShowStationMsg);
	//  DDX_Control(pDX, IDC_EDIT2, m_InputQID);
	DDX_Control(pDX, IDC_EDIT1, m_InputQDescEng);
	DDX_Control(pDX, IDC_EDIT4, m_InputQDescChn);
	DDX_Control(pDX, IDC_LIST_STATION, m_ListErrorCode);
	DDX_Control(pDX, IDC_COMBO1, m_InputQID);
}


BEGIN_MESSAGE_MAP(ManageErrorCodeDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ManageErrorCodeDlg::OnBnClickedOk)
	ON_WM_CONTEXTMENU()
	ON_COMMAND(ID_EDIT_ERROR_CODE, &ManageErrorCodeDlg::OnEditErrorCode)
	ON_COMMAND(ID_ADD_ERROR_CODE, &ManageErrorCodeDlg::OnAddErrorCode)
//	ON_WM_LBUTTONDBLCLK()
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST_STATION, &ManageErrorCodeDlg::OnLButtonClkInListView)
//	ON_NOTIFY(NM_CLICK, IDC_LIST_STATION, &ManageErrorCodeDlg::OnNMClickListStation)
END_MESSAGE_MAP()


// ManageErrorCodeDlg 訊息處理常式


void ManageErrorCodeDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}

ErrorCode_T g_ErrorCodeData[8] =
{
	{1, "88/FF", "88/FF"},
	{2, "No Boot", "不開機"},
	{3, "Short Circuited", "線路短路"},
	{4, "No Power", "無電源"},
	{5, "Auto Power On After Power Off", "關機後自動開機"},
	{6, "Video Resolution", "畫面解析度"},
	{7, "No Video", "無畫面"},
	{8, "No Audio", "無聲音"},
};

BOOL ManageErrorCodeDlg::OnInitDialog()
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
	m_ShowStationMsg.SetFont(m_MessageFont, 1);

	m_InputQID.EnableWindow(FALSE);
	m_InputQDescEng.EnableWindow(FALSE);
	m_InputQDescChn.EnableWindow(FALSE);

	ListView_SetExtendedListViewStyle(m_ListErrorCode.m_hWnd, LVS_EX_FULLROWSELECT | WS_CHILD);
	m_ListErrorCode.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListErrorCode.InsertColumn(ID_LIST_ERROR_QID, "錯誤代碼", LVCFMT_CENTER);
	m_ListErrorCode.InsertColumn(ID_LIST_ERROR_DESC_ENG, "錯誤代碼英文描述", LVCFMT_LEFT);
	m_ListErrorCode.InsertColumn(ID_LIST_ERROR_DESC_CHN, "錯誤代碼中文描述", LVCFMT_LEFT);

	m_ListErrorCode.SetColumnWidth(ID_LIST_ID, 50);
	m_ListErrorCode.SetColumnWidth(ID_LIST_ERROR_QID, 100);
	m_ListErrorCode.SetColumnWidth(ID_LIST_ERROR_DESC_ENG, 400);
	m_ListErrorCode.SetColumnWidth(ID_LIST_ERROR_DESC_CHN, 400);

	PErrorCode_T pErrorCode;
	m_ListErrorCode.DeleteAllItems();
	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = 0;
	CHAR StrBuff[2000];
	int Number = sizeof(g_ErrorCodeData) / sizeof(ErrorCode_T);
	for (int i = 0; i < Number; i++)
	{
		pErrorCode = &g_ErrorCodeData[i];
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ListErrorCode.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ListErrorCode.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, "%03d", pErrorCode->QID);
		m_ListErrorCode.SetItemText(ListIndex, ID_LIST_ERROR_QID, StrBuff);
		sprintf_s(StrBuff, 2000, pErrorCode->QDescEng);
		m_ListErrorCode.SetItemText(ListIndex, ID_LIST_ERROR_DESC_ENG, StrBuff);
		sprintf_s(StrBuff, 2000, pErrorCode->QDescChn);
		m_ListErrorCode.SetItemText(ListIndex, ID_LIST_ERROR_DESC_CHN, StrBuff);

		ListIndex++;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void ManageErrorCodeDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListErrorCode.GetWindowRect(Rect);
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
	m_nItemIdx = m_ListErrorCode.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListErrorCode.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_PRINT_ERROR_CODE);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_ERROR_CODE);
		pop = m_PopMenuForMonitor.GetSubMenu(0);
		pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}


void ManageErrorCodeDlg::OnEditErrorCode()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_InputQID.EnableWindow(FALSE);
	m_InputQDescEng.EnableWindow(TRUE);
	m_InputQDescChn.EnableWindow(TRUE);

	CHAR StrBuff[2000];
	sprintf_s(StrBuff, 2000, "%03d", g_ErrorCodeData[m_nItemIdx].QID);
	m_InputQID.SetWindowTextA(StrBuff);
	sprintf_s(StrBuff, 2000, "%s", g_ErrorCodeData[m_nItemIdx].QDescEng);
	m_InputQDescEng.SetWindowTextA(StrBuff);
	sprintf_s(StrBuff, 2000, "%s", g_ErrorCodeData[m_nItemIdx].QDescChn);
	m_InputQDescChn.SetWindowTextA(StrBuff);
}


void ManageErrorCodeDlg::OnAddErrorCode()
{
	// TODO: 在此加入您的命令處理常式程式碼
	m_InputQID.EnableWindow(TRUE);
	m_InputQDescEng.EnableWindow(TRUE);
	m_InputQDescChn.EnableWindow(TRUE);
	m_InputQDescEng.SetWindowTextA("");
	m_InputQDescChn.SetWindowTextA("");

	BOOL Found;
	PErrorCode_T pErrorCode;
	int Number = sizeof(g_ErrorCodeData) / sizeof(ErrorCode_T);
	for (int j = 1; j < 1000; j++)
	{
		Found = FALSE;
		for (int i = 0; i < Number; i++)
		{
			pErrorCode = &g_ErrorCodeData[i];
			if (j == pErrorCode->QID)
			{
				Found = TRUE;
				break;
			}
		}
		if (Found == FALSE)
		{
			CHAR StrBuff[2000];
			sprintf_s(StrBuff, 2000, "%03d", j);
			m_InputQID.AddString(StrBuff);
		}
	}
	m_InputQID.SetCurSel(0);
}


void ManageErrorCodeDlg::OnLButtonClkInListView(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	LPNMLISTVIEW pLVCD = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	m_nItemIdx = m_ListErrorCode.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_InputQID.EnableWindow(FALSE);
		m_InputQDescEng.EnableWindow(TRUE);
		m_InputQDescChn.EnableWindow(TRUE);

		CHAR StrBuff[2000];
		sprintf_s(StrBuff, 2000, "%03d", g_ErrorCodeData[m_nItemIdx].QID);
		m_InputQID.SetWindowTextA(StrBuff);
		sprintf_s(StrBuff, 2000, "%s", g_ErrorCodeData[m_nItemIdx].QDescEng);
		m_InputQDescEng.SetWindowTextA(StrBuff);
		sprintf_s(StrBuff, 2000, "%s", g_ErrorCodeData[m_nItemIdx].QDescChn);
		m_InputQDescChn.SetWindowTextA(StrBuff);
	}
}


//void ManageErrorCodeDlg::OnNMClickListStation(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	// TODO: 在此加入控制項告知處理常式程式碼
//	*pResult = 0;
//}
