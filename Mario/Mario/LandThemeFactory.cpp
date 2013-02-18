#include "LandThemeFactory.h"

Obstacle LandThemeFactory::createBlock(){
	return LandThemeBlock();
}

Obstacle LandThemeFactory::createPipe(){
	return LandThemePipe();
}