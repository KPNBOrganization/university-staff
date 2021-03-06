
// Mini_FootballDlg.h : header file
//

#pragma once
#define PI 3.1415926535897932385

class Ball;
class Field;

// CMiniFootballDlg dialog
class CMiniFootballDlg : public CDialogEx
{
// Construction
public:
	CMiniFootballDlg(CWnd* pParent = nullptr);	// standard constructor
	Ball* ball;
	Field* field;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MINI_FOOTBALL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRun();
	afx_msg void OnBnClickedStop();
	void Simulate();
	void OnTimer(UINT_PTR nIDEvent);
};
