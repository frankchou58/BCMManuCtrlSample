
// MFCApplication1.h: PROJECT_NAME 應用程式的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 在包含此檔案前先包含 'pch.h'"
#endif

#include "resource.h"		// 主要符號


// CMFCApplication1App:
// 查看 MFCApplication1.cpp 以了解此類別的實作
//

class CMFCApplication1App : public CWinApp
{
public:
	CMFCApplication1App();

// 覆寫
public:
	virtual BOOL InitInstance();

// 程式碼實作
	int m_OpenCounter;
	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication1App theApp;
typedef struct CtrlSNList_Tag
{
	CHAR	CtrlSN[100];
	CHAR	MType[10];
	CHAR	MNo[100];
	CHAR	MDesc[200];
	CHAR	MINo[20];
	CHAR	MAC1[100];
	BOOL	bMACPrintOut;
	BOOL	bPutInStation;
}CtrlSNList_T, * PCtrlSNList_T;

typedef struct StationData_Tag
{
	INT		StationId;
	BOOL	bIsTemplate;
	BOOL	bIsStationCtrlSnBatch;
	BOOL	bIsStationException;
	CHAR	StationName[100];
}StationData_T, *PStationData_T;

typedef struct ErrorCode_Tag
{
	INT		QID;
	CHAR	QDescEng[250];
	CHAR	QDescChn[250];
}ErrorCode_T, *PErrorCode_T;