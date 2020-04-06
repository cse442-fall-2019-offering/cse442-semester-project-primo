// Settings.cpp: 实现文件
//

#include "pch.h"
#include "Chinese_Chess.h"
#include "Chinese_ChessDlg.h"
#include "Settings.h"
#include "afxdialogex.h"
#include "Resource.h"

CChineseChessDlg* _mainDlg;

// Settings 对话框

IMPLEMENT_DYNAMIC(Settings, CDialog)

Settings::Settings(CWnd* pParent /*=nullptr*/, CChineseChessDlg mainDlg)
	: CDialog(IDD_Settings, pParent)
{
	_mainDlg = &mainDlg;
}

Settings::~Settings()
{
}

void Settings::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Settings, CDialog)

	ON_BN_CLICKED(IDC_ChangeUI, &Settings::OnBnClickedChangeui)
END_MESSAGE_MAP()


// Settings 消息处理程序

void Settings::OnBnClickedChangeui()
{
	_mainDlg->UIChange_Button_ini();
}
