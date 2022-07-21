// EditCtrlSnDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "EditCtrlSnDlg.h"
#include "afxdialogex.h"


// EditCtrlSnDlg 對話方塊

IMPLEMENT_DYNAMIC(EditCtrlSnDlg, CDialogEx)

EditCtrlSnDlg::EditCtrlSnDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EditCtrlSnDlg, pParent)
{

}

EditCtrlSnDlg::~EditCtrlSnDlg()
{
}

void EditCtrlSnDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(EditCtrlSnDlg, CDialogEx)
END_MESSAGE_MAP()


// EditCtrlSnDlg 訊息處理常式
