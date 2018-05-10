#pragma once
#include "human.h"
class Girl : public Human {
public:
	Girl(CWnd* pImage, Field* field);
	void move();
	void draw();
};
