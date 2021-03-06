
// Full_FootballDlg.h : header file
//

#pragma once
#define PI 3.1415926535897932385
class Ball;
class Field;
class Human;
class AssReferee;	// all classes for initialisation in this header (Ball *ball; Field *field; ...)
class Referee;
class Girl;
class Player;
class Forward;
class HalfBack;
class FullBack;
class Goalkeeper;
class Lights;

// CFullFootballDlg dialog
class CFullFootballDlg : public CDialogEx
{
// Construction
public:
	CFullFootballDlg(CWnd* pParent = nullptr);	// standard constructor
	Ball *ball;
	Field *field;
	AssReferee *assRefereeTop, *assRefereeBot;
	Referee *referee;
	Girl *girl[5];
	Lights *lights[2];
	int scoreL;
	int scoreR;
	int time;


	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FULL_FOOTBALL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	void energyControl();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	void Simulate();
	void startGame();
	void drawAll();
	void moveAll();
	void position0();
	void position1();
	void position2();
	void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedRun();
	afx_msg void OnBnClickedStop();
	void CFullFootballDlg::soundONOFF(WCHAR* soundFile);
	afx_msg void OnDeltaposSpinenergyleft(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDeltaposSpinenergyright(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck12();
};
