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
	HANDLE getGadget();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
	void delImage();
private:
	HANDLE pipeBitmap;
	HANDLE blockBitmap;
	HANDLE groundBitmap;
	HANDLE gadgetBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif