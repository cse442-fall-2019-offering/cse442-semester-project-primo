#pragma once


// Settings 对话框

class Settings : public CDialog
{
	DECLARE_DYNAMIC(Settings)

	Settings(CWnd* pParent, CChineseChessDlg* mainDlg);
	// 标准构造函数
	virtual ~Settings();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Settings };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChangeui();
	afx_msg void OnBnClickedCancel();
};
