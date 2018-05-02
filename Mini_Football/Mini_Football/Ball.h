#pragma once
class Field;
class Ball {
private:
	int x;
	int y;
	int r;
	int speed;
	int slowdown;
	double dir;
	Field* field;

	CDC* pImageDC; //  CDC class for device context; represents the area on the screen that needs to be repainted
	COLORREF color;

public:
	Ball(CWnd* pImage, Field* field); // CWnd class for handle of a window
	void setSpeed(int s) { speed = s; }
	int getSpeed() { return speed; }
	void setDir(double d) { dir = d; }
	double getDir() { return dir; }
	void draw();
	void move();
	void moveTo(int xTo, int yTo) { x = xTo; y = yTo; }
	void getCoord(int& xb, int& yb) { xb = x; yb = y; }


};