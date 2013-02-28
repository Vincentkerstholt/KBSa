#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include "Win.h"
#include "GameObject.h"
#include "factories.h"

using namespace std;

class Gamestate
{
public:
	Gamestate();
	Gamestate(int x, int y);
	void drawGrid(HDC & hdc);
	void drawBackground(HDC & hdc);
	void drawWorld(HDC & hdc);
	void changeFactory(char firstLetter);
	~Gamestate();
private:
	IThemeFactory * factory;
	Gameobject * level;
	int x;
	int y;
	int multiplier;
	HDC hdc;
	POINT point;
	HANDLE hBackgroundBitmap;
	HDC hBackgroundDC;
	BITMAP bitmap;

	void DrawHorizontalBorder(int startX, int startY);
	void DrawVerticalBorder(int startX, int startY);
	int ConvertIndexToXY(int index);
};
#endif