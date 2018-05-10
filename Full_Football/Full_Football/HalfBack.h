#pragma once
#include "Player.h"
class HalfBack : public Player
{
public:
	HalfBack(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n);
	void kick();
};