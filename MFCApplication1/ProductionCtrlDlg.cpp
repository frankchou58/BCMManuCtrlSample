// ProductionCtrlDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "ProductionCtrlDlg.h"
#include "afxdialogex.h"


// ProductionCtrlDlg 對話方塊

IMPLEMENT_DYNAMIC(ProductionCtrlDlg, CDialogEx)

ProductionCtrlDlg::ProductionCtrlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ProductionCtrlDlg, pParent)
{

}

ProductionCtrlDlg::~ProductionCtrlDlg()
{
}

void ProductionCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	//  DDX_Control(pDX, IDC_COMBO1, m_FlowDeployIndex);
	//  DDX_Control(pDX, IDC_COMBO2, m_ShippingNoIndex);
	//  DDX_Control(pDX, IDOK, m_BtnSure);
	//  DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	//  DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	//  DDX_Control(pDX, IDC_EDIT_MNO, m_EditMNo);
	//  DDX_Control(pDX, IDC_EDIT7, m_ShowParentMQty);
	//  DDX_Control(pDX, IDC_EDIT6, m_ShowParentMDesc);
	//  DDX_Control(pDX, IDC_EDIT8, m_ShowParentMINo);
	//  DDX_Control(pDX, IDC_EDIT1, m_EditPWA);
	//  DDX_Control(pDX, IDC_EDIT2, m_EditPWB);
	//  DDX_Control(pDX, IDC_EDIT3, m_EditBIOSVer);
	//  DDX_Control(pDX, IDC_STATIC_SHOWMARK, m_ShowCtrlSnListMark);
	//  DDX_Control(pDX, IDC_SHOW_CTRL_LIST2, m_ShowCtrlSnList2);
	//  DDX_Control(pDX, IDC_LIST_CTRL_NO3, m_ListCtrlNo2);
	//  DDX_Control(pDX, IDC_RADIO_BATCH2, m_BatchCtrlSn);
	//  DDX_Control(pDX, IDC_EDIT17, m_AllowCtrlSnListNumber);
	//DDX_Control(pDX, IDC_TAB1, m_TabCtrl);
	//  DDX_Control(pDX, IDC_TAB_PRODUCTION_CTRL, m_TabCtrl);
	DDX_Control(pDX, IDC_TAB_PRODUCTION_CTRL, m_TabCtrl);
}


BEGIN_MESSAGE_MAP(ProductionCtrlDlg, CDialogEx)
//	ON_EN_CHANGE(IDC_EDIT_MNO, &ProductionCtrlDlg::OnEnChangeEditMno)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ProductionCtrlDlg::OnCbnSelchangeCombo1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_PRODUCTION_CTRL, &ProductionCtrlDlg::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// ProductionCtrlDlg 訊息處理常式


BOOL ProductionCtrlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	CWnd* This = AfxGetMainWnd();
	This->SetWindowTextA("BCM生產履歷APP");
	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = _T("內控碼資料產生對話框");
	m_TabCtrl.InsertItem(CTRL_ID_CTRL_SN_MAKE_DLG, &tcItem);
	tcItem.pszText = _T("內控碼資料編輯對話框");
	m_TabCtrl.InsertItem(CTRL_ID_CTRL_SN_EDIT_DLG, &tcItem);

	CRect rs;
	m_TabCtrl.GetClientRect(&rs);
#if 1
	rs.top += 25;
	rs.bottom -= 10;
	rs.left += 1;
	rs.right -= 2;
#endif
	m_CtrlSNMakeDlg.Create(IDD_MakeCtrlSnDlg, &m_TabCtrl);
	m_pWndModleDlg[CTRL_ID_CTRL_SN_MAKE_DLG] = &m_CtrlSNMakeDlg;
	m_CtrlSNMakeDlg.MoveWindow(&rs);
	m_CtrlSNEditDlg.Create(IDD_EditCtrlSnDlg, &m_TabCtrl);
	m_pWndModleDlg[CTRL_ID_CTRL_SN_EDIT_DLG] = &m_CtrlSNEditDlg;
	m_CtrlSNEditDlg.MoveWindow(&rs);

	m_CtrlSNMakeDlg.ShowWindow(true);
	m_CtrlSNEditDlg.ShowWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}

//void ProductionCtrlDlg::OnEnChangeEditMno()
//{
//	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
//	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
//	// 函式和呼叫 CRichEditCtrl().SetEventMask()
//	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。
//
//	// TODO:  在此加入控制項告知處理常式程式碼
//}


void ProductionCtrlDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


void ProductionCtrlDlg::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int CurSel = m_TabCtrl.GetCurSel();
	switch (CurSel)
	{
	case CTRL_ID_CTRL_SN_MAKE_DLG:
		m_CtrlSNMakeDlg.ShowWindow(true);
		m_CtrlSNEditDlg.ShowWindow(false);
		break;
	case CTRL_ID_CTRL_SN_EDIT_DLG:
		m_CtrlSNMakeDlg.ShowWindow(false);
		m_CtrlSNEditDlg.ShowWindow(true);
		break;
	}

	*pResult = 0;
}
