
// Chinese_ChessDlg.h : header file
#include "Game.h"
//

#define Dev_window_size_x	1920
#define Dev_window_size_y	1080

#define Dev_Wind_Left		500
#define Dev_Wind_Right		1400
#define Dev_Wind_Top		90
#define Dev_Wind_Bottom		990

#define Dev_piece_size		60
#define Dev_board_Width		600
#define Dev_board_Height	675
#define Dev_SQ_Width		180
#define Dev_SQ_Height		70
#define Dev_RR_size			47
#define Dev_BStart_x		200
#define Dev_BStart_y		300
#define Dev_BQuit_x			500
#define Dev_BQuit_y			300
#define Dev_BReturn_x		0
#define Dev_BReturn_y		0
#define Dev_BRestart_x		720
#define Dev_BRestart_y		0


#pragma once


// CChineseChessDlg dialog
class CChineseChessDlg : public CDialogEx
{
// Construction
public:
	CChineseChessDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHINESE_CHESS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation

#define Startup_Page 1
#define Single_Page 2
#define UI2_Page 3
#define Multi_Local_Page 4


private:
	int Model = 1;
	int Count=60;
	BOOL Mute = FALSE;
	int voulmn = 50;
	Game game;

	float Resolution_x;
	float Resolution_y;

	vector< pair<Piece, Piece> > history;

	CPoint cur_point;

	vector<pair<int, int>> aviliable;

	Piece selected_piece;

	void Bitmap_ini();

	CBitmap board;
	BITMAP Board;

	CBitmap charoit1;
	BITMAP	Charoit1;
	CBitmap charoit2;
	BITMAP	Charoit2;

	CBitmap horse1;
	BITMAP	Horse1;
	CBitmap horse2;
	BITMAP	Horse2;

	CBitmap cannon1;
	BITMAP	Cannon1;
	CBitmap cannon2;
	BITMAP	Cannon2;

	CBitmap bishop1;
	BITMAP	Bishop1;
	CBitmap bishop2;
	BITMAP	Bishop2;

	CBitmap advisor1;
	BITMAP	Advisor1;
	CBitmap advisor2;
	BITMAP	Advisor2;

	CBitmap king1;
	BITMAP	King1;
	CBitmap king2;
	BITMAP	King2;

	CBitmap soldier1;
	BITMAP	Soldier1;
	CBitmap soldier2;
	BITMAP	Soldier2;

	CBitmap selected;
	BITMAP	Selected;


protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Button_BackGround_ini();
	afx_msg void Start_Button_ini();
	afx_msg void Start_Page_ini();
	afx_msg void SGame_Button_ini();
	afx_msg void SGame_Page_ini();
	afx_msg void Mlocal_Page_ini();
	afx_msg void Mlocal_Button_ini();

	pair<int, int> getIndex(CPoint point);

	DECLARE_MESSAGE_MAP()
public:
	CButton BStart;
	afx_msg void OnBnClickedBstart();
	CButton BQuit;
	afx_msg void OnBnClickedBquit();
	CButton BVol;
	afx_msg void OnBnClickedBvol();
	CButton BReturn;
	afx_msg void OnBnClickedBreturn();
	CButton BRestart;
	afx_msg void OnBnClickedBrestart();
	CButton BUndo;
	afx_msg void OnBnClickedBundo();

	void BGM_Play();

	bool contain(pair<int, int>);

		afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
		afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedUiButton();
	void UIChange_Button_ini();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
	CButton BTurnoff;
	afx_msg void OnBnClickedBturnoff();
	CButton BMul_Local;
	afx_msg void OnBnClickedMulLocal();
	CStatic Show_Player;
	CButton BLoadgame;
	afx_msg void OnBnClickedBloadgame();
	CEdit TimeCount;
	CString sec;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
