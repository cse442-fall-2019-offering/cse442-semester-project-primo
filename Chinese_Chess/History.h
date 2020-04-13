#pragma once


// History 对话框

class History : public CDialogEx
{
	DECLARE_DYNAMIC(History)

public:
	History(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~History();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_History };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
};
