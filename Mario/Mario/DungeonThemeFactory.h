#ifndef DUNGEONTHEMEFACTORY_H
#define DUNGEONTHEMEFACTORY_H

#include "ThemeFactory.h"

class DungeonThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe(int x, int y);
	HANDLE getBlock(int x, int y);
	HANDLE getBackgroundImage();
};

#endif