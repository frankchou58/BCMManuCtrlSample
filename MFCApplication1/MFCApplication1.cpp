
// MFCApplication1.cpp: 定義應用程式的類別表現方式。
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "LoginDlg.h"
#include "TemplateStationDlg.h"
#include "ProductionCtrlDlg.h"
#include "SmdDlg.h"
#include "SmdFixDlg.h"
#include "MaterialCtrlDlg.h"
#include "BusinessDlg.h"
#include "PrintMACDlg.h"
#include "BurnMACDlg.h"
#include "EnguneeringDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1App

BEGIN_MESSAGE_MAP(CMFCApplication1App, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CMFCApplication1App 建構

CMFCApplication1App::CMFCApplication1App()
{
	// 支援重新啟動管理員
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: 在此加入建構程式碼，
	// 將所有重要的初始設定加入 InitInstance 中
}


// 唯一一個 CMFCApplication1App 物件

CMFCApplication1App theApp;


// CMFCApplication1App 初始化
#define STATION_ID_TEMP				0
#define STATION_ID_MATERIAL_CTRL	1
#define STATION_ID_ENG				2
#define STATION_ID_BUSINESS			3
#define STATION_ID_PRDUCTION_CTRL	4
#define STATION_ID_MAC_PRINT		5
#define STATION_ID_BURN_MAC			6
#define STATION_ID_SMD_FIX			7
#define STATION_ID_FT1				8
#define STATION_ID_FT2				9
#define STATION_ID_FT3				10
#define STATION_ID_FT4				11
#define STATION_ID_FIX				12
#define STATION_ID_SF1				13
#define STATION_ID_SF2				14
#define STATION_ID_SF3				15
#define STATION_ID_SF_FIX			16
#define STATION_ID_REWORK			17
#define STATION_ID_RMA				18
/*工程自行定義*/
#define STATION_ID_SMD				50
#define STATION_ID_SMD_SFP			51 /*SMD 半成品*/



StationData_T g_StationData[20] =
{
	{STATION_ID_MATERIAL_CTRL, FALSE, FALSE, FALSE, "倉管"},
	{STATION_ID_ENG, FALSE, FALSE, FALSE, "工程"},
	{STATION_ID_BUSINESS, FALSE, FALSE, FALSE, "業務"},
	{STATION_ID_PRDUCTION_CTRL, FALSE, FALSE, FALSE, "生管"},
	{STATION_ID_BURN_MAC, FALSE, FALSE, FALSE, "燒MAC"},
	{STATION_ID_MAC_PRINT, FALSE, FALSE, FALSE, "MAC管理"},
	{STATION_ID_SMD_FIX, FALSE, FALSE, TRUE, "SMD維修站"},
	{STATION_ID_FT1, FALSE, FALSE, FALSE, "功能測試站1"},
	{STATION_ID_FT2, FALSE, FALSE, FALSE, "功能測試站2"},
	{STATION_ID_FT3, FALSE, FALSE, FALSE, "功能測試站3"},
	{STATION_ID_FT4, FALSE, FALSE, FALSE, "功能測試站4"},
	{STATION_ID_FIX, FALSE, FALSE, TRUE, "維修站"},
	{STATION_ID_SF1, FALSE, FALSE, FALSE, "系統測試站1"},
	{STATION_ID_SF2, FALSE, FALSE, FALSE, "系統測試站2"},
	{STATION_ID_SF3, FALSE, FALSE, FALSE, "系統測試站3"},
	{STATION_ID_SF_FIX, FALSE, FALSE, TRUE, "系統維修站"},
	{STATION_ID_REWORK, FALSE, FALSE, TRUE, "重工站"},
	{STATION_ID_RMA, FALSE, FALSE, TRUE, "RMA站"},

	{STATION_ID_SMD, TRUE, TRUE, FALSE, "SMD收料站"},
	{STATION_ID_SMD_SFP, TRUE, FALSE, FALSE, "SMD半成品站"},
};

BOOL CMFCApplication1App::InitInstance()
{
	// 假如應用程式資訊清單指定使用 ComCtl32.dll 6 (含) 以後版本，
	// 來啟動視覺化樣式，在 Windows XP 上，則需要 InitCommonControls()。
	// 否則任何視窗的建立都將失敗。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 設定要包含所有您想要用於應用程式中的
	// 通用控制項類別。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	AfxEnableControlContainer();

	// 建立殼層管理員，以防對話方塊包含
	// 任何殼層樹狀檢視或殼層清單檢視控制項。
	CShellManager *pShellManager = new CShellManager;

	// 啟動 [Windows 原生] 視覺化管理員可啟用 MFC 控制項中的主題
	CMFCVisualManager::SetDefaultManager(RUNTIME_CLASS(CMFCVisualManagerWindows));

	// 標準初始設定
	// 如果您不使用這些功能並且想減少
	// 最後完成的可執行檔大小，您可以
	// 從下列程式碼移除不需要的初始化常式，
	// 變更儲存設定值的登錄機碼
	// TODO: 您應該適度修改此字串
	// (例如，公司名稱或組織名稱)
	SetRegistryKey(_T("本機 AppWizard 所產生的應用程式"));

	CWnd* pWndPrev, * pWndChild;
	char		ClassName[200] = "BCM生產履歷APP";
	CString		StoreClassName;
	StoreClassName = AfxGetApp()->GetProfileString("Settings", "Class Name", "default string");
	pWndPrev = CWnd::FindWindow(NULL, ClassName);
	if (pWndPrev != NULL)
	{
		m_OpenCounter = AfxGetApp()->GetProfileInt("Settings", "OpenCounter", 0);
		m_OpenCounter++;
		if (m_OpenCounter == 4)
		{
			MessageBoxA(NULL, "超過開啟數目", "警告", MB_ICONWARNING);
			return FALSE;
		}
		AfxGetApp()->WriteProfileInt("Settings", "OpenCounter", m_OpenCounter);
	}
	else
	{
		AfxGetApp()->WriteProfileInt("Settings", "OpenCounter", 0);
	}

#if 0
	INT_PTR nResponse;
	CMFCApplication1Dlg dlg;
	m_pMainWnd = &dlg;
	nResponse = dlg.DoModal();
#endif
#if 1

	INT_PTR nResponse = IDOK;
	LoginDlg LoginDlg;
	nResponse = LoginDlg.DoModal();

	AfxGetApp()->WriteProfileString("Settings", "Class Name", ClassName);
	CHAR SettingString[50];
	sprintf_s(SettingString, 50, "Settings_%d", m_OpenCounter);
	int SelectedStaion = AfxGetApp()->GetProfileInt(SettingString, "SelectedStation", 0);

	CMFCApplication1Dlg dlg;
	TemplateStationDlg TemplateStationDlg;
	ProductionCtrlDlg ProductionCtrlDlg;
	BurnMACDlg BurnMACDlg;
	SmdDlg SmdDlg;
	SmdFixDlg SmdFixDlg;
	MaterialCtrlDlg MaterialCtrlDlg;
	EnguneeringDlg EnguneeringDlg;
	BusinessDlg BusinessDlg;
	PrintMACDlg PrintMACDlg;
	int Index;
	if (nResponse == IDOK)
	{
		int StationNo = SelectedStaion;
		int StationNumbers = sizeof(g_StationData) / sizeof(StationData_T);
		for (int i = 0; i < StationNumbers; i++)
		{
			if (SelectedStaion == g_StationData[i].StationId && g_StationData[i].bIsTemplate == TRUE)
			{
				StationNo = STATION_ID_TEMP;
				Index = i;
				break;
			}
		}

		int ThisStation = SelectedStaion;

		switch (StationNo)
		{
		case STATION_ID_TEMP:
			ThisStation = g_StationData[Index].StationId;
			m_pMainWnd = &TemplateStationDlg;
			nResponse = TemplateStationDlg.DoModal();
			break;
		case STATION_ID_MATERIAL_CTRL:
			m_pMainWnd = &MaterialCtrlDlg;
			nResponse = MaterialCtrlDlg.DoModal();
			break;
		case STATION_ID_PRDUCTION_CTRL:
			m_pMainWnd = &ProductionCtrlDlg;
			nResponse = ProductionCtrlDlg.DoModal();
			break;
		case 20:
			m_pMainWnd = &dlg;
			nResponse = dlg.DoModal();
			break;
		case STATION_ID_ENG:
			m_pMainWnd = &EnguneeringDlg;
			nResponse = EnguneeringDlg.DoModal();
			break;
		case STATION_ID_BUSINESS:
			m_pMainWnd = &BusinessDlg;
			nResponse = BusinessDlg.DoModal();
			break;
		case STATION_ID_MAC_PRINT:
			m_pMainWnd = &PrintMACDlg;
			nResponse = PrintMACDlg.DoModal();
			break;
		case STATION_ID_BURN_MAC:
			m_pMainWnd = &BurnMACDlg;
			nResponse = BurnMACDlg.DoModal();
			break;		
		case STATION_ID_SMD_FIX:
			m_pMainWnd = &SmdFixDlg;
			nResponse = SmdFixDlg.DoModal();
			break;
		}
		AfxGetApp()->WriteProfileInt(SettingString, "SelectedStation", ThisStation);
	}
#endif

	if (nResponse == IDOK)
	{
		// TODO: 在此放置於使用 [確定] 來停止使用對話方塊時
		// 處理的程式碼
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: 在此放置於使用 [取消] 來停止使用對話方塊時
		// 處理的程式碼
	}
	else if (nResponse == -1)
	{
		TRACE(traceAppMsg, 0, "警告: 對話方塊建立失敗，因此，應用程式意外終止。\n");
		TRACE(traceAppMsg, 0, "警告: 如果您要在對話方塊上使用 MFC 控制項，則無法 #define _AFX_NO_MFC_CONTROLS_IN_DIALOGS。\n");
	}

	// 刪除上面所建立的殼層管理員。
	if (pShellManager != nullptr)
	{
		delete pShellManager;
	}

#if !defined(_AFXDLL) && !defined(_AFX_NO_MFC_CONTROLS_IN_DIALOGS)
	ControlBarCleanUp();
#endif

	// 因為已經關閉對話方塊，傳回 FALSE，所以我們會結束應用程式，
	// 而非提示開始應用程式的訊息。
	return FALSE;
}

