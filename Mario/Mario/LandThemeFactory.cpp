#include "LandThemeFactory.h"

Obstacle LandThemeFactory::createBlock(){
	
	return Block();
}

Obstacle LandThemeFactory::createPipe(){
	return Pipe();
}