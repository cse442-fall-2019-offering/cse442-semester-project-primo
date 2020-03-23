﻿
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
#include <Windows.h>
#include "settingDialog.h"

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
	DDX_Control(pDX, IDC_BRETURN, BReturn);
	DDX_Control(pDX, IDC_BRESTART, BRestart);
	DDX_Control(pDX, IDC_UI_BUTTON1, settings);
}

BEGIN_MESSAGE_MAP(CChineseChessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BSTART, &CChineseChessDlg::OnBnClickedBstart)
	ON_BN_CLICKED(IDC_BQUIT, &CChineseChessDlg::OnBnClickedBquit)
	ON_BN_CLICKED(IDC_BVOL, &CChineseChessDlg::OnBnClickedBvol)
	ON_BN_CLICKED(IDC_BRETURN, &CChineseChessDlg::OnBnClickedBreturn)
	ON_BN_CLICKED(IDC_BRESTART, &CChineseChessDlg::OnBnClickedBrestart)
	ON_BN_CLICKED(IDC_UI_BUTTON1, &CChineseChessDlg::OnBnClickedUiButton)
	ON_BN_CLICKED(IDC_Settings, &CChineseChessDlg::OnBnClickedSettings)
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

void CChineseChessDlg::OnBnClickedBreturn()
{
	// TODO: Add your control notification handler code here
	if (this->Model == 2) this->Model = 1;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBrestart()
{
	// TODO: Add your control notification handler code here
	if (this->Model == 2) this->Model = 2;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

//---------------------------Page Buttons initialization-------------------------------------

afx_msg void CChineseChessDlg::Button_BackGround_ini() {
/*	Start up Page buttons' background Initialization */
	CBitmap Startbgp;
	CBitmap Quitbgp;
	CBitmap Volbgp;
	CBitmap Returnbgp;
	CBitmap Restartbgp;
	Startbgp.LoadBitmap(IDB_BSTART);
	Quitbgp.LoadBitmap(IDB_BQUIT);
	Volbgp.LoadBitmap(IDB_BVOLUMN);
	Returnbgp.LoadBitmap(IDB_BRETURN);
	Restartbgp.LoadBitmap(IDB_BRESTART);
	BStart.SetBitmap(Startbgp);
	BQuit.SetBitmap(Quitbgp);
	BReturn.SetBitmap(Returnbgp);
	BRestart.SetBitmap(Restartbgp);
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
	BReturn.MoveWindow(0, 0, 47, 47, true);
	BRestart.MoveWindow(720, 0, 47, 47, true);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BSTART)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_HIDE);
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
	GetDlgItem(IDC_BSTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_SHOW);
	
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

	/*dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &mem_dc, 0, 0,
		Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);*/
	dc.BitBlt(0, 0, Bitmap.bmWidth, Bitmap.bmHeight, &mem_dc, 0, 0, SRCCOPY);
}

/*	Single Game Page initialization
*/
afx_msg void CChineseChessDlg::SGame_Page_ini() {
	CRect rect;
	GetClientRect(&rect);

	CBitmap board; //bitmap object to hold your bitmap
	board.LoadBitmap(IDB_BOARD); // IDB_BITMAPID is the id of bmp
	BITMAP Board;
	board.GetBitmap(&Board);

	CSize dim = board.GetBitmapDimension();
	CPaintDC dc(this); //device context of dialog box
	CDC mem_dc; // memory device context
	mem_dc.CreateCompatibleDC(&dc); // makes compatible with CPaintDC

	//charoit
	CBitmap charoit1;
	charoit1.LoadBitmap(IDB_PCHAR1);
	BITMAP	Charoit1;
	charoit1.GetBitmap(&Charoit1);

	CBitmap charoit2;
	charoit2.LoadBitmap(IDB_PCHAR2);
	BITMAP	Charoit2;
	charoit2.GetBitmap(&Charoit2);

	//horse
	CBitmap horse1;
	horse1.LoadBitmap(IDB_PHORSE1);
	BITMAP	Horse1;
	horse1.GetBitmap(&Horse1);

	CBitmap horse2;
	horse2.LoadBitmap(IDB_PHORSE2);
	BITMAP	Horse2;
	horse2.GetBitmap(&Horse2);

	//cannon
	CBitmap cannon1;
	cannon1.LoadBitmap(IDB_PCAN1);
	BITMAP	Cannon1;
	cannon1.GetBitmap(&Cannon1);

	CBitmap cannon2;
	cannon2.LoadBitmap(IDB_PCAN2);
	BITMAP	Cannon2;
	cannon2.GetBitmap(&Cannon2);

	//bishop
	CBitmap bishop1;
	bishop1.LoadBitmap(IDB_PBISHOP1);
	BITMAP	Bishop1;
	bishop1.GetBitmap(&Bishop1);

	CBitmap bishop2;
	bishop2.LoadBitmap(IDB_PBISHOP2);
	BITMAP	Bishop2;
	bishop2.GetBitmap(&Bishop2);

	//advisor
	CBitmap advisor1;
	advisor1.LoadBitmap(IDB_PADVISOR1);
	BITMAP	Advisor1;
	advisor1.GetBitmap(&Advisor1);

	CBitmap advisor2;
	advisor2.LoadBitmap(IDB_PADVISOR2);
	BITMAP	Advisor2;
	advisor2.GetBitmap(&Advisor2);

	//king
	CBitmap king1;
	king1.LoadBitmap(IDB_PKING1);
	BITMAP	King1;
	king1.GetBitmap(&King1);

	CBitmap king2;
	king2.LoadBitmap(IDB_PKING2);
	BITMAP	King2;
	king2.GetBitmap(&King2);

	//soldier
	CBitmap soldier1;
	soldier1.LoadBitmap(IDB_PSOLDIER1);
	BITMAP	Soldier1;
	soldier1.GetBitmap(&Soldier1);

	CBitmap soldier2;
	soldier2.LoadBitmap(IDB_PSOLDIER2);
	BITMAP	Soldier2;
	soldier2.GetBitmap(&Soldier2);
	
	std::vector<std::vector<int>> B(10, std::vector<int>(9, 0));
	std::vector<std::vector<int>> P(10, std::vector<int>(9, 0));

	B.at(0).at(0) = 5;
	B.at(0).at(1) = 4;
	B.at(0).at(2) = 3;
	B.at(0).at(3) = 2;
	B.at(0).at(4) = 1;
	B.at(0).at(5) = 2;
	B.at(0).at(6) = 3;
	B.at(0).at(7) = 4;
	B.at(0).at(8) = 5;

	B.at(2).at(1) = 6;
	B.at(2).at(7) = 6;

	B.at(3).at(0) = 7;
	B.at(3).at(2) = 7;
	B.at(3).at(4) = 7;
	B.at(3).at(6) = 7;
	B.at(3).at(8) = 7;

	B.at(6).at(0) = 7;
	B.at(6).at(2) = 7;
	B.at(6).at(4) = 7;
	B.at(6).at(6) = 7;
	B.at(6).at(8) = 7;

	B.at(7).at(1) = 6;
	B.at(7).at(7) = 6;

	B.at(9).at(0) = 5;
	B.at(9).at(1) = 4;
	B.at(9).at(2) = 3;
	B.at(9).at(3) = 2;
	B.at(9).at(4) = 1;
	B.at(9).at(5) = 2;
	B.at(9).at(6) = 3;
	B.at(9).at(7) = 4;
	B.at(9).at(8) = 5;

	P.at(0).at(0) = 2;
	P.at(0).at(1) = 2;
	P.at(0).at(2) = 2;
	P.at(0).at(3) = 2;
	P.at(0).at(4) = 2;
	P.at(0).at(5) = 2;
	P.at(0).at(6) = 2;
	P.at(0).at(7) = 2;
	P.at(0).at(8) = 2;

	P.at(2).at(1) = 2;
	P.at(2).at(7) = 2;

	P.at(3).at(0) = 2;
	P.at(3).at(2) = 2;
	P.at(3).at(4) = 2;
	P.at(3).at(6) = 2;
	P.at(3).at(8) = 2;

	P.at(6).at(0) = 1;
	P.at(6).at(2) = 1;
	P.at(6).at(4) = 1;
	P.at(6).at(6) = 1;
	P.at(6).at(8) = 1;

	P.at(7).at(1) = 1;
	P.at(7).at(7) = 1;

	P.at(9).at(0) = 1;
	P.at(9).at(1) = 1;
	P.at(9).at(2) = 1;
	P.at(9).at(3) = 1;
	P.at(9).at(4) = 1;
	P.at(9).at(5) = 1;
	P.at(9).at(6) = 1;
	P.at(9).at(7) = 1;
	P.at(9).at(8) = 1;
	

	mem_dc.SelectObject(board);
	dc.BitBlt(100, 100, Board.bmWidth, Board.bmHeight, &mem_dc, 0, 0, SRCCOPY);
	//dc.StretchBlt(100, 100, 600, 600, &mem_dc, 0, 0,
	//	Board.bmWidth, Board.bmHeight, SRCCOPY);
	int ini_x, ini_y;
	int increase_x, increase_y;
	ini_x = 120;
	ini_y = 120;
	increase_x = 63;
	increase_y = 63;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			int current_x = ini_x + j * increase_x;
			int current_y = ini_y + i * increase_y;
			if (B.at(i).at(j) == 1 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(king1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King1.bmWidth, King1.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 1 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(king2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 2 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(advisor1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 2 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(advisor2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 3 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(bishop1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 3 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(bishop2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 4 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(horse1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 4 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(horse2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 5 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(charoit1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 5 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(charoit2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 6 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(cannon1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 6 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(cannon2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 7 && P.at(i).at(j) == 1) {
				mem_dc.SelectObject(soldier1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (B.at(i).at(j) == 7 && P.at(i).at(j) == 2) {
				mem_dc.SelectObject(soldier2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
		}
	}
}
//-------------------------------------------------------------------------------------------

void CChineseChessDlg::OnBnClickedUiButton()
{
	// TODO: Add your control notification handler code here
	if (this->Model == 1 || this->Model == 2) this->Model = 3;
	else this->Model = 1;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}


void CChineseChessDlg::UIChange_Button_ini()
{
	// TODO: Add your control notification handler code here
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





void CChineseChessDlg::OnBnClickedSettings()
{
	settingDialog settings;
	settings.DoModal();

	// TODO: 在此添加控件通知处理程序代码
}
