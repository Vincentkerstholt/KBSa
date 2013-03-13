#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

WaterThemeFactory::WaterThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/Wall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}
WaterThemeFactory::~WaterThemeFactory(){
	delete blockBitmap;
	blockBitmap = NULL;
	delete pipeBitmap;
	pipeBitmap = NULL;
	delete groundBitmap;
	groundBitmap = NULL;
	delete bkGroundBitmap;
	bkGroundBitmap = NULL;
	delete bkGround2Bitmap;
	bkGround2Bitmap = NULL;
}
HANDLE WaterThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE WaterThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE WaterThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE WaterThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE WaterThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}