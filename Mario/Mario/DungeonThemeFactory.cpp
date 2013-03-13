#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

HANDLE DungeonThemeFactory::getBlock(){
	return LoadImage(NULL, "res/world8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getPipe(){
	return LoadImage(NULL, "res/world8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getGround(){
	return LoadImage(NULL, "res/world8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getBackgroundImage2(){
	return LoadImage(NULL, "res/backgroundrocks.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}