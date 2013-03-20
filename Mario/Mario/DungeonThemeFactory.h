#ifndef DUNGEONTHEMEFACTORY_H
#define DUNGEONTHEMEFACTORY_H

#include "ThemeFactory.h"

class DungeonThemeFactory : public IThemeFactory{
public:
	DungeonThemeFactory();
	~DungeonThemeFactory();
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getGoomba();
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
	HANDLE gadgetBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif