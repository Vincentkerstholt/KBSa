#include "Block.h"

Block::Block(int spriteX, int spriteY){
	this->spriteX = spriteX;
	this->spriteY = spriteY;
}

string Block::getClassName(){
	return "Block";
}

int Block::getSpriteX(){
	return spriteX;
}

int Block::getSpriteY(){
	return spriteY;
}