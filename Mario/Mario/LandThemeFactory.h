#ifndef LANDTHEMEFACTORY_H
#define LANDTHEMEFACTORY_H

#include "ThemeFactory.h"

class LandThemeFactory : public IThemeFactory{
public:
	Obstacle createPipe();
	Obstacle createBlock();
};

#endif