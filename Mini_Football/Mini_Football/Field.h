#pragma once
class Field {
private:
	int h;
	int w;
	int x_c;
	int y_c;
	CWnd* pImage;
	CDC* pImageDC;

public:
	CRect MyRect;
	Field(CWnd* pImage);
	void getCentre(int& x, int& y) { x = x_c; y = y_c; }
	int getH() { return h; }
	int getW() { return w; }
	void draw();
	void drawLines();
	bool isInside(int x, int y, int r);
	bool isOutSide(int x, int y, int r);
	bool isOutLeft(int x, int y, int r);
	bool isOutRight(int x, int y, int r);
};