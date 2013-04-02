#include "CityThemeFactory.h"

CityThemeFactory::CityThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/cityblock.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	castleBitmap = LoadImage(NULL, "res/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/cityPipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/cityGround2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundCity.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundCity2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

CityThemeFactory::~CityThemeFactory(){
	delImage();
}

string CityThemeFactory::getName(){
	return "landscape";
}

void CityThemeFactory::delImage()
{
	DeleteObject(pipeBitmap);
	DeleteObject(blockBitmap);
	DeleteObject(groundBitmap);
	DeleteObject(goombaBitmap);
	DeleteObject(gadgetBitmap);
	DeleteObject(bkGroundBitmap);
	DeleteObject(bkGround2Bitmap);
	DeleteObject(castleBitmap);

	pipeBitmap = NULL;
	blockBitmap = NULL;
	groundBitmap = NULL;
	goombaBitmap = NULL;
	gadgetBitmap = NULL;
	bkGroundBitmap = NULL;
	bkGround2Bitmap = NULL;
	castleBitmap = NULL;
}

HANDLE CityThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE CityThemeFactory::getCastle(){
	return castleBitmap;
}

HANDLE CityThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE CityThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE CityThemeFactory::getGoomba(){
	return goombaBitmap;
}

HANDLE CityThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE CityThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE CityThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}