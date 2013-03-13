#include "Ground.h"

Ground::Ground(int spriteX, int spriteY, int textureType){
	this->spriteX = spriteX;
	this->spriteY = spriteY;
	this->textureType = textureType;
}

string Ground::getClassName(){
	return "Ground";
}

int Ground::getTextureType(){
	return textureType;
}