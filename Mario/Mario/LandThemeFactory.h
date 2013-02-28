#ifndef LANDTHEMEFACTORY_H
#define LANDTHEMEFACTORY_H

#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe(int x, int y);
	HANDLE getBlock(int x, int y);
	HANDLE getBackgroundImage();
};

#endif