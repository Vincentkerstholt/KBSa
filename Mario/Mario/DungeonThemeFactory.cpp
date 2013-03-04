#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

HANDLE DungeonThemeFactory::getBlock(int x, int y){
	return LoadImage(NULL, "res/dungeon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getPipe(int x, int y){
	return LoadImage(NULL, "res/dungeon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getGround(int x, int y){
	return LoadImage(NULL, "res/dungeon.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

HANDLE DungeonThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}