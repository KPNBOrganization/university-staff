#include "stdafx.h"
#include <math.h>
#include "Girl.h"
#include "Field.h"
#include "Functions.h"
#include "Full_footballDlg.h"


Girl::Girl(CWnd* pImage, Field* Secondfield)
{
	field = Secondfield;
	pImageDC = pImage->GetDC();
	type = tGirl;
	color = RGB(255,0,255);
	speed = 5;
}

void Girl::move()
{
	int xc, yc;
	field->getCentre(xc, yc);
	if (speed>0 && y<100) speed = 3; else speed = -7;
	y += speed;
	if (y<5) {
		field->gameState = sRestartGame;
		r = 3;
		speed = 5;
	}
}
void Girl::draw()
{
	if (field->gameState == sPause) {
		r = (r == 3) ? 4 : 3;
	}
	Human::draw();

}