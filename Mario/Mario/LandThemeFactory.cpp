#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

LandThemeFactory::LandThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	castleBitmap = LoadImage(NULL, "res/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/forrestsmall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

LandThemeFactory::~LandThemeFactory(){
	delImage();
}

string LandThemeFactory::getName(){
	return "landscape";
}

void LandThemeFactory::delImage()
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

HANDLE LandThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE LandThemeFactory::getCastle(){
	return castleBitmap;
}

HANDLE LandThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE LandThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE LandThemeFactory::getGoomba(){
	return goombaBitmap;
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