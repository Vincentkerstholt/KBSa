#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	SkyThemeFactory();
	~SkyThemeFactory();
	HANDLE getPipe();
	HANDLE getGround();
	HANDLE getBlock();
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