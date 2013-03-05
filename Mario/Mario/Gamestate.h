#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <typeinfo>
#include "Win.h"
#include "GameObject.h"
#include "Hero.h"
#include "factories.h"
#include "obstacles.h"
#include "Camera.h"
#include <sstream>

using namespace std;

class Hero;

class Gamestate
{
public:
	Gamestate();
	Gamestate(int x, int y);
	void draw (HDC & hdc, bool debugMode);
	void changeFactory(char firstLetter);
	Hero * Mario;
	~Gamestate();

	Camera camera;
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
	int frames;

	void DrawHorizontalBorder(int startY);
	void DrawVerticalBorder(int startX);
	void drawCharacters(HDC & hdc);
	void drawGrid(HDC & hdc);
	void drawBackground(HDC & hdc);
	void drawWorld(HDC & hdc);
	int ConvertIndexToXY(int index);
	void CreateWorld();
	int getIndex(int n, int m);
	void Gamestate::drawStatistics(HDC & hdc);
};
#endif