#pragma once


// InternetDlg 对话框

class InternetDlg : public CDialog
{
	DECLARE_DYNAMIC(InternetDlg)

public:
	InternetDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~InternetDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INTERNET };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL isHost;
	BOOL isBlack;
	bool isLink;
	int netPort;
	CString ipAddress;
	afx_msg void OnBnClickedRadioClient();
	afx_msg void OnBnClickedRadioHost();
	afx_msg void OnChangeEditPort();
	virtual BOOL OnInitDialog();
};
