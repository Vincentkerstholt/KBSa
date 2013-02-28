#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <typeinfo>
#include "Win.h"
#include "GameObject.h"
#include "factories.h"
#include "Block.h"
#include "Pipe.h"

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
	Gameobject ** level;
	int x;
	int y;
	int multiplier;
	HDC hdc;
	POINT point;
	HANDLE hBackgroundBitmap;
	HANDLE hObstacleBitmap;
	HDC hBackgroundDC;
	HDC hObstacleDC;
	BITMAP bitmap;

	void DrawHorizontalBorder(int startX, int startY);
	void DrawVerticalBorder(int startX, int startY);
	int ConvertIndexToXY(int index);
	void CreateWorld();
	int getIndex(int n, int m);
};
#endif