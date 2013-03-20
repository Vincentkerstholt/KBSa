#include "Block.h"

Block::Block(){
	gadget = NULL;
	gadgetAmount = 0;
}

Block::Block(bool isSpecial){
	this->isSpecial = isSpecial;
	posX = 0;
	gadget = NULL;
	gadgetAmount = 0;
}

Block::Block(bool isSpecial, Gadget ** gadgetType, int amount)
{
	posX = 0;
	gadget = gadgetType;
	gadgetAmount = amount;
	this->isSpecial = isSpecial;
}

Gadget * Block::getGadget(){
	if (gadgetAmount > 0)
	{
		gadgetAmount--;
		return gadget[gadgetAmount];
	}
	return NULL;
}

string Block::getClassName(){
	return "Block";
}

bool Block::getIsSpecial(){
	return isSpecial;
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

 Block::~Block(){
	 for (int n=0 ; n < gadgetAmount ; n++)
	 {
		 delete gadget[n];
		 gadget[n] = NULL;
	 }
 }