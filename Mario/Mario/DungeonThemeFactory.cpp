#include "DungeonThemeFactory.h"
#include "DungeonThemeBlock.h"
#include "DungeonThemePipe.h"

Obstacle DungeonThemeFactory::createBlock(){
	return DungeonThemeBlock();
}

Obstacle DungeonThemeFactory::createPipe(){
	return DungeonThemePipe();
}