#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	Obstacle createPipe();
	Obstacle createBlock();
	HANDLE getBackgroundImage();
};

#endif