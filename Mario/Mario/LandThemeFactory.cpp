#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

Obstacle LandThemeFactory::createBlock(){
	return LandThemeBlock();
}

Obstacle LandThemeFactory::createPipe(){
	return LandThemePipe();
}

HANDLE LandThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}