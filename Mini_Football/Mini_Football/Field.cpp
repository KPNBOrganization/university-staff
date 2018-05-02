#include "stdafx.h"
#include "Field.h"
#include "Mini_footballDlg.h"

extern CMiniFootballDlg *FootballDlg;

Field::Field(CWnd* pImage) {
	pImage->GetWindowRect(MyRect);
	pImageDC = pImage->GetDC();
	h = MyRect.Height();
	w = MyRect.Width();
	x_c = w / 2;
	y_c = h / 2;
}

void Field::draw() {
	CBrush pMyBrush;
	pMyBrush.CreateSolidBrush(RGB(0, 102, 0));

	pImageDC->SelectObject(&pMyBrush);
	pImageDC->Rectangle(0, 0, w, h);
	drawLines();
}

void Field::drawLines() {
	CPen pMyPen;
	CBrush pMySecondBrush;
	pMyPen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	pMySecondBrush.CreateSolidBrush(RGB(255, 255, 255));

	pImageDC->SelectObject(&pMyPen);
	pImageDC->Ellipse(x_c - 45, y_c - 45, x_c + 45, y_c + 45);
	pImageDC->MoveTo(x_c, 0);
	pImageDC->LineTo(x_c, MyRect.bottom);
	pImageDC->SelectObject(&pMySecondBrush);
	pImageDC->Ellipse(x_c - 2, y_c - 2, x_c + 2, y_c + 2);
}

bool Field::isInside(int x, int y, int r) {

	return x >= (0 + r) && x <= (w - r) && y >= (0 + r) && y <= (h - r);
}

bool Field::isOutSide(int x, int y, int r) {
	return y < (0 + r) || y > (h - r);
}

bool Field::isOutLeft(int x, int y, int r) {
	return x < (0 + r);
}

bool Field::isOutRight(int x, int y, int r) {
	return x >(w - r);
}