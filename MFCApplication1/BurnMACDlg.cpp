// BurnMACDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "BurnMACDlg.h"
#include "afxdialogex.h"

// BurnMACDlg 對話方塊

IMPLEMENT_DYNAMIC(BurnMACDlg, CDialogEx)

BurnMACDlg::BurnMACDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BurnMACDlg, pParent)
{
}

BurnMACDlg::~BurnMACDlg()
{
}

void BurnMACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	//  DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_RADIO_BATCH, m_RadioBatch);
	DDX_Control(pDX, IDC_RADIO_ONE, m_RadioOne);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowCtrlList);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_EDIT_M_TYPE, m_ShowParentMType);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	//  DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDC_SHOW_MAC_NUMBER, m_ShowMACNumber);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_EditCtrlSN);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT_M_TYPE2, m_ShowCtrlSNParentMType);
	DDX_Control(pDX, IDC_SHOW_PARENT_MNO4, m_ShowCtrlSNParentMNo);
	DDX_Control(pDX, IDC_EDIT7, m_ShowCtrlSNParentMDesc);
	DDX_Control(pDX, IDC_SHOW_PARENT_MNO3, m_ShowParentMNo);
	DDX_Control(pDX, IDC_SHOW_PARENT_MQTY, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT6, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowPrevCtrlNoListMsg);
	DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_ShowCtrlNoListSignMsg);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST3, m_ShowThisCtrlNoListMsg);
	DDX_Control(pDX, IDC_EDIT_THIS_CTRL_NO_NUM, m_ShowThisCtrlNoNumbers);
	DDX_Control(pDX, IDC_EDIT_PREV_CTRL_NO_NUM, m_ShowPrevCtrlNoNumbers);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowPrevCtrlNoList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO4, m_ShowThisCtrlNoList);
	DDX_Control(pDX, IDC_BUTTON1, m_BtnSure);
	DDX_Control(pDX, IDC_STATIC_MESSAGE_BOX, m_MessageBox);
	DDX_Control(pDX, IDC_STATIC_MESSAGE_BOX_TITLE, m_TitleMessageBox);
}


BEGIN_MESSAGE_MAP(BurnMACDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_CTRL_NO, &BurnMACDlg::OnEnChangeEditCtrlNo)
//	ON_BN_CLICKED(IDOK, &BurnMACDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT_MNO, &BurnMACDlg::OnEnChangeEditMno)
	ON_BN_CLICKED(IDOK, &BurnMACDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &BurnMACDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// BurnMACDlg 訊息處理常式
static CtrlSNList_T CtrlSNList[] =
{
	{"IBCM20059546515", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546516", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546517", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546518", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546519", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546520", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546521", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546522", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546523", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546524", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546525", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546526", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546527", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546528", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546529", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546530", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546531", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546532", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546533", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546534", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546535", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546536", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546537", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546538", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546539", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546540", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546541", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546542", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546543", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546544", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546545", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
	{"IBCM20059546546", "M", "210913003", "PCA1520340-0-2 V:A1-F SMD", "2206000324"},
};



BOOL BurnMACDlg::OnInitDialog()
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

	m_ShowPrevCtrlNoListMsg.SetFont(m_MessageFont, 1);
	m_ShowCtrlNoListSignMsg.SetFont(m_MessageFont, 1);
	m_ShowThisCtrlNoListMsg.SetFont(m_MessageFont, 1);
	m_TitleMessageBox.SetFont(m_MessageFont, 1);
	m_MessageBox.SetFont(m_MessageFont, 1);

	m_RadioOne.SetCheck(1);
	m_MType.SetCurSel(0);

	CHAR Buff[100];

	CListCtrl* ListCtrlNo[2] = { &m_ShowPrevCtrlNoList , &m_ShowThisCtrlNoList };
	for (int i = 0; i < 2; i++)
	{
		CListCtrl* pListCtrl = ListCtrlNo[i];
		ListView_SetExtendedListViewStyle(m_ShowPrevCtrlNoList.m_hWnd, LVS_EX_FULLROWSELECT);
		pListCtrl->InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
//		pListCtrl->InsertColumn(ID_LIST_CTRL_M_TYPE, "母製令別", LVCFMT_CENTER);
//		pListCtrl->InsertColumn(ID_LIST_CTRL_M_NO, "母製令號碼", LVCFMT_LEFT);
//		pListCtrl->InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_LEFT);

		pListCtrl->SetColumnWidth(ID_LIST_ID, 50);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_NO, 150);
//		pListCtrl->SetColumnWidth(ID_LIST_CTRL_M_TYPE, 100);
//		pListCtrl->SetColumnWidth(ID_LIST_CTRL_M_NO, 150);
//		pListCtrl->SetColumnWidth(ID_LIST_CTRL_DESC, 300);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void BurnMACDlg::OnEnChangeEditCtrlNo()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。
	// TODO:  在此加入控制項告知處理常式程式碼
	CString CtrlSN;
	m_EditCtrlSN.GetWindowTextA(CtrlSN);
	int Ret;
	int Len = CtrlSN.GetLength();
	if (Len == 15)
	{
		m_ShowCtrlSNParentMType.SetWindowTextA("M");
		m_ShowCtrlSNParentMNo.SetWindowTextA("210913003");
		m_ShowCtrlSNParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
		m_ShowMACNumber.SetWindowTextA("2");

		PCtrlSNList_T pCtrlSNList;
		int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
		BOOL Found = FALSE;
		for (int i = 0; i < Number; i++)
		{
			pCtrlSNList = &CtrlSNList[i];
			int Compared = strcmp(pCtrlSNList->CtrlSN, CtrlSN.GetBuffer());
			if (Compared == 0)
			{
				Found = TRUE;
				m_FoundIndex = i;
			}
		}
		if (Found == FALSE && Len > 0)
		{
			MessageBox("輸入的內控號碼不存在\n請檢查製令資料及內控號碼", "錯誤", MB_OK | MB_ICONERROR);
			m_EditCtrlSN.SetWindowTextA("");
			Len = 0;
		}
		else
		{
			int nColumnCount = m_ShowPrevCtrlNoList.GetHeaderCtrl()->GetItemCount();
			if (nColumnCount > 2)
			{
				// Delete all of the columns.
//				for (int i = 0; i < nColumnCount; i++)
//				{
//					m_ShowPrevCtrlNoList.DeleteColumn(0);
//				}
				m_ShowPrevCtrlNoList.DeleteColumn(2);
				m_ShowPrevCtrlNoList.DeleteColumn(2);
				m_ShowPrevCtrlNoList.DeleteColumn(2);
				m_ShowPrevCtrlNoList.DeleteColumn(2);
			}
			m_ShowPrevCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_1, "MAC1", LVCFMT_LEFT);
			m_ShowPrevCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1, "MAC1已燒錄", LVCFMT_LEFT);
			m_ShowPrevCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_1, 120);
			m_ShowPrevCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1, 100);

			m_ShowPrevCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1 + 1, "MAC2", LVCFMT_LEFT);
			m_ShowPrevCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1 + 2, "MAC2已燒錄", LVCFMT_LEFT);
			m_ShowPrevCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1 + 1, 120);
			m_ShowPrevCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1 + 2, 100);
			PCtrlSNList_T pCtrlSNList;
			m_ShowPrevCtrlNoList.SetFocus();
			m_ShowPrevCtrlNoList.SetItemState(-1, 0, LVIS_FOCUSED | LVIS_SELECTED);
			Ret = m_ShowPrevCtrlNoList.SetItemState(m_FoundIndex, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

			m_InputMACAddrDlg.DoModal();

			INT Compared;
			Compared = strcmp(m_Mac1, "00026B0A1833");
			if (Compared == 1)
			{
				m_MessageBox.SetWindowTextA("刷入的MAC位址錯誤");
			}
			else
			{
				m_ShowPrevCtrlNoList.SetItemText(m_FoundIndex, ID_LIST_CTRL_MAC_1, m_Mac1);
				m_ShowPrevCtrlNoList.SetItemText(m_FoundIndex, ID_LIST_CTRL_MAC_BURNED_1, "否");
				m_ShowPrevCtrlNoList.SetItemText(m_FoundIndex, ID_LIST_CTRL_MAC_BURNED_1 + 1, m_Mac2);
				m_ShowPrevCtrlNoList.SetItemText(m_FoundIndex, ID_LIST_CTRL_MAC_BURNED_1 + 2, "否");
			}
		}
	}
}


void BurnMACDlg::OnEnChangeEditMno()
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
		int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
		for (int i = 0; i < Number; i++)
		{
			pCtrlSNList = &CtrlSNList[i];
			pCtrlSNList->bPutInStation = FALSE;
		}
		ShowCtrlNoList();
	}
}


int BurnMACDlg::ShowCtrlNoList()
{
	// TODO: 請在此新增您的實作程式碼.
	PCtrlSNList_T pCtrlSNList;
	m_ShowPrevCtrlNoList.DeleteAllItems();
	LVITEM	lvI;
	lvI.mask = LVIF_TEXT;
	int ListIndex = 0;
	CHAR StrBuff[2000];
	int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
	for (int i = 0; i < Number; i++)
	{
		pCtrlSNList = &CtrlSNList[i];
		if (pCtrlSNList->bPutInStation == TRUE)
			continue;
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ShowPrevCtrlNoList.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
//		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
//		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
//		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);

		ListIndex++;
	}
	sprintf_s(StrBuff, 2000, "%d", ListIndex);
	m_ShowPrevCtrlNoNumbers.SetWindowTextA(StrBuff);

	m_ListIndexInStation = 0;
	m_ShowThisCtrlNoList.DeleteAllItems();
	lvI.mask = LVIF_TEXT;
	Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
	for (int i = 0; i < Number; i++)
	{
		pCtrlSNList = &CtrlSNList[i];
		if (pCtrlSNList->bPutInStation == FALSE)
			continue;
		lvI.iItem = m_ListIndexInStation;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_ShowThisCtrlNoList.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", m_ListIndexInStation + 1);
		m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
		m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation, ID_LIST_CTRL_NO, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
//		m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation, ID_LIST_CTRL_M_TYPE, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
//		m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation, ID_LIST_CTRL_M_NO, StrBuff);
//		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
//		m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation, ID_LIST_CTRL_DESC, StrBuff);

		m_ListIndexInStation++;
	}
	sprintf_s(StrBuff, 2000, "%d", m_ListIndexInStation);
	m_ShowThisCtrlNoNumbers.SetWindowTextA(StrBuff);

	return 0;
}


int BurnMACDlg::PutMacAddress(PCHAR pMac1, PCHAR pMac2)
{
	// TODO: 請在此新增您的實作程式碼.
	strcpy_s(m_Mac1, 100, pMac1);
	strcpy_s(m_Mac2, 100, pMac2);
	return 0;
}


void BurnMACDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}


void BurnMACDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CtrlSNList[m_FoundIndex].bPutInStation = TRUE;
	ShowCtrlNoList();

	m_ShowThisCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_1, "MAC1", LVCFMT_LEFT);
	m_ShowThisCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1, "MAC1已燒錄", LVCFMT_LEFT);
	m_ShowThisCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_1, 120);
	m_ShowThisCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1, 100);

	m_ShowThisCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1 + 1, "MAC2", LVCFMT_LEFT);
	m_ShowThisCtrlNoList.InsertColumn(ID_LIST_CTRL_MAC_BURNED_1 + 2, "MAC2已燒錄", LVCFMT_LEFT);
	m_ShowThisCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1 + 1, 120);
	m_ShowThisCtrlNoList.SetColumnWidth(ID_LIST_CTRL_MAC_BURNED_1 + 2, 100);

	m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation - 1, ID_LIST_CTRL_MAC_1, m_Mac1);
	m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation - 1, ID_LIST_CTRL_MAC_BURNED_1, "是");
	m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation - 1, ID_LIST_CTRL_MAC_BURNED_1 + 1, m_Mac2);
	m_ShowThisCtrlNoList.SetItemText(m_ListIndexInStation - 1, ID_LIST_CTRL_MAC_BURNED_1 + 2, "是");
}
