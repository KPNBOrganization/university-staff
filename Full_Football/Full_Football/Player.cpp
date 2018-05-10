#include "stdafx.h"
#include <math.h>
#include "Player.h"
#include "Field.h"
#include "Ball.h"
#include "Referee.h"
#include "Functions.h"
#include <Windows.h>	// for sound
#include <MMSystem.h>	//for sound
#include "Full_FootballDlg.h"
#include "Full_Football.h"
extern CWnd *CommentText;
extern CButton *Sound;
Player::Player(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n)
{
	field = Secondfield;
	ball = Secondball;
	pImageDC = pImage->GetDC();
	teamNo = t;
	No = n;
	color = t == 1 ? RGB(50,50,50) : RGB(0,0,255);
	speed = 0;
	sound = 0;
	font = new CFont;
	font->CreateFont(2 * r + 1, 0, 0, 0, FW_NORMAL,
		FALSE, FALSE, FALSE, 0, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_ROMAN, _T("Courier New"));
	inGame = true;
}
void Player::draw()
{
	Human::draw();
	CString str, str2;
	str.Format(_T("%d"),No);// int to CString
	pImageDC->SelectObject(font);
	pImageDC->SelectStockObject(NULL_BRUSH);
	pImageDC->SetBkMode(TRANSPARENT);
	pImageDC->SetTextColor(RGB(255,255,255));
	pImageDC->TextOut(x - r / 2, y - r + 1, str);	//Number on player


	switch (sound) {
	case 0: break;
	case 1: if (Sound->GetCheck() == BST_CHECKED) PlaySound(TEXT("kick1.wav"), NULL, SND_ASYNC); break;
	case 2: if (Sound->GetCheck() == BST_CHECKED) PlaySound(TEXT("kick2.wav"), NULL, SND_ASYNC); break;	// drops FPS because of sound
	case 3: if (Sound->GetCheck() == BST_CHECKED) PlaySound(TEXT("kick3.wav"), NULL, SND_ASYNC); break;
	};
	if (sound) {
		str2.Format(_T("%d"),teamNo);
		CommentText->SetWindowText(_T("Team ") + str2 + _T(", No. ") + str);
	}
	sound = 0;
}

void Player::move()
{
	if (!inGame) { moveToBench(); return; }
	int close = 2 * r + 2;
	int xc, yc, xb, yb, xd, yd;
	field->getCentre(xc, yc);
	ball->getCoord(xb, yb);
	xd = xb; yd = yb;
	bool ownSide = (teamNo == 1 && x<xc) || (teamNo == 2 && x>xc);
	if (ownSide && distance(x, y, xb, yb)>150) yd = disperse(y, 50);
	energy = energy>0 ? --energy : 0;
	if(energy != 0)speed = 5 + rand() % energy / 1000;
	else speed = 5;

	dir = direction(x, y, xd, yd);
	dir = disperse(dir, PI / 12);

	x += speed * cos(dir);
	y -= speed * sin(dir);

	avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void Player::kick()
{
	int xb, yb, xc, yc, xd, yd, speedb;
	ball->getCoord(xb, yb);
	field->getCentre(xc, yc);
	yd = yc;
	if (teamNo == 1)  xd = field->MyRect.right; //field right
	else            xd = field->MyRect.left; // field left

	speedb = disperse(20, 10);

	bool ownSide = (teamNo == 1 && x<xc) || (teamNo == 2 && x>xc);

	CPoint p = partner();
	if (p.x >= 0) { 
		int speedp = sqrt(2 * distance(x, y, p.x, p.y) + 0.25) - 0.5;

		if ((teamNo == 1 && p.x>x + 10) || (teamNo == 2 && p.x<x - 10)) {
			xd = p.x; yd = p.y;
			speedb = speedp + disperse(10, 5);
		}

		if (field->gameState == sFirstKick) {
			xd = p.x; yd = p.y; speedb = speedp + disperse(10, 3);
			field->gameState = sRunning;
		}
	} 

	double dirb;
	dirb = direction(xb, yb, xd, yd);
	dirb = disperse(dirb, PI / 24);
	ball->setDir(dirb);
	ball->setSpeed(speedb);
	sound = 2;
}
void Player::avoidCollision()
{
	int lim = 5 * r;
	int nPos = field->Team1.size() + field->Team2.size();
	CPoint* occupiedPos = new CPoint[nPos];

	int j = 0;
	for (int i = 0; i < field->Team1.size(); i++) {
		if (field->Team1[i] == this) continue;
		if (!field->Team1[i]->inGame) continue;
		occupiedPos[j].x = field->Team1[i]->x;
		occupiedPos[j].y = field->Team1[i]->y;
		++j;
	}
	for (int i = 0; i < field->Team2.size(); i++) {
		if (field->Team2[i] == this) continue;
		if (!field->Team2[i]->inGame) continue;
		occupiedPos[j].x = field->Team2[i]->x;
		occupiedPos[j].y = field->Team2[i]->y;
		++j;
	}
	occupiedPos[j].x = field->referee->getPos().x;
	occupiedPos[j].y = field->referee->getPos().y;

	int attempts = 10000;
	bool tooClose;
	int xa = x, ya = y, speeda = speed;
	double dira = dir;
	int dist;
	nPos = j + 1;
	do {
		for (int i = 0; i < nPos; i++) {
			tooClose = distance(xa, ya, occupiedPos[i].x, occupiedPos[i].y)<lim;
			dist = distance(xa, ya, occupiedPos[i].x, occupiedPos[i].y);
			if (tooClose) {
				--attempts;
				speeda = speeda + dist - lim;//disperse(speed, lim);
				dira = disperse(dir, PI / 12);
				xa = x + speeda * cos(dira);
				ya = y - speeda * sin(dira);
				break;
			}
		}
	} while (tooClose && attempts>0);
	x = xa;
	y = ya;
	speed = speeda;
	dir = dira;
	delete occupiedPos;
}

void Player::moveToBench()
{
	int xc, yc;
	field->getCentre(xc, yc);
	if (teamNo == 1)
		moveTo(xc - 20 - No * 3 * r, r + 1);
	else
		moveTo(xc + 20 + No * 3 * r, r + 1);
}

CPoint& Player::partner()
{
	int dist[7];
	CPoint p[6];
	int n = 0;

	if (teamNo == 1) {
		for (int i = 0; i < field->Team1.size(); i++) {
			if (field->Team1[i] == this) continue;
			if (!field->Team1[i]->inGame) continue;
			if (field->Team1[i]->type == tGoalkeeper) continue;
			p[n].x = field->Team1[i]->x;
			p[n].y = field->Team1[i]->y;
			++n;
		}
	}
	else {
		for (int i = 0; i < field->Team2.size(); i++) {
			if (field->Team2[i] == this) continue;
			if (!field->Team2[i]->inGame) continue;
			if (field->Team2[i]->type == tGoalkeeper) continue;
			p[n].x = field->Team2[i]->x;
			p[n].y = field->Team2[i]->y;
			++n;
		}
	}
	if (n == 0) { p[0].x = -1; return p[0]; } // no partners
	int d, mindist = distance(x, y, p[0].x, p[0].y);
	int np = 0;
	for (int i = 0; i < n; i++) {
		d = distance(x, y, p[i].x, p[i].y);
		if (d<mindist) {
			mindist = d;
			np = i;
		}
	}
	return p[np];
} 