#include "WaterThemeFactory.h"
#include "WaterThemeBlock.h"
#include "WaterThemePipe.h"

Obstacle WaterThemeFactory::createBlock(){
	return WaterThemeBlock();
}

Obstacle WaterThemeFactory::createPipe(){
	return WaterThemePipe();
}