#include "stdafx.h"
#include <math.h>
#include "Forward.h"
#include "Field.h"
#include "Ball.h"
#include "Full_FootballDlg.h"
#include "Referee.h"
#include "functions.h"

Forward::Forward(CWnd* pImage, Field* Secondfield, Ball* Secondball, int t, int n) : Player(pImage, Secondfield, Secondball, t, n)
{
	field = Secondfield;
	ball = Secondball;
	pImageDC = pImage->GetDC();
	teamNo = t;
	No = n;
	speed = 10;
	area = *(field->MyRect);
	type = tForward;
}