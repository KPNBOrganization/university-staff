#include "stdafx.h"
#include <math.h>
#include "Ball.h"
#include "Field.h"
#include "Full_FootballDlg.h"


Ball::Ball(CWnd* pImage, Field* Secondfield) {
	field = Secondfield;
	pImageDC = pImage->GetDC();
	r = 2;
	color = RGB(0, 255, 255);
	speed = 0;
	slowdown = 3;
	dir = 0;
}

void Ball::draw() {
		CPen pMyPen;
		CBrush pMyBrush;
		pMyPen.CreatePen(PS_SOLID, 1, color);
		pMyBrush.CreateSolidBrush(color);
		pImageDC->SelectObject(&pMyPen);
		pImageDC->SelectObject(&pMyBrush);
		pImageDC->Ellipse(x - r, y - r, x + r, y + r);
}

void Ball::move() {
	if (speed == 0) return;
	bool is_in = field->isInside(x, y, r);
	x += speed * cos(dir);
	y -= speed * sin(dir);
	speed = speed < slowdown ? 0 : speed - slowdown;
	bool will_be_in = field->isInside(x, y, r);

	int xc, yc, wg, hg;
	field->getCentre(xc, yc);
	field->getGoalArea(wg, hg);
	if (field->isGoalLeft(x, y, r)) { x = field->getBorderW() - 4 * r; return;}
	if (field->isGoalRight(x, y, r)) { x = field->getW() + 4 * r; return; }
	if (is_in && !will_be_in) {
		if (field->isOutSide(x, y, r)) dir = 2 * PI - dir;
		if (field->isOutRight(x, y, r)) {
			moveTo(field->getW() - wg, yc);
			speed = 0;
		}
		if (field->isOutLeft(x, y, r)) {
			moveTo(field->getBorderW() + wg, yc);
			speed = 0;
		}
	}
}