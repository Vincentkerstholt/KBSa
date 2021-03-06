#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	SkyThemeFactory();
	~SkyThemeFactory();
	HANDLE getPipe();
	HANDLE getCastle();
	HANDLE getGround();
	HANDLE getBlock();
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