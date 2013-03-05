#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <typeinfo>
#include "Win.h"
#include "GameObject.h"
#include "Hero.h"
#include "factories.h"
#include "obstacles.h"
#include <sstream>

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
	void drawWorld(HDC & hdc);
	void drawStatistics(HDC & hdc);
	void changeFactory(char firstLetter);
	Hero * Mario;
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
	HDC hCharacterDC;

	void DrawHorizontalBorder(int startX, int startY);
	void DrawVerticalBorder(int startX, int startY);
	int ConvertIndexToXY(int index);
	void CreateWorld();
	int getIndex(int n, int m);
};
#endif