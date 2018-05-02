#include "stdafx.h"
#include <math.h>
#include "Ball.h"
#include "Field.h"
#include "Mini_FootballDlg.h"

extern CMiniFootballDlg *FootballDlg;

Ball::Ball(CWnd* pImage, Field* Secondfield) {
	field = Secondfield;
	pImageDC = pImage->GetDC();
	r = 5;
	color = RGB(0, 0, 0);
	speed = 0;
	slowdown = 1;
	dir = 0;
}

void Ball::draw(){
	if (field->isInside(x, y, r)) {
		CPen pMyPen, pMySecondPen;
		CBrush pMyBrush, pMySecondBrush;
		pMyPen.CreatePen(PS_SOLID, 1, color);
		pMyBrush.CreateSolidBrush(color);
		pImageDC->SelectObject(&pMyPen);
		pImageDC->SelectObject(&pMyBrush);
		pImageDC->Ellipse(x - r, y - r, x + r, y + r);

	}
}

void Ball::move() {
	if (speed == 0) return;
	bool is_in = field->isInside(x, y, r);

	x += speed * cos(dir);
	y -= speed * sin(dir);
	speed = speed < slowdown ? 0 : speed - slowdown;
	bool will_be_in = field->isInside(x, y, r);

	if ( (is_in && !will_be_in) || (!is_in && !will_be_in) ) {
		if (field->isOutRight(x, y, r) ||
			field->isOutLeft(x, y, r)) dir = PI - dir;
		else dir = -dir;
	}
}


