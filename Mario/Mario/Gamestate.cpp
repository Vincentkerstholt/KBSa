#include "Gamestate.h"

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;
	Mario = new Hero();

	multiplier = 32;
	hBackgroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	level = new Gameobject*[(x * y)];
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

void Gamestate::drawCharacters(HDC & hdc){
	this->hdc = hdc;
	hCharacterDC = CreateCompatibleDC(hdc);
	GetObject(this->Mario->texture, sizeof(BITMAP), &bitmap);
	SelectObject(hCharacterDC, this->Mario->texture);

	TransparentBlt(hdc, (Mario->GetPositionPixel().x), (Mario->GetPositionPixel().y), 32, 32, hCharacterDC, (Mario->getTexturePosition().x*multiplier), Mario->getTexturePosition().y*multiplier, 32,32, GetPixel(hCharacterDC, 0,0));
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
	oss.clear();

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
			else if(level[index]->getClassName() == "Ground")
				hObstacleBitmap = factory->getGround(n, m);

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
				level[index] = new Ground(68,0);
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