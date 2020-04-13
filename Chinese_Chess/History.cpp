// History.cpp: 实现文件
//

#include "pch.h"
#include "Chinese_Chess.h"
#include "History.h"
#include "afxdialogex.h"


// History 对话框

IMPLEMENT_DYNAMIC(History, CDialogEx)

History::History(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_History, pParent)
{

}

History::~History()
{
}

void History::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(History, CDialogEx)
	ON_BN_CLICKED(IDC_CLOSE, &History::OnBnClickedClose)
END_MESSAGE_MAP()


// History 消息处理程序


void History::OnBnClickedClose()
{
	DestroyWindow();
	CDialog::OnCancel();
	// TODO: 在此添加控件通知处理程序代码
}

