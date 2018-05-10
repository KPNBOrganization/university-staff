#pragma once
#include "human.h"

class Referee : public Human
{
public:
	Referee(CWnd* pImage, Field* field, Ball* ball);
	void move();
};