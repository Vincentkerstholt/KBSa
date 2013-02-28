#include "Gamestate.h"

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;
	level = new int[(x * y)];

	multiplier = 16;

	hBackgroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

int Gamestate::ConvertIndexToXY(int index){
	return (index*multiplier);
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
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc,0,0,x*multiplier,y*multiplier,hBackgroundDC,0,0,bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);

	DeleteDC(hBackgroundDC);	
}

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;
}