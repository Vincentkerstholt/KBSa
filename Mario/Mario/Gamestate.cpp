#include "Gamestate.h"

#pragma region CONST
const int multiplier = 32;
const int GROUND_TOPLEFT = 1;
const int GROUND_TOPCENTER = 2;
const int GROUND_TOPRIGHT = 3;
const int GROUND_CENTERLEFT = 4;
const int GROUND_CENTERCENTER = 5;
const int GROUND_CENTERRIGHT = 6;
const int GROUND_BOTTOMLEFT = 7;
const int GROUND_BOTTOMCENTER = 8;
const int GROUND_BOTTOMRIGHT = 9;

const int PIPE_TOPLEFT = 1;
const int PIPE_TOPCENTER = 2;
const int PIPE_TOPRIGHT = 3;
const int PIPE_BOTTOMLEFT = 4;
const int PIPE_BOTTOMCENTER = 5;
const int PIPE_BOTTOMRIGHT = 6;

const int CASTLE_BATTLEMENT = 1;
const int CASTLE_BATTLEMENT_WALL = 2;
const int CASTLE_WALL = 3;
const int CASTLE_DOOR = 4;
const int CASTLE_LEFTGAP = 5;
const int CASTLE_GAP = 6;
const int CASTLE_RIGHTGAP = 7;
#pragma endregion CONST

Gamestate::Gamestate()
{
	SpecialSheet = LoadImage(NULL, "res/heart.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	xml = new XmlParser();
	frames = 0;
	curTime = 0;
	fps = 0;
	selector = 0;
	xml = new XmlParser();
	inMenu = true;
	inHighScore = false;
	inNameInput = false;
	currentLevel = -1;
	highScorePos = 0;
	name = "";
	Mario = NULL;
	quit = false;
	hFont = CreateFont(48,0,0,0,FW_DONTCARE,FALSE,TRUE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
	hFont2 = CreateFont(32,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
	hFontOld = CreateFont(20,0,0,0,FW_DONTCARE,FALSE,FALSE,FALSE,DEFAULT_CHARSET,OUT_OUTLINE_PRECIS,
		CLIP_DEFAULT_PRECIS,CLEARTYPE_QUALITY, VARIABLE_PITCH,TEXT("Impact"));
	toDoNewGame = false;
	toDoNextLevel = false;
	toDoLoadLevel = false;
}

Gameobject ** Gamestate::getLevel(){
	return level;
}

int Gamestate::getX(){
	return x;
}

int Gamestate::getY(){
	return y;
}

void Gamestate::saveGame(){
	xml->saveGame(this);
	inMenu = false;
}

bool Gamestate::getQuit(){
	return quit;
}

void Gamestate::draw(HDC & hdc, bool debugMode)
{
	if (toDoNewGame)
	{
		CreateWorld();
		Sleep(1000);
	}
	if (toDoLoadLevel)
	{
		loadGame();
		Sleep(1000);
	}
	if (toDoNextLevel)
	{
		nextLevel();
		Sleep(1000);
	}
	toDoNewGame = false;
	toDoNextLevel = false;
	toDoLoadLevel = false;


	frames++;
	camera.setXMidPosition(Mario->GetPositionPixel().x);
	Collision();
	if (UpDownCollision(hdc) == false)
		return;
	drawBackground(hdc);
	
	drawWorld(hdc);

	if (debugMode == true)
	{
		drawGrid(hdc);
		drawStatistics(hdc);
	}
	drawCharacters(hdc);
	drawHUD(hdc);

}

IThemeFactory * Gamestate::getFactory(string name){
	if(name == "landscape")
		return new LandThemeFactory();
	else if(name == "dungeon")
		return new DungeonThemeFactory();
	else if(name == "sky")
		return new SkyThemeFactory();
	else if(name == "city")
		return new CityThemeFactory();
	return new LandThemeFactory();
}

int Gamestate::ConvertIndexToXY(int index){
	return (index*multiplier);
}

int Gamestate::getIndex(int n, int m){
	return (m*x)+n;
}

int Gamestate::getIndex(POINT & pnt)
{
	return getIndex(pnt.x, pnt.y);
}

POINT Gamestate::getPixelPoint(int index)
{
	POINT temp;
	temp.y = (index / x) * 32;
	temp.x = (index % x) * 32;
	return temp;
}

void Gamestate::DrawHorizontalBorder(int y){
	MoveToEx(hdc, ConvertIndexToXY(0), ConvertIndexToXY(y), &point);
	LineTo(hdc, ConvertIndexToXY(43), ConvertIndexToXY(y));
}

void Gamestate::DrawVerticalBorder(int x){
	MoveToEx(hdc, ConvertIndexToXY(x)- camera.getXPosition()%multiplier, ConvertIndexToXY(0), &point);
	LineTo(hdc, ConvertIndexToXY(x)- camera.getXPosition()%multiplier, ConvertIndexToXY(22));
}

void Gamestate::drawGrid(HDC & hdc){
	this->hdc = hdc;
	for (int n = 0; n < 44; n++)
		DrawVerticalBorder(n);

	for(int m = 0; m < 22; m++)
		DrawHorizontalBorder(m);
}

void Gamestate::drawCharacters(HDC & hdc){
	this->hdc = hdc;
	hCharacterDC = CreateCompatibleDC(hdc);
	GetObject(this->Mario->texture, sizeof(BITMAP), &bitmap);
	SelectObject(hCharacterDC, this->Mario->texture);
	TransparentBlt(hdc, (Mario->GetPositionPixel().x - camera.getXPosition()), (Mario->GetPositionPixel().y), 32, 32, hCharacterDC, (Mario->getTexturePosition().x*multiplier), Mario->getTexturePosition().y*multiplier, 32,32, GetPixel(hCharacterDC, 0,0));
	DeleteDC(hCharacterDC);
}

void Gamestate::drawStatistics(HDC & hdc){
	SetBkMode(hdc,TRANSPARENT);
	int xValue = this->Mario->GetPositionPixel().x;
	int yValue = this->Mario->GetPositionPixel().y;
	ostringstream oss;

	oss << xValue << " " << yValue;
	TextOut(hdc, 10, 10, "Pos. Mario: ", 16);
	TextOut(hdc, 85, 10, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	int xValueTexture = this->Mario->getTexturePosition().x;
	int yValueTexture = this->Mario->getTexturePosition().y;
	oss << xValueTexture << " " << yValueTexture;
	TextOut(hdc, 10, 30, "TexturePos. Mario: ", strlen("TexturePos. Mario: "));
	TextOut(hdc, 140, 30, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	oss << Mario->getDirection();
	TextOut(hdc, 10, 50, "Direction Mario: ", strlen("Direction Mario: "));
	TextOut(hdc, 120, 50, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");

	POINT p;
	GetCursorPos(&p);

	oss << "Cursor X: " << (p.x-3) << " Y: " << (p.y-26);
	TextOut(hdc,  10, 70, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");

	frames++;
	if(time(NULL) != curTime)
	{
		curTime = (int)time(NULL);
		fps = frames;
		frames = 0;
	}
	oss << "Frames per second: " << fps;
	TextOut(hdc,  10, 90, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.clear();
}

void Gamestate::drawHUD(HDC & hdc){
	ostringstream oss;

	oss << "Score: " << Mario->getScore() ;
	TextOut(hdc, 600, 10, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	oss << "Coins: " << Mario->getCoins() ;
	TextOut(hdc, 600, 30, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	oss << "Lives: " ;
	TextOut(hdc, 600, 50, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	SIZE imgSize;

	hLivesDC = CreateCompatibleDC(hdc);
	GetObject(SpecialSheet, sizeof(BITMAP), &bitmap);
	SelectObject(hLivesDC, SpecialSheet);

	imgSize.cx = bitmap.bmWidth;
	imgSize.cy = bitmap.bmHeight;

	int x = 645;
	for (int i = 0; i < Mario->getLives(); i++)
	{
		TransparentBlt(hdc, x, 50, 16, 16, hLivesDC, 0, 0, 32, 32, RGB(255,174,201));
		x += 18;
	}

	DeleteDC(hLivesDC);
}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();
	
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, 1362, 702, hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	
	DeleteDC(hBackgroundDC);

	hBackgroundBitmap2 = factory->getBackgroundImage2();
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap2, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap2);

	TransparentBlt(hdc, -camera.getXPosition()/2%bitmap.bmWidth, 230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	TransparentBlt(hdc, bitmap.bmWidth - camera.getXPosition() / 2 % bitmap.bmWidth, 230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	DeleteDC(hBackgroundDC);
}

void Gamestate::drawWorld(HDC & hdc){
	for(int n = camera.getXPosition()/32; n < camera.getXPosition()/32 + 44  && n < x; n++){
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			if(level[index] == NULL)
				continue;
			
			string className = level[index]->getClassName();
			if(className == "Block")
			{
				hObstacleBitmap = factory->getBlock();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				Block * block = (Block *)level[index];

				int blockX = block->getPosX() * 34;
				int blockY = 0;
				
				if(!block->getIsSpecial())
					blockY = 32;

				if(block->getIsFixed())
					blockY = 64;
				
				TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,blockX,blockY,32,32,RGB(255,174,201));
			}
			else if(className == "Pipe")
			{
				Pipe * pipe = (Pipe*)level[index];
				hObstacleBitmap = factory->getPipe();
				
				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				
				int textTureType = pipe->getTextureType();

				switch(textTureType)
				{
				case PIPE_TOPLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
					break;

				case PIPE_TOPCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,0,32,32,RGB(255,174,201));
					break;

				case PIPE_TOPRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,0,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,32,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,32,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,32,32,32,RGB(255,174,201));
					break;
				}
			}
			else if(className == "Castle")
			{
				Castle * castle = (Castle*)level[index];
				hObstacleBitmap = factory->getCastle();
				
				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				
				int textTureType = castle->getTextureType();

				switch(textTureType)
				{
				case CASTLE_BATTLEMENT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,32,32,32,RGB(255,174,201));
					break;

				case CASTLE_BATTLEMENT_WALL:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,32,32,32,RGB(255,174,201));
					break;

				case CASTLE_WALL:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
					break;

				case CASTLE_DOOR:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,32,32,32,RGB(255,174,201));
					break;

				case CASTLE_LEFTGAP:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,0,32,32,RGB(255,174,201));
					break;

				case CASTLE_GAP:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,64,32,32,RGB(255,174,201));
					break;

				case CASTLE_RIGHTGAP:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,0,32,32,RGB(255,174,201));
					break;
				}
			}
			else if(className == "Ground")
			{
				Ground * ground = (Ground*)level[index];
				hObstacleBitmap = factory->getGround();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				int textTureType = ground->getTextureType();

				switch(textTureType){
				case GROUND_TOPLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
					break;

				case GROUND_TOPCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,0,32,32,RGB(255,174,201));
					break;

				case GROUND_TOPRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,0,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,32,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,32,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,32,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,64,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,64,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,64,32,32,RGB(255,174,201));
					break;
				}
			}
			else if(className == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[index];
				hObstacleBitmap = factory->getGoomba();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				TransparentBlt(hdc, (goomba->GetPositionPixel().x - camera.getXPosition()), (goomba->GetPositionPixel().y), 32, 32, hObstacleDC, (goomba->getTexturePosition().x*multiplier), goomba->getTexturePosition().y*multiplier, 32,32, RGB(255,174,201));
				UpdateEnemy(index);

			}
			else if(className == "Koopa")
			{
				Koopa * koopa = (Koopa*)level[index];
				hObstacleBitmap = factory->getKoopa();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				TransparentBlt(hdc, (koopa->GetPositionPixel().x - camera.getXPosition()), (koopa->GetPositionPixel().y), 32, 32, hObstacleDC, (koopa->getTexturePosition().x*multiplier), koopa->getTexturePosition().y*multiplier, 32,32, RGB(255,174,201));
				UpdateEnemy(index);

			}
			else if (className == "Coin")
			{
				hObstacleBitmap = factory->getGadget();
				hObstacleDC = CreateCompatibleDC(hdc);
				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				Gadget * tempGadget = (Gadget*)level[index];
				TransparentBlt(hdc,tempGadget->position.x - camera.getXPosition(), tempGadget->position.y, 32,32,hObstacleDC,0,0,32,32,GetPixel(hObstacleDC,0,0));
				tempGadget->updateGadget();
				if (tempGadget->progress == 32)
				{
					Mario->grabcoin();
					delete level[index];
					level[index] = NULL;
				}
			}
			else if (level[index]->getClassName() == "LiveUp")
			{
				hObstacleBitmap = factory->getGadget();
				hObstacleDC = CreateCompatibleDC(hdc);
				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				Gadget * tempGadget = (Gadget*)level[index];
				tempGadget->updateGadget();
				TransparentBlt(hdc,tempGadget->position.x - camera.getXPosition(), tempGadget->position.y, 32,32,hObstacleDC,32,0,32,32,GetPixel(hObstacleDC,0,0));
			}
			else if (level[index]->getClassName() == "Mushroom")
			{
				hObstacleBitmap = factory->getGadget();
				hObstacleDC = CreateCompatibleDC(hdc);
				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				Gadget * tempGadget = (Gadget*)level[index];
				tempGadget->updateGadget();
				TransparentBlt(hdc,tempGadget->position.x - camera.getXPosition(), tempGadget->position.y, 32,32,hObstacleDC,96,0,32,32,GetPixel(hObstacleDC,0,0));
			}
			else if (level[index]->getClassName() == "Flower")
			{
				hObstacleBitmap = factory->getGadget();
				hObstacleDC = CreateCompatibleDC(hdc);
				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				Gadget * tempGadget = (Gadget*)level[index];
				tempGadget->updateGadget();
				TransparentBlt(hdc,tempGadget->position.x - camera.getXPosition(), tempGadget->position.y, 32,32,hObstacleDC,64,0,32,32,GetPixel(hObstacleDC,0,0));
			}
			DeleteDC(hObstacleDC);
		}
	}
}

void Gamestate::changeFactory(char firstLetter){
	factory->delImage();
	factory = NULL;
	switch(firstLetter){
	case 'D':
		factory = new DungeonThemeFactory();
		break;
	case 'L':
		factory = new LandThemeFactory();
		break;
	case 'S':
		factory = new SkyThemeFactory();
		break;
	case 'C':
		factory = new CityThemeFactory();
		break;
	}
}

void Gamestate::CreateWorld(){
	if(currentLevel != -1)
		destroyWorld(true);

	xml->parse("res/World 1-1.xml");
	
	createLevel();
	createHero();
	createFactory();
	createBlocks();
	createGrounds();
	createPipes();
	createEnemies();
	createCastles();

	currentLevel = stoi(xml->getNode("level")->getAttribute("nr"));
}

void Gamestate::resetWorld(){
	destroyWorld(false);

	createLevel();
	createFactory();
	createBlocks();
	createGrounds();
	createPipes();
	createEnemies();
	createCastles();

	Mario->ResetPosition();
}

void Gamestate::destroyWorld(bool deleteXML)
{
	for(int i = 0 ; i < x ; i++)
	{
		for (int j = 0 ; j < y ; j++)
		{
			int index = getIndex(i,j);
			if (level[index] != NULL)
			{
				string levelName = level[index]->getClassName();
				if(levelName == "Block")
				{
					Block * block = (Block *)level[index];
					delete block;
					block = NULL;
				}
				else if(levelName == "Ground")
				{
					Ground * ground = (Ground *)level[index];
					delete ground;
					ground = NULL;
				}
				else if(levelName == "Pipe")
				{
					Pipe * pipe = (Pipe *)level[index];
					delete pipe;
					pipe = NULL;
				}
				else if(levelName == "Castle")
				{
					Castle * castle = (Castle *)level[index];
					delete castle;
					castle = NULL;
				}
				else if(levelName == "Goomba")
				{
					Goomba * goomba = (Goomba *)level[index];
					delete goomba;
					goomba = NULL;
				}
				else if(levelName == "Koopa")
				{
					Koopa * koopa = (Koopa *)level[index];
					delete koopa;
					koopa = NULL;
				}
			}
		}
	}
	
	delete [] level;
	level = NULL;

	string factoryName = factory->getName();
	if(factoryName == "dungeon")
	{
		DungeonThemeFactory * dungeon = (DungeonThemeFactory *)factory;
		delete dungeon;
		dungeon = NULL;
	}
	else if(factoryName == "landscape")
	{
		LandThemeFactory * landscape = (LandThemeFactory *)factory;
		delete landscape;
		landscape = NULL;
	}
	else if(factoryName == "sky")
	{
		SkyThemeFactory * sky = (SkyThemeFactory *)factory;
		delete sky;
		sky = NULL;
	}
	else if(factoryName == "city")
	{
		CityThemeFactory * city = (CityThemeFactory *)factory;
		delete city;
		city = NULL;
	}

	if(deleteXML)
		xml->Clear();
}

void Gamestate::loadGame(){
	if(currentLevel != -1)
		destroyWorld(true);

	xml->parse("res/saveGame.xml");
	
	createLevel();
	createHero();
	createFactory();
	createBlocks();
	createGrounds();
	createPipes();
	createEnemies();
	createCastles();

	inMenu = false;

	currentLevel = stoi(xml->getNode("level")->getAttribute("nr"));
}

void Gamestate::nextLevel()
{
	currentLevel++;
	destroyWorld(true);
	switch(currentLevel)
	{
	case 1:
		xml->parse("res/World 1-1.xml");
		break;

	case 2:
		xml->parse("res/World 1-2.xml");
		break;

	case 3:
		xml->parse("res/World 1-3.xml");
		break;

	case 4:
		xml->parse("res/World 1-4.xml");
		break;
		
	case 5:
		setHighscore();
		break;
	}

	if(!inMenu)
	{
		createLevel();
		createFactory();
		createBlocks();
		createGrounds();
		createPipes();
		createEnemies();
		createCastles();

		XmlParserNode * marioXml = xml->getNode("hero");

		int xMario = stoi(marioXml->getAttribute("x"));
		int yMario = stoi(marioXml->getAttribute("y"));

		Mario->SetStartPosition(xMario * 32, yMario * 32);
		Mario->SetPosition(xMario * 32, yMario * 32);
		Mario->setDirection('R');
		Mario->setTexturePosition(0,1);
	}
}

void Gamestate::createHero(){
	XmlParserNode * marioXml = xml->getNode("hero");

	if(currentLevel == -1)
		Mario = new Hero();

	int xMario = stoi(marioXml->getAttribute("x"));
	int yMario = stoi(marioXml->getAttribute("y"));

	Mario->SetStartPosition(xMario * 32, yMario * 32);
	Mario->setName(marioXml->getAttribute("character"));
	Mario->setLives(stoi(marioXml->getAttribute("lives")));
	Mario->setCoins(stoi(marioXml->getAttribute("coins")));
	Mario->setScore(stoi(marioXml->getAttribute("points")));
}

void Gamestate::createLevel(){
	XmlParserNode * levelXml = xml->getNode("level");
	x = stoi( levelXml->getAttribute("width") );
	y = stoi( levelXml->getAttribute("height") );

	level = new Gameobject*[(x * y)];

	for(int n = 0; n < x; n++)
	{
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			level[index] = NULL;
		}
	}
}

void Gamestate::createFactory(){
	XmlParserNode * factoryXml = xml->getNode("factory");
	factory = getFactory(factoryXml->getAttribute("name"));
}

void Gamestate::createBlocks(){
	XmlParserNode * blocks = xml->getNode("blocks");
	XmlParserNode ** childs = blocks->getChilds();

	for(int i = 0; i < blocks->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));

		XmlParserNode * gadget = child->getNode("gadget");
		Gadget ** gadgetArray = NULL;
		int gadgetLength = gadget->getChildsLength();
		if(gadgetLength > 0){
			gadgetArray = new Gadget * [gadgetLength];
			XmlParserNode ** gadgetChilds = gadget->getChilds();
			for(int j = 0; j < gadgetLength; j++)
			{
				XmlParserNode * gadgetChild = gadgetChilds[j];
				string gadgetChildTitle = gadgetChild->getTitle();
				if(gadgetChildTitle == "coin"){
					gadgetArray[j] = new Coin(getPixelPoint(index));
				}
				else if(gadgetChildTitle == "liveup"){
					gadgetArray[j] = new LiveUp(getPixelPoint(index));
				}
				else if(gadgetChildTitle == "powerup"){
					gadgetArray[j] = new Mushroom(getPixelPoint(index));
				}
			}
		}
		bool isSpecial = false;
		bool isFixed = false;


		if (child->getAttribute("isSpecial") == "true")
			isSpecial = true;
		if(child->getAttribute("isFixed") == "true")
			isFixed = true;

		if(gadgetLength > 0)
			level[index] = new Block(isSpecial, isFixed, gadgetArray, gadgetLength);
		else
			level[index] = new Block(isSpecial, isFixed);
	}
}

void Gamestate::createGrounds(){
	XmlParserNode * grounds = xml->getNode("grounds");
	XmlParserNode ** childs = grounds->getChilds();
	for(int i = 0; i < grounds->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int x = stoi(childLocation->getAttribute("x"));
		int y = stoi(childLocation->getAttribute("y"));
		int index = getIndex(x, y);
		level[index] = new Ground(stoi(child->getAttribute("type")));
	}
}

void Gamestate::createPipes(){
	XmlParserNode * pipes = xml->getNode("pipes");
	XmlParserNode ** childs = pipes->getChilds();
	for(int i = 0; i < pipes->getChildsLength(); i++){
		XmlParserNode * child = childs[i];

		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));
		level[index] = new Pipe(stoi(child->getAttribute("type")));
	}
}

void Gamestate::createEnemies(){
	XmlParserNode * enemies = xml->getNode("enemies");
	XmlParserNode ** childs = enemies->getChilds();
	for(int i = 0; i < enemies->getChildsLength(); i++)
	{
		XmlParserNode * child = childs[i];

		XmlParserNode * childLocation = child->getNode("location");
		XmlParserNode * childEndPath = child->getNode("endPath");
		int locationX = stoi(childLocation->getAttribute("x"));
		int locationY = stoi(childLocation->getAttribute("y"));
		int index = getIndex(locationX, locationY);

		int endPathX = stoi(childEndPath->getAttribute("x"));
		int endPathY = stoi(childEndPath->getAttribute("y"));
		string characterName = child->getAttribute("character");
		POINT P;
		if(characterName == "goomba")
		{
			Goomba * goomba = new Goomba(locationX, locationY, endPathX, endPathY);
			P.x = goomba->getStartPoint('x') *32;	
			P.y = goomba->getStartPoint('y') *32;	
			goomba->Move('R', P);
			level[getIndex(goomba->GetPositionIndex())] = goomba;
		}
		else if(characterName == "koopa")
		{
			Koopa * koopa = new Koopa(locationX, locationY, endPathX, endPathY);
			P.x = koopa->getStartPoint('x') *32;	
			P.y = koopa->getStartPoint('y') *32;	
			koopa->Move('R', P);
			level[getIndex(koopa->GetPositionIndex())] = koopa;
		}
	}
}

void Gamestate::createCastles(){
	XmlParserNode * castles = xml->getNode("castles");
	XmlParserNode ** childs = castles->getChilds();
	for(int i = 0; i < castles->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int x = stoi(childLocation->getAttribute("x"));
		int y = stoi(childLocation->getAttribute("y"));
		int index = getIndex(x, y);
		level[index] = new Castle(stoi(child->getAttribute("type")));
	}
}

void Gamestate::menu(HDC & hdc)
{
	if(inHighScore == true)
	{
		HighScore(hdc);
		return;
	}

	Sleep(100);

	if(GetAsyncKeyState(VK_UP))	{
		selector--;
	}
	if(GetAsyncKeyState(VK_DOWN))	{
		selector++;
	}
	if (GetAsyncKeyState(VK_ESCAPE))	{
		if(inMenu == false)
		{
			Sleep(150);
			inMenu = true;
		}
	}

	//clear the async key to prevent interacting with the game while in menu
	GetAsyncKeyState(VK_RIGHT);
	GetAsyncKeyState(VK_LEFT);
	GetAsyncKeyState(VK_F1);
	GetAsyncKeyState(VK_F2);
	GetAsyncKeyState(VK_F3);
	GetAsyncKeyState(VK_F4);
	GetAsyncKeyState(VK_F12);

	if (selector < 0)
		selector = 0;
	if (selector > 5)
		selector = 5;

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (selector)
		{
		case 0:
			// New game
			SelectObject(hdc, hFontOld);
			toDoNewGame = true;
			splashscreen(hdc,1);
			inMenu = false;
			return;
		break;
		case 1: //Continue game

			if (Mario!= NULL)
				if(Mario->getLives() > 0)
					inMenu = false;
			break;
		case 2:	//save game
			if (Mario!= NULL)
				if(Mario->getLives() > 0)
					saveGame();
		break;
		case 3:	//load game
			toDoLoadLevel = true;
			inMenu = false;
			splashscreen(hdc,6);
			return;
		break;
	
		case 4: //highscore
			inHighScore = true;
			break;

		case 5: //quit
			quit = true;
			break;
		default:
		break;
		}
	}
	if (Mario!= NULL)
	{
		if(Mario->getLives() > 0)
			hBackgroundBitmap = LoadImage(NULL, "res/menu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		else
			hBackgroundBitmap = LoadImage(NULL, "res/menu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	}
	else
		hBackgroundBitmap = LoadImage(NULL, "res/menu2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	BitBlt(hdc,0,0,1362,702,hBackgroundDC,0,0,SRCCOPY);

	DeleteObject(hBackgroundBitmap);

	hBackgroundBitmap = LoadImage(NULL, "res/Arrows.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	TransparentBlt(hdc,365 , 110 + (selector * 75) , bitmap.bmWidth , bitmap.bmHeight,hBackgroundDC,0,0,bitmap.bmWidth,bitmap.bmHeight,GetPixel(hBackgroundDC,0,0));
	
	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap);
}

void Gamestate::HighScore(HDC & hdc)
{
	if (inNameInput == true)
	{
		nameInput();
	}
	hBackgroundBitmap = LoadImage(NULL, "res/Highscore.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	BitBlt(hdc,0,0,1362,702,hBackgroundDC,0,0,SRCCOPY);

	DeleteObject(hBackgroundBitmap);
	DeleteDC(hBackgroundDC);
	SelectObject(hdc, hFont);

	ostringstream oss;
	oss << "Highscores:";
	TextOut(hdc, 580, 120, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	FILE * file;
	file = fopen(((string)"res/Highscores.txt").c_str(), "r");
	char * buffer;
	buffer = new char[100];
	SelectObject(hdc , hFont2);
	oss.str("");
	int n=0;
	if (file != NULL)
	while (!feof(file))
	{
		if(fgets(buffer, 100, file) == NULL) break;
		fputs(buffer, stdout);
		oss << (n+1) << ". " << buffer;
		TextOut(hdc, 580, 170+n*45, oss.str().c_str(), strlen(oss.str().c_str()));
		n++;
		oss.str("");
	}

	oss.clear();
	delete[] buffer;
	fclose(file);
	
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		inHighScore = false;
		SelectObject(hdc ,hFontOld);
	}
}

Gamestate::~Gamestate()
{
	if (currentLevel != -1)
	destroyWorld(true);
	if (xml != NULL)
	{
		delete xml;
		xml = NULL;
	}
}

bool Gamestate::UpDownCollision(HDC & hdc)
{
	// This collision detection is based on points. This function checks for every point in witch tile it is and what's in that tile.
	POINT mario;
	POINT MarioRightFeet;
	POINT MarioLeftFeet;
	POINT MarioRightHead;
	POINT MarioLeftHead;
	POINT MarioMidHead;
	BOOL selfjump;

	selfjump=false;

	//down points for collision
	mario = Mario->GetPositionPixel();
	MarioRightFeet.x = ((mario.x+24)/32); // Rightfeet x
	MarioRightFeet.y = ((mario.y+32)/32); //rightfeet y
	MarioLeftFeet.x = ((mario.x+ 4)/32); //left feet x
	MarioLeftFeet.y = ((mario.y+32)/32); //left feet y
	//up point for collision
	MarioRightHead.x = ((mario.x+24)/32); //Righthead x
	MarioRightHead.y = ((mario.y)/32); //Righthead y
	MarioLeftHead.x = ((mario.x+4)/32); //Lefthead x
	MarioLeftHead.y = ((mario.y)/32); //leftthead y
	MarioMidHead.x = ((mario.x+16)/32);
	MarioMidHead.y = ((mario.y)/32);
	
	if (mario.y < 662 && mario.y > 0 )
	{
	string RightFeet = BoxCheck(getIndex(MarioRightFeet));
	string LeftFeet = BoxCheck(getIndex(MarioLeftFeet));
	string RightHead = BoxCheck(getIndex(MarioRightHead));
	string LeftHead = BoxCheck(getIndex(MarioLeftHead));
	string MidHead = BoxCheck(getIndex(MarioMidHead));
	int index = getIndex(MarioMidHead);

		if (RightHead == "Block" || LeftHead == "Block" )
		{			
			Mario->JumpAbility = false;
			Mario->Jumped = 15;
			mario.y += 8;
			string boxCheck = BoxCheck(index);
			if (boxCheck == "Block" )
			{
				Block * tempBlock = ((Block *)level[index]);
				Gadget * tempGadget = tempBlock->getGadget();

				if (tempGadget != NULL)
				{
					string className = tempGadget->getClassName();
					if ( className == "Coin")
						level[index-x] = tempGadget;
					if ( className == "LiveUp")
						level[index-x] = tempGadget;
					if ( className == "Mushroom")
					{
						if (Mario->getPowerUp() == false)
							level[index-x] = tempGadget;
						else
						{
							POINT tempPoint = tempGadget->position;
							delete tempGadget;
							level[index-x] = new Flower(tempPoint);
						}
						level[index-x] = tempGadget;
					}
				}
				else
				{
					delete level[index];
					level[index] = NULL;
				}
			}
			if (boxCheck == "Coin")
			{
				Mario->grabcoin();
				delete level[index];
			}
			
			Mario->JumpAbility = false;
			Mario->Jumped = 15;
			
		}
		else if(RightHead == "Castle" || LeftHead == "Castle")
		{
			if(BoxCheck(index) == "Castle")
			{
				Castle * castle = (Castle *) level[index];
				if(castle->getTextureType() == CASTLE_DOOR)
				{
					toDoNextLevel = true;
					splashscreen(hdc, currentLevel+1);
					return false;
				}
			}
		}
		//this part below is a error fix for the 1 pixel on a block problem.
		else if (RightFeet == "Block"  || RightFeet == "Pipe"  ||   RightFeet == "Ground"   )
		{		
			int ypos = Mario->GetPositionPixel().y;
			if( ypos %32 != 0)
			{
				if(RightHead == "Null")
				{

				}
				else
				{
					Mario->SetPosition(mario.x, (mario.y+4));
				}
			}
		}
		else if ( RightHead == "LiveUp" || RightFeet == "LiveUp" || LeftHead == "LiveUp" || LeftFeet == "LiveUp" )
		{
			if (RightHead == "LiveUp"){
				delete level[getIndex(MarioRightHead)];
				level[getIndex(MarioRightHead)] = NULL;
				Mario->addLive();
			}
			else if (LeftHead == "LiveUp"){
				delete level[getIndex(MarioLeftHead)];
				level[getIndex(MarioLeftHead)] = NULL;
				Mario->addLive();
			}
			else if (LeftFeet == "LiveUp"){
				delete level[getIndex(MarioLeftFeet)];
				level[getIndex(MarioLeftFeet)] = NULL;
				Mario->addLive();
			}
			else if (RightFeet == "LiveUp"){
				delete level[getIndex(MarioRightFeet)];
				level[getIndex(MarioRightFeet)] = NULL;
				Mario->addLive();
			}
		}

		else if ( RightHead == "Mushroom" || RightFeet == "Mushroom" || LeftHead == "Mushroom" || LeftFeet == "Mushroom" )
		{
			if (RightHead == "Mushroom"){
				delete level[getIndex(MarioRightHead)];
				level[getIndex(MarioRightHead)] = NULL;
				Mario->grabPowerUp();
			}
			else if (LeftHead == "Mushroom"){
				delete level[getIndex(MarioLeftHead)];
				level[getIndex(MarioLeftHead)] = NULL;
				Mario->grabPowerUp();
			}
			else if (LeftFeet == "Mushroom"){
				delete level[getIndex(MarioLeftFeet)];
				level[getIndex(MarioLeftFeet)] = NULL;
				Mario->grabPowerUp();
			}
			else if (RightFeet == "Mushroom"){
				delete level[getIndex(MarioRightFeet)];
				level[getIndex(MarioRightFeet)] = NULL;
				Mario->grabPowerUp();

			}
		}

		else if ( RightHead == "Flower" || RightFeet == "Flower" || LeftHead == "Flower" || LeftFeet == "Flower" )
		{
			if (RightHead == "Flower"){
				delete level[getIndex(MarioRightHead)];
				level[getIndex(MarioRightHead)] = NULL;
				Mario->increaseScore(2000);
			}
			else if (LeftHead == "Flower"){
				delete level[getIndex(MarioLeftHead)];
				level[getIndex(MarioLeftHead)] = NULL;
				Mario->increaseScore(2000);
			}
			else if (LeftFeet == "Flower"){
				delete level[getIndex(MarioLeftFeet)];
				level[getIndex(MarioLeftFeet)] = NULL;
				Mario->increaseScore(2000);
			}
			else if (RightFeet == "Flower"){
				delete level[getIndex(MarioRightFeet)];
				level[getIndex(MarioRightFeet)] = NULL;
				Mario->increaseScore(2000);
			}
		}

		

		else if (LeftFeet == "Block"  || LeftFeet == "Pipe"  ||   LeftFeet == "Ground"   )
		{		

			int ypos = Mario->GetPositionPixel().y;
			int xpos = Mario->GetPositionPixel().x;
			if( ypos %32 != 0)
			{
				if(LeftHead == "Null")
				{

				}
				else
				{
					Mario->SetPosition(mario.x, (mario.y+4));
				}
			}

		}

		else if (RightHead == "Ground" || LeftHead == "Ground" )
		{			
			Mario->JumpAbility = false; 	
			Mario->Jumped = 15;	
		}
				
		else if (RightFeet == "Goomba" || LeftFeet == "Goomba" )
		{
			if (RightFeet == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioRightFeet.x,MarioRightFeet.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.y = goom.y - mari.y;
				mari.x = goom.x - mari.x;
					
				if(mari.y < 33)
				{
					if(mari.x < 20)
					{
						delete level[getIndex(MarioRightFeet.x,MarioRightFeet.y)];
						level[getIndex(MarioRightFeet.x,MarioRightFeet.y)]= NULL;
						Mario->SetPosition(mario.x, (mario.y-32)); // let mario jump

						selfjump=true;
					}
				}
			}
			else if (LeftFeet == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.y = goom.y - mari.y;
				mari.x = goom.x - mari.x;

				if(mari.y < 33)
				{
					mari.x = mari.x * (-1);
					if(mari.x < 20)
					{
					delete level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)];
					level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)]= NULL;
					Mario->SetPosition(mario.x, (mario.y-32)); // let mario jump

					selfjump=true;
					}
				}
			}
		}
				
		if (RightFeet == "NULL" && LeftFeet == "NULL" ) //if there is no block below mario
		{
			if (Mario->Jumped == 0) //if mario had not jumped yet
				Mario->JumpAbility = false; //set the jump ability false
			Mario->SetPosition(mario.x, (mario.y+4)); // let mario fall
		}
		else
		{
			if (RightFeet == "Castle" || LeftFeet == "Castle")
			{
				if (Mario->Jumped == 0) //if mario had not jumped yet
					Mario->JumpAbility = false; //set the jump ability false
				Mario->SetPosition(mario.x, (mario.y+4)); // let mario fall
			}
			else
			{
			Mario->Jumped=0; // if there is no air below, let mario jump again. 
			Mario->JumpAbility = true; 
			}
		}
	}
	else
	{
		if ( mario.y < 662) // if mario is not at the ground, so must be at the top of the level.
		{
			Mario->Jumped = 15; // max jump position. Mario can't jump anymore
			Mario->SetPosition(mario.x, (mario.y+4)); // let mario fall
		}
		else
		{
			HeroDie();
		}
		Mario->JumpAbility = false; // stop mario from jumping 
	}	
	return true;
}

string Gamestate::BoxCheck(int index)
{
	string type;
	if (level[index] != NULL)
	{
		type = level[index]->getClassName();
	}
	else
	{
	type = "NULL";
	}

	return type;
}

void Gamestate::HeroDie()
{
	if(Mario->hurt())
	{
		/////////////////
		//Add HighScore//
		/////////////////
		setHighscore();
		inMenu = true;
	}
	else
	{
		resetWorld();
	}
}

void Gamestate::Collision()
{
	POINT mario , MarioUp, MarioDown;
	mario = Mario->GetPositionPixel();
	if ( 0 < mario.y && mario.y < 670)
	{
		//gameState->Mario->setTexturePosition(1,1);
		MarioDown.x = ((mario.x+28)/32);
		MarioDown.y = ((mario.y+31)/32);
		MarioUp.x = ((mario.x+28)/32);
		MarioUp.y = ((mario.y)/32);

		string DownPoint = BoxCheck(getIndex(MarioDown.x,MarioDown.y));
		string UpPoint = BoxCheck(getIndex(MarioUp.x,MarioUp.y));

		if (DownPoint == "Block" || UpPoint == "Block")
			Mario->MoveAbilityR = false;

		else if (DownPoint == "Ground" || UpPoint == "Ground")
			Mario->MoveAbilityR = false;

		else if (DownPoint == "Pipe" || UpPoint == "Pipe")
			Mario->MoveAbilityR = false;

		else if (DownPoint == "Goomba" || UpPoint == "Goomba")
		{
			if(DownPoint == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioDown.x,MarioDown.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.x = goom.x - mari.x;
				if(mari.x < 15)
				{
					HeroDie();
				}
				else
				{
					Mario->MoveAbilityR = true;
				}
			}
			else if(UpPoint == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioUp.x,MarioUp.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.x = goom.x - mari.x;
				if(mari.x < 15)
				{
					HeroDie();
				}
				else
				{
					Mario->MoveAbilityR = true;
				}
			}
		}
		else
		{
			Mario->MoveAbilityR = true;
			
		}
	}

	mario = Mario->GetPositionPixel();
	if ( 0 < mario.y && mario.y < 670)
	{
		
		MarioDown.x = ((mario.x+2)/32);
		MarioDown.y = ((mario.y+31)/32);
		MarioUp.x = ((mario.x+2)/32);
		MarioUp.y = ((mario.y)/32);

		string DownPoint = BoxCheck(getIndex(MarioDown.x,MarioDown.y));
		string UpPoint = BoxCheck(getIndex(MarioUp.x,MarioUp.y));


		if (DownPoint == "Block" || UpPoint == "Block")
			Mario->MoveAbilityL = false;

		else if (DownPoint == "Ground" || UpPoint == "Ground")
			Mario->MoveAbilityL = false;

		else if (DownPoint == "Pipe" || UpPoint == "Pipe")
			Mario->MoveAbilityL = false;

		else if (DownPoint == "Goomba" || UpPoint == "Goomba")
			HeroDie();

		else
			Mario->MoveAbilityL = true;
	}
}

void Gamestate::UpdateEnemy(int index)
{
	string enemyName = level[index]->getClassName();
	if(enemyName == "Goomba"){
		Goomba * goomba = (Goomba*)level[index];
		
		if (goomba->GetPositionIndex().x == goomba->getEndPoint('x') )
			goomba->setDirection('R');
		else if (goomba->GetPositionIndex().x == goomba->getStartPoint('x'))
			goomba->setDirection('L');

		level[getIndex(goomba->GetPositionIndex())] = NULL;
		goomba->Move(goomba->getDirection(), goomba->GetPositionPixel());
		level[getIndex(goomba->GetPositionIndex())] = goomba;
	}
	else if(enemyName == "Koopa")
	{
		Koopa * koopa = (Koopa*)level[index];

		if (koopa->GetPositionIndex().x == koopa->getEndPoint('x') )
			koopa->setDirection('R');
		else if (koopa->GetPositionIndex().x == koopa->getStartPoint('x'))
			koopa->setDirection('L');

		level[getIndex(koopa->GetPositionIndex())] = NULL;
		koopa->Move(koopa->getDirection(), koopa->GetPositionPixel());
		level[getIndex(koopa->GetPositionIndex())] = koopa;
	}
}

string Gamestate::getCurrentFactory(){
	return factory->getName();
}

void Gamestate::setHighscore()
{
	ostringstream oss("");
	FILE * file;
	file = fopen(((string)"res/Highscores.txt").c_str(), "r");
	char * buffer;
	buffer = new char[100];
	SelectObject(hdc , hFont2);
	int n=0;

	Score scores [5];

	if (file != NULL)
		while ((!feof(file)) && n<5)
		{
			if(fgets(buffer, 100, file) == NULL) break;
			fputs(buffer, stdout);
			scores[n].setScore(buffer);
			n++;
		}
		
		bool inserted = false;
		for (int i = 0 ; i < 5 ; i++ )
		{
			if (scores[i].getScore() < Mario->getScore())
			{
				for(int j=3 ; j>=i ; j-- )
				{
					scores[j+1].setScore(scores[j].toString());
				}
				oss.str("");
				oss << " :" << Mario->getScore() << endl;
				scores[i].setScore(oss.str());
				oss.str("");
				highScorePos = i;
				inNameInput =true;
				break;
			}
		}
		fclose(file);
		//overwrite score with new scores here
		file = fopen(((string)"res/Highscores.txt").c_str(), "w");
		for (int i = 0 ; i < 5 ; i++)
			fputs(scores[i].toString().c_str(),file);
		
		inHighScore = true;
		oss.str("");
		oss.clear();
		delete[] buffer;
		fclose(file);
}

void Gamestate::nameInput()
{
	if (GetAsyncKeyState(0x41))
		name += "a";
	if (GetAsyncKeyState(0x42))
		name += "b";
	if (GetAsyncKeyState(0x43))
		name += "c";
	if (GetAsyncKeyState(0x44))
		name += "d";
	if (GetAsyncKeyState(0x45))
		name += "e";
	if (GetAsyncKeyState(0x46))
		name += "f";
	if (GetAsyncKeyState(0x47))
		name += "g";
	if (GetAsyncKeyState(0x48))
		name += "h";
	if (GetAsyncKeyState(0x49))
		name += "i";
	if (GetAsyncKeyState(0x4A))
		name += "j";
	if (GetAsyncKeyState(0x4B))
		name += "k";
	if (GetAsyncKeyState(0x4C))
		name += "l";
	if (GetAsyncKeyState(0x4D))
		name += "m";
	if (GetAsyncKeyState(0x4E))
		name += "n";
	if (GetAsyncKeyState(0x4F))
		name += "o";
	if (GetAsyncKeyState(0x50))
		name += "p";
	if (GetAsyncKeyState(0x51))
		name += "q";
	if (GetAsyncKeyState(0x52))
		name += "r";
	if (GetAsyncKeyState(0x53))
		name += "s";
	if (GetAsyncKeyState(0x54))
		name += "t";
	if (GetAsyncKeyState(0x55))
		name += "u";
	if (GetAsyncKeyState(0x56))
		name += "v";
	if (GetAsyncKeyState(0x57))
		name += "w";
	if (GetAsyncKeyState(0x58))
		name += "x";
	if (GetAsyncKeyState(0x59))
		name += "y";
	if (GetAsyncKeyState(0x5A))
		name += "z";
	if (GetAsyncKeyState(VK_BACK) && name.length()>0)
		name.pop_back();
	if (GetAsyncKeyState(VK_SPACE))
		name += " ";

	ostringstream oss("");
	oss << name << " :" << Mario->getScore() << "\n";
	


	FILE * file;
	file = fopen(((string)"res/Highscores.txt").c_str(), "r");
	char * buffer;
	buffer = new char[100];
	SelectObject(hdc , hFont2);
	int n=0;

	Score scores [5];

	if (file != NULL)
		while ((!feof(file)) && n<5)
		{
			if(fgets(buffer, 100, file) == NULL) break;
			fputs(buffer, stdout);
			scores[n].setScore(buffer);
			n++;
		}
		fclose(file);

		scores[highScorePos].setScore(oss.str());

		file = fopen(((string)"res/Highscores.txt").c_str(), "w");
		for (int i = 0 ; i < 5 ; i++)
			fputs(scores[i].toString().c_str(),file);
		
		oss.clear();
		delete[] buffer;
		fclose(file);
		Sleep(100);

		if (GetAsyncKeyState(VK_ESCAPE))
		{
			inNameInput = false;
			name = "";
		}
		else if (GetAsyncKeyState(VK_RETURN))
		{
			inNameInput = false;
			name = "";
		}
}

void Gamestate::splashscreen(HDC & hdc,int splashscreenlevel)
{
	switch (splashscreenlevel)
	{
	case 1:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenlvl1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenlvl1
		break;
	case 2:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenlvl2 
		break;
	case 3:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenlvl3
		break;
	case 4:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenlvl4
		break;
	case 5:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenfinish
		break;
	case 6:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenload
		break;
	default:
		hBackgroundBitmap = LoadImage(NULL, "res/splashscreenEnd.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE); //splashscreenlvl1
		break;
	}
	hBackgroundDC = CreateCompatibleDC(hdc);
	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	BitBlt(hdc,0,0,1362,702,hBackgroundDC,0,0,SRCCOPY);

	DeleteObject(hBackgroundBitmap);
	DeleteObject(hBackgroundDC);

}

int Gamestate::getCurrentLevel(){
	return currentLevel;
}