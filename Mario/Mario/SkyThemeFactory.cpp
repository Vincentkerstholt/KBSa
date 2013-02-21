#include "SkyThemeFactory.h"
#include "SkyThemeBlock.h"
#include "SkyThemePipe.h"

Obstacle SkyThemeFactory::createBlock(){
	return SkyThemeBlock();
}

Obstacle SkyThemeFactory::createPipe(){
	return SkyThemePipe();
}