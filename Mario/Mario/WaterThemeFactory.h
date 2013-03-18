#ifndef WATERTHEMEFACTORY_H
#define WATERTHEMEFACTORY_H

#include "ThemeFactory.h"

class WaterThemeFactory : public IThemeFactory{
public:
	WaterThemeFactory();
	~WaterThemeFactory();
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getGoomba();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
	string getName();
	void delImage();
private:
	HANDLE pipeBitmap;
	HANDLE blockBitmap;
	HANDLE groundBitmap;
	HANDLE goombaBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif