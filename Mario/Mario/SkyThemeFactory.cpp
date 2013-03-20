#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

SkyThemeFactory::SkyThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/skybrick.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipeSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/skyblock.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/clouds.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundcloud.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

SkyThemeFactory::~SkyThemeFactory(){
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

HANDLE SkyThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE SkyThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE SkyThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE SkyThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE SkyThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}