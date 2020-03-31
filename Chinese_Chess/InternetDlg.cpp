// InternetDlg.cpp: 实现文件
//

#include "pch.h"
#include "Chinese_Chess.h"
#include "InternetDlg.h"
#include "afxdialogex.h"


// InternetDlg 对话框

IMPLEMENT_DYNAMIC(InternetDlg, CDialog)

InternetDlg::InternetDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_INTERNET, pParent)
{
	isHost = TRUE;
	isBlack = TRUE;
	netPort = 10000;
	ipAddress = "127.0.0.1";
}

InternetDlg::~InternetDlg()
{
}

void InternetDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PORT, netPort);
	DDX_Radio(pDX, IDC_RADIO_CLIENT, isHost);
	DDX_Radio(pDX, IDC_RADIO_WHITE, isBlack);

	GetDlgItem(IDC_IPADDRESS)->GetWindowText(ipAddress);

	if (isLink)
	{
		GetDlgItem(IDC_RADIO_CLIENT)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_HOST)->EnableWindow(FALSE);
		GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_PORT)->EnableWindow(FALSE);
	}
	if (!isHost)
	{
		GetDlgItem(IDC_RADIO_BLACK)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIO_WHITE)->EnableWindow(FALSE);
	}
}


BEGIN_MESSAGE_MAP(InternetDlg, CDialog)
	ON_BN_CLICKED(IDC_RADIO_HOST, &InternetDlg::OnBnClickedRadioHost)
	ON_BN_CLICKED(IDC_RADIO_HOST, &InternetDlg::OnBnClickedRadioHost)
	ON_EN_CHANGE(IDC_EDIT_PORT, &InternetDlg::OnChangeEditPort)
END_MESSAGE_MAP()


// InternetDlg 消息处理程序
BOOL InternetDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	GetDlgItem(IDC_IPADDRESS)->SetWindowText(LPCTSTR("127.0.0.1"));
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE);
	((CEdit*)GetDlgItem(IDC_EDIT_PORT))->LimitText(8);

	return TRUE;
}

void InternetDlg::OnBnClickedRadioHost()
{
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_BLACK)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_WHITE)->EnableWindow(TRUE);
}

void InternetDlg::OnBnClickedRadioClient()
{
	GetDlgItem(IDC_IPADDRESS)->EnableWindow(TRUE);
	GetDlgItem(IDC_RADIO_BLACK)->EnableWindow(FALSE);
	GetDlgItem(IDC_RADIO_WHITE)->EnableWindow(FALSE);
}

void InternetDlg::OnChangeEditPort()
{
	char cPort[8];
	((CEdit*)GetDlgItem(IDC_EDIT_PORT))->GetWindowTextW(CString(cPort));
	if (atoi(cPort) > 65535) 
	{
		MessageBeep(0);
		((CEdit*)GetDlgItem(IDC_EDIT_PORT))->SetWindowText(LPTSTR("65535"));
		((CEdit*)GetDlgItem(IDC_EDIT_PORT))->SetSel(0, -1);
	}
}