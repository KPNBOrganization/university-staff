#pragma once
#include "Player.h"
class FullBack : public Player
{
protected:

public:
	FullBack(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n);
	void move();
	void kick();
};
