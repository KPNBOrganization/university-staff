#pragma once
#include "human.h"
class AssReferee : public Human {
public:
	AssReferee(CWnd* pImage, Field* field, Ball* ball);
	void move();
};