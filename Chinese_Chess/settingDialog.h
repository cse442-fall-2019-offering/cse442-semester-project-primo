#pragma once


// settingDialog 对话框

class settingDialog : public CDialogEx
{
	DECLARE_DYNAMIC(settingDialog)

public:
	settingDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~settingDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Settings };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
