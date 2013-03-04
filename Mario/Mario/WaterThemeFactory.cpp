#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

HANDLE WaterThemeFactory::getBlock(int x, int y){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getPipe(int x, int y){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getGround(int x, int y){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE WaterThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}