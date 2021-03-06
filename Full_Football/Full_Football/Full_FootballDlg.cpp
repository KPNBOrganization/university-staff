
// Full_FootballDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Full_Football.h"
#include "Full_FootballDlg.h"
#include "afxdialogex.h"
#include "Ball.h"
#include "Field.h"
#include "AssReferee.h"
#include "Referee.h"
#include "Girl.h"
#include "Player.h"
#include "Forward.h"
#include "HalfBack.h"
#include "FullBack.h"
#include "Goalkeeper.h"
#include "Lights.h"
#include <Windows.h>	// for sound
#include <MMSystem.h>	//for sound
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CButton *pRun, *pStop, *GirlsShow, *Sound;
CSpinButtonCtrl *SpinEnergyLeft, *SpinEnergyRight;
CSliderCtrl *SimSlider;
CWnd *CommentText, *TimeKeeper, *ScoreLeft, *ScoreRight, *EnergyLeft, *EnergyRight;
CButton *C_CHECK3, *C_CHECK4, *C_CHECK5, *C_CHECK6, *C_CHECK7, *C_CHECK8, *C_CHECK9, *C_CHECK10, *C_CHECK11, *C_CHECK12;
// CFullFootballDlg dialog



CFullFootballDlg::CFullFootballDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FULL_FOOTBALL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFullFootballDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFullFootballDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_TIMER()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDRun, &CFullFootballDlg::OnBnClickedRun)
	ON_BN_CLICKED(IDStop, &CFullFootballDlg::OnBnClickedStop)
	ON_NOTIFY(UDN_DELTAPOS, IDSpinEnergyLeft, &CFullFootballDlg::OnDeltaposSpinenergyleft)
	ON_NOTIFY(UDN_DELTAPOS, IDSpinEnergyRight, &CFullFootballDlg::OnDeltaposSpinenergyright)
	ON_BN_CLICKED(IDC_CHECK3, &CFullFootballDlg::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CFullFootballDlg::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CFullFootballDlg::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &CFullFootballDlg::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &CFullFootballDlg::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK8, &CFullFootballDlg::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK9, &CFullFootballDlg::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &CFullFootballDlg::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &CFullFootballDlg::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK12, &CFullFootballDlg::OnBnClickedCheck12)
END_MESSAGE_MAP()


// CFullFootballDlg message handlers

BOOL CFullFootballDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	AllocConsole();

	AttachConsole(GetCurrentProcessId());

	freopen("CONIN$", "r", stdin);

	freopen("CONOUT$", "w", stdout);

	freopen("CONOUT$", "w", stderr);

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	pRun = (CButton *)GetDlgItem(IDRun);
	pStop = (CButton *)GetDlgItem(IDStop);
	CommentText = GetDlgItem(IDCommentText);
	TimeKeeper = GetDlgItem(IDTime);
	ScoreLeft = GetDlgItem(IDScoreLeft);
	ScoreRight = GetDlgItem(IDScoreRight);
	GirlsShow = (CButton *)GetDlgItem(IDGirlsShow);
	EnergyRight = GetDlgItem(IDEnergyRight);
	EnergyLeft = GetDlgItem(IDEnergyLeft);
	Sound = (CButton *)GetDlgItem(IDSound);	Sound->SetCheck(0);
	SpinEnergyLeft = (CSpinButtonCtrl *)GetDlgItem(IDSpinEnergyLeft);
	SpinEnergyRight = (CSpinButtonCtrl *)GetDlgItem(IDSpinEnergyRight);
	SimSlider = (CSliderCtrl *)GetDlgItem(IDC_SLIDER1);
	C_CHECK3 = (CButton *)GetDlgItem(IDC_CHECK3);	C_CHECK3->SetCheck(1);
	C_CHECK4 = (CButton *)GetDlgItem(IDC_CHECK4);	C_CHECK4->SetCheck(1);
	C_CHECK5 = (CButton *)GetDlgItem(IDC_CHECK5);	C_CHECK5->SetCheck(1);
	C_CHECK6 = (CButton *)GetDlgItem(IDC_CHECK6);	C_CHECK6->SetCheck(1);
	C_CHECK7 = (CButton *)GetDlgItem(IDC_CHECK7);	C_CHECK7->SetCheck(1);
	C_CHECK8 = (CButton *)GetDlgItem(IDC_CHECK8);	C_CHECK8->SetCheck(1);
	C_CHECK9 = (CButton *)GetDlgItem(IDC_CHECK9);	C_CHECK9->SetCheck(1);
	C_CHECK10 = (CButton *)GetDlgItem(IDC_CHECK10);	C_CHECK10->SetCheck(1);
	C_CHECK11 = (CButton *)GetDlgItem(IDC_CHECK11);	C_CHECK11->SetCheck(1);
	C_CHECK12 = (CButton *)GetDlgItem(IDC_CHECK12);	C_CHECK12->SetCheck(1);

	SimSlider->SetPos(50);

	field = new Field(GetDlgItem(FOOTBALL_FIELD));
	ball = new Ball(GetDlgItem(FOOTBALL_FIELD), field);
	assRefereeTop = new AssReferee(GetDlgItem(FOOTBALL_FIELD), field, ball);
	assRefereeBot = new AssReferee(GetDlgItem(FOOTBALL_FIELD), field, ball);
	field->referee = new Referee(GetDlgItem(FOOTBALL_FIELD), field, ball);
	Player *p;
	//make team1
	int n = 0;
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new HalfBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new FullBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new FullBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	p = new Goalkeeper(GetDlgItem(FOOTBALL_FIELD), field, ball, 1, ++n);
	field->Team1.push_back(p);
	//make team 2
	n = 0;
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new Forward(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new HalfBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new FullBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new FullBack(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);
	p = new Goalkeeper(GetDlgItem(FOOTBALL_FIELD), field, ball, 2, ++n);
	field->Team2.push_back(p);

	for (int i = 0; i<5; ++i) girl[i] = new Girl(GetDlgItem(FOOTBALL_FIELD), field);
	
	 lights[0] = new Lights(GetDlgItem(FOOTBALL_FIELD), 0, 0, 250, PI / 32, -PI / 12, -PI / 2 + PI / 12, PI / 12, PI / 3);
	 lights[1] = new Lights(GetDlgItem(FOOTBALL_FIELD), field->getW(), 0, 250, PI / 32, -PI / 2 - PI / 8, -PI + PI / 8, PI / 12, PI / 3);

	for (int i = 0; i < field->Team1.size(); i++) field->Team1[i]->setEnergy(rand() % 2000 + 2000);
	for (int i = 0; i < field->Team2.size(); i++) field->Team2[i]->setEnergy(rand() % 2000 + 2000);
	field->gameState = sStop;
	scoreL = scoreR = 0;
	time = 0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFullFootballDlg::OnPaint()
{
	position0();
	drawAll();
	CDialogEx::OnPaint();
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFullFootballDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFullFootballDlg::Simulate() {
	CString str;
	str.Format(_T("%d"), ++time);
	TimeKeeper->SetWindowText(str);
	int xc, yc, xb, yb;
	field->getCentre(xc, yc);
	ball->getCoord(xb, yb);
	drawAll();
	switch (field->gameState) {
	case sGoal:
		::Sleep(1000);
		CommentText->SetWindowText(_T("***** GOAL!!! *****"));
		soundONOFF(TEXT("whistle.wav"));
		soundONOFF(TEXT("mencheer.wav"));

		str.Format(_T("%d"), scoreL);
		ScoreLeft->SetWindowText(str);
		str.Format(_T("%d"), scoreR);
		ScoreRight->SetWindowText(str);
		if (GirlsShow->GetCheck() == BST_CHECKED) {	
			field->gameState = sPause;
			lights[0]->on = lights[1]->on = true;
			soundONOFF(TEXT("successtada.wav"));
		}
		else field->gameState = sRestartGame;
		return;
	case sRestartGame:
		::Sleep(1000);
		for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);
		lights[0]->on = lights[1]->on = false;
		soundONOFF(TEXT("whistle.wav"));
		field->gameState = sFirstKick;
		return;
	}
	if (field->isGoalLeft(xb, yb, ball->getR()))
	{
		scoreR += 1;
		field->gameState = sGoal;
		ball->moveTo(xc, yc);
		ball->setSpeed(0);
		position1();
		return;
	}

	if (field->isGoalRight(xb, yb, ball->getR()))
	{
		scoreL += 1;
		field->gameState = sGoal;
		ball->moveTo(xc, yc);
		ball->setSpeed(0);
		position2();
		return;
	}
	//::Sleep(500 - 50 * TrackBar->Position);  //slows down action

	moveAll();

	energyControl();
}

void CFullFootballDlg::energyControl()
{
	CString str;
	int enL = 0, enR = 0;
	for (int i = 0; i < field->Team1.size(); i++) enL += field->Team1[i]->getEnergy();
	for (int i = 0; i < field->Team2.size(); i++) enR += field->Team2[i]->getEnergy();
	str.Format(_T("%d"), enL);
	EnergyLeft->SetWindowText(str);
	SpinEnergyLeft->SetPos(enL);
	str.Format(_T("%d"), enR);
	EnergyRight->SetWindowText(str);
	SpinEnergyRight->SetPos(enR);
}

void CFullFootballDlg::soundONOFF(WCHAR* soundFile)
{
	if (Sound->GetCheck() == BST_CHECKED ) PlaySound(soundFile, NULL, SND_ASYNC);
}

void CFullFootballDlg::startGame() {
	int xc, yc;
	field->getCentre(xc, yc);
	ball->moveTo(xc, yc);
	ball->setSpeed(0);
	assRefereeTop->moveTo(xc, field->getBorderW() / 2 + 2);
	assRefereeBot->moveTo(xc, field->getBorderW() / 2 + field->getH() - 2);
	for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);
	if (rand() % 2) position1(); else position2();
	soundONOFF(TEXT("whistle.wav"));
	field->gameState = sFirstKick;
}
void CFullFootballDlg::drawAll() {
	field->draw();
	lights[0]->draw();
	lights[1]->draw();
	field->drawLines();
	ball->draw();
	assRefereeTop->draw();
	assRefereeBot->draw();
	field->referee->draw();
	for (int i = 0; i < field->Team1.size(); i++)
		field->Team1[i]->draw();
	for (int i = 0; i < field->Team2.size(); i++)
		field->Team2[i]->draw();
	for (int i = 0; i<5; ++i) girl[i]->draw();
}

void CFullFootballDlg::moveAll()
{
	if (field->gameState == sPause) {
		for (int i = 0; i<5; ++i) {
			girl[i]->move();
		}
		lights[0]->move();
		lights[1]->move();
		return;
	}

	ball->move();
	assRefereeTop->move();
	assRefereeBot->move();
	field->referee->move();
	for (int i = 0; i < field->Team1.size(); i++)
		field->Team1[i]->move();
	for (int i = 0; i < field->Team2.size(); i++)
		field->Team2[i]->move();
}

void CFullFootballDlg::position0()
{
	int y, xc, yc;
	field->getCentre(xc, yc);
	field->referee->moveTo(xc, yc - 50);
	ball->moveTo(xc, yc - 45);
	assRefereeTop->moveTo(xc - 10, yc - 50);
	assRefereeBot->moveTo(xc + 10, yc - 50);
	y = yc - 10 * field->Team1.size() / 2;
	for (int i = 0; i < field->Team1.size(); i++)
	{
		field->Team1[i]->moveTo(xc - 20, y);
		y += 10;
	}
	y = yc - 10 * field->Team2.size() / 2;
	for (int i = 0; i < field->Team2.size(); i++)
	{
		field->Team2[i]->moveTo(xc + 20, y);
		y += 10;
	}
	for (int i = 0; i<5; ++i) girl[i]->moveTo(xc - 2 * 6 + i * 6, 4);
}

void CFullFootballDlg::position1()
{
	int xc, yc;
	field->getCentre(xc, yc);
	field->referee->moveTo(xc + 50, yc - 50);
	field->Team1[0]->moveTo(xc - 5, yc);
	for (int i = 1; i < field->Team1.size(); i++)
	{
		if (!field->Team1[i]->inGame) continue;
		if (field->Team1[i]->type == tGoalkeeper) field->Team1[i]->moveTo(field->getBorderW(), yc);
		else field->Team1[i]->moveTo(xc - rand() % (field->getW() / 2 - 30), rand() % (field->getH() - 20) + 20);
	}

	for (int i = 0; i < field->Team2.size(); i++)
	{
		if (!field->Team2[i]->inGame) continue;
		if (field->Team2[i]->type == tGoalkeeper) field->Team2[i]->moveTo(field->getW(), yc);
		else field->Team2[i]->moveTo(xc + rand() % (field->getW() / 2 - 30), rand() % (field->getH() - 20) + 20);
	}
}

void CFullFootballDlg::position2()
{
	int xc, yc;
	field->getCentre(xc, yc);
	field->referee->moveTo(xc - 50, yc - 50);
	for (int i = 0; i < field->Team1.size(); i++)
	{
		if (!field->Team1[i]->inGame) continue;
		if (field->Team1[i]->type == tGoalkeeper) field->Team1[i]->moveTo(field->getBorderW(), yc);
		else field->Team1[i]->moveTo(xc - rand() % (field->getW() / 2 - 30), rand() % (field->getH() - 20) + 20);
	}

	field->Team2[0]->moveTo(xc + 5, yc);
	for (int i = 1; i < field->Team2.size(); i++)
	{
		if (!field->Team2[i]->inGame) continue;
		if (field->Team2[i]->type == tGoalkeeper) field->Team2[i]->moveTo(field->getW(), yc);
		else field->Team2[i]->moveTo(xc + rand() % (field->getW() / 2 - 30), rand() % (field->getH() - 20) + 20);
	}
}


void CFullFootballDlg::OnTimer(UINT_PTR nIDEvent) {
	Simulate();
	Sleep(10000 / ((SimSlider->GetPos() + 50)));
	CDialog::OnTimer(nIDEvent);
}

void CFullFootballDlg::OnBnClickedRun()
{
	SetTimer(1, 50, NULL);
	pRun->EnableWindow(false);
	pStop->EnableWindow(true);
	startGame();
}


void CFullFootballDlg::OnBnClickedStop()
{
	KillTimer(1);
	pRun->EnableWindow(true);
	pStop->EnableWindow(false);
	CommentText->SetWindowText(_T("Pause..."));
	field->gameState = sStop;
}


void CFullFootballDlg::OnDeltaposSpinenergyleft(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	int enL = SpinEnergyLeft->GetPos();
	int enPortion = enL / field->Team1.size();
	for (int i = 0; i < field->Team1.size(); i++) field->Team1[i]->setEnergy(enPortion);
	*pResult = 0;
}


void CFullFootballDlg::OnDeltaposSpinenergyright(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	int enR = SpinEnergyRight->GetPos();
	int enPortion = enR / field->Team2.size();
	for (int i = 0; i < field->Team2.size(); i++) field->Team2[i]->setEnergy(enPortion);
	*pResult = 0;
}


void CFullFootballDlg::OnBnClickedCheck3()
{
	if (C_CHECK3->GetCheck() == BST_CHECKED ) field->Team1[1]->inGame = true;
	else field->Team1[1]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck4()
{
	if (C_CHECK4->GetCheck() == BST_CHECKED) field->Team1[2]->inGame = true;
	else field->Team1[2]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck5()
{
	if (C_CHECK5->GetCheck() == BST_CHECKED) field->Team1[3]->inGame = true;
	else field->Team1[3]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck6()
{
	if (C_CHECK6->GetCheck() == BST_CHECKED) field->Team1[4]->inGame = true;
	else field->Team1[4]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck7()
{
	if (C_CHECK7->GetCheck() == BST_CHECKED) field->Team1[5]->inGame = true;
	else field->Team1[5]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck8()
{
	if (C_CHECK8->GetCheck() == BST_CHECKED) field->Team2[1]->inGame = true;
	else field->Team2[1]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck9()
{
	if (C_CHECK9->GetCheck() == BST_CHECKED) field->Team2[2]->inGame = true;
	else field->Team2[2]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck10()
{
	if (C_CHECK10->GetCheck() == BST_CHECKED) field->Team2[3]->inGame = true;
	else field->Team2[3]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck11()
{
	if (C_CHECK11->GetCheck() == BST_CHECKED) field->Team2[4]->inGame = true;
	else field->Team2[4]->inGame = false;
}


void CFullFootballDlg::OnBnClickedCheck12()
{
	if (C_CHECK12->GetCheck() == BST_CHECKED) field->Team2[5]->inGame = true;
	else field->Team2[5]->inGame = false;
}
