#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

LandThemeFactory::LandThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/forrestsmall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

LandThemeFactory::~LandThemeFactory(){}

void LandThemeFactory::delImage()
{
	DeleteObject(blockBitmap);
	blockBitmap = NULL;
	DeleteObject(pipeBitmap);
	pipeBitmap = NULL;
	DeleteObject(groundBitmap);
	groundBitmap = NULL;
	DeleteObject(gadgetBitmap);
	gadgetBitmap = NULL;
	DeleteObject(bkGroundBitmap);
	bkGroundBitmap = NULL;
	DeleteObject(bkGround2Bitmap);
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

HANDLE LandThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE LandThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE LandThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}