#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

DungeonThemeFactory::DungeonThemeFactory(){
	blockBitmap = LoadImage(NULL, "res/DungeonTheme/Block.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	pipeBitmap = LoadImage(NULL, "res/DungeonTheme/pipe.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	groundBitmap = LoadImage(NULL, "res/DungeonTheme/groundDungeon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	goombaBitmap = LoadImage(NULL, "res/DungeonTheme/goomba.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	koopaBitmap = LoadImage(NULL, "res/DungeonTheme/koopa.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gadgetBitmap = LoadImage(NULL, "res/DungeonTheme/gadget.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	castleBitmap = LoadImage(NULL, "res/DungeonTheme/castleAndFlagSprites.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGroundBitmap = LoadImage(NULL, "res/DungeonTheme/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bkGround2Bitmap = LoadImage(NULL, "res/DungeonTheme/backgroundDungeon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

DungeonThemeFactory::~DungeonThemeFactory(){
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
	DeleteObject(castleBitmap);
	castleBitmap = NULL;
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
	return koopaBitmap;
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