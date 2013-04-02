#ifndef WATERTHEMEFACTORY_H
#define WATERTHEMEFACTORY_H

#include "ThemeFactory.h"

class WaterThemeFactory : public IThemeFactory{
public:
	WaterThemeFactory();
	~WaterThemeFactory();
	HANDLE getPipe();
	HANDLE getCastle();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getGoomba();
	HANDLE getGadget();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
	string getName();
	void delImage();
private:
	HANDLE castleBitmap;
	HANDLE pipeBitmap;
	HANDLE blockBitmap;
	HANDLE groundBitmap;
	HANDLE goombaBitmap;
	HANDLE gadgetBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif