#include "Ground.h"

Ground::Ground(int spriteX, int spriteY){
	this->spriteX = spriteX;
	this->spriteY = spriteY;
}

string Ground::getClassName(){
	return "Ground";
}

int Ground::getSpriteX(){
	return spriteX;
}

int Ground::getSpriteY(){
	return spriteY;
}