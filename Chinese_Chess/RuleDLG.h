#pragma once


// RuleDLG 对话框

class RuleDLG : public CDialog
{
	DECLARE_DYNAMIC(RuleDLG)

public:
	RuleDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RuleDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RULE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
