#include "Gamestate.h"

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;

	level = new Gameobject*[(x * y)];
	//factory = new DungeonThemeFactory();
	factory = new LandThemeFactory();

	multiplier = 32;

	CreateWorld();
}

int Gamestate::ConvertIndexToXY(int index){
	return (index*multiplier);
}

int Gamestate::getIndex(int n, int m){
	return (m*x)+n;
}

void Gamestate::DrawHorizontalBorder(int x, int y){
	MoveToEx(hdc, ConvertIndexToXY(x), ConvertIndexToXY(y), &point);
	LineTo(hdc, ConvertIndexToXY(x + 1), ConvertIndexToXY(y));
}

void Gamestate::DrawVerticalBorder(int x, int y){
	MoveToEx(hdc, ConvertIndexToXY(x), ConvertIndexToXY(y), &point);
	LineTo(hdc, ConvertIndexToXY(x), ConvertIndexToXY(y + 1));
}

void Gamestate::drawGrid(HDC & hdc){
	this->hdc = hdc;
	for (int n = 0; n < x; n++){
		for(int m = 0; m < y; m++){
			DrawVerticalBorder(n,m);
			DrawHorizontalBorder(n,m);
			if(m == y - 1)
				DrawHorizontalBorder(n,m+1);
			if(n == x - 1)
				DrawVerticalBorder(n+1,m);
		}
	}
}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();

	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, ConvertIndexToXY(x), ConvertIndexToXY(y), hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap);
}

void Gamestate::drawWorld(HDC & hdc){
	for(int n = 0; n < x; n++){
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			if(level[index] == NULL)
				continue;
			if(level[index]->getClassName() == "Block")
				hObstacleBitmap = factory->getBlock(n, m);
			else if(level[index]->getClassName() == "Pipe")
				hObstacleBitmap = factory->getPipe(n, m);

			hObstacleDC = CreateCompatibleDC(hdc);

			GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
			SelectObject(hObstacleDC, hObstacleBitmap);

			BitBlt(hdc, ConvertIndexToXY(n), ConvertIndexToXY(m), 32, 32, hObstacleDC, 68, 0, SRCCOPY);

			DeleteDC(hObstacleDC);
			DeleteObject(hObstacleBitmap);
		}
	}
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
			if(m == y-1)
				level[index] = new Block();
			else
				level[index] = NULL;
		}
	}
}

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;

	delete factory;
	factory = NULL;
}