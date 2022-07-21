// LoginDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// LoginDlg 對話方塊

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoginDlg, pParent)
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_ListStation);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LoginDlg 訊息處理常式


//void LoginDlg::OnFinalRelease()
//{
//	// TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
//
//	CDialogEx::OnFinalRelease();
//}

BOOL LoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// TODO:  在此加入額外的初始化
	PStationData_T pStationData;
	m_OpenCounter = AfxGetApp()->GetProfileInt("Settings", "OpenCounter", 0);
	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	int SelectedStaion = AfxGetApp()->GetProfileInt(SettingString, "SelectedStation", 0);
	int Number = sizeof(g_StationData) / sizeof(StationData_T);
	for (int i = 0; i < Number; i++)
	{
		pStationData = &g_StationData[i];
		m_ListStation.AddString(pStationData->StationName);
		if (SelectedStaion == pStationData->StationId)
			m_ListStation.SetCurSel(i);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX 屬性頁應傳回 FALSE
}


void LoginDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	int Selected = m_ListStation.GetCurSel();
	int StationNo = g_StationData[Selected].StationId;
	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	AfxGetApp()->WriteProfileInt(SettingString, "SelectedStation", StationNo);

	CDialogEx::OnOK();
}
