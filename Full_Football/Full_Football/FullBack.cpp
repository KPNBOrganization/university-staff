#include "stdafx.h"
#include <math.h>
#include "FullBack.h"
#include "Field.h"
#include "Ball.h"
#include "Full_FootballDlg.h"
#include "Referee.h"
#include "functions.h"

FullBack::FullBack(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n) : Player(pImage, Secondfield, Secondball, t, n)
{
	field = Secondfield;
	ball = Secondball;
	pImageDC = pImage->GetDC();
	teamNo = t;
	No = n;
	speed = 5;
	int xc, yc;
	field->getCentre(xc, yc);
	if (teamNo == 1)  area = CRect(field->getBorderW(), field->getBorderW(),
		xc, field->getH());
	else            area = CRect(xc, field->getBorderW(),
		field->getW(), field->getH());
	type = tFullBack;
}

void FullBack::move()
{
	if (!inGame) {
		moveToBench(); return;
	}
	int close = 2 * r;
	int xb, yb, xc, yc, xd, yd;
	ball->getCoord(xb, yb);
	field->getCentre(xc, yc);

	energy = energy>0 ? --energy : 0;
	if (energy != 0)speed = 3 + rand() % energy / 1000;
	else speed = 3;

	xd = xb; yd = yb;
	if (teamNo == 1 && xb>xc) { xd = disperse(xc / 2, xc / 4); yd = rand() % (2 * yc); }
	if (teamNo == 2 && xb<xc) { xd = disperse(xc + xc / 2, xc / 4);  yd = rand() % (2 * yc); }

	dir = direction(x, y, xd, yd);

	x += speed * cos(dir);
	y -= speed * sin(dir);
	if (x<area.left) x = area.left + 2 * r;
	if (x>area.right) x = area.right - 2 * r;

	avoidCollision();

	if (distance(x, y, xb, yb)<close) kick();
}

void FullBack::kick()
{
	int xb, yb, xc, yc;
	ball->getCoord(xb, yb);
	field->getCentre(xc, yc);

	if (teamNo == 1) xc = field->getW();
	else  xc = field->getBorderW();
	double dirb = direction(xb, yb, xc, yc);
	dirb = disperse(dirb, PI / 8);
	ball->setDir(dirb);
	ball->setSpeed(30);
	sound = 1;
}