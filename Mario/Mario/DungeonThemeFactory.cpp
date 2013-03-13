#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

DungeonThemeFactory::DungeonThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/Wall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/world8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundrocks.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

DungeonThemeFactory::~DungeonThemeFactory(){
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

HANDLE DungeonThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE DungeonThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE DungeonThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE DungeonThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE DungeonThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}