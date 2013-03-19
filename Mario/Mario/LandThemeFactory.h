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