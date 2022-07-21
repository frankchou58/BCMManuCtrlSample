// InputMACAddrDlg.cpp: 實作檔案
//

#include "pch.h"
#include "MFCApplication1.h"
#include "InputMACAddrDlg.h"
#include "afxdialogex.h"
#include "BurnMACDlg.h"

// InputMACAddrDlg 對話方塊

IMPLEMENT_DYNAMIC(InputMACAddrDlg, CDialogEx)

InputMACAddrDlg::InputMACAddrDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_InputMACAddrDlg, pParent)
{

	m_Result = 0;
}

InputMACAddrDlg::~InputMACAddrDlg()
{
}

void InputMACAddrDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_InputMAC1Addr);
	DDX_Control(pDX, IDC_EDIT2, m_InputMAC2Addr);
	//  DDX_Control(pDX, IDOK, m_Ok);
	//  DDX_Control(pDX, IDC_BUTTON1, m_OK);
	//  DDX_Control(pDX, IDOK, m_OK);
	//  DDX_Control(pDX, IDC_BUTTON_OK, m_OK);
}


BEGIN_MESSAGE_MAP(InputMACAddrDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &InputMACAddrDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &InputMACAddrDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDOK, &InputMACAddrDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_OK, &InputMACAddrDlg::OnBnClickedButtonOk)
	ON_BN_CLICKED(IDCANCEL, &InputMACAddrDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// InputMACAddrDlg 訊息處理常式


void InputMACAddrDlg::OnEnChangeEdit1()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	CString MACAddr;

	int Len = m_InputMAC1Addr.GetWindowTextLengthA();

	if (Len == 12)
	{
		m_InputMAC2Addr.SetFocus();
	}

}


void InputMACAddrDlg::OnEnChangeEdit2()
{
	// TODO:  如果這是 RICHEDIT 控制項，控制項將不會
	// 傳送此告知，除非您覆寫 CDialogEx::OnInitDialog()
	// 函式和呼叫 CRichEditCtrl().SetEventMask()
	// 讓具有 ENM_CHANGE 旗標 ORed 加入遮罩。

	// TODO:  在此加入控制項告知處理常式程式碼
	int Len = m_InputMAC2Addr.GetWindowTextLengthA();
	if (Len == 12)
	{
		m_InputMAC1Addr.GetWindowTextA(m_Mac1);
		m_InputMAC2Addr.GetWindowTextA(m_Mac2);
		
		BurnMACDlg* pBurnMACDlg = (BurnMACDlg *)AfxGetMainWnd();
		pBurnMACDlg->PutMacAddress(m_Mac1.GetBuffer(), m_Mac2.GetBuffer());

		OnBnClickedButtonOk();
		CDialogEx::OnCancel();
	}
}


void InputMACAddrDlg::OnBnClickedOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	//CDialogEx::OnOK();
}


void InputMACAddrDlg::OnBnClickedButtonOk()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	m_Result = 1;
//	CDialogEx::OnOK();
}




int InputMACAddrDlg::GetMacAddress(PCHAR pMac1, PCHAR pMac2)
{
	// TODO: 請在此新增您的實作程式碼.

	return 0;
}


int InputMACAddrDlg::GetResult()
{
	// TODO: 請在此新增您的實作程式碼.
	return m_Result;
}


void InputMACAddrDlg::OnBnClickedCancel()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	m_Result = 2;
	CDialogEx::OnCancel();
}
