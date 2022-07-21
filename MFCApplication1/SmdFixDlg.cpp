// SmdFixDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "SmdFixDlg.h"
#include "afxdialogex.h"
#include "SMDFixDescDlg.h"

// SmdFixDlg 對話方塊

IMPLEMENT_DYNAMIC(SmdFixDlg, CDialogEx)

SmdFixDlg::SmdFixDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SmdFixDlg, pParent)
{

}

SmdFixDlg::~SmdFixDlg()
{
}

void SmdFixDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	//  DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDC_RADIO_ONE, m_RadioOne);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT1, m_ShowParentMType);
	//  DDX_Control(pDX, IDC_SHOW_PARENT_MNO2, m_ShowParentMNo);
	DDX_Control(pDX, IDC_EDIT10, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT11, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_EDIT2, m_ShowParentMNo);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_EditCtrlSN);
	DDX_Control(pDX, IDC_EDIT13, m_ShowCtrlSNParentMType);
	DDX_Control(pDX, IDC_EDIT14, m_ShowCtrlSNParentMNo);
	//  DDX_Control(pDX, IDC_SHOW_PARENT_DESC, m_ShowCtrlSNParentMDesc);
	DDX_Control(pDX, IDC_EDIT12, m_ShowCtrlSNParentMDesc);
	//  DDX_Control(pDX, IDC_EDIT6, m_ShowListCtrlSNNumbers);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowPrevCtrlNoListMsg);
	//  DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_TempShowCtrlNoListSignMsg);
	DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_ShowCtrlNoListSignMsg);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST3, m_ShowThisCtrlNoListMsg);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowPrevCtrlNoList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO4, m_ShowThisCtrlNoList);
	DDX_Control(pDX, IDC_EDIT6, m_ShowPrevCtrlNoNumbers);
	DDX_Control(pDX, IDC_EDIT_THIS_CTRL_NO_NUM, m_ShowThisCtrlNoNumbers);
}


BEGIN_MESSAGE_MAP(SmdFixDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_MNO, &SmdFixDlg::OnEnChangeEditMno)
	ON_EN_CHANGE(IDC_EDIT_CTRL_NO, &SmdFixDlg::OnEnChangeEditCtrlNo)
END_MESSAGE_MAP()


// SmdFixDlg 訊息處理常式


BOOL SmdFixDlg::OnInitDialog()
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
	m_ShowPrevCtrlNoListMsg.SetFont(m_MessageFont, 1);
	m_ShowCtrlNoListSignMsg.SetFont(m_MessageFont, 1);
	m_ShowThisCtrlNoListMsg.SetFont(m_MessageFont, 1);

	m_RadioOne.SetCheck(1);
	m_MType.SetCurSel(0);

	CListCtrl* ListCtrlNo[2] = { &m_ShowPrevCtrlNoList , &m_ShowThisCtrlNoList };
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

void SmdFixDlg::OnEnChangeEditMno()
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

		m_ShowPrevCtrlNoList.DeleteAllItems();
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
			m_ShowPrevCtrlNoList.InsertItem(&lvI);
			sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
			sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
			m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

			ListIndex++;
		}
		sprintf_s(StrBuff, 2000, "%d", ListIndex);
		m_ShowPrevCtrlNoNumbers.SetWindowTextA(StrBuff);
	}
}


void SmdFixDlg::OnEnChangeEditCtrlNo()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString CtrlSN;
	CString MNo;

	m_EditCtrlSN.GetWindowTextA(CtrlSN);
	int Len = CtrlSN.GetLength();
	int Ret;
	if (Len == 15)
	{
		m_EditMNo.GetWindowTextA(MNo);
		if (MNo.GetLength() > 0)
		{
			m_ShowCtrlSNParentMType.SetWindowTextA("M");
			m_ShowCtrlSNParentMNo.SetWindowTextA("210913003");
			m_ShowCtrlSNParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");

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
				m_EditCtrlSN.SetWindowTextA("");
				Len = 0;
			}
			else
			{
				PCtrlSNList_T pCtrlSNList;

				m_ShowPrevCtrlNoList.DeleteAllItems();
				LVITEM	lvI;
				lvI.mask = LVIF_TEXT;
				int ListIndex = 0;
				CHAR StrBuff[2000];
				int Number = sizeof(CtrlSNList) / sizeof(CtrlSNList_T);

				pCtrlSNList = &CtrlSNList[FoundIndex];
				lvI.iItem = ListIndex;
				lvI.iSubItem = 0;
				lvI.pszText = "1";
				lvI.cchTextMax = 60;
				m_ShowPrevCtrlNoList.InsertItem(&lvI);
				sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
				m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);
				ListIndex++;
				for (int i = 0; i < Number; i++)
				{
					if (i == FoundIndex)
						continue;
					pCtrlSNList = &CtrlSNList[i];
					lvI.iItem = ListIndex;
					lvI.iSubItem = 0;
					lvI.pszText = "1";
					lvI.cchTextMax = 60;
					m_ShowPrevCtrlNoList.InsertItem(&lvI);
					sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
					sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
					sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
					sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
					sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
					sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
					m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

					ListIndex++;
				}

				m_ShowPrevCtrlNoList.SetFocus();
				m_ShowPrevCtrlNoList.SetItemState(-1, 0, LVIS_FOCUSED | LVIS_SELECTED);
				Ret = m_ShowPrevCtrlNoList.SetItemState(0, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);
				SMDFixDescDlg SMDFixDescDlg;
				SMDFixDescDlg.DoModal();
			}
		}
		else
		{
			MessageBox("請先輸入製令別及製令號碼", "警告", MB_OK | MB_ICONWARNING);
			m_EditCtrlSN.SetWindowTextA("");
			m_EditMNo.SetFocus();
		}
	}
}


int SmdFixDlg::ShowCtrlNoList()
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
		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
		m_ShowPrevCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

		ListIndex++;
	}
	sprintf_s(StrBuff, 2000, "%d", ListIndex);
	m_ShowPrevCtrlNoNumbers.SetWindowTextA(StrBuff);

	ListIndex = 0;
	m_ShowThisCtrlNoList.DeleteAllItems();
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
		m_ShowThisCtrlNoList.InsertItem(&lvI);
		sprintf_s(StrBuff, 2000, "%d", ListIndex + 1);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_ID, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->CtrlSN);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MType);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_TYPE, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MNo);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_M_NO, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
		sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
		m_ShowThisCtrlNoList.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);

		ListIndex++;
	}
	sprintf_s(StrBuff, 2000, "%d", ListIndex);
	m_ShowThisCtrlNoNumbers.SetWindowTextA(StrBuff);

	return 0;
}
