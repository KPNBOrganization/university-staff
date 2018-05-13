#include "stdafx.h"
#include "Referee.h"
#include <math.h>
#include "Ball.h"
#include "Field.h"
#include "Functions.h"
#include "Full_FootballDlg.h"

Referee::Referee(CWnd* pImage, Field* Secondfield, Ball* Secondball)
{
	ball = Secondball;
	field = Secondfield;
	pImageDC = pImage->GetDC();
	type = tReferee;
	color = RGB(255, 255, 0);
	speed = 0;
}

void Referee::move()
{
	int xb, yb;
	ball->getCoord(xb, yb);
	dir = direction(x, y, xb, yb);
	dir = disperse(dir, PI / 8);
	if (distance(x, y, xb, yb)<50) { speed = 3 + (rand() % 3); dir = -dir; }
	else speed = 3 + (rand() % 3 );
	x += speed * cos(dir);
	y -= speed * sin(dir);

}