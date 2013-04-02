#ifndef DUNGEONTHEMEFACTORY_H
#define DUNGEONTHEMEFACTORY_H

#include "ThemeFactory.h"

class DungeonThemeFactory : public IThemeFactory{
public:
	DungeonThemeFactory();
	~DungeonThemeFactory();
	HANDLE getCastle();
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getGoomba();
	HANDLE getKoopa();
	HANDLE getGadget();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
	void delImage();
	string getName();
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