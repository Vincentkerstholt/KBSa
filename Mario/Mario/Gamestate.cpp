#include "Gamestate.h"

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;
	level = new int[(x * y)];

	multiplier = 16;
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

void Gamestate::drawGrid(HDC hdc){
	this->hdc = hdc;
	for (int n = 0; n < x; n++){
		for(int m = 0; m < y; m++){
			DrawVerticalBorder(n,m);
			DrawHorizontalBorder(n,m);
		}
	}
}

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;
}