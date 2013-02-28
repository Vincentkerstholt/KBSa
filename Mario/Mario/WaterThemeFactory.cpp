#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

Obstacle WaterThemeFactory::createBlock(){
	return WaterThemeBlock();
}

Obstacle WaterThemeFactory::createPipe(){
	return WaterThemePipe();
}

HANDLE WaterThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}