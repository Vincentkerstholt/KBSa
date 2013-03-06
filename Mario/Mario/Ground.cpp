#include "Ground.h"

Ground::Ground(int spriteX, int spriteY, string textureType){
	this->spriteX = spriteX;
	this->spriteY = spriteY;
	this->textureType = textureType;
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

string Ground::getTextureType(){
	return textureType;
}