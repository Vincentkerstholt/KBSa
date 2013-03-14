#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <typeinfo>
#include "Win.h"
#include "GameObject.h"
#include "Hero.h"
#include "factories.h"
#include "obstacles.h"
#include "Camera.h"
#include <time.h>
#include <sstream>
#include "XMLParser.h"

using namespace std;

class Hero;

class Gamestate
{
public:
	Gamestate();
	void menu(HDC & hdc);
	Gamestate(int x, int y);
	void draw (HDC & hdc, bool debugMode);
	void changeFactory(char firstLetter);
	string BoxCheck(int index);
	int getIndex(int n, int m);
	void UpDownCollision();
	void HeroDie();
	Hero * Mario;
	bool inMenu;
	~Gamestate();

	Camera camera;
private:
	IThemeFactory * factory;
	Gameobject ** level;
	int x;
	int y;
	HDC hdc;
	POINT point;
	int selector;


	HANDLE hBackgroundBitmap;
	HANDLE hBackgroundBitmap2;
	HANDLE SpecialSheet;
	HANDLE hObstacleBitmap;
	
	HDC hBackgroundDC;
	HDC hObstacleDC;
	BITMAP bitmap;
	HDC hCharacterDC;
	HDC hLivesDC;
	int frames;
	int curTime;
	int fps;
	XmlParser * xml;

	void DrawHorizontalBorder(int startY);
	void DrawVerticalBorder(int startX);
	void drawCharacters(HDC & hdc);
	void drawGrid(HDC & hdc);
	void drawBackground(HDC & hdc);
	void drawWorld(HDC & hdc);
	int ConvertIndexToXY(int index);
	void CreateWorld(int number);
	void destroyWorld();
	void CreateWorld();
	void Gamestate::drawStatistics(HDC & hdc);
	void Gamestate::drawHUD(HDC & hdc);
	IThemeFactory * getFactory(string name);
};
#endif