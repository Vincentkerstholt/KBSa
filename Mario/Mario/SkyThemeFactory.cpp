#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

SkyThemeFactory::SkyThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/SkyTheme/skybrick.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	castleBitmap = LoadImage(NULL, "res/SkyTheme/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/SkyTheme/pipeSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/SkyTheme/skyblock.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/SkyTheme/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/SkyTheme/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	koopaBitmap = LoadImage(NULL, "res/SkyTheme/koopa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/SkyTheme/backgroundcloud.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/SkyTheme/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

SkyThemeFactory::~SkyThemeFactory(){
	delImage();
}

string SkyThemeFactory::getName(){
	return "sky";
}

void SkyThemeFactory::delImage()
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

HANDLE SkyThemeFactory::getBlock(){
	return blockBitmap;
}

HANDLE SkyThemeFactory::getPipe(){
	return pipeBitmap;
}

HANDLE SkyThemeFactory::getGround(){
	return groundBitmap;
}

HANDLE SkyThemeFactory::getGoomba(){
	return goombaBitmap;
}

HANDLE SkyThemeFactory::getKoopa(){
	return koopaBitmap;
}

HANDLE SkyThemeFactory::getCastle(){
	return castleBitmap;
}

HANDLE SkyThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE SkyThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE SkyThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}
