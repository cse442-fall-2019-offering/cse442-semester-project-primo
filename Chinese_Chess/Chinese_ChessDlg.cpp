// Chinese_ChessDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "resource.h"
#include "Chinese_Chess.h"
#include "Chinese_ChessDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "Game.h"
#include <vector>
#include "Settings.h"
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <Vfw.H>

int PlayBGM = 0;
int StopBGM = 0;
int Playsound = 0;
int Loadgame = 0;

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
	, sec(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_GAME_ICON);
	Bitmap_ini();
	
	this->history = vector<pair<Piece, Piece>>();
}

void CChineseChessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BSTART, BStart);
	DDX_Control(pDX, IDC_BQUIT, BQuit);
	DDX_Control(pDX, IDC_BVOL, BVol);
	DDX_Control(pDX, IDC_BRETURN, BReturn);
	DDX_Control(pDX, IDC_BRESTART, BRestart);
	DDX_Control(pDX, IDC_BUNDO, BUndo);
	DDX_Control(pDX, IDC_BTURNOFF, BTurnoff);
	DDX_Control(pDX, IDC_MUL_LOCAL, BMul_Local);
	DDX_Control(pDX, IDC_Player, Show_Player);
	DDX_Control(pDX, IDC_BLOADGAME, BLoadgame);
	DDX_Control(pDX, IDC_EDIT_TIME, TimeCount);
	DDX_Text(pDX, IDC_EDIT_TIME, sec);
	DDX_Control(pDX, IDC_VOLBAR, BVolbar);
	DDX_Control(pDX, IDC_BMULTI, BMul);
	DDX_Control(pDX, IDC_BEASY, BEasy);
	DDX_Control(pDX, IDC_BMEDIUM, BMedium);
	DDX_Control(pDX, IDC_BHARD, BHard);
	DDX_Control(pDX, IDC_BONLINE, BOline);
	DDX_Control(pDX, IDC_BTURNOFFSOUND, BTurnoffsound);
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
	ON_BN_CLICKED(IDC_BUNDO, &CChineseChessDlg::OnBnClickedBundo)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_UI_BUTTON1, &CChineseChessDlg::OnBnClickedUiButton)
//	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BTURNOFF, &CChineseChessDlg::OnBnClickedBturnoff)
	ON_BN_CLICKED(IDC_Settings, &CChineseChessDlg::OnBnClickedSettings)
	ON_BN_CLICKED(IDC_MUL_LOCAL, &CChineseChessDlg::OnBnClickedMulLocal)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BLOADGAME, &CChineseChessDlg::OnBnClickedBloadgame)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BMULTI, &CChineseChessDlg::OnBnClickedBmulti)
	ON_BN_CLICKED(IDC_BMEDIUM, &CChineseChessDlg::OnBnClickedBmedium)
	ON_BN_CLICKED(IDC_BEASY, &CChineseChessDlg::OnBnClickedBeasy)
	ON_BN_CLICKED(IDC_BHARD, &CChineseChessDlg::OnBnClickedBhard)
	ON_BN_CLICKED(IDC_BONLINE, &CChineseChessDlg::OnBnClickedBonline)
	ON_BN_CLICKED(IDC_BTURNOFFSOUND, &CChineseChessDlg::OnBnClickedTurnoffsound)

END_MESSAGE_MAP()


// CChineseChessDlg message handlers

BOOL CChineseChessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.

	this->Resolution_x = GetSystemMetrics(SM_CXSCREEN) * 1.0/ Dev_window_size_x;
	this->Resolution_y = GetSystemMetrics(SM_CYSCREEN) * 1.0/ Dev_window_size_y;
	int l = Dev_Wind_Left * this->Resolution_x;
	int r = Dev_Wind_Right * this->Resolution_x;
	int t = Dev_Wind_Top * this->Resolution_y;
	int b = Dev_Wind_Bottom * this->Resolution_y;

	CWnd::SetWindowPos(NULL,l,t,r,b,SWP_NOZORDER|SWP_NOMOVE);


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
			CChineseChessDlg::Single_Button_ini();
			break;
		case Multi_Page:
			CChineseChessDlg::Multi_Button_ini();
			break;
		case Easy_Game_Page:
			CChineseChessDlg::SGame_Button_ini();
			break;
		case Medium_Game_Page:
			CChineseChessDlg::SGame_Button_ini();
			break;
		case Hard_Game_Page:
			CChineseChessDlg::SGame_Button_ini();
			break;
		case Mlocal_Page:
			CChineseChessDlg::Mlocal_Button_ini();
			break;
		case Monline_Page:
			CChineseChessDlg::Mlocal_Button_ini();
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
			CChineseChessDlg::Start_Page_ini();
			break;
		case Multi_Page:
			CChineseChessDlg::Start_Page_ini();
			break;
		case Easy_Game_Page:
			this->game.move();
			CChineseChessDlg::SGame_Page_ini();
			break;
		case Medium_Game_Page:
			CChineseChessDlg::SGame_Page_ini();
			break;
		case Hard_Game_Page:
			CChineseChessDlg::SGame_Page_ini();
			break;
		case Mlocal_Page:
			CChineseChessDlg::SGame_Page_ini();

			if (this->game.getturns() == this->game.getPlayer1()) CChineseChessDlg::SetDlgItemText(IDC_STATIC3, _T("Player 1"));
			else CChineseChessDlg::SetDlgItemText(IDC_STATIC3, _T("Player 2"));
			if (this->game.getturns() == this->game.getPlayer1()) CChineseChessDlg::SetDlgItemText(IDC_Player, _T("Player1, please make a movement"));
			else CChineseChessDlg::SetDlgItemText(IDC_Player, _T("Player2, please make a movement"));
			break;
		case Monline_Page:
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
	if (PlayBGM == 0) {
		CChineseChessDlg::BGM_Play();
		PlayBGM = 1;
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
	if (this->Model == Startup_Page || this->Model == UI2_Page) this->Model = Single_Page;
	else this->Model = Startup_Page;
	/*Player player1 = Player(1, human);
	Player player2 = Player(2, human);
	this->game = Game(&player1, &player2);*/
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
	
	//CDialogEx::OnOK();
}

void CChineseChessDlg::OnBnClickedBmulti()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Startup_Page || this->Model == UI2_Page) this->Model = Multi_Page;
	else this->Model = Startup_Page;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBeasy()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Single_Page) this->Model = Easy_Game_Page;
	else this->Model = Single_Page;
	Player player1 = Player(1, human);
	Player player2 = Player(2, Easy_AI);
	this->game = Game(&player1, &player2);
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBmedium()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Single_Page) this->Model = Medium_Game_Page;
	else this->Model = Single_Page;
	Player player1 = Player(1, human);
	Player player2 = Player(2, Medium_AI);
	this->game = Game(&player1, &player2);
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBhard()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Single_Page) this->Model = Hard_Game_Page;
	else this->Model = Single_Page;
	Player player1 = Player(1, human);
	Player player2 = Player(2, Hard_AI);
	this->game = Game(&player1, &player2);
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedMulLocal()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Multi_Page || this->Model == UI2_Page) this->Model = Mlocal_Page;
	else this->Model = Startup_Page;
	Player player1 = Player(1, human);
	Player player2 = Player(2, human);
	this->game = Game(&player1, &player2);
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBonline()
{
	// TODO: Add your control notification handler code here
	if (this->Model == Multi_Page || this->Model == UI2_Page) this->Model = Monline_Page;
	else this->Model = Startup_Page;
	Player player1 = Player(1, human);
	Player player2 = Player(2, human);
	this->game = Game(&player1, &player2);
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBquit()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}

void CChineseChessDlg::OnBnClickedUiButton()
{
	if (this->Model == 1 || this->Model == 2) this->Model = 3;
	else this->Model = 1;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBvol()
{
	// TODO: Add your control notification handler code here
	if (this->Mute) this->Mute = FALSE;
	else this->Mute = TRUE;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBundo()
{
	size_t len = this->history.size();
	if (len != 0) {
		pair<Piece, Piece> pre = history.at(len - 1);
		Piece old_m = pre.first;
		int old_m_line = old_m.get_line();
		int old_m_row = old_m.get_row();
		this->game.setboard(old_m_line, old_m_row, old_m);
		Piece old_d = pre.second;
		int old_d_line = old_d.get_line();
		int old_d_row = old_d.get_row();
		this->game.setboard(old_d_line, old_d_row, old_d);
		history.erase(history.begin() + len - 1);
		this->game.switch_turn();
		CWnd::Invalidate();
	}
	// TODO: Add your control notification handler code here
}

void CChineseChessDlg::OnBnClickedBreturn()
{
	// TODO: Add your control notification handler code here
	if (isGame(this->Model)) {
		this->Model = Startup_Page;
		this->history.clear();
		
		KillTimer(1);
		this->Count = 60;
		sec.Format(_T("%d"), Count);
		SetDlgItemText(IDC_EDIT_TIME, sec);
		this->history = vector<pair<Piece, Piece>>();
	}

	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBrestart()
{
	// TODO: Add your control notification handler code here
	Player player1 = Player(1, human);
	Player player2 = Player(2, human);
	this->game = Game(&player1, &player2);
	this->history.clear();
	this->history = vector<pair<Piece, Piece>>();
	if (isGame(this->Model) == 2) {
		this->Count = 60;
		SetTimer(1, 1000, NULL);
	}
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBturnoff()
{
	// TODO: Add your control notification handler code here
	if (StopBGM == 0) {
		mciSendString(_T("pause backMusic"), NULL, 0, NULL);
		StopBGM = 1;
	}
	else {
		mciSendString(_T("resume backMusic"), NULL, 0, NULL);
		StopBGM = 0;
	}
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedBloadgame()
{
	if (!isGame(this->Model)) {
		this->Model = Easy_Game_Page;
	}
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

void CChineseChessDlg::OnBnClickedTurnoffsound()
{
	if (Playsound == 0) Playsound = 1;
	else Playsound = 0;
	CWnd::Invalidate();
	CChineseChessDlg::OnInitDialog();
}

//---------------------------Page Buttons initialization-------------------------------------

afx_msg void CChineseChessDlg::Button_BackGround_ini() {
/*	Start up Page buttons' background Initialization */
	CBitmap Singlebgp;
	CBitmap Multibgp;
	CBitmap Quitbgp;
	
	CBitmap Easybgp;
	CBitmap Mediumbgp;
	CBitmap Hardbgp;
	CBitmap Localbgp;
	CBitmap Onlinebgp;

	CBitmap Volbgp;
	CBitmap Returnbgp;
	CBitmap Restartbgp;
	CBitmap TurnoffBgp;
	CBitmap TurnonBgp;
	CBitmap LoadgameBgp;
	CBitmap UndoBgp;
	CBitmap TurnoffsoundBgp;
	
	Singlebgp.LoadBitmap(IDB_BSINGLE);
	Multibgp.LoadBitmap(IDB_BMUL);
	Quitbgp.LoadBitmap(IDB_BQUIT);

	Easybgp.LoadBitmap(IDB_BEASY);
	Mediumbgp.LoadBitmap(IDB_BMEDIUM);
	Hardbgp.LoadBitmap(IDB_BHARD);
	Localbgp.LoadBitmap(IDB_BQUIT);
	Onlinebgp.LoadBitmap(IDB_BQUIT);

	Volbgp.LoadBitmap(IDB_BVOLUMN);
	Returnbgp.LoadBitmap(IDB_BRETURN);
	Restartbgp.LoadBitmap(IDB_BRESTART);
	TurnoffBgp.LoadBitmap(IDB_BTURNOFF);
	TurnonBgp.LoadBitmap(IDB_BTURNON);
	LoadgameBgp.LoadBitmap(IDB_BLOADGAME);
	UndoBgp.LoadBitmap(IDB_BUNDO);
	TurnoffsoundBgp.LoadBitmap(IDB_BTURNOFFSOUND);

	BStart.SetBitmap(Singlebgp);
	BMul.SetBitmap(Multibgp);
	BQuit.SetBitmap(Quitbgp);

	BEasy.SetBitmap(Easybgp);
	BMedium.SetBitmap(Mediumbgp);
	BHard.SetBitmap(Hardbgp);

	BReturn.SetBitmap(Returnbgp);
	BRestart.SetBitmap(Restartbgp);
	BTurnoff.SetBitmap(TurnoffBgp);
	BLoadgame.SetBitmap(LoadgameBgp);
	BUndo.SetBitmap(UndoBgp);
	BTurnoffsound.SetBitmap(TurnoffsoundBgp);

	if (this->Mute) BVol.SetBitmap(NULL);
	else BVol.SetBitmap(Volbgp);

	if(StopBGM==0) BTurnoff.SetBitmap(TurnoffBgp);
	else BTurnoff.SetBitmap(TurnonBgp);

/*	Single Game Page buttons' background Initialization*/

}

/*	Start up Page buttons initialization
*/
afx_msg void CChineseChessDlg::Start_Button_ini(){

/*	Enable the Start up Page buttons*/
	BStart.MoveWindow(350, 200, 180, 70, true);
	BMul.MoveWindow(350, 300, 180, 70, true);
	BQuit.MoveWindow(350, 400, 180, 70, true);
	BLoadgame.MoveWindow(700, 100, 48, 48, true);
	BVol.MoveWindow(840, 440, 30, 30, true);
	BVolbar.MoveWindow(840, 290, 30, 150, true);
	BTurnoff.MoveWindow(830, 480, 48, 48, true);
	BTurnoffsound.MoveWindow(830, 530, 48, 48, true);


	GetDlgItem(IDC_BSTART)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BMULTI)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFFSOUND)->ShowWindow(SW_SHOW);

	
	BMul_Local.MoveWindow(200, 400, 180, 70, true);

	GetDlgItem(IDC_BEASY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMEDIUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BHARD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BONLINE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Player)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_HIDE);

}

afx_msg void CChineseChessDlg::Single_Button_ini() {
	
	BEasy.MoveWindow(350, 200, 180, 70, true);
	BMedium.MoveWindow(350, 300, 180, 70, true);
	BHard.MoveWindow(350, 400, 180, 70, true);
	BQuit.MoveWindow(350, 500, 180, 70, true);

	GetDlgItem(IDC_BEASY)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BMEDIUM)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BHARD)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFFSOUND)->ShowWindow(SW_SHOW);


	BTurnoff.MoveWindow(830, 480, 47, 47, true);
	BLoadgame.MoveWindow(700, 100, 48, 48, true);
	BVol.MoveWindow(840, 440, 30, 30, true);
	BVolbar.MoveWindow(840, 290, 30, 150, true);
	
	GetDlgItem(IDC_BONLINE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BSTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMULTI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Player)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_HIDE);

	if (this->Mute) GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_HIDE);
	else GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
}

afx_msg void CChineseChessDlg::Multi_Button_ini() {

	BMul_Local.MoveWindow(350, 200, 180, 70, true);
	BOline.MoveWindow(350, 300, 180, 70, true);
	BQuit.MoveWindow(350, 400, 180, 70, true);
	
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BONLINE)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFFSOUND)->ShowWindow(SW_SHOW);
	
	GetDlgItem(IDC_BSTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMULTI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BEASY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMEDIUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BHARD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Player)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
}

/*	Single Game Page buttons initialization
*/
afx_msg void CChineseChessDlg::SGame_Button_ini() {
/*	Enabled buttons*/
	BReturn.MoveWindow(0, 0, 47, 47, true);
	BRestart.MoveWindow(720, 0, 47, 47, true);
	BUndo.MoveWindow(750, 200, 100, 50, true);
	BTurnoff.MoveWindow(830, 480, 47, 47, true);

	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFFSOUND)->ShowWindow(SW_SHOW);
/*	Disabled buttons*/

	GetDlgItem(IDC_BSTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BEASY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMEDIUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BHARD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMULTI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BONLINE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_Player)->ShowWindow(SW_HIDE);

	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_HIDE);
}

afx_msg void CChineseChessDlg::Mlocal_Button_ini() {

	GetDlgItem(IDC_BSTART)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BEASY)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMEDIUM)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BHARD)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BMULTI)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_MUL_LOCAL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BONLINE)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BQUIT)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BVOL)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_VOLBAR)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_BUNDO)->ShowWindow(SW_HIDE);

	Show_Player.MoveWindow(350, 50, 200, 20, true);
	BReturn.MoveWindow(0, 0, 47, 47, true);
	BRestart.MoveWindow(720, 0, 47, 47, true);
	BTurnoff.MoveWindow(830, 480, 47, 47, true);

	GetDlgItem(IDC_BRETURN)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BRESTART)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFF)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_Player)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_BTURNOFFSOUND)->ShowWindow(SW_SHOW);
}

void CChineseChessDlg::UIChange_Button_ini()
{
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
	GetDlgItem(IDC_BLOADGAME)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT_TIME)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC)->ShowWindow(SW_SHOW);
}


//-------------------------------------------------------------------------------------------

//---------------------------Page Display initialization-------------------------------------

/*	Start up Page Initialization
*/
afx_msg void CChineseChessDlg::Start_Page_ini() {

	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BGP);
	CRect   rect;
	GetClientRect(&rect);

	CSize dim = bitmap.GetBitmapDimension();
	CPaintDC dc(this);
	CDC mem_dc;

	BITMAP Bitmap;
	bitmap.GetBitmap(&Bitmap);
	mem_dc.CreateCompatibleDC(&dc);
	mem_dc.SelectObject(bitmap); 

	/*dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &mem_dc, 0, 0,
		Bitmap.bmWidth, Bitmap.bmHeight, SRCCOPY);*/
	dc.BitBlt(0, 0, Bitmap.bmWidth, Bitmap.bmHeight, &mem_dc, 0, 0, SRCCOPY);
}

/*	Single Game Page initialization
*/
afx_msg void CChineseChessDlg::SGame_Page_ini() {
	Loadgame = 1;
	CRect rect;
	GetClientRect(&rect);
	
	CPaintDC dc(this);
	CDC mem_dc; 
	mem_dc.CreateCompatibleDC(&dc); 

	CSize dim = board.GetBitmapDimension();
	
	vector<vector<Piece>> B = this->game.getBoard();
	Player* player1 = this->game.getPlayer1();
	Player* player2 = this->game.getPlayer2();
	mem_dc.SelectObject(board);
	//dc.BitBlt(100, 100, Board.bmWidth/2, Board.bmHeight/2, &mem_dc, 0, 0, SRCCOPY);
	dc.StretchBlt(100, 100, 600, 675, &mem_dc, 0, 0,
		Board.bmWidth, Board.bmHeight, SRCCOPY);
	
	int ini_x, ini_y;
	int ix, iy;
	ini_x = 120;
	ini_y = 120;
	ix = 60;
	iy = 60;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			int current_x = ini_x + j * ix + 3 * (j - 1);
			int current_y = ini_y + i * iy + 3 * (i - 1);
			int p_type = B.at(i).at(j).get_type();
			Player* p_player = B.at(i).at(j).get_player();
			if (p_type == King && p_player == player1) {
				mem_dc.SelectObject(king1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King1.bmWidth, King1.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == King && p_player == player2) {
				mem_dc.SelectObject(king2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player1) {
				mem_dc.SelectObject(advisor1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player2) {
				mem_dc.SelectObject(advisor2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player1) {
				mem_dc.SelectObject(bishop1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player2) {
				mem_dc.SelectObject(bishop2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player1) {
				mem_dc.SelectObject(horse1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player2) {
				mem_dc.SelectObject(horse2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player1) {
				mem_dc.SelectObject(charoit1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player2) {
				mem_dc.SelectObject(charoit2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player1) {
				mem_dc.SelectObject(cannon1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player2) {
				mem_dc.SelectObject(cannon2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player1) {
				mem_dc.SelectObject(soldier1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player2) {
				mem_dc.SelectObject(soldier2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
		}
	}

	if (this->game.aviliable_flag == 1) {
		for (int i = 0; i < this->aviliable.size(); i++) {
			int x = this->aviliable.at(i).second;
			int y = this->aviliable.at(i).first;
			int c_x = ini_x + x * ix + 3 * (x - 1);
			int c_y = ini_y + y * iy + 3 * (y - 1);
			mem_dc.SelectObject(selected);
			dc.TransparentBlt(c_x, c_y, 60, 60, &mem_dc, 0, 0, Selected.bmWidth, Selected.bmHeight, RGB(255, 255, 255));
		}
	}
}

afx_msg void CChineseChessDlg::Mlocal_Page_ini() {
	Loadgame = 1;
	CRect rect;
	GetClientRect(&rect);

	CPaintDC dc(this);
	CDC mem_dc;
	mem_dc.CreateCompatibleDC(&dc);

	CSize dim = board.GetBitmapDimension();

	vector<vector<Piece>> B = this->game.getBoard();
	Player* player1 = this->game.getPlayer1();
	Player* player2 = this->game.getPlayer2();
	SetTimer(1, 1000, NULL);
	mem_dc.SelectObject(board);
	//dc.BitBlt(100, 100, Board.bmWidth/2, Board.bmHeight/2, &mem_dc, 0, 0, SRCCOPY);
	dc.StretchBlt(100, 100, 600, 675, &mem_dc, 0, 0,
		Board.bmWidth, Board.bmHeight, SRCCOPY);

	int ini_x, ini_y;
	int ix, iy;
	ini_x = 120;
	ini_y = 120;
	ix = 60;
	iy = 60;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			int current_x = ini_x + j * ix + 3 * (j - 1);
			int current_y = ini_y + i * iy + 3 * (i - 1);
			int p_type = B.at(i).at(j).get_type();
			Player* p_player = B.at(i).at(j).get_player();
			if (p_type == King && p_player == player1) {
				mem_dc.SelectObject(king1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King1.bmWidth, King1.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == King && p_player == player2) {
				mem_dc.SelectObject(king2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player1) {
				mem_dc.SelectObject(advisor1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player2) {
				mem_dc.SelectObject(advisor2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player1) {
				mem_dc.SelectObject(bishop1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player2) {
				mem_dc.SelectObject(bishop2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player1) {
				mem_dc.SelectObject(horse1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player2) {
				mem_dc.SelectObject(horse2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player1) {
				mem_dc.SelectObject(charoit1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player2) {
				mem_dc.SelectObject(charoit2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player1) {
				mem_dc.SelectObject(cannon1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player2) {
				mem_dc.SelectObject(cannon2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player1) {
				mem_dc.SelectObject(soldier1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player2) {
				mem_dc.SelectObject(soldier2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
		}
	}

	if (this->game.aviliable_flag == 1) {
		for (int i = 0; i < this->aviliable.size(); i++) {
			int x = this->aviliable.at(i).second;
			int y = this->aviliable.at(i).first;
			int c_x = ini_x + x * ix + 3 * (x - 1);
			int c_y = ini_y + y * iy + 3 * (y - 1);
			mem_dc.SelectObject(selected);
			dc.TransparentBlt(c_x, c_y, 60, 60, &mem_dc, 0, 0, Selected.bmWidth, Selected.bmHeight, RGB(255, 255, 255));
		}
	}
}


//-------------------------------------------------------------------------------------------
void CChineseChessDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CPoint point1;
	CRect Rect;
	GetClientRect(Rect);
	GetCursorPos(&point1);

	ScreenToClient(&point1);
	this->cur_point = point1;
	int x = point.x;
	int y = point.y;
	CString strx;
	strx.Format(_T("%d"), x);
	CString stry;
	stry.Format(_T("%d"), y);
	CString co_point = strx + "," + stry;
	CChineseChessDlg::SetDlgItemText(IDC_STATIC1, co_point);
	CDialogEx::OnMouseMove(nFlags, point);
}

void CChineseChessDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (isGame(this->Model) > 0 && this->game.getturns() == this->game.getPlayer1()) {
		pair<int, int> location = getIndex(this->cur_point);
		if (location.first != -1) {
			CString strx;
			strx.Format(_T("%d"), location.first);
			CString stry;
			stry.Format(_T("%d"), location.second);
			CString co_point = strx + "," + stry;
			CChineseChessDlg::SetDlgItemText(IDC_STATIC2, co_point);

			if (this->game.aviliable_flag == 0) {

				Piece s_piece = this->game.getBoard().at(location.first).at(location.second);
				this->selected_piece = s_piece;
				Player* curplayer = this->game.getturns();
				this->aviliable = s_piece.aviliable_move(this->game.getBoard(), curplayer);
				if (this->aviliable.size() > 0) {
					this->game.aviliable_flag = 1;
					CWnd::Invalidate();
				}
			}
			else {
				if (this->contain(location)) {
					int line = location.first;
					int row = location.second;
					int s_line = this->selected_piece.get_line();
					int s_row = this->selected_piece.get_row();

					Piece old_m = Piece();
					old_m.copy(this->selected_piece);

					Piece old_d = Piece();
					old_d.copy(this->game.getBoard().at(line).at(row));

					Piece null_p = Piece();
					null_p.set_line(s_line);
					null_p.set_row(s_row);
					null_p.set_ini_line(s_line);
					null_p.set_ini_row(s_row);
					null_p.set_player(NULL);
					null_p.set_type(no_piece);

					this->selected_piece.set_line(line);
					this->selected_piece.set_row(row);
					this->game.setboard(line, row, this->selected_piece);
					this->game.setboard(s_line, s_row, null_p);


					this->game.aviliable_flag = 0;
					this->game.switch_turn();

					if(Playsound==0) PlaySound(MAKEINTRESOURCE(IDR_PIECE), NULL, SND_RESOURCE | SND_ASYNC);
					
					pair<Piece, Piece> step(old_m, old_d);

					this->history.push_back(step);
					if (this->game.check_win() != 0) {
						this->Model = 1;
						this->history.clear();
						this->history = vector<pair<Piece, Piece>>();
						CChineseChessDlg::OnInitDialog();
					}
					if (isGame(this->Model) == 2) {
						Count = 60;
						SetTimer(1, 1000, NULL);

						sec.Format(_T("%d"), Count);
						SetDlgItemText(IDC_EDIT_TIME, sec);
					}
					CWnd::Invalidate();

				}
			}
		}
		
	}
	

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CChineseChessDlg::Bitmap_ini() {
	
	board.LoadBitmap(IDB_BOARD); 
	board.GetBitmap(&Board);

	//charoit
	charoit1.LoadBitmap(IDB_PCHAR1);
	charoit1.GetBitmap(&Charoit1);

	charoit2.LoadBitmap(IDB_PCHAR2);
	charoit2.GetBitmap(&Charoit2);

	//horse
	horse1.LoadBitmap(IDB_PHORSE1);
	horse1.GetBitmap(&Horse1);

	horse2.LoadBitmap(IDB_PHORSE2);
	horse2.GetBitmap(&Horse2);

	//cannon
	cannon1.LoadBitmap(IDB_PCAN1);
	cannon1.GetBitmap(&Cannon1);

	cannon2.LoadBitmap(IDB_PCAN2);
	cannon2.GetBitmap(&Cannon2);

	//bishop
	bishop1.LoadBitmap(IDB_PBISHOP1);
	bishop1.GetBitmap(&Bishop1);

	bishop2.LoadBitmap(IDB_PBISHOP2);
	bishop2.GetBitmap(&Bishop2);

	//advisor
	advisor1.LoadBitmap(IDB_PADVISOR1);
	advisor1.GetBitmap(&Advisor1);

	advisor2.LoadBitmap(IDB_PADVISOR2);
	advisor2.GetBitmap(&Advisor2);

	//king
	king1.LoadBitmap(IDB_PKING1);
	king1.GetBitmap(&King1);

	king2.LoadBitmap(IDB_PKING2);
	king2.GetBitmap(&King2);

	//soldier
	soldier1.LoadBitmap(IDB_PSOLDIER1);
	soldier1.GetBitmap(&Soldier1);

	soldier2.LoadBitmap(IDB_PSOLDIER2);
	soldier2.GetBitmap(&Soldier2);


	selected.LoadBitmap(IDB_SELECTED);
	selected.GetBitmap(&Selected);
}

void CChineseChessDlg::BGM_Play()
{
	mciSendString(_T("open res\\BGM.mp3 alias backMusic"), NULL, 0, NULL);
	mciSendString(_T("play backMusic repeat"), NULL, 0, NULL);
}

void CChineseChessDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (Count == 0) {
		game.switch_turn();
		Count = 60;
		sec.Format(_T("%d"), Count);
		SetDlgItemText(IDC_EDIT_TIME, sec);
		SetTimer(1, 1000, NULL);
		return;
	}
	switch (nIDEvent) {
	case 1:
		sec.Format(_T("%d"), Count--);
		SetDlgItemText(IDC_EDIT_TIME, sec);

		break;
	default:
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}

void CChineseChessDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

}

void CChineseChessDlg::OnBnClickedSettings(){
	Settings dlg(nullptr,this);
	dlg.DoModal();

}

//--------------------------------Helper function-----------------------------------
pair<int, int> CChineseChessDlg::getIndex(CPoint point) {
	int x = point.x;
	int y = point.y;
	int line = (y - 120) / 63;
	int row = (x - 120) / 63;
	if (row < 0 || row > 8 || line < 0 || line > 9) {
		pair<int, int> pair(-1, -1);
		return pair;
	}

	pair<int, int> pair(line, row);

	return pair;
}

bool CChineseChessDlg::contain(pair<int, int> Pair) {
	for (int i = 0; i < this->aviliable.size(); i++) {
		pair<int, int> p = aviliable.at(i);
		if (p.second == Pair.second && p.first == Pair.first) return true;
	}
	return false;
}

int CChineseChessDlg::isGame(int model) {
	if (model >= Easy_Game_Page && model <= Hard_Game_Page) return 1;
	else if (model >= Mlocal_Page && model <= Monline_Page) return 2;
	else return 0;
}

void CChineseChessDlg::setgameboard(CPaintDC dc, CDC mem_dc, int ini_x, int ini_y, int ix, int iy) {
	Player* player1 = this->game.getPlayer1();
	Player* player2 = this->game.getPlayer2();
	vector<vector<Piece>> B = this->game.getBoard();
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 9; j++) {
			int current_x = ini_x + j * ix + 3 * (j - 1);
			int current_y = ini_y + i * iy + 3 * (i - 1);
			int p_type = B.at(i).at(j).get_type();
			Player* p_player = B.at(i).at(j).get_player();
			if (p_type == King && p_player == player1) {
				mem_dc.SelectObject(king1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King1.bmWidth, King1.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == King && p_player == player2) {
				mem_dc.SelectObject(king2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player1) {
				mem_dc.SelectObject(advisor1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Advisor && p_player == player2) {
				mem_dc.SelectObject(advisor2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player1) {
				mem_dc.SelectObject(bishop1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Bishop && p_player == player2) {
				mem_dc.SelectObject(bishop2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player1) {
				mem_dc.SelectObject(horse1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Horse && p_player == player2) {
				mem_dc.SelectObject(horse2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player1) {
				mem_dc.SelectObject(charoit1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Chariots && p_player == player2) {
				mem_dc.SelectObject(charoit2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player1) {
				mem_dc.SelectObject(cannon1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Cannon && p_player == player2) {
				mem_dc.SelectObject(cannon2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player1) {
				mem_dc.SelectObject(soldier1);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
			else if (p_type == Soldier && p_player == player2) {
				mem_dc.SelectObject(soldier2);
				dc.TransparentBlt(current_x, current_y, 60, 60, &mem_dc, 0, 0, King2.bmWidth, King2.bmHeight, RGB(255, 255, 255));
			}
		}
	}
}
