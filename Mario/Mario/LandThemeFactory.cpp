#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

HANDLE LandThemeFactory::getBlock(int x, int y){
	return LoadImage(NULL, "res/forestlandps.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE LandThemeFactory::getPipe(int x, int y){
	return LoadImage(NULL, "res/forestlandps.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE LandThemeFactory::getGround(int x, int y){
	return LoadImage(NULL, "res/forestlandps.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE LandThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}