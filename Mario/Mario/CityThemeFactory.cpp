#include "CityThemeFactory.h"

CityThemeFactory::CityThemeFactory(){
	castleBitmap = LoadImage(NULL, "res/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	blockBitmap = LoadImage(NULL, "res/block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	koopaBitmap = LoadImage(NULL, "res/koopa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

CityThemeFactory::~CityThemeFactory(){
	delImage();
}

string CityThemeFactory::getName(){
	return "city";
}

void CityThemeFactory::delImage()
{
	DeleteObject(blockBitmap);
	blockBitmap = NULL;
	DeleteObject(pipeBitmap);
	pipeBitmap = NULL;
	DeleteObject(groundBitmap);
	groundBitmap = NULL;
	DeleteObject(goombaBitmap);
	goombaBitmap = NULL;
	DeleteObject(koopaBitmap);
	koopaBitmap = NULL;
	DeleteObject(gadgetBitmap);
	gadgetBitmap = NULL;
	DeleteObject(bkGroundBitmap);
	bkGroundBitmap = NULL;
	DeleteObject(bkGround2Bitmap);
	bkGround2Bitmap = NULL;
	DeleteObject(castleBitmap);
	castleBitmap = NULL;
}

HANDLE CityThemeFactory::getBlock(){
	return blockBitmap;
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

HANDLE CityThemeFactory::getKoopa(){
	return koopaBitmap;
}

HANDLE CityThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE CityThemeFactory::getCastle(){
	return castleBitmap;
}

HANDLE CityThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE CityThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}