// AddFlowDeployDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "AddFlowDeployDlg.h"
#include "afxdialogex.h"
#include "EnguneeringDlg.h"
#include "TempFlowDeployDlg.h"

// AddFlowDeployDlg 對話方塊

IMPLEMENT_DYNAMIC(AddFlowDeployDlg, CDialogEx)

AddFlowDeployDlg::AddFlowDeployDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddFlowDeployDlg, pParent)
{

}

AddFlowDeployDlg::~AddFlowDeployDlg()
{
}

void AddFlowDeployDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddFlowDeployDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AddFlowDeployDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// AddFlowDeployDlg 訊息處理常式


void AddFlowDeployDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	EnguneeringDlg* pEnguneeringDlg;
	pEnguneeringDlg = (EnguneeringDlg*)AfxGetMainWnd();

	TempFlowDeployDlg* pTempFlowDeployDlg;
	pTempFlowDeployDlg = (TempFlowDeployDlg*)pEnguneeringDlg->m_pWndModleDlg[ENG_TEMP_FLOW_DEPLOY_DLG];
	pTempFlowDeployDlg->OnBnClickedAddTempFlowDeploy();

	CDialogEx::OnOK();
}
