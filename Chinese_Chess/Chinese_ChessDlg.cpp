
// Chinese_ChessDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Chinese_Chess.h"
#include "Chinese_ChessDlg.h"
#include "afxdialogex.h"

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
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChineseChessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BSTART, BStart);
	DDX_Control(pDX, IDC_BQUIT, BQuit);
}

BEGIN_MESSAGE_MAP(CChineseChessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BSTART, &CChineseChessDlg::OnBnClickedBstart)
	ON_BN_CLICKED(IDC_BQUIT, &CChineseChessDlg::OnBnClickedBquit)
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

	CBitmap Startbgp;
	CBitmap Quitbgp;
	CBitmap Volumnbgp;

	Startbgp.LoadBitmap(IDB_BSTART);
	Quitbgp.LoadBitmap(IDB_BQUIT);
	Volumnbgp.LoadBitmap(IDB_BVOLUMN);
	BStart.SetBitmap(Startbgp);
	BQuit.SetBitmap(Quitbgp);
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
		//CDialogEx::OnPaint();							//This is for refreshing the background;
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
}




void CChineseChessDlg::OnBnClickedBquit()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
