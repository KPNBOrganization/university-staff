
// Mini_FootballDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mini_Football.h"
#include "Mini_FootballDlg.h"
#include "afxdialogex.h"
#include "Ball.h"
#include "Field.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CButton* pRun;
CButton* pStop;
CMiniFootballDlg* FootballDlg;

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


// CMiniFootballDlg dialog



CMiniFootballDlg::CMiniFootballDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MINI_FOOTBALL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMiniFootballDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMiniFootballDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRun, &CMiniFootballDlg::OnBnClickedRun)
	ON_BN_CLICKED(IDStop, &CMiniFootballDlg::OnBnClickedStop)
END_MESSAGE_MAP()


// CMiniFootballDlg message handlers

BOOL CMiniFootballDlg::OnInitDialog()
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

	// TODO: Add extra initialization here
	pRun = (CButton *)GetDlgItem(IDRun);
	pStop = (CButton *)GetDlgItem(IDStop);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMiniFootballDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMiniFootballDlg::OnPaint()
{
	field = new Field(GetDlgItem(IDC_STATIC));
	field->draw();

	ball = new Ball(GetDlgItem(IDC_STATIC), field);
	ball->moveTo(100, 100);
	ball->draw();
	ball->setSpeed(50);
	ball->setDir(PI / 4 - 0.1);

	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMiniFootballDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMiniFootballDlg::OnBnClickedRun()
{
	SetTimer(1, 50, NULL);
	pRun->EnableWindow(false);
	pStop->EnableWindow(true);
}


void CMiniFootballDlg::OnBnClickedStop()
{
	KillTimer(1);
	pRun->EnableWindow(true);
	pStop->EnableWindow(false);
}

void CMiniFootballDlg::Simulate() {
	ball->move();
	field->draw();
	ball->draw();
}

void CMiniFootballDlg::OnTimer(UINT_PTR nIDEvent) {
	Simulate();
	CDialog::OnTimer(nIDEvent);
}