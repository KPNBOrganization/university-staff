#include "stdafx.h"
#include <math.h>
#include "Goalkeeper.h"
#include "Field.h"
#include "Ball.h"
#include "Full_FootballDlg.h"
#include "Referee.h"
#include "functions.h"

Goalkeeper::Goalkeeper(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n) : Player(pImage, Secondfield, Secondball, t, n)
{
	field = Secondfield;
	ball = Secondball;
	pImageDC = pImage->GetDC();
	teamNo = t;
	No = n;
	speed = 1;
	color = t == 1 ? RGB(0,0,0) : RGB(0,0,150);
	int xc, yc;
	field->getCentre(xc, yc);
	int gw, gh;
	field->getGoalArea(gw, gh);
	if (teamNo == 1)  area = CRect(field->getBorderW(), yc - gh / 2,
		field->getBorderW() + gw, yc + gh / 2);
	else            area = CRect(field->getW() - gw, yc - gh / 2,
		field->getW(), yc + gh / 2);
	type = tGoalkeeper;
}

void Goalkeeper::move()
{
	int close = 2 * r;
	int xb, yb;
	ball->getCoord(xb, yb);

	speed = 5 + rand() % 5;          

	dir = direction(x, y, xb, yb);
	dir = disperse(dir, PI / 8);

	x += speed * cos(dir);
	y -= speed * sin(dir);

	if (x<area.left) x = area.left + 2 * r;
	if (x>area.right) x = area.right - 2 * r;
	if (y<area.top) y = area.top + 2 * r;
	if (y>area.bottom) y = area.bottom - 2 * r;

	avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void Goalkeeper::kick()
{
	int xb, yb, xc, yc;
	ball->getCoord(xb, yb);
	field->getCentre(xc, yc);

	if (teamNo == 1) xc = field->getW();
	else  xc = field->getBorderW();
	double dirb = direction(xb, yb, xc, yc);
	dirb = disperse(dirb, PI / 4);
	ball->setDir(dirb);
	ball->setSpeed(40);
	sound = 3;
}
