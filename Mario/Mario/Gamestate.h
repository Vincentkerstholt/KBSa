#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <typeinfo>
#include "Win.h"
#include "GameObject.h"
#include "factories.h"
#include "obstacles.h"
#include "characters.h"
#include "Camera.h"
#include <time.h>
#include <sstream>
#include "XMLParser.h"
#include "Castle.h"
#include "gadgets.h"
#include "Score.h"

using namespace std;

class Hero;
class XmlParser;

class Gamestate
{
public:
	Gamestate();
	void menu(HDC & hdc);
	Gamestate(int x, int y);
	Gameobject ** getLevel();
	void draw (HDC & hdc, bool debugMode);
	void changeFactory(char firstLetter);
	bool getQuit();
	string BoxCheck(int index);
	int getIndex(int n, int m);
	int getIndex(POINT & pnt);
	void Collision();
	void UpdateEnemy(int index);
	POINT getPixelPoint(int index);
	bool UpDownCollision(HDC & hdc);
	string getCurrentFactory();
	int getCurrentLevel();
	int getX();
	int getY();
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
	HFONT hFont;
	HFONT hFont2;
	HFONT hFontOld;
	bool inHighScore;
	bool quit;
	bool toDoNextLevel;
	bool toDoLoadLevel;
	bool toDoNewGame;
	int currentLevel;
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
	int highScorePos;
	string name;
	bool inNameInput;
	void nameInput();
	void HighScore(HDC & hdc);
	void DrawHorizontalBorder(int startY);
	void DrawVerticalBorder(int startX);
	void drawCharacters(HDC & hdc);
	void drawGrid(HDC & hdc);
	void drawBackground(HDC & hdc);
	void drawWorld(HDC & hdc);
	int ConvertIndexToXY(int index);
	IThemeFactory * getFactory(string name);
	void CreateWorld(int number);
	void destroyWorld(bool deleteXML);
	void CreateWorld();
	void loadGame();
	void saveGame();
	void Gamestate::drawStatistics(HDC & hdc);
	void Gamestate::drawHUD(HDC & hdc);
	void resetWorld();
	void createHero();
	void createLevel();
	void createFactory();
	void createBlocks();
	void createGrounds();
	void createPipes();
	void createEnemies();
	void createCastles();
	void nextLevel();
	void setHighscore();
	void splashscreen(HDC & hdc,int splashscreenlevel);
};
#endif