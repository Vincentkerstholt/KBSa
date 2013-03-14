#include "Block.h"

Block::Block(bool isSpecial){
	this->isSpecial = isSpecial;
}

string Block::getClassName(){
	return "Block";
}

bool Block::getIsSpecial(){
	return isSpecial;
}