#ifndef LANDTHEMEFACTORY_H
#define LANDTHEMEFACTORY_H

#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	LandThemeFactory();
	~LandThemeFactory();
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
	HANDLE pipeBitmap;
	HANDLE blockBitmap;
	HANDLE groundBitmap;
	HANDLE goombaBitmap;
	HANDLE koopaBitmap;
	HANDLE gadgetBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
	HANDLE castleBitmap;
};

#endif