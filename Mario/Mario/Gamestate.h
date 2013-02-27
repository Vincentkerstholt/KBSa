#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include "Win.h"

using namespace std;

class Gamestate
{
public:
	Gamestate();
	Gamestate(int x, int y);
	void drawGrid(HDC hdc);
	~Gamestate();
private:
	int * level;
	int x;
	int y;
	int multiplier;
	HDC hdc;
	POINT point;

	void DrawHorizontalBorder(int startX, int startY);
	void DrawVerticalBorder(int startX, int startY);
	int ConvertIndexToXY(int index);
};
#endif