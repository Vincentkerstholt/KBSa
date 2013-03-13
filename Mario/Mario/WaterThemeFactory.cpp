#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

HANDLE WaterThemeFactory::getBlock(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getPipe(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getGround(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getBackgroundImage2(){
	return LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}