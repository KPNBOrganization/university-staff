#pragma once
#include "Player.h"
class Forward : public Player
{
protected:

public:
	Forward(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n);
	//void kick();
};