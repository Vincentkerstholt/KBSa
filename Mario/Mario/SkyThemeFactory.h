#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe(int x, int y);
	HANDLE getGround(int x, int y);
	HANDLE getBlock(int x, int y);
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
};

#endif