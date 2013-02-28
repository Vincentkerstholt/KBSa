#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

Obstacle DungeonThemeFactory::createBlock(){
	return DungeonThemeBlock();
}

Obstacle DungeonThemeFactory::createPipe(){
	return DungeonThemePipe();
}

HANDLE DungeonThemeFactory::getBackgroundImage(){
	return LoadImage(NULL, "res/backgroundCave.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}