// AddCustomerMACDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "AddCustomerMACDlg.h"
#include "afxdialogex.h"


// AddCustomerMACDlg 對話方塊

IMPLEMENT_DYNAMIC(AddCustomerMACDlg, CDialogEx)

AddCustomerMACDlg::AddCustomerMACDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AddCustomerMACDlg, pParent)
{

}

AddCustomerMACDlg::~AddCustomerMACDlg()
{
}

void AddCustomerMACDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(AddCustomerMACDlg, CDialogEx)
END_MESSAGE_MAP()


// AddCustomerMACDlg 訊息處理常式
