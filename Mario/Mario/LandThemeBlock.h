#ifndef LANDTHEMEBLOCK_H
#define LANDTHEMEBLOCK_H

#include "Block.h"
#include "Win.h"

class LandThemeBlock : public Block{
public:
	LandThemeBlock();
	LandThemeBlock(int x, int y);
	void Paint(HDC & hdc);
private:
	int x;
	int y;
	POINT point;
	HANDLE hBackgroundBitmap;
	HDC hBackgroundDC;
	BITMAP bitmap;
};

#endif