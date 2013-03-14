#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

HANDLE SkyThemeFactory::getBlock(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getPipe(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getGround(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getBackgroundImage2(){
	return LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}