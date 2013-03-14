#ifndef LANDTHEMEFACTORY_H
#define LANDTHEMEFACTORY_H

#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	LandThemeFactory();
	~LandThemeFactory();
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
private:
	HANDLE pipeBitmap;
	HANDLE blockBitmap;
	HANDLE groundBitmap;
	HANDLE bkGroundBitmap;
	HANDLE bkGround2Bitmap;
};

#endif