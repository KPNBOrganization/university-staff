#include "stdafx.h"
#include "Field.h"
#include "Full_footballDlg.h"


Field::Field(CWnd* pImage) {
	pImage->GetWindowRect(MyRect);
	pImageDC = pImage->GetDC();
	borderWidth = MyRect.Height() / 20;
	
	h = MyRect.Height() - borderWidth;
	w = MyRect.Width() - borderWidth;

	goalWidth = h / 8;
	goalAreaH = goalWidth * 2;
	goalAreaW = goalWidth * 0.75;
	
	x_c = MyRect.Width() / 2;	// previous w/2 + borderheight is incorrect (due to geom. calculations)
	y_c = MyRect.Height() / 2;	// same with h
}

void Field::draw() {
	CBrush pMyGreenBrush, pMyBlackBrush;
	pMyGreenBrush.CreateSolidBrush(RGB(0, 102, 0));
	pMyBlackBrush.CreateSolidBrush(RGB(0, 0, 0));

	pImageDC->SelectObject(&pMyBlackBrush);
	pImageDC->Rectangle(0, 0, MyRect.Width(), MyRect.Height());
	pImageDC->SelectObject(&pMyGreenBrush);
	pImageDC->Rectangle(borderWidth, borderWidth, w, h);
}

void Field::drawLines() {
	CPen pMyWhitePen;
	CBrush pMyWhiteBrush, pMyDiagCrossWhiteBrush;
	pMyWhitePen.CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	pMyWhiteBrush.CreateSolidBrush(RGB(255, 255, 255));
	pMyDiagCrossWhiteBrush.CreateHatchBrush(HS_DIAGCROSS, RGB(255, 255, 255));
	pImageDC->SelectObject(&pMyWhitePen);
	pImageDC->SelectStockObject(NULL_BRUSH);
	pImageDC->Rectangle(borderWidth, borderWidth, w, h);
	pImageDC->Ellipse(x_c - 45, y_c - 45, x_c + 45, y_c + 45);
	pImageDC->MoveTo(x_c, borderWidth);
	pImageDC->LineTo(x_c, MyRect.Height() - borderWidth);
	pImageDC->SelectObject(&pMyDiagCrossWhiteBrush);
	pImageDC->SetBkMode(TRANSPARENT);
	pImageDC->Rectangle(0, y_c - goalWidth / 2, borderWidth, y_c + goalWidth / 2);
	pImageDC->Rectangle(w, y_c - goalWidth / 2, MyRect.Width(), y_c + goalWidth / 2);
	pImageDC->SelectStockObject(NULL_BRUSH);
	pImageDC->Rectangle(borderWidth, y_c - goalAreaH / 2, borderWidth + goalAreaW, y_c + goalAreaH / 2);
	pImageDC->Rectangle(w - goalAreaW, y_c - goalAreaH / 2, w, y_c + goalAreaH / 2);
	pImageDC->SelectObject(&pMyWhiteBrush);
	pImageDC->Ellipse(x_c - 2, y_c - 2, x_c + 2, y_c + 2); 
}

bool Field::isInside(int x, int y, int r) {

	return x >= (borderWidth + r) && x <= (w - r) && y >= (borderWidth + r) && y <= (h - r);
}

bool Field::isOutSide(int x, int y, int r) {
	return y < (borderWidth + r) || y >(h - r);
}

bool Field::isOutLeft(int x, int y, int r) {
	return x < (borderWidth + r);
}

bool Field::isOutRight(int x, int y, int r) {
	return x >(w - r);
}

bool Field::onLeft(int x, int y, int r) {
	return x <= (x_c + r);
}

bool Field::onRight(int x, int y, int r) {
	return x >= (x_c - r);
}

bool Field::isGoalLeft(int x, int y, int r) {
	return isOutLeft(x, y, r) && (y >(y_c - goalWidth / 2)) && (y < (y_c + goalWidth / 2));
}

bool Field::isGoalRight(int x, int y, int r) {
	return isOutRight(x, y, r) && (y >(y_c - goalWidth / 2)) && (y < (y_c + goalWidth / 2));
}

bool Field::insideLeftGoalArea(int x, int y, int r) {
	return x < (borderWidth + goalAreaW) && x > borderWidth && (y > (y_c - goalAreaH / 2)) && (y < (y_c + goalAreaH / 2));

}
bool Field::insideRightGoalArea(int x, int y, int r) {
	return x > (w - goalAreaW) && x < w && (y >(y_c - goalAreaH / 2)) && (y < (y_c + goalAreaH / 2));
}