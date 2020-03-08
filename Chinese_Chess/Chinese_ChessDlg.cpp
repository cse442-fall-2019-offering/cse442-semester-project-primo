
// Chinese_ChessDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Chinese_Chess.h"
#include "Chinese_ChessDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include "Game.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CChineseChessDlg dialog



CChineseChessDlg::CChineseChessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHINESE_CHESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_GAME_ICON);
}

void CChineseChessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BSTART, BStart);
	DDX_Control(pDX, IDC_BQUIT, BQuit);
	DDX_Control(pDX, IDC_BVOL, BVol);
}

BEGIN_MESSAGE_MAP(CChineseChessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BSTART, &CChineseChessDlg::OnBnClickedBstart)
	ON_BN_CLICKED(IDC_BQUIT, &CChineseChessDlg::OnBnClickedBquit)
	ON_BN_CLICKED(IDC_BVOL, &CChineseChessDlg::OnBnClickedBvol)
	ON_BN_CLICKED(IDC_UI_BUTTON1, &CChineseChessDlg::OnBnClickedUiButton)
END_MESSAGE_MAP()


// CChineseChessDlg message handlers

BOOL CChineseChessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	BStart.SetButtonStyle(BS_BITMAP);

	CChineseChessDlg::Button_BackGround_ini();

	switch (Model) {
		case Startup_Page:
			CChineseChessDlg::Start_Button_ini();
			break;
		case Single_Page:
			CChineseChessDlg::SGame_Button_ini();
			break;

		default :
			break;
	}
	
	
	
	//BStart.Create(_T("1111"), WS_VISIBLE | BS_BITMAP, CRect(10,10,100,30), this, 1);

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChineseChessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CChineseChessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		switch (Model) {
		case Startup_Page:
			CChineseChessDlg::Start_Page_ini();
			break;
		case Single_Page:
			CChineseChessDlg::SGame_Page_ini();
			break;
		case UI2_Page:
			CChineseChessDlg::UIChange_Button_ini();
			break;
		default:
			break;
		}
		
		//CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CChineseChessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CChineseChessDlg::OnBnClickedBstart()
{
	// TODO: Add your control notification handler code here
	if (this->Model == 1|| this->Model == 3) this->Model = 2;
	else this->Model = 1;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
	
	//CDialogEx::OnOK();
}




void CChineseChessDlg::OnBnClickedBquit()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CChineseChessDlg::OnBnClickedBvol()
{
	// TODO: Add your control notification handler code here
	if (this->Mute) this->Mute = FALSE;
	else this->Mute = TRUE;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}
//---------------------------Page Buttons initialization-------------------------------------

afx_msg void CChineseChessDlg::Button_BackGround_ini() {
/*	Start up Page buttons' background Initialization */
	CBitmap Startbgp;
	CBitmap Quitbgp;
	CBitmap Volbgp;
	Startbgp.LoadBitmap(IDB_BSTART);
	Quitbgp.LoadBitmap(IDB_BQUIT);
	Volbgp.LoadBitmap(IDB_BVOLUMN);
	BStart.SetBitmap(Startbgp);
	BQuit.SetBitmap(Quitbgp);
	if (this->Mute) BVol.SetBitmap(NULL);
	else BVol.SetBitmap(Volbgp);

/*	Single Game Page buttons' background Initialization*/

}

/*	Start up Page buttons initialization
*/
afx_msg void CChineseChessDlg::Start_Button_ini(){

/*	Enable the Start up Page buttons*/
	BStart.MoveWindow(200, 300, 180, 70, true);
	BQuit.MoveWindow(500, 300, 180, 70, true);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	if (this->Mute) GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_HIDE);
	else GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	//GetDlgItem(IDC_BQUIT)->ShowWindow(SW_HIDE);
}

/*	Single Game Page buttons initialization
*/
afx_msg void CChineseChessDlg::SGame_Button_ini() {
/*	Enable the Single Game Page buttons*/

/*	Disable the Start up Page buttons*/
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_HIDE);
}


//-------------------------------------------------------------------------------------------

//---------------------------Page Display initialization-------------------------------------

/*	Start up Page Initialization
*/
afx_msg void CChineseChessDlg::Start_Page_ini() {
	CBitmap bitmap; //bitmap object to hold your bitmap
	bitmap.LoadBitmap(IDB_BGP); // IDB_BITMAPID is the id of bmp
	CRect   rect;
	GetClientRect(&rect);

	CSize dim = bitmap.GetBitmapDimension();
	CPaintDC dc(this); //device context of dialog box
	CDC mem_dc; // memory device context

	BITMAP Bitmap;
	bitmap.GetBitmap(&Bitmap);
	mem_dc.CreateCompatibleDC(&dc); // makes compatible with CPaintDC
	mem_dc.SelectObject(bitmap); // Selects bitmap into CDC
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &mem_dc, 0, 0,
		Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
	//dc.BitBlt(0, 0, Bitmap.bmWidth, Bitmap.bmHeight, &mem_dc, 0, 0, SRCCOPY);
}

/*	Single Game Page initialization
*/
afx_msg void CChineseChessDlg::SGame_Page_ini() {
	CBitmap bitmap; //bitmap object to hold your bitmap
	bitmap.LoadBitmap(IDB_CB1); // IDB_BITMAPID is the id of bmp
	CRect   rect;
	GetClientRect(&rect);

	CSize dim = bitmap.GetBitmapDimension();
	CPaintDC dc(this); //device context of dialog box
	CDC mem_dc; // memory device context

	BITMAP Bitmap;
	bitmap.GetBitmap(&Bitmap);
	mem_dc.CreateCompatibleDC(&dc); // makes compatible with CPaintDC
	mem_dc.SelectObject(bitmap); // Selects bitmap into CDC
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &mem_dc, 0, 0,
		Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
}
//-------------------------------------------------------------------------------------------

void CChineseChessDlg::OnBnClickedUiButton()
{
	// TODO: 在此添加控件通知处理程序代码
	if (this->Model == 1 || this->Model == 2) this->Model = 3;
	else this->Model = 1;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}


void CChineseChessDlg::UIChange_Button_ini()
{
	// TODO: 在此处添加实现代码.
	CBitmap bitmap; //bitmap object to hold your bitmap
	bitmap.LoadBitmap(IDB_BGP2); // IDB_BITMAPID is the id of bmp
	CRect   rect;
	GetClientRect(&rect); 

	CSize dim = bitmap.GetBitmapDimension();
	CPaintDC dc(this); //device context of dialog box
	CDC mem_dc; // memory device context

	BITMAP Bitmap;
	bitmap.GetBitmap(&Bitmap);
	mem_dc.CreateCompatibleDC(&dc); // makes compatible with CPaintDC
	mem_dc.SelectObject(bitmap); // Selects bitmap into CDC
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &mem_dc, 0, 0,
		Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);
}
