#pragma once
#include <vector>
enum state { sStop, sRunning, sPause, sGoal, sRestartGame, sFirstKick };
class Player;
class Referee;
class Field {
private:
	int h;
	int w;
	int x_c;
	int y_c;
	int borderWidth;
	int goalWidth;
	int goalAreaW;
	int goalAreaH;
	CWnd* pImage;
	CDC* pImageDC;

public:
	std::vector<Player*> Team1;
	std::vector<Player*> Team2;
	state gameState;
	CRect MyRect;
	Field(CWnd* pImage);
	Referee *referee;
	void getCentre(int& x, int& y) { x = x_c; y = y_c; }
	void getGoalArea(int& w, int& h) { w = goalAreaW; h = goalAreaH; }
	int getBorderW() { return borderWidth; }
	int getH() { return h; }
	int getW() { return w; }
	void draw();
	void drawLines();
	bool isInside(int x, int y, int r);
	bool isOutSide(int x, int y, int r);
	bool isOutLeft(int x, int y, int r);
	bool isOutRight(int x, int y, int r);
	bool onLeft(int x, int y, int r);
	bool onRight(int x, int y, int r);
	bool isGoalLeft(int x, int y, int r);
	bool isGoalRight(int x, int y, int r);
	bool insideLeftGoalArea(int x, int y, int r);
	bool insideRightGoalArea(int x, int y, int r);
};