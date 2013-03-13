#include "Block.h"

Block::Block(){
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