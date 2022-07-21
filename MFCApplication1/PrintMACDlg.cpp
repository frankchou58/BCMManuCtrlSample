// PrintMACDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "PrintMACDlg.h"
#include "afxdialogex.h"
#include "AddCustomerMACDlg.h"

// PrintMACDlg 對話方塊

IMPLEMENT_DYNAMIC(PrintMACDlg, CDialogEx)

PrintMACDlg::PrintMACDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PrintMACDlg, pParent)
{

}

PrintMACDlg::~PrintMACDlg()
{
}

void PrintMACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CUSTOMER_MAC, m_SelectCustomerMAC);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_RADIO_BATCH, m_RadioBatch);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_EDIT_M_TYPE, m_ShowParentMType);
	DDX_Control(pDX, IDC_COMBO_MACS_PER_ONE, m_SelectMACsPerOne);
	DDX_Control(pDX, IDC_BUTTON_REPRINT, m_BtnRePrintMAC);
	//  DDX_Control(pDX, IDC_SHOW_LAST_MAC, m_ShowLastMAC);
	DDX_Control(pDX, IDC_EDIT_M_TYPE2, m_CtrlSNMtype);
	DDX_Control(pDX, IDC_SHOW_PARENT_MNO3, m_ShowParentMNo);
	DDX_Control(pDX, IDC_SHOW_PARENT_MQTY, m_ShowParentMQty);
	DDX_Control(pDX, IDC_SHOW_PARENT_MNO4, m_CtrlSNParentMSN);
	//  DDX_Control(pDX, IDC_EDIT6, m_ShowMDesc);
	DDX_Control(pDX, IDC_EDIT7, m_CtrlSNParentMDesc);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT6, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_EditCtrlSN);
	DDX_Control(pDX, IDC_EDIT17, m_ShowListCtrlSNNumbers);
	//  DDX_Control(pDX, IDCANCEL, m_TitleLastMAC);
	DDX_Control(pDX, IDC_STATIC_SHOW_TITLE_LAST_MAC, m_TitleLastMAC);
	DDX_Control(pDX, IDC_SHOW_LAST_MAC, m_ShowLastMAC);
	DDX_Control(pDX, IDC_EDIT_END_MAC, m_InputEndMAC);
	DDX_Control(pDX, IDC_EDIT_START_MAC, m_InputStartMAC);
	DDX_Control(pDX, IDC_STATIC_MARK, m_TitleMark);
	DDX_Control(pDX, IDC_STATIC_TITLE_MAC_RANGE, m_TitleMACRange);
}


BEGIN_MESSAGE_MAP(PrintMACDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_MACS_PER_ONE, &PrintMACDlg::OnCbnSelchangeComboMacsPerOne)
	ON_BN_CLICKED(IDOK, &PrintMACDlg::OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO_CUSTOMER_MAC, &PrintMACDlg::OnCbnSelchangeComboCustomerMac)
	ON_WM_CONTEXTMENU()
	ON_EN_CHANGE(IDC_EDIT_MNO, &PrintMACDlg::OnEnChangeEditMno)
	ON_EN_CHANGE(IDC_EDIT_START_MAC, &PrintMACDlg::OnEnChangeEditStartMac)
	ON_EN_CHANGE(IDC_EDIT_END_MAC, &PrintMACDlg::OnEnChangeEditEndMac)
END_MESSAGE_MAP()


// PrintMACDlg 訊息處理常式

static CtrlSNList_T CtrlSNList[] =
{
	{"IBCM20059546515", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032AB", TRUE},
	{"IBCM20059546516", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032AC", TRUE},
	{"IBCM20059546517", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032AD", TRUE},
	{"IBCM20059546518", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032AE", TRUE},
	{"IBCM20059546519", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032AD", TRUE},
	{"IBCM20059546520", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B0", TRUE},
	{"IBCM20059546521", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B1", TRUE},
	{"IBCM20059546522", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B2", TRUE},
	{"IBCM20059546523", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B3", TRUE},
	{"IBCM20059546524", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B4", TRUE},
	{"IBCM20059546525", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B5", TRUE},
	{"IBCM20059546526", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B6", TRUE},
	{"IBCM20059546527", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B7", TRUE},
	{"IBCM20059546528", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B8", TRUE},
	{"IBCM20059546529", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032B9", TRUE},
	{"IBCM20059546530", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BA", TRUE},
	{"IBCM20059546531", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BB", TRUE},
	{"IBCM20059546532", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BC", TRUE},
	{"IBCM20059546533", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BD", TRUE},
	{"IBCM20059546534", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BE", TRUE},
	{"IBCM20059546535", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032BF", TRUE},
	{"IBCM20059546536", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C0", TRUE},
	{"IBCM20059546537", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C1", TRUE},
	{"IBCM20059546538", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C2", TRUE},
	{"IBCM20059546539", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C3", TRUE},
	{"IBCM20059546540", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C4", TRUE},
	{"IBCM20059546541", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C5", TRUE},
	{"IBCM20059546542", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C6", TRUE},
	{"IBCM20059546543", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C7", TRUE},
	{"IBCM20059546544", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C8", TRUE},
	{"IBCM20059546545", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032C9", TRUE},
	{"IBCM20059546546", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324", "00026B0032CA", TRUE},
};


BOOL PrintMACDlg::OnInitDialog()
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

	m_BtnFontHeight = 50;
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
	m_BtnRePrintMAC.SetFont(m_BtnFont, 1);
	m_ShowCtrlList.SetFont(m_MessageFont, 1);

	m_TitleLastMAC.ShowWindow(FALSE);
	m_ShowLastMAC.ShowWindow(FALSE);

	m_RadioBatch.SetCheck(1);
	m_MType.SetCurSel(0);
	m_SelectCustomerMAC.SetCurSel(0);
	m_ShowParentMType.SetWindowTextA("M");
	CHAR Buff[100];

	for (int i = 1; i <= 5; i++)
	{
		sprintf_s(Buff, 100, "%d", i);
		m_SelectMACsPerOne.AddString(Buff);
	}
	m_SelectMACsPerOne.SetCurSel(0);

	ListView_SetExtendedListViewStyle(m_ListCtrlNo.m_hWnd, LVS_EX_FULLROWSELECT);
	m_ListCtrlNo.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_TYPE, "母製令別", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_NO, "母製令號碼", LVCFMT_LEFT);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_LEFT);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_I_NO, "料號", LVCFMT_LEFT);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_MAC_1, "MAC1", LVCFMT_LEFT);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_MAC_OUT_1, "MAC1已列印", LVCFMT_LEFT);

	m_ListCtrlNo.SetColumnWidth(ID_LIST_ID, 50);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_NO, 150);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_TYPE, 100);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_NO, 150);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_DESC, 300);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_I_NO, 200);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_MAC_1, 120);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_MAC_OUT_1, 100);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void PrintMACDlg::OnCbnSelchangeComboMacsPerOne()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int Number = m_SelectMACsPerOne.GetCurSel();
	CHAR Buff[100];
	int nColumnCount = m_ListCtrlNo.GetHeaderCtrl()->GetItemCount();

	// Delete all of the columns.
	for (int i = 0; i < nColumnCount; i++)
	{
		m_ListCtrlNo.DeleteColumn(0);
	}

	m_ListCtrlNo.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_TYPE, "母製令別", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_NO, "母製令號碼", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_I_NO, "料號", LVCFMT_CENTER);

	m_ListCtrlNo.SetColumnWidth(ID_LIST_ID, 50);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_NO, 150);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_TYPE, 100);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_NO, 150);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_DESC, 300);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_I_NO, 200);
	int Index = 1;
	for (int i = 0; i <= Number * 2; i+=2)
	{
		sprintf_s(Buff, 100, "MAC%d", Index);
		m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_MAC_1 + i, Buff, LVCFMT_CENTER);
		m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_MAC_1 + i, 120);
		sprintf_s(Buff, 100, "MAC%d已列印", Index);
		m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_MAC_1 + i + 1, Buff, LVCFMT_CENTER);
		m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_MAC_1 + i + 1, 100);
		Index++;
	}
}


void PrintMACDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int SelectedCustomer = m_SelectCustomerMAC.GetCurSel();
	if (SelectedCustomer == 0)
	{
		MessageBox("必須選擇一個客戶MAC", "錯誤", MB_OK | MB_ICONERROR);
	}

	//CDialogEx::OnOK();
}


void PrintMACDlg::OnCbnSelchangeComboCustomerMac()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int SelectedCustomer = m_SelectCustomerMAC.GetCurSel();
	if (SelectedCustomer == 1)
	{
		AddCustomerMACDlg AddCustomerMACDlg;
		AddCustomerMACDlg.DoModal();
		m_SelectCustomerMAC.SetCurSel(0);
	}
	else if (SelectedCustomer == 0)
	{
		m_TitleMACRange.ShowWindow(TRUE);
		m_InputStartMAC.ShowWindow(TRUE);
		m_TitleMark.ShowWindow(TRUE);
		m_InputEndMAC.ShowWindow(TRUE);

		m_TitleLastMAC.ShowWindow(FALSE);
		m_ShowLastMAC.ShowWindow(FALSE);
	}
	else if (SelectedCustomer == 3)
	{
		CString MNo;
		m_EditMNo.GetWindowTextA(MNo);

		if (MNo.GetLength() == 0)
		{
			MessageBox("請先輸入製令資料", "錯誤", MB_OK | MB_ICONERROR);
			m_SelectCustomerMAC.SetCurSel(0);
		}
		else
		{
			m_TitleMACRange.ShowWindow(FALSE);
			m_InputStartMAC.ShowWindow(FALSE);
			m_TitleMark.ShowWindow(FALSE);
			m_InputEndMAC.ShowWindow(FALSE);

			m_TitleLastMAC.ShowWindow(TRUE);
			m_ShowLastMAC.ShowWindow(TRUE);

			m_ShowLastMAC.SetWindowTextA("00026b0032AA");
			m_CtrlSNMtype.SetWindowTextA("M");
			m_ShowParentMNo.SetWindowTextA("210913003");
			m_ShowParentMQty.SetWindowTextA("32");
			m_ShowParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
			m_CtrlSNParentMSN.SetWindowTextA("210913003");
			m_CtrlSNParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
			PCtrlSNList_T pCtrlSNList;
			m_ListCtrlNo.DeleteAllItems();
			int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
			LVITEM	lvI;
			lvI.mask = LVIF_TEXT;
			int ListIndex = 0;
			CHAR StrBuff[2000];
			for (int i = 0; i < Number; i++)
			{
				pCtrlSNList = &CtrlSNList[i];
				lvI.iItem = ListIndex;
				lvI.iSubItem = 0;
				lvI.pszText = "1";
				lvI.cchTextMax = 60;
				m_ListCtrlNo.InsertItem(&lvI);
				sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
				sprintf_s(StrBuff, 200, pCtrlSNList->CtrlSN);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
				strcpy_s(StrBuff, 2000, pCtrlSNList->MType);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
				strcpy_s(StrBuff, 2000, pCtrlSNList->MNo);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
				strcpy_s(StrBuff, 2000, pCtrlSNList->MDesc);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
				strcpy_s(StrBuff, 2000, pCtrlSNList->MINo);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);
				strcpy_s(StrBuff, 2000, pCtrlSNList->MAC1);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_1, StrBuff);
				strcpy_s(StrBuff, 2000, "否");
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_OUT_1, StrBuff);

				ListIndex++;
			}
		}
	}
}


void PrintMACDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_ListCtrlNo.GetWindowRect(Rect);
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
	m_nItemIdx = m_ListCtrlNo.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
		m_uSelectedCount = m_ListCtrlNo.GetSelectedCount();
		if (m_uSelectedCount)
		{
			m_PopMenuForMonitor.LoadMenu(IDR_MENU_REPRINT_MAC);
			pop = m_PopMenuForMonitor.GetSubMenu(0);
			pop->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);
		}
	}
	else if (m_nItemIdx == -1)
	{
	}
}


void PrintMACDlg::OnEnChangeEditMno()
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
		m_EditCtrlSN.SetWindowTextA("");

		PCtrlSNList_T pCtrlSNList;

		m_ListCtrlNo.DeleteAllItems();
		LVITEM	lvI;
		lvI.mask = LVIF_TEXT;
		int ListIndex = 0;
		CHAR StrBuff[2000];
		int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
		for (int i = 0; i < Number; i++)
		{
			pCtrlSNList = &CtrlSNList[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ListCtrlNo.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

			ListIndex++;
		}
		//m_ListCtrlNo.SetSelectedColumn(1);
		sprintf_s(StrBuff, 2000, "%d", ListIndex);
		m_ShowListCtrlSNNumbers.SetWindowTextA(StrBuff);
	}
}

static CHAR MacAddr[32][13] =
{
	"00190F56D450", "00190F56D451", "00190F56D452", "00190F56D453", "00190F56D454", "00190F56D455", "00190F56D456", "00190F56D457",
	"00190F56D458", "00190F56D459", "00190F56D45A", "00190F56D45B", "00190F56D45C", "00190F56D45D", "00190F56D45E", "00190F56D45F",
	"00190F56D460", "00190F56D461", "00190F56D462", "00190F56D463", "00190F56D464", "00190F56D465", "00190F56D466", "00190F56D467",
	"00190F56D468", "00190F56D469", "00190F56D46A", "00190F56D46B", "00190F56D46C", "00190F56D46D", "00190F56D46E", "00190F56D46F",
};

void PrintMACDlg::OnEnChangeEditStartMac()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString StartMacAddr;
	CString EndMacAddr;
	m_InputStartMAC.GetWindowTextA(StartMacAddr);
	m_InputEndMAC.GetWindowTextA(EndMacAddr);

	if (StartMacAddr.GetLength() == 12 && EndMacAddr.GetLength() == 12)
	{
		PCtrlSNList_T pCtrlSNList;
		m_ListCtrlNo.DeleteAllItems();
		int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
		LVITEM	lvI;
		lvI.mask = LVIF_TEXT;
		int ListIndex = 0;
		CHAR StrBuff[2000];
		for (int i = 0; i < Number; i++)
		{
			pCtrlSNList = &CtrlSNList[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ListCtrlNo.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 200, pCtrlSNList->CtrlSN);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MType);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MNo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MDesc);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MINo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MAC1);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_1, MacAddr[i]);
			strcpy_s(StrBuff, 2000, "否");
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_OUT_1, StrBuff);

			ListIndex++;
		}
	}
}


void PrintMACDlg::OnEnChangeEditEndMac()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString StartMacAddr;
	CString EndMacAddr;
	m_InputStartMAC.GetWindowTextA(StartMacAddr);
	m_InputEndMAC.GetWindowTextA(EndMacAddr);

	if (StartMacAddr.GetLength() == 12 && EndMacAddr.GetLength() == 12)
	{
		PCtrlSNList_T pCtrlSNList;
		m_ListCtrlNo.DeleteAllItems();
		int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
		LVITEM	lvI;
		lvI.mask = LVIF_TEXT;
		int ListIndex = 0;
		CHAR StrBuff[2000];
		for (int i = 0; i < Number; i++)
		{
			pCtrlSNList = &CtrlSNList[i];
			lvI.iItem = ListIndex;
			lvI.iSubItem = 0;
			lvI.pszText = "1";
			lvI.cchTextMax = 60;
			m_ListCtrlNo.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 200, pCtrlSNList->CtrlSN);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MType);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MNo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MDesc);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MINo);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);
			strcpy_s(StrBuff, 2000, pCtrlSNList->MAC1);
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_1, MacAddr[i]);
			strcpy_s(StrBuff, 2000, "否");
			m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_MAC_OUT_1, StrBuff);

			ListIndex++;
		}
	}
}