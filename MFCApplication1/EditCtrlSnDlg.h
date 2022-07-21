#pragma once


// EditCtrlSnDlg 對話方塊

class EditCtrlSnDlg : public CDialogEx
{
	DECLARE_DYNAMIC(EditCtrlSnDlg)

public:
	EditCtrlSnDlg(CWnd* pParent = nullptr);   // 標準建構函式
	virtual ~EditCtrlSnDlg();

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EditCtrlSnDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

	DECLARE_MESSAGE_MAP()
};
