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

Block::Block(bool isSpecial, int gadgetType, int amount)
{
	gadget = new Gadget*[amount];
	this->isSpecial = isSpecial;
	posX = 0;

	switch (gadgetType)
	{
	case COIN:
		for (int n=0 ; n < amount ; n++)
		{
			gadget[n] = new Coin();
		}
		gadgetAmount = amount;
	break;
	case LIVEUP:
		gadget[0] = new LiveUp();
		gadgetAmount = 1;
	break;
	case FLOWER:
		gadget[0] = new Flower();
		gadgetAmount = 1;
	break;
	case MUSHROOM:
		gadget[0] = new Mushroom();
		gadgetAmount = 1;
	break;
	default:
		gadget[0] = NULL;
		gadgetAmount = 0;
	break;
	}

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