#ifndef DUNGEONTHEMEFACTORY_H
#define DUNGEONTHEMEFACTORY_H

#include "ThemeFactory.h"

class DungeonThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
};

#endif