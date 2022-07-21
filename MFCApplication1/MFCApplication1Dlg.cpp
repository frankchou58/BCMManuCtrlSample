
// MFCApplication1Dlg.cpp: 實作檔案
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"
#include "ProductionCtrlDlg.h"
#include "SmdDlg.h"
#include "SmdFixDlg.h"
#include "MaterialCtrlDlg.h"
#include "TempFlowDeployDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 對話方塊



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDCANCEL, m_Text);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_LIST_CTRL_NO, m_ListCtrlNo);
	DDX_Control(pDX, IDC_SHOW_STATION_NAME, m_ShowStationName);
	DDX_Control(pDX, IDC_RADIO_BATCH, m_RadioBatch);
	DDX_Control(pDX, IDC_RADIO_ONE, m_RadioOne);
	DDX_Control(pDX, IDC_EDIT_CTRL_NO, m_EditCtrlNo);
	DDX_Control(pDX, IDC_BUTTON_SURE, m_BtnSure);
	DDX_Control(pDX, IDC_EDIT_MNO, m_MNo);
	DDX_Control(pDX, IDC_COMBO_M_TYPE, m_MType);
	DDX_Control(pDX, IDC_SHOW_DESC, m_ShowDesc);
	DDX_Control(pDX, IDC_SHOW_INO, m_ShowINo);
	DDX_Control(pDX, IDC_SHOW_CTRL_LIST, m_ShowCtrlList);
	DDX_Control(pDX, IDC_SHOW_PARENT_MNO, m_ShowParentMNo);
	//  DDX_Control(pDX, IDC_SHOW_MTYPE, m_ShowMType);
	DDX_Control(pDX, IDC_SHOW_MTYPE, m_ShowParentMType);
	DDX_Control(pDX, IDC_SHOW_PARENT_DESC, m_ShowParentDesc);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
//	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO_ONE, &CMFCApplication1Dlg::OnBnClickedRadioOne)
	ON_BN_CLICKED(IDC_RADIO_BATCH, &CMFCApplication1Dlg::OnBnClickedRadioBatch)
	ON_COMMAND(ID_STATION_SELECT, &CMFCApplication1Dlg::OnStationSelect)
	ON_COMMAND(ID_STATION_1, &CMFCApplication1Dlg::OnStation1)
	ON_COMMAND(ID_STATION_3, &CMFCApplication1Dlg::OnStation3)
	ON_COMMAND(ID_STATION_4, &CMFCApplication1Dlg::OnStation4)
	ON_WM_DESTROY()
	ON_COMMAND(ID_STATION_23, &CMFCApplication1Dlg::OnStation23)
	ON_COMMAND(ID_STATION_25, &CMFCApplication1Dlg::OnStation25)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 訊息處理常式

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	LoginDlg LoginDlg;
	INT nResponse = LoginDlg.DoModal();

#define STATION_ID_MATERIAL_CTRL	1
#define STATION_IDPRDUCTION_CTRL	18
#define STATION_ID_SMD				15
#define STATION_ID_SMD_FIX			34
#define STATION_ID_ENG				21
#define STATION_ID_ENG_FLOW_DEPLOY	24

	if (nResponse == IDOK)
	{
		ProductionCtrlDlg ProductionCtrlDlg;
		SmdDlg SmdDlg;
		SmdFixDlg SmdFixDlg;
		MaterialCtrlDlg MaterialCtrlDlg;
		TempFlowDeployDlg TempFlowDeployDlg;

		int StationNo = STATION_ID_ENG_FLOW_DEPLOY;

		switch (StationNo)
		{
		case STATION_ID_MATERIAL_CTRL:
			MaterialCtrlDlg.DoModal();
			break;
		case STATION_IDPRDUCTION_CTRL:
			ProductionCtrlDlg.DoModal();
			break;
		case STATION_ID_SMD:
			SmdDlg.DoModal();
			break;
		case STATION_ID_SMD_FIX:
			SmdFixDlg.DoModal();
			break;
		case STATION_ID_ENG_FLOW_DEPLOY:
			TempFlowDeployDlg.DoModal();
			break;
		}
	}

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

//void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

//void CMFCApplication1Dlg::OnPaint()
//{
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // 繪製的裝置內容
//
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// 將圖示置中於用戶端矩形
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// 描繪圖示
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
//		CDialogEx::OnPaint();
//	}
//}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
//HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}



void CMFCApplication1Dlg::OnBnClickedRadioOne()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CMFCApplication1Dlg::OnBnClickedRadioBatch()
{
	// TODO: 在此加入控制項告知處理常式程式碼
}


void CMFCApplication1Dlg::OnStationSelect()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CWnd* pMain = AfxGetMainWnd();
	CMenu* pMenu = pMain->GetMenu();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	int SelectedStaion = AfxGetApp()->GetProfileInt(SettingString, "SelectedStation", 0);

	if (SelectedStaion == 0)
	{
		pMenu->CheckMenuItem(ID_STATION_1, MF_CHECKED);
		pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
		m_ShowStationName.SetWindowTextA("倉管");
	}
	else if (SelectedStaion == 1)
	{
		pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_3, MF_CHECKED);
		pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
		m_ShowStationName.SetWindowTextA("測試燒MAC");
	}
	else if (SelectedStaion == 2)
	{
		pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_4, MF_CHECKED);
		pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
		m_ShowStationName.SetWindowTextA("DIP半成品倉");
	}
	else if (SelectedStaion == 3)
	{
		pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_23, MF_CHECKED);
		pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
		m_ShowStationName.SetWindowTextA("SMD半成品倉");
	}
	else if (SelectedStaion == 4)
	{
		pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
		pMenu->CheckMenuItem(ID_STATION_25, MF_CHECKED);
		m_ShowStationName.SetWindowTextA("DIP");
	}
}


void CMFCApplication1Dlg::OnStation1()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMenu* pMenu;
	pMenu = GetMenu();

	pMenu->CheckMenuItem(ID_STATION_1, MF_CHECKED);
	pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
	CWinApp* pApp = AfxGetApp();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	pApp->WriteProfileInt(SettingString, "SelectedStation", 0);
	m_ShowStationName.SetWindowTextA("倉管");
}


void CMFCApplication1Dlg::OnStation3()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMenu* pMenu;
	pMenu = GetMenu();

	pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_3, MF_CHECKED);
	pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
	CWinApp* pApp = AfxGetApp();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	pApp->WriteProfileInt(SettingString, "SelectedStation", 1);
	m_ShowStationName.SetWindowTextA("測試燒MAC");
}


void CMFCApplication1Dlg::OnStation4()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMenu* pMenu;
	pMenu = GetMenu();

	pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_4, MF_CHECKED);
	pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
	CWinApp* pApp = AfxGetApp();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	pApp->WriteProfileInt(SettingString, "SelectedStation", 2);
	m_ShowStationName.SetWindowTextA("DIP半成品倉");
}


void CMFCApplication1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此加入您的訊息處理常式程式碼
	int OpenCounter = AfxGetApp()->GetProfileInt("Settings", "OpenCounter", 0);
	OpenCounter--;
	AfxGetApp()->WriteProfileInt("Settings", "OpenCounter", OpenCounter);
}


void CMFCApplication1Dlg::OnStation23()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMenu* pMenu;
	pMenu = GetMenu();

	pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_23, MF_CHECKED);
	pMenu->CheckMenuItem(ID_STATION_25, MF_UNCHECKED);
	CWinApp* pApp = AfxGetApp();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	pApp->WriteProfileInt(SettingString, "SelectedStation", 3);
	m_ShowStationName.SetWindowTextA("SMD半成品倉");
}


void CMFCApplication1Dlg::OnStation25()
{
	// TODO: 在此加入您的命令處理常式程式碼
	CMenu* pMenu;
	pMenu = GetMenu();

	pMenu->CheckMenuItem(ID_STATION_1, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_3, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_4, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_23, MF_UNCHECKED);
	pMenu->CheckMenuItem(ID_STATION_25, MF_CHECKED);
	CWinApp* pApp = AfxGetApp();

	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	pApp->WriteProfileInt(SettingString, "SelectedStation", 4);
	m_ShowStationName.SetWindowTextA("DIP");

}


//INT_PTR CMFCApplication1Dlg::DoModal()
//{
//	// TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
//
//	return CDialogEx::DoModal();
//}


//INT_PTR CMFCApplication1Dlg::DoModal()
//{
//	// TODO: 在此加入特定的程式碼和 (或) 呼叫基底類別
//
//	return CDialogEx::DoModal();
//}
