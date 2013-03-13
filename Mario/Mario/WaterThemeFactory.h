#ifndef WATERTHEMEFACTORY_H
#define WATERTHEMEFACTORY_H

#include "ThemeFactory.h"

class WaterThemeFactory : public IThemeFactory{
public:
	HANDLE getPipe();
	HANDLE getBlock();
	HANDLE getGround();
	HANDLE getBackgroundImage();
	HANDLE getBackgroundImage2();
};

#endif