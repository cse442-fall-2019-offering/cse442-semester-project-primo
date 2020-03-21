
// Chinese_ChessDlg.h : header file
#include "Game.h"
//

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


private:
	int Model = 1;
	BOOL Mute = FALSE;
	int voulmn = 50;
	Game game;

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

	bool contain(pair<int, int>);

		afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
		afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedUiButton();
	void UIChange_Button_ini();
};
