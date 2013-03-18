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