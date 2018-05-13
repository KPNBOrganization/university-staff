#pragma once
#include "Player.h"
class Goalkeeper : public Player
{
protected:

public:
	Goalkeeper(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n);
	void move();
	void kick();
};
