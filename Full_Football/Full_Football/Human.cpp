#include "stdafx.h"
#include "Field.h"
#include "Human.h"
#include <math.h>
#include "Full_FootballDlg.h"

Human::Human()
{
	r = 3;
	speed = 0;
	energy = 0;
	dir = 0;
	color = RGB(0, 0, 255);
}

void Human::moveTo(int xTo, int yTo)
{
	x = xTo; y = yTo;
}

void Human::draw()
{
	CPen pMyPen;
	CBrush pMyBrush;
	pMyPen.CreatePen(PS_SOLID, 1, color);
	pMyBrush.CreateSolidBrush(color);
	pImageDC->SelectObject(&pMyPen);
	pImageDC->SelectObject(&pMyBrush);
	pImageDC->Ellipse(x - r, y - r, x + r, y + r);

}