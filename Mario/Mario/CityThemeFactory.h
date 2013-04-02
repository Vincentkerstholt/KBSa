#ifndef CITYTHEMEFACTORY_H
#define CITYTHEMEFACTORY_H

#include "ThemeFactory.h"

class CityThemeFactory : public IThemeFactory{
public:
	CityThemeFactory();
	~CityThemeFactory();
	HANDLE getPipe();
	HANDLE getCastle();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getGoomba();
	HANDLE getKoopa();
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
	HANDLE koopaBitmap;
	HANDLE gadgetBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif