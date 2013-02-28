#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe(int x, int y);
	HANDLE getBlock(int x, int y);
	HANDLE getBackgroundImage();
};

#endif