// EnguneeringDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "EnguneeringDlg.h"
#include "afxdialogex.h"


// EnguneeringDlg 對話方塊

IMPLEMENT_DYNAMIC(EnguneeringDlg, CDialogEx)

EnguneeringDlg::EnguneeringDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EnguneeringDlg, pParent)
{

}

EnguneeringDlg::~EnguneeringDlg()
{
}

void EnguneeringDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_ENGINEERING, m_TabCtrl);
}


BEGIN_MESSAGE_MAP(EnguneeringDlg, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_ENGINEERING, &EnguneeringDlg::OnTcnSelchangeTabEngineering)
END_MESSAGE_MAP()


// EnguneeringDlg 訊息處理常式


BOOL EnguneeringDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此加入額外的初始化
	CWnd* This = AfxGetMainWnd();
	This->SetWindowTextA("BCM生產履歷APP");

	TCITEM tcItem;
	tcItem.mask = TCIF_TEXT;
	tcItem.pszText = _T("樣板流程部屬編輯對話框");
	m_TabCtrl.InsertItem(ENG_TEMP_FLOW_DEPLOY_DLG, &tcItem);
	tcItem.pszText = _T("內控流程部屬編輯對話框");
	m_TabCtrl.InsertItem(ENG_EDIT_FLOW_DEPLOY_DLG, &tcItem);
	tcItem.pszText = _T("站台編輯對話框");
	m_TabCtrl.InsertItem(ENG_EDIT_STATION_DLG, &tcItem);
	tcItem.pszText = _T("錯誤代碼編輯對話框");
	m_TabCtrl.InsertItem(ENG_EDIT_ERROR_CODE_DLG, &tcItem);
	
	CRect rs;
	m_TabCtrl.GetClientRect(&rs);
	rs.top += 25;
	rs.bottom -= 10;
	rs.left += 1;
	rs.right -= 2;

	m_TempFlowDeployDlg.Create(IDD_TempFlowDeployDlg, &m_TabCtrl);
	m_pWndModleDlg[ENG_TEMP_FLOW_DEPLOY_DLG] = &m_TempFlowDeployDlg;
	m_TempFlowDeployDlg.MoveWindow(&rs);

	m_CtrlSNFlowDeployDlg.Create(IDD_CtrlSNFlowDeployDlg, &m_TabCtrl);
	m_pWndModleDlg[ENG_EDIT_FLOW_DEPLOY_DLG] = &m_CtrlSNFlowDeployDlg;
	m_CtrlSNFlowDeployDlg.MoveWindow(&rs);

	m_ManageStationDlg.Create(IDD_ManageStationDlg, &m_TabCtrl);
	m_pWndModleDlg[ENG_EDIT_STATION_DLG] = &m_ManageStationDlg;
	m_ManageStationDlg.MoveWindow(&rs);

	m_ManageErrorCodeDlg.Create(IDD_ManageErrorCodeDlg, &m_TabCtrl);
	m_pWndModleDlg[ENG_EDIT_ERROR_CODE_DLG] = &m_ManageErrorCodeDlg;
	m_ManageErrorCodeDlg.MoveWindow(&rs);

	m_TempFlowDeployDlg.ShowWindow(true);
	m_CtrlSNFlowDeployDlg.ShowWindow(false);
	m_ManageStationDlg.ShowWindow(false);
	m_ManageErrorCodeDlg.ShowWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void EnguneeringDlg::OnTcnSelchangeTabEngineering(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int CurSel = m_TabCtrl.GetCurSel();
	switch (CurSel)
	{
	case ENG_TEMP_FLOW_DEPLOY_DLG:
		m_TempFlowDeployDlg.ShowWindow(true);
		m_CtrlSNFlowDeployDlg.ShowWindow(false);
		m_ManageStationDlg.ShowWindow(false);
		m_ManageErrorCodeDlg.ShowWindow(false);
		break;
	case ENG_EDIT_FLOW_DEPLOY_DLG:
		m_TempFlowDeployDlg.ShowWindow(false);
		m_CtrlSNFlowDeployDlg.ShowWindow(true);
		m_ManageStationDlg.ShowWindow(false);
		m_ManageErrorCodeDlg.ShowWindow(false);
		break;
	case ENG_EDIT_STATION_DLG:
		m_TempFlowDeployDlg.ShowWindow(false);
		m_CtrlSNFlowDeployDlg.ShowWindow(false);
		m_ManageStationDlg.ShowWindow(true);
		m_ManageErrorCodeDlg.ShowWindow(false);
		break;
	case ENG_EDIT_ERROR_CODE_DLG:
		m_TempFlowDeployDlg.ShowWindow(false);
		m_CtrlSNFlowDeployDlg.ShowWindow(false);
		m_ManageStationDlg.ShowWindow(false);
		m_ManageErrorCodeDlg.ShowWindow(true);
		break;
	}

	*pResult = 0;
}
