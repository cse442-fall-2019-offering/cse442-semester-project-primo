// settingDialog.cpp: 实现文件
//

#include "pch.h"
#include "Chinese_Chess.h"
#include "settingDialog.h"
#include "afxdialogex.h"


// settingDialog 对话框

IMPLEMENT_DYNAMIC(settingDialog, CDialogEx)

settingDialog::settingDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Settings, pParent)
{

}

settingDialog::~settingDialog()
{
}

void settingDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(settingDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &settingDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// settingDialog 消息处理程序


void settingDialog::OnBnClickedOk()
{
	CDialogEx::OnOK();
	DestroyWindow();
}
