#include "Gamestate.h"

const int multiplier = 32;

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;
	
	Mario = new Hero();

	hBackgroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBackgroundBitmap2 = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	level = new Gameobject*[(x * y)];
	factory = new LandThemeFactory();

	frames = 0;
	curTime = 0;
	fps = 0;
	selector = 0;
	Mario->SetPosition(160,640);

	CreateWorld();
}

void Gamestate::draw(HDC & hdc, bool debugMode)
{
	frames++;

	camera.setXMidPosition(Mario->GetPositionPixel().x);
	DownCollision();
	drawBackground(hdc);
	drawCharacters(hdc);
	drawWorld(hdc);
	if (debugMode == true)
	{
		drawGrid(hdc);
		drawStatistics(hdc);
	}
}

int Gamestate::ConvertIndexToXY(int index){
	return (index*multiplier);
}

int Gamestate::getIndex(int n, int m){
	return (m*x)+n;
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
	oss.clear();

}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();
	

	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, 1362, 702, hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	
	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap);

	hBackgroundBitmap2 = factory->getBackgroundImage2();
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap2, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap2);

	TransparentBlt(hdc, -camera.getXPosition()/2%bitmap.bmWidth,				230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	TransparentBlt(hdc, bitmap.bmWidth - camera.getXPosition() / 2 % bitmap.bmWidth, 230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap2);
}

void Gamestate::drawWorld(HDC & hdc){

	hObstacleBitmap = factory->getGround(0, 0);

	for(int n = camera.getXPosition()/32; n < camera.getXPosition()/32 + 44  && n < x; n++){
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			if(level[index] == NULL)
				continue;
			if(level[index]->getClassName() == "Block")
			{
				hObstacleBitmap = factory->getBlock(n, m);

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				BitBlt(hdc, ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32, 32, hObstacleDC, 68, 50, SRCCOPY);

				DeleteDC(hObstacleDC);
				DeleteObject(hObstacleBitmap);
			}

			else if(level[index]->getClassName() == "Pipe")
				hObstacleBitmap = factory->getPipe(n, m);
			else if(level[index]->getClassName() == "Ground")
			{
				hObstacleBitmap = factory->getGround(n, m);

			hObstacleDC = CreateCompatibleDC(hdc);

			GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
			SelectObject(hObstacleDC, hObstacleBitmap);

			BitBlt(hdc, ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32, 32, hObstacleDC, 68, 0, SRCCOPY);

			DeleteDC(hObstacleDC);

			DeleteObject(hObstacleBitmap);
			}

		}
	}

	DeleteObject(hObstacleBitmap);
}


void Gamestate::changeFactory(char firstLetter){
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
	case 'W':
		factory = new WaterThemeFactory();
		break;
	}
}

void Gamestate::CreateWorld(){
	for(int n = 0; n < x; n++)
	{
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);

			if(m == y-1 && n == 10 )
				level[index] = NULL;
			else if(m == y-3 && n == 2 )
				level[index] = new Block(68,0);
			else if(m == y-2 && n == 15 )
				level[index] = new Ground(68,0);
			else if(m == y-1)
				level[index] = new Ground(68,0);
			else
				level[index] = NULL;
		}
	}
}

void Gamestate::menu(HDC & hdc)
{
	Sleep(100);

	if(GetAsyncKeyState(VK_UP))	{
		selector--;
	}
	if(GetAsyncKeyState(VK_DOWN))	{
		selector++;
	}
	if (GetAsyncKeyState(VK_ESCAPE))	{
		Sleep(150);
		inMenu = false;
	}

	if (selector < 0)
		selector = 0;
	if (selector > 2)
		selector = 2;

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (selector)
		{
		case 0:
			// reset lvl
			Mario->SetPosition(160,640);
			inMenu = false;
		break;
		case 1:
			//save game
		break;
		case 2:
			//load game
		break;
		default:
		break;
		}
	}

	hBackgroundBitmap = LoadImage(NULL, "res/menu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;

	delete factory;
	factory = NULL;
}

void Gamestate::DownCollision()
{
	POINT mario;
	POINT mario1;
	POINT mario2;
	POINT mario3;
	POINT mario4;
	int marioindex = 0 , marioindex2 = 0, marioindex3 = 0 , marioindex4 = 0;
	//down
	mario = Mario->GetPositionPixel();
	mario1.x = ((mario.x+31)/32);
	mario1.y = ((mario.y+33)/32);
	mario2.x = ((mario.x)/32);
	mario2.y = ((mario.y+33)/32);
	//up
	mario3.x = ((mario.x+31)/32);
	mario3.y = ((mario.y)/32);
	mario4.x = ((mario.x+2)/32);
	mario4.y = ((mario.y)/32);

	marioindex = getIndex(mario1.x,mario1.y);
	marioindex2 = getIndex(mario2.x,mario2.y);
	marioindex3 = getIndex(mario3.x,mario3.y);
	marioindex4 = getIndex(mario4.x,mario4.y);


	string check = BoxCheck(marioindex);
	string check2 = BoxCheck(marioindex2);
	string check3 = BoxCheck(marioindex3);
	string check4 = BoxCheck(marioindex4);
	
	if ( mario.y < 670)
	{
		if(Mario->Jumped < Mario->JumpHeight )
		{
			Mario->JumpAbility = true;
		}

		if (check3 == "Block" || check4 == "Block" )
		{
			Mario->JumpAbility = false;
									
		}

		if (check == "NULL" && check2 == "NULL" )
		{
			if (Mario->Jumped == 0)
			{
				Mario->JumpAbility = false;
			}
			Mario->SetPosition(mario.x, (mario.y+8));
		}
		else
		{
			Mario->Jumped=0;
			Mario->JumpAbility = true;
		}
		
	}
	else
	{
		Mario->JumpAbility = false;
	}	
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

