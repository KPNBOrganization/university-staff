#include "stdafx.h"
#include <math.h>
#include "HalfBack.h"
#include "Field.h"
#include "Ball.h"
#include "Full_FootballDlg.h"
#include "Referee.h"
#include "functions.h"



HalfBack::HalfBack(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n) : Player(pImage,  Secondfield, Secondball,  t, n)
{
	field = Secondfield;
	ball = Secondball;
	pImageDC = pImage->GetDC();
	teamNo = t;
	No = n;
	speed = 10;
	area = *(field->MyRect);
	type = tHalfBack;
}

void HalfBack::kick()
{
	int xb, yb, xc, yc, xd, yd;
	double dirb, dirdisp = PI / 8;
	int kickSpeed = 20;
	ball->getCoord(xb, yb);
	field->getCentre(xc, yc);
	yd = yb;
	if (teamNo == 1) {
		xd = field->getW();
	}
	else {
		xd = field->getBorderW();
	}
	if (distance(xb, yb, xd, yd) <= 3 * kickSpeed) {
		yd = yc;
		dirdisp = 0;
	}

	dirb = direction(xb, yb, xd, yd);
	dirb = disperse(dirb, dirdisp);
	ball->setDir(dirb);
	ball->setSpeed(disperse(kickSpeed, kickSpeed / 2));
	sound = 1;
}


