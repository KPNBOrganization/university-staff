#pragma once
#ifndef HUMAN_H
#define HUMAN_H

enum htype { // enumerated type, data type that consists of several named values(elements)
	tReferee, tAssReferee,
	tGoalkeeper, tForward,
	tHalfBack, tQuarterBack,
	tFullBack, tGirl
};

class Field;
class Ball;
class Human {
protected:
	int x;
	int y;
	int r;
	int speed;
	int energy;
	double dir;
	Field* field;
	Ball* ball;
	CDC* pImageDC;
	COLORREF color;
public:
	Human();
	htype type;
	void setSpeed(int s) { speed = s; }
	void setDir(double d) { dir = d; }
	void setEnergy(int e) { energy = e; };
	int getEnergy() { return energy; };
	CPoint getPos() { return CPoint(x, y); }
	double getDir() { return dir; }
	int getSpeed() { return speed; }
	virtual void draw();
	virtual void move() = 0;
	void moveTo(int x, int y);
};
#endif