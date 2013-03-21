#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

WaterThemeFactory::WaterThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

WaterThemeFactory::~WaterThemeFactory(){
}

string WaterThemeFactory::getName(){
	return "water";
}

void WaterThemeFactory::delImage()
{
	DeleteObject(blockBitmap);
	blockBitmap = NULL;
	DeleteObject(pipeBitmap);
	pipeBitmap = NULL;
	DeleteObject(groundBitmap);
	groundBitmap = NULL;
	DeleteObject(goombaBitmap);
	goombaBitmap = NULL;
	DeleteObject(gadgetBitmap);
	gadgetBitmap = NULL;
	DeleteObject(bkGroundBitmap);
	bkGroundBitmap = NULL;
	DeleteObject(bkGround2Bitmap);
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

HANDLE WaterThemeFactory::getGoomba(){
	return goombaBitmap;
}

HANDLE WaterThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE WaterThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE WaterThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}