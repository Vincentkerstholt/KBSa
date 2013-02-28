#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

Obstacle SkyThemeFactory::createBlock(){
	return SkyThemeBlock();
}

Obstacle SkyThemeFactory::createPipe(){
	return SkyThemePipe();
}

HANDLE SkyThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}