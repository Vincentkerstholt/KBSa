#include "LandThemeFactory.h"

LandThemeFactory::LandThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/LandscapeTheme/block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	castleBitmap = LoadImage(NULL, "res/LandscapeTheme/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/LandscapeTheme/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/LandscapeTheme/forrestsmall.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/LandscapeTheme/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	koopaBitmap = LoadImage(NULL, "res/LandscapeTheme/koopa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/LandscapeTheme/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/LandscapeTheme/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/LandscapeTheme/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
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
	DeleteObject(koopaBitmap);
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
	koopaBitmap = NULL;
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

HANDLE LandThemeFactory::getKoopa(){
	return koopaBitmap;
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