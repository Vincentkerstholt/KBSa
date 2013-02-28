#ifndef WATERTHEMEFACTORY_H
#define WATERTHEMEFACTORY_H

#include "ThemeFactory.h"

class WaterThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe(int x, int y);
	HANDLE getBlock(int x, int y);
	HANDLE getBackgroundImage();
};

#endif