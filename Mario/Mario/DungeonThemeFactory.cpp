#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

DungeonThemeFactory::DungeonThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/Block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/world8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	koopaBitmap = LoadImage(NULL, "res/koopa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/backgroundrocks.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

DungeonThemeFactory::~DungeonThemeFactory()
{
	delImage();
}


string DungeonThemeFactory::getName(){
	return "dungeon";
}

void DungeonThemeFactory::delImage()
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
}

HANDLE DungeonThemeFactory::getCastle()
{
	return castleBitmap;
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

HANDLE DungeonThemeFactory::getGoomba(){
	return goombaBitmap;
}

HANDLE DungeonThemeFactory::getKoopa(){
	return goombaBitmap;
}

HANDLE DungeonThemeFactory::getGadget(){
	return gadgetBitmap;
}

HANDLE DungeonThemeFactory::getBackgroundImage(){
	return bkGroundBitmap;
}

HANDLE DungeonThemeFactory::getBackgroundImage2(){
	return bkGround2Bitmap;
}