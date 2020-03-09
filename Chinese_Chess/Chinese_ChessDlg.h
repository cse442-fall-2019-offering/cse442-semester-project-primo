
// Chinese_ChessDlg.h : header file
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
#define Multi_Page 3


private:
	int Model = 1;
	BOOL Mute = FALSE;
	int voulmn = 50;

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
	BOOL CChineseChessDlg::TransBit(CDC* dcSnow, CDC* dcDest, int pos_x, int pos_y);
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
};
