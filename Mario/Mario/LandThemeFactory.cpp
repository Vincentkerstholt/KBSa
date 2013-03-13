#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

LandThemeFactory::LandThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/Wall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/forrestsmall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

LandThemeFactory::~LandThemeFactory(){
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

HANDLE LandThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE LandThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE LandThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE LandThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE LandThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}