#include "Block.h"

Block::Block(){}

Block::Block(bool isSpecial){
	this->isSpecial = isSpecial;
	posX = 0;
}

string Block::getClassName(){
	return "Block";
}

bool Block::getIsSpecial(){
	return isSpecial;
}

string Block::getIsSpecialString(){
	if(isSpecial)
		return "true";
	else
		return "false";
}

int Block::getPosX(){
	if(isSpecial)
		posX++;

	if(posX == 56)
	{
		posX = 0;
	}

	return posX/2;
}