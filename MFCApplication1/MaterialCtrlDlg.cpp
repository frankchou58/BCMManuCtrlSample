// MaterialCtrlDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "MaterialCtrlDlg.h"
#include "afxdialogex.h"
#include "AddCompoentStatusDlg.h"

// MaterialCtrlDlg 對話方塊

IMPLEMENT_DYNAMIC(MaterialCtrlDlg, CDialogEx)

MaterialCtrlDlg::MaterialCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MaterialCtrlDlg, pParent)
{

}

MaterialCtrlDlg::~MaterialCtrlDlg()
{
}

void MaterialCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SHOW_NEED_COMPOENT, m_CompoentNeed);
	DDX_Control(pDX, IDC_SHOW_NEED_COMPOENT, m_ShowCompoentNeed);
	DDX_Control(pDX, IDC_SHOW_COMPOENT_STATUS, m_ShowCompoentStatus);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowCompoentNeedList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO2, m_ShowCompoentStatusList);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT1, m_ShowParentMType);
	DDX_Control(pDX, IDC_EDIT2, m_ShowParentMNo);
	DDX_Control(pDX, IDC_EDIT11, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT12, m_ShowParentMDesc);
}


BEGIN_MESSAGE_MAP(MaterialCtrlDlg, CDialogEx)
	ON_WM_CONTEXTMENU()
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_CTRL_NO, OnDblClickCompoentNeedList)
	ON_COMMAND(ID_MENU_ADD_COMPOENT_STATUS, &MaterialCtrlDlg::OnMenuAddCompoentStatus)
	ON_COMMAND(ID_MENU_DEL_COMPOENT_STATUS, &MaterialCtrlDlg::OnMenuDelCompoentStatus)
	ON_EN_CHANGE(IDC_EDIT_MNO, &MaterialCtrlDlg::OnEnChangeEditMno)
END_MESSAGE_MAP()


// MaterialCtrlDlg 訊息處理常式


BOOL MaterialCtrlDlg::OnInitDialog()
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
	m_ShowCompoentNeed.SetFont(m_MessageFont, 1);
	m_ShowCompoentStatus.SetFont(m_MessageFont, 1);
	
	m_MType.SetCurSel(0);
	m_EditMNo.SetWindowTextA("");

	ListView_SetExtendedListViewStyle(m_ShowCompoentNeedList.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ShowCompoentNeedList.InsertColumn(ID_LIST_COMPOENT_NEED_ID, "編號", LVCFMT_CENTER);
	m_ShowCompoentNeedList.InsertColumn(ID_LIST_COMPOENT_NEED_TYPE, "替代料", LVCFMT_CENTER);
	m_ShowCompoentNeedList.InsertColumn(ID_LIST_COMPOENT_NEED_INO, "元件料號", LVCFMT_LEFT);
	m_ShowCompoentNeedList.InsertColumn(ID_LIST_COMPOENT_NEED_DESC, "元件品名", LVCFMT_LEFT);

	m_ShowCompoentNeedList.SetColumnWidth(ID_LIST_COMPOENT_NEED_ID, 50);
	m_ShowCompoentNeedList.SetColumnWidth(ID_LIST_COMPOENT_NEED_TYPE, 70);
	m_ShowCompoentNeedList.SetColumnWidth(ID_LIST_COMPOENT_NEED_INO, 100);
	m_ShowCompoentNeedList.SetColumnWidth(ID_LIST_COMPOENT_NEED_DESC, 500);

	ListView_SetExtendedListViewStyle(m_ShowCompoentStatusList.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_ID, "編號", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_M_TYPE, "製令別", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_M_NO, "製令號碼", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_M_INO, "製令料號", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_M_DESC, "製令品名", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_S_INO, "元件料號", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_S_DESC, "元件品名", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_DATE_CODE, "Date Code", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_DC_QTY, "DC QTY", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_LOT_NO, "Lot No", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_BIN_CODE, "BIN Code", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_CREATE_DATE, "建立日期", LVCFMT_CENTER);
	m_ShowCompoentStatusList.InsertColumn(ID_LIST_COMPOENT_STATUS_CREATE_ID, "建立者", LVCFMT_CENTER);	

	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_ID, 50);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_M_TYPE, 70);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_M_NO, 150);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_M_INO, 200);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_M_DESC, 300);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_S_INO, 200);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_S_DESC, 300);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_DATE_CODE, 100);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_DC_QTY, 150);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_LOT_NO, 300);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_BIN_CODE, 200);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_CREATE_DATE, 200);
	m_ShowCompoentStatusList.SetColumnWidth(ID_LIST_COMPOENT_STATUS_CREATE_ID, 100);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void MaterialCtrlDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ShowCompoentStatusList.GetWindowRect(Rect);
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
	m_nItemIdx = m_ShowCompoentStatusList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ShowCompoentStatusList.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_DEL_COMPOENT_STATUS);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
		m_PopMenuForMonitor.LoadMenu(IDR_MENU_ADD_COMPOENT_STATUS);
		pop = m_PopMenuForMonitor.GetSubMenu(0);
		pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
	}
}

void MaterialCtrlDlg::OnDblClickCompoentNeedList(NMHDR* pNMHDR, LRESULT* pResult)
{
	// get index of item that was double-clicked
	int Index = ((NM_LISTVIEW*)pNMHDR)->iItem;
	if (Index >= 0)
	{
		m_SelectedCompoentNeedIndex = Index;
	}
}

void MaterialCtrlDlg::OnMenuAddCompoentStatus()
{
	// TODO: 在此加入您的命令處理常式程式碼
	AddCompoentStatusDlg AddCompoentStatusDlg;
	AddCompoentStatusDlg.DoModal();
}


void MaterialCtrlDlg::OnMenuDelCompoentStatus()
{
	// TODO: 在此加入您的命令處理常式程式碼
	int Ret = MessageBox("確定刪除該筆資料?", "警告", MB_OKCANCEL | MB_ICONWARNING);
	if (Ret == 1)
	{
		/*確定刪除*/
	}
	else if (Ret == 2)
	{
		/*取消刪除*/
	}
}


void MaterialCtrlDlg::OnEnChangeEditMno()
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
		m_ShowParentMType.SetWindowTextA("P");
		m_ShowParentMNo.SetWindowTextA("220401012");
		m_ShowParentMDesc.SetWindowTextA("IR700B-WM2P V13G 20220330 SMD");
		m_ShowParentMQty.SetWindowTextA("660");

		typedef struct Compoents_Tag
		{
			BOOL bReplace;
			CHAR INo[100];
			CHAR IName[300];
		}Compoents_T, * PCompoents_T;
		PCompoents_T pCompoents;
		Compoents_T CompoentsData[] =
		{
			{false, "36110002310", "3A, DC-DC BUCK Converter, QFN-10 , LF"},
			{false, "36117005210", "giga ethernet controller, PCIe int RTL8111EPV-CG QFN 48P"},
			{false, "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF"},
			{false, "40071547502", "CAP CMC 4U7 6V3 X5R 20% 1005 LF"},
			{false, "72030079000", "IND POWER 2.2UH 9A5 7.3X6.8X3.0 SMD"},
			{false, "72030081000", "IND POWER 2.2UH, 2.35A,3.5X3X2 LF"},
			{false, "72030078000", "IND POWER 2.2U 12A 11.5X10.3 SMD LF"},
			{false, "72030080000", "IND POWER 4.7UH 1A5 3.5X3X2 SMD LF"},
			{false, "35108003804", "FLASH SPI EEPROM 8Mbit SOIC8-208 LF"},
			{false, "37102013200", "REGULATOR LINEAR 2A for DDR-SDRAM"},
			{false, "37102013301", "REGULATOR LINEAR , 3A , SOP-8P, LF"},
			{false, "37102013400", "IC BD50GA3WEFJ-E2 300mA 5V,HTSOP-J8"},
			{false, "37103001902", "IC 2N7002LT3G SOT-23 3P LF"},
			{false, "37103011401", "N-CH AP73T03GMT 30V/58A PMPAK5X6 LF"},
			{false, "37104004100", "P-CH CEZ3P08, -30V/-58A PMPAK5X6 LF"},
			{false, "37103012100", "IC CEN2306,3.6A,20V,100mΩ,SOT-23,L"},
			{false, "37103014000", "Dual N-ch power mos for hi-lo side"},
			{false, "37103014100", "Dual N-Ch MOS  30V/10A  RDS: 10m@V"},
			{false, "37104000510", "XTR NPN 2N3904 SOT-23 3P LF"},
			{false, "37104000600", "XTR PNP 2N3906 SOT-23 3P 200mA LF"},
			{false, "37106005900", "DIODE TVS WS05M2T 150PF  SOT-23 LF"},
			{false, "37106006400", "DIODE TVS TV06B150JB-G 15V DO-214AA"},
			{true, "35101002000", "IC SRAM 512KX16 3.3V,-55, FBGA-48"},
			{true, "36108010110", "IC Dual 1.5A over current protect , MSOP-8,LF "},
			{true, "36110002310", "3A, DC-DC BUCK Converter, QFN-10 , LF"},
			{true, "36110002300", "3A  Step down DC-DC converter Vin:"},

		};

		int Number = sizeof(CompoentsData) / sizeof(Compoents_T);
		LVITEM	lvI;
		lvI.mask = LVIF_TEXT;
		int ListIndex = 0;
		CHAR StrBuff[2000];
		for (int i = 0; i < Number; i++)
		{
			pCompoents = &CompoentsData[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ShowCompoentNeedList.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ShowCompoentNeedList.SetItemText(ListIndex, ID_LIST_COMPOENT_NEED_ID, StrBuff);
			sprintf_s(StrBuff, 2000, "");
			if (pCompoents->bReplace == TRUE)
				sprintf_s(StrBuff, 200, "是");
			m_ShowCompoentNeedList.SetItemText(ListIndex, ID_LIST_COMPOENT_NEED_TYPE, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoents->INo);
			m_ShowCompoentNeedList.SetItemText(ListIndex, ID_LIST_COMPOENT_NEED_INO, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoents->IName);
			m_ShowCompoentNeedList.SetItemText(ListIndex, ID_LIST_COMPOENT_NEED_DESC, StrBuff);

			ListIndex++;
		}


		typedef struct CompoentStatus_Tag
		{
			CHAR MType[10];
			CHAR MNo[100];
			CHAR MINo[50];
			CHAR MDesc[300];
			CHAR SINo[50];
			CHAR SDesc[300];
			CHAR DateCode[100];
			CHAR Date[100];
			CHAR LotNo[100];
			CHAR BINCode[100];
			CHAR DcQty[100];
			CHAR Creator[100];
		}CompoentStatus_T, * PCompoentStatus_T;

		PCompoentStatus_T pCompoentStatus;
		CompoentStatus_T CompoentStatusData[] =
		{
			{"M", "200727003", "2205000711", "VF3965U (75531) 1.1B SMD", "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF", "", "2020-07-29", "", "", "謝秋蜂"},
			{"M", "200702001", "2205000489", "BG670T 1.0C SMD", "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF", "1pgrm155r71e104ke14d", "2020-07-02", "3n2 10000 ia8319ct9n0o 108710", "", "謝秋蜂"},
			{"M", "200702001", "2205000489", "BG670T 1.0C SMD", "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF", "d/c 05/22/18", "2020-07-03", "pgrm155r71e104ke14d", "", "謝秋蜂"},
			{"M", "200701016", "2205000714", "PR-WHLU-4305UE (71721) 0.5A SMD", "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF", "", "2020-07-06", "", "", "謝秋蜂"},
			{"M", "200701016", "2205000714", "PR-WHLU-4305UE (71721) 0.5A SMD", "40065710402", "CAP CMC 0.1U 25V X7R 10% 1005 LF", "", "2020-07-06", "", "", "謝秋蜂"},
		};

		m_ShowCompoentStatusList.DeleteAllItems();
		lvI.mask = LVIF_TEXT;
		Number = sizeof(CompoentStatusData) / sizeof(CompoentStatus_T);
		ListIndex = 0;

		for (int i = 0; i < Number; i++)
		{
			pCompoentStatus = &CompoentStatusData[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ShowCompoentStatusList.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_ID, StrBuff);
			sprintf_s(StrBuff, 200, pCompoentStatus->MType);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_M_TYPE, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->MNo);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_M_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->MINo);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_M_INO, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->SDesc);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_M_DESC, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->SINo);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_S_INO, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->SDesc);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_S_DESC, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->DateCode);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_DATE_CODE, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->DcQty);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_DC_QTY, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->LotNo);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_LOT_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->BINCode);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_BIN_CODE, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->Date);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_CREATE_DATE, StrBuff);
			strcpy_s(StrBuff, 2000, pCompoentStatus->Creator);
			m_ShowCompoentStatusList.SetItemText(ListIndex, ID_LIST_COMPOENT_STATUS_CREATE_ID, StrBuff);

			ListIndex++;
		}
	}
}
