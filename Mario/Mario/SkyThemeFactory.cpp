#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

HANDLE SkyThemeFactory::getBlock(int x, int y){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getPipe(int x, int y){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE SkyThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}