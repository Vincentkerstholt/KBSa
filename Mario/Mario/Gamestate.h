#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include "Win.h"
#include "GameObject.h"
#include "Hero.h"

using namespace std;
class Hero;

class Gamestate
{
public:
	Gamestate();
	Gamestate(int x, int y);
	void drawCharacters(HDC & hdc);
	void drawGrid(HDC & hdc);
	void drawBackground(HDC & hdc);
	~Gamestate();
private:
	int * level;
	int x;
	int y;
	int multiplier;
	HDC hdc;
	POINT point;
	HANDLE hBackgroundBitmap;
	HDC hBackgroundDC;
	BITMAP bitmap;
	HDC hCharacterDC;
	Hero * Mario;

	void DrawHorizontalBorder(int startX, int startY);
	void DrawVerticalBorder(int startX, int startY);
	int ConvertIndexToXY(int index);
};
#endif