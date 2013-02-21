#include "LandThemeFactory.h"
#include "LandThemeBlock.h"
#include "LandThemePipe.h"

Obstacle LandThemeFactory::createBlock(){
	return LandThemeBlock();
}

Obstacle LandThemeFactory::createPipe(){
	return LandThemePipe();
}