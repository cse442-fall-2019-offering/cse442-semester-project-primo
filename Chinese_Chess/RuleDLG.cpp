// RuleDLG.cpp: 实现文件
//

#include "pch.h"
#include "Chinese_Chess.h"
#include "RuleDLG.h"
#include "afxdialogex.h"


// RuleDLG 对话框

IMPLEMENT_DYNAMIC(RuleDLG, CDialog)

RuleDLG::RuleDLG(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_RULE, pParent)
{

}

RuleDLG::~RuleDLG()
{
}

void RuleDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(RuleDLG, CDialog)
END_MESSAGE_MAP()


// RuleDLG 消息处理程序
