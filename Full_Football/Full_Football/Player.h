#ifndef PLAYER_H
#define PLAYER_H
#include "human.h"

class Player : public Human
{
protected:
	int teamNo;
	int No;
	CRect area;
	CFont *font;
	int sound;


public:
	Player(CWnd* pImage, Field* field, Ball* ball, int t, int n);
	virtual void draw();
	virtual void move();
	
	void avoidCollision();
	bool inGame;
	virtual void kick();
	CPoint& partner();
	void moveToBench();
};
#endif 