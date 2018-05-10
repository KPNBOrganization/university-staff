#include "stdafx.h"
#include "AssReferee.h"
#include <math.h>
#include "Ball.h"
#include "Full_FootballDlg.h"

AssReferee::AssReferee(CWnd* pImage, Field* Secondfield, Ball* Secondball) {
	ball = Secondball;
	field = Secondfield;
	pImageDC = pImage->GetDC();
	type = tAssReferee;
	color = RGB(0,255,0);
	speed = 2;
}

void AssReferee::move() {
	int xb, yb;
	ball->getCoord(xb, yb);
	if ((xb - x) != 0) {
		int delta = rand() % abs(xb - x);
		delta = delta > 5 ? 5 : delta;
		if (x < xb) x += speed + delta;
		if (x > xb) x -= speed + delta;
	}
}
