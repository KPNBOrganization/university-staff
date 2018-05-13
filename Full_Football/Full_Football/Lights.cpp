#include "stdafx.h"
#include "Lights.h"
#include "Field.h"
#include "Full_FootballDlg.h"
#include "functions.h"
#include "afxwin.h"


Lights::Lights(CWnd* pImage, int xp, int yp, int towerH,
	double foc,
	double dir1, double dir2,
	double tilt1, double tilt2)
{
	pImageDC = pImage->GetDC();
	x = xp;
	y = yp;
	dir = dir1;
	dirStart = dir1;
	dirEnd = dir2;
	dirSpeed = PI / 64;
	focus = foc;
	towerHeight = towerH;
	tilt = tilt1;
	tiltStart = tilt1;
	tiltEnd = tilt2;
	tiltSpeed = PI / 48;
	on = false;
}

void Lights::draw()
{
	if (!on) return;
	CPoint poly[3];
	poly[0].x = x;
	poly[0].y = y;
	int dist = towerHeight * tan(tilt);
	int xspot = x + dist * cos(dir);
	int yspot = y - dist * sin(dir);
	int d1 = dist / sin(tilt);

	int spotLength = towerHeight * tan(tilt - focus / 2) - towerHeight * tan(tilt + focus / 2);
	int spotWidth = 2 * d1*tan(focus / 2);

	int x1 = xspot - spotWidth / 2 * sin(dir);
	int y1 = yspot - spotWidth / 2 * cos(dir);
	int x2 = xspot + spotWidth / 2 * sin(dir);
	int y2 = yspot + spotWidth / 2 * cos(dir);

	poly[1].x = x1;
	poly[1].y = y1;
	poly[2].x = x2;
	poly[2].y = y2;
	CPen pMyYellowPen, pMyGreenPen;
	CBrush pMyYellowBrush, pMyGreenBrush;
	pMyYellowPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 0));
	pMyYellowBrush.CreateSolidBrush(RGB(255, 255, 0));
	pImageDC->SelectObject(pMyYellowPen);
	pImageDC->SelectObject(pMyYellowBrush);
	pImageDC->Polygon(poly,3);

	pMyGreenPen.CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	pMyGreenBrush.CreateSolidBrush(RGB(0, 255, 0));
	pImageDC->SelectObject(&pMyGreenPen);
	pImageDC->SelectObject(&pMyGreenBrush);
	angellipse(pImageDC, xspot, yspot, spotLength / 2, 0, 2 * PI, dir, spotWidth*1.0 / spotLength);

}


void Lights::move()
{
	if (dir >= dirStart && dirSpeed>0) dirSpeed = -PI / 64;
	if (dir <= dirEnd && dirSpeed<0) dirSpeed = PI / 64;
	dir += dirSpeed;
	if (tilt <= tiltStart && tiltSpeed<0) tiltSpeed = PI / 48;
	if (tilt >= tiltEnd && tiltSpeed>0) tiltSpeed = -PI / 48;
	tilt += tiltSpeed;
}