#ifndef WATERTHEMEFACTORY_H
#define WATERTHEMEFACTORY_H

#include "ThemeFactory.h"

class WaterThemeFactory : public IThemeFactory{
public:
	WaterThemeFactory();
	~WaterThemeFactory();
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