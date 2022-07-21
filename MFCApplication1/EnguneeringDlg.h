#pragma once
#include "TempFlowDeployDlg.h"
#include "CtrlSNFlowDeployDlg.h"
#include "ManageStationDlg.h"
#include "ManageErrorCodeDlg.h"

// EnguneeringDlg 對話方塊

class EnguneeringDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EnguneeringDlg)

public:
	EnguneeringDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~EnguneeringDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EnguneeringDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl m_TabCtrl;
	TempFlowDeployDlg m_TempFlowDeployDlg;
	CtrlSNFlowDeployDlg m_CtrlSNFlowDeployDlg;
	ManageStationDlg m_ManageStationDlg;
	ManageErrorCodeDlg m_ManageErrorCodeDlg;
	afx_msg void OnTcnSelchangeTabEngineering(NMHDR* pNMHDR, LRESULT* pResult);
	CWnd* m_pWndModleDlg[6];
};

enum 
{
	ENG_TEMP_FLOW_DEPLOY_DLG = 0,
	ENG_EDIT_FLOW_DEPLOY_DLG,
	ENG_EDIT_STATION_DLG,
	ENG_EDIT_ERROR_CODE_DLG,
};

