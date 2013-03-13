#ifndef SKYTHEMEFACTORY_H
#define SKYTHEMEFACTORY_H

#include "ThemeFactory.h"

class SkyThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe();
	HANDLE getGround();
	HANDLE getBlock();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
};

#endif