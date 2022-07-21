// SmdDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "SmdDlg.h"
#include "afxdialogex.h"


// SmdDlg 對話方塊

IMPLEMENT_DYNAMIC(SmdDlg, CDialogEx)

SmdDlg::SmdDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SmdDlg, pParent)
{

}

SmdDlg::~SmdDlg()
{
}

void SmdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	//  DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlNo);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	DDX_Control(pDX, IDC_RADIO_BATCH, m_RadioBatch);
	DDX_Control(pDX, IDC_EDIT6, m_ShowListCtrlSNNumbers);
	DDX_Control(pDX, IDC_EDIT1, m_ShowParentMType);
	DDX_Control(pDX, IDC_EDIT2, m_ShowParentMNo);
	DDX_Control(pDX, IDC_EDIT10, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT11, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_EditCtrlSN);
	DDX_Control(pDX, IDC_EDIT13, m_ShowCtrlSNParentMType);
	DDX_Control(pDX, IDC_EDIT14, m_ShowCtrlSNParentMNo);
	DDX_Control(pDX, IDC_EDIT12, m_ShowCtrlSNParentMDesc);
	DDX_Control(pDX, IDC_BUTTON1, m_BtnSure);
}


BEGIN_MESSAGE_MAP(SmdDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_MNO, &SmdDlg::OnEnChangeEditMno)
	ON_EN_CHANGE(IDC_EDIT_CTRL_NO, &SmdDlg::OnEnChangeEditCtrlNo)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()


// SmdDlg 訊息處理常式


BOOL SmdDlg::OnInitDialog()
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
	m_ShowCtrlList.SetFont(m_MessageFont, 1);

	m_RadioBatch.SetCheck(1);
	m_MType.SetCurSel(0);

	m_ShowListCtrlSNNumbers.SetWindowTextA("");

	ListView_SetExtendedListViewStyle(m_ListCtrlNo.m_hWnd, LVS_EX_FULLROWSELECT/* | LVS_SHOWSELALWAYS*/);
	m_ListCtrlNo.InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_TYPE, "母製令別", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_M_NO, "母製令號碼", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_CENTER);
	m_ListCtrlNo.InsertColumn(ID_LIST_CTRL_I_NO, "料號", LVCFMT_CENTER);

	m_ListCtrlNo.SetColumnWidth(ID_LIST_ID, 50);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_NO, 140);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_TYPE, 80);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_M_NO, 100);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_DESC, 400);
	m_ListCtrlNo.SetColumnWidth(ID_LIST_CTRL_I_NO, 100);

	//MessageBox("正確站台應該:\n  SMD半成品倉(23)\n  測試燒 MAC(3)", "站台錯誤", MB_OK | MB_ICONERROR);
	//MessageBox("內控資料的母製令不符", "內控資料錯誤", MB_OK | MB_ICONERROR);

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

void SmdDlg::OnEnChangeEditMno()
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


void SmdDlg::OnEnChangeEditCtrlNo()
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

				m_ListCtrlNo.DeleteAllItems();
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
				for (int i = 0; i < Number; i++)
				{
					if (i == FoundIndex)
						continue;
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

				m_ListCtrlNo.SetFocus();
				m_ListCtrlNo.SetItemState(-1, 0, LVIS_FOCUSED | LVIS_SELECTED);
				Ret = m_ListCtrlNo.SetItemState(0, LVIS_FOCUSED | LVIS_SELECTED, LVIS_FOCUSED | LVIS_SELECTED);

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


void SmdDlg::OnContextMenu(CWnd* pWnd, CPoint point)
{
	// TODO: 在此加入您的訊息處理常式程式碼
}
