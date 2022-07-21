// MakeCtrlSnDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "MakeCtrlSnDlg.h"
#include "afxdialogex.h"


// MakeCtrlSnDlg 對話方塊

IMPLEMENT_DYNAMIC(MakeCtrlSnDlg, CDialogEx)

MakeCtrlSnDlg::MakeCtrlSnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MakeCtrlSnDlg, pParent)
{

}

MakeCtrlSnDlg::~MakeCtrlSnDlg()
{
}

void MakeCtrlSnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDOK, m_BtnFont);
	DDX_Control(pDX, IDOK, m_BtnSure);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ShowCtrlList);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO3, m_ShowCtrlSnList2);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST2, m_ShowCtrlSnList2);
	DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_ShowCtrlSnListMark);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	DDX_Control(pDX, IDC_LIST_CTRL_NO3, m_ListCtrlNo2);
	DDX_Control(pDX, IDC_COMBO1, m_FlowDeployIndex);
	DDX_Control(pDX, IDC_COMBO2, m_ShippingNoIndex);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_RADIO_BATCH2, m_BatchCtrlSn);
	DDX_Control(pDX, IDC_EDIT17, m_AllowCtrlSnListNumber);
	DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	DDX_Control(pDX, IDC_EDIT7, m_ShowParentMQty);
	DDX_Control(pDX, IDC_EDIT6, m_ShowParentMDesc);
	DDX_Control(pDX, IDC_EDIT8, m_ShowParentMINo);
	DDX_Control(pDX, IDC_EDIT1, m_EditPWA);
	DDX_Control(pDX, IDC_EDIT2, m_EditPWB);
	DDX_Control(pDX, IDC_EDIT3, m_EditBIOSVer);
}


BEGIN_MESSAGE_MAP(MakeCtrlSnDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT_MNO, &MakeCtrlSnDlg::OnEnChangeEditMno)
	ON_BN_CLICKED(IDOK, &MakeCtrlSnDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MakeCtrlSnDlg 訊息處理常式


BOOL MakeCtrlSnDlg::OnInitDialog()
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
	m_ShowCtrlSnList2.SetFont(m_MessageFont, 1);
	m_ShowCtrlSnListMark.SetFont(m_MessageFont, 1);

	m_FlowDeployIndex.SetCurSel(0);
	m_ShippingNoIndex.SetCurSel(0);
	m_MType.SetCurSel(0);
	m_BatchCtrlSn.SetCheck(1);

	CListCtrl* ListCtrlNo[2] = { &m_ListCtrlNo , &m_ListCtrlNo2 };
	for (int i = 0; i < 2; i++)
	{
		CListCtrl* pListCtrl = ListCtrlNo[i];
		ListView_SetExtendedListViewStyle(m_ListCtrlNo.m_hWnd, LVS_EX_FULLROWSELECT);
		pListCtrl->InsertColumn(ID_LIST_ID, "編號", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_NO, "內控碼", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_PWA, "PWA", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_PWB, "PWB", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_BIOS_VER, "BIOS版本", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_FLOW_DEPLOY_INDEX, "流程部屬", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_SHIPPING_NO_DEF_INDEX, "出貨序號格式", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_DESC, "品名", LVCFMT_CENTER);
		pListCtrl->InsertColumn(ID_LIST_CTRL_I_NO, "料號", LVCFMT_CENTER);


		pListCtrl->SetColumnWidth(ID_LIST_ID, 50);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_NO, 140);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_PWA, 100);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_PWB, 100);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_BIOS_VER, 150);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_DESC, 400);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_I_NO, 100);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_FLOW_DEPLOY_INDEX, 100);
		pListCtrl->SetColumnWidth(ID_LIST_CTRL_SHIPPING_NO_DEF_INDEX, 200);

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



void MakeCtrlSnDlg::OnEnChangeEditMno()
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
		m_ShowParentMQty.SetWindowTextA("32");
		m_ShowParentMDesc.SetWindowTextA("PCA1520340-0-2 V:A1-F SMD");
		m_ShowParentMINo.SetWindowTextA("2206000324");
		CString PWA;
		m_EditPWA.GetWindowTextA(PWA);
		m_EditPWB.SetWindowTextA("B12.2");
		m_EditBIOSVer.SetWindowTextA("20220712A001");
		if (m_FlowDeployIndex.GetCurSel() > 0)
		{
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
				sprintf_s(StrBuff, 2000, pCtrlSNList->MDesc);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_DESC, StrBuff);
				sprintf_s(StrBuff, 2000, pCtrlSNList->MINo);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_I_NO, StrBuff);
				sprintf_s(StrBuff, 2000, PWA);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_PWA, StrBuff);
				sprintf_s(StrBuff, 2000, "B12.2");
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_PWB, StrBuff);
				sprintf_s(StrBuff, 2000, "20220712A001");
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_BIOS_VER, StrBuff);
				CString FlowDeployName;
				m_FlowDeployIndex.GetWindowTextA(FlowDeployName);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_FLOW_DEPLOY_INDEX, FlowDeployName);
				CString ShippingNoDefName;
				m_ShippingNoIndex.GetWindowTextA(ShippingNoDefName);
				m_ListCtrlNo.SetItemText(ListIndex, ID_LIST_CTRL_SHIPPING_NO_DEF_INDEX, ShippingNoDefName);

				ListIndex++;
			}
			sprintf_s(StrBuff, 2000, "%d", ListIndex);
			m_AllowCtrlSnListNumber.SetWindowTextA(StrBuff);

		}
		else
		{
			MessageBox("請先選擇一個流程部屬", "警告", MB_OK | MB_ICONWARNING);
			m_EditMNo.SetWindowTextA("");
			m_ShowParentMQty.SetWindowTextA("");
			m_ShowParentMDesc.SetWindowTextA("");
			m_ShowParentMINo.SetWindowTextA("");
			m_EditPWA.SetWindowTextA("");
			m_EditPWB.SetWindowTextA("");
			m_EditBIOSVer.SetWindowTextA("");
			m_ListCtrlNo.DeleteAllItems();
		}
	}
}


void MakeCtrlSnDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}
