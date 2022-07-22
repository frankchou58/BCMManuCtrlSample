// TemplateStationDlg.cpp: 實作檔案
//
//Haha
//Ok

#include "pch.h"
#include "MFCApplication1.h"
#include "TemplateStationDlg.h"
#include "afxdialogex.h"


// TemplateStationDlg 對話方塊

IMPLEMENT_DYNAMIC(TemplateStationDlg, CDialogEx)

TemplateStationDlg::TemplateStationDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TemplateStationDlg, pParent)
{
}

TemplateStationDlg::~TemplateStationDlg()
{
}

void TemplateStationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_TempShowStationName);
	//  DDX_Control(pDX, IDC_COMBO_M_TYPE, m_TempMType);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_TempSelectMType);
	DDX_Control(pDX, IDC_EDIT_MNO, m_TempInputMNo);
	DDX_Control(pDX, IDC_EDIT1, m_TempShowParentMType);
	DDX_Control(pDX, IDC_EDIT2, m_TempShowParentMNo);
	DDX_Control(pDX, IDC_EDIT10, m_TempShowParentMQty);
	DDX_Control(pDX, IDC_EDIT11, m_TempShowParentMDesc);
	//  DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_TempInputMNo);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_TempInputCtrlNo);
	DDX_Control(pDX, IDC_EDIT13, m_TempShowCtrlNoMType);
	DDX_Control(pDX, IDC_EDIT14, m_TempShowCtrlNoMNo);
	DDX_Control(pDX, IDC_EDIT12, m_TempShowCtrlNoMDesc);
	DDX_Control(pDX, IDC_RADIO_BATCH, m_TempRadioBatch);
	DDX_Control(pDX, IDC_RADIO_ONE, m_TempRadioOne);
	DDX_Control(pDX, IDC_EDIT_PREV_CTRL_NO_NUM, m_TempShowPrevCtrlNoNumbers);
	DDX_Control(pDX, IDC_EDIT_THIS_CTRL_NO_NUM, m_TempShowThisCtrlNoNumbers);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_TempShowPrevCtrlNoListMsg);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST3, m_TempShowThisCtrlNoListMsg);
	DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_TempShowCtrlNoListSignMsg);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_TempShowPrevCtrlNoList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO4, m_TempShowThisCtrlNoList);
	DDX_Control(pDX, IDOK, m_BtnSure);
}


BEGIN_MESSAGE_MAP(TemplateStationDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_MNO, &TemplateStationDlg::OnEnChangeEditMno)
	ON_EN_CHANGE(IDC_EDIT_CTRL_NO, &TemplateStationDlg::OnEnChangeEditCtrlNo)
	ON_BN_CLICKED(IDOK, &TemplateStationDlg::OnBnClickedOk)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// TemplateStationDlg 訊息處理常式


BOOL TemplateStationDlg::OnInitDialog()
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

	m_TempShowStationName.SetFont(m_MessageFont, 1);
	m_BtnSure.SetFont(m_BtnFont, 1);
	m_TempShowPrevCtrlNoListMsg.SetFont(m_MessageFont, 1);
	m_TempShowCtrlNoListSignMsg.SetFont(m_MessageFont, 1);
	m_TempShowThisCtrlNoListMsg.SetFont(m_MessageFont, 1);

	CHAR SettingString[50];
	int OpenCounter = AfxGetApp()->GetProfileInt("Settings", "OpenCounter", 0);
	sprintf_s(SettingString, 50, "Settings_%d", OpenCounter);
	int SelectedStaion = AfxGetApp()->GetProfileInt(SettingString, "SelectedStation", 0);
	PStationData_T pStationData = NULL;
	int StationNumer = sizeof(g_StationData) / sizeof(StationData_T);
	for (int i = 0; i < StationNumer; i++)
	{
		if (SelectedStaion == g_StationData[i].StationId)
		{
			pStationData = &g_StationData[i];
			break;
		}
	}

	if (pStationData)
	{
		CWnd* This = AfxGetMainWnd();
		This->SetWindowTextA("BCM生產履歷APP");
		if(pStationData->bIsStationCtrlSnBatch)
			m_TempRadioOne.SetCheck(1);
		else
			m_TempRadioBatch.SetCheck(1);
		m_TempSelectMType.SetCurSel(0);
		m_TempShowStationName.SetWindowTextA(pStationData->StationName);
	}

	CListCtrl* ListCtrlNo[2] = { &m_TempShowPrevCtrlNoList , &m_TempShowThisCtrlNoList };
	for (int i = 0; i < 2; i++)
	{
		CListCtrl* pListCtrl = ListCtrlNo[i];
		ListView_SetExtendedListViewStyle(pListCtrl->m_hWnd, LVS_EX_FULLROWSELECT);
		pListCtrl->InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_M_TYPE, "母製令別", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_M_NO, "母製令號碼", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_I_NO, "料號", LVCFMT_CENTER);

		pListCtrl->SetColumnWidth(ID_LIST_ID, 50);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_NO, 140);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_M_TYPE, 80);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_M_NO, 100);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_DESC, 400);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_I_NO, 100);

	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}

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


void TemplateStationDlg::OnEnChangeEditMno()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString MNo;
	m_TempInputMNo.GetWindowTextA(MNo);
	int Len = MNo.GetLength();
	if (Len == 9)
	{
		m_TempShowParentMType.SetWindowTextA("M");
		m_TempShowParentMNo.SetWindowTextA("210913003");
		m_TempShowParentMQty.SetWindowTextA("32");
		m_TempShowParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
		m_TempInputCtrlNo.SetWindowTextA("");

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


void TemplateStationDlg::OnEnChangeEditCtrlNo()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString CtrlSN;
	CString MNo;

	m_TempInputCtrlNo.GetWindowTextA(CtrlSN);
	int Len = CtrlSN.GetLength();
	int Ret;
	if (Len == 15)
	{
		m_TempInputMNo.GetWindowTextA(MNo);
		if (MNo.GetLength() > 0)
		{
			m_TempShowCtrlNoMType.SetWindowTextA("M");
			m_TempShowCtrlNoMNo.SetWindowTextA("210913003");
			m_TempShowCtrlNoMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");

			PCtrlSNList_T pCtrlSNList;
			int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
			BOOL Found = FALSE;
			int FoundIndex;
			for (int i = 0; i < Number; i++)
			{
				pCtrlSNList = &CtrlSNList[i];
				int Compared = strcmp(pCtrlSNList->CtrlSN, CtrlSN.GetBuffer());
				if (Compared == 0)
				{
					Found = TRUE;
					FoundIndex = i;
				}
			}
			if (Found == FALSE && Len > 0)
			{
				MessageBox("輸入的內控號碼不存在\n請檢查製令資料及內控號碼", "錯誤", MB_OK | MB_ICONERROR);
				m_TempInputCtrlNo.SetWindowTextA("");
				Len = 0;
			}
			else
			{
				PCtrlSNList_T pCtrlSNList;
				m_TempShowPrevCtrlNoList.SetFocus();
				m_TempShowPrevCtrlNoList.SetItemState(-1, 0, LVIS_FOCUSED | LVIS_SELECTED);
				Ret = m_TempShowPrevCtrlNoList.SetItemState(FoundIndex, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
			}
		}
		else
		{
			MessageBox("請先輸入製令別及製令號碼", "警告", MB_OK | MB_ICONWARNING);
			m_TempInputCtrlNo.SetWindowTextA("");
			m_TempInputMNo.SetFocus();
		}
	}
}


void TemplateStationDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	CString Numbers;
	m_TempShowPrevCtrlNoNumbers.GetWindowTextA(Numbers);
	if (Numbers.GetLength() == 0)
	{
		MessageBox("允取區沒有資料", "錯誤", MB_OK | MB_ICONERROR);
	}
	else
	{
		m_uSelectedCount = m_TempShowPrevCtrlNoList.GetSelectedCount();
		m_nItemIdx = m_TempShowPrevCtrlNoList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
		for (int i = 0; i < m_uSelectedCount; i++)
		{
			CtrlSNList[m_nItemIdx].bPutInStation = TRUE;
			m_nItemIdx = m_TempShowPrevCtrlNoList.GetNextItem(m_nItemIdx, LVNI_ALL | LVNI_SELECTED);
		}
		ShowCtrlNoList();
	}
	//CDialogEx::OnOK();
}


void TemplateStationDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
	CRect Rect;
	m_TempShowPrevCtrlNoList.GetWindowRect(Rect);
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
	m_nItemIdx = m_TempShowPrevCtrlNoList.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
	if (m_nItemIdx >= 0)
	{
	}
	else if (m_nItemIdx == -1)
	{
	}

}


int TemplateStationDlg::ShowCtrlNoList()
{
	// TODO: 請在此新增您的實作程式碼.
	PCtrlSNList_T pCtrlSNList;
	m_TempShowPrevCtrlNoList.DeleteAllItems();
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
		m_TempShowPrevCtrlNoList.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
		m_TempShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

		ListIndex++;
	}
	sprintf_s(StrBuff, 2000, "%d", ListIndex);
	m_TempShowPrevCtrlNoNumbers.SetWindowTextA(StrBuff);

	ListIndex = 0;
	m_TempShowThisCtrlNoList.DeleteAllItems();
	lvI.mask = LVIF_TEXT;
	Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);
	for (int i = 0; i < Number; i++)
	{
		pCtrlSNList = &CtrlSNList[i];
		if (pCtrlSNList->bPutInStation == FALSE)
			continue;
		lvI.iItem = ListIndex;
		lvI.iSubItem = 0;
		lvI.pszText = "1";
		lvI.cchTextMax = 60;
		m_TempShowThisCtrlNoList.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
		m_TempShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

		ListIndex++;
	}
	sprintf_s(StrBuff, 2000, "%d", ListIndex);
	m_TempShowThisCtrlNoNumbers.SetWindowTextA(StrBuff);

	return 0;
}
