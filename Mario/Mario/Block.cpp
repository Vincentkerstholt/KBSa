#include "Block.h"

Block::Block(){
	gadget = NULL;
	gadgetAmount = 0;
}

Block::Block(bool isSpecial, bool isFixed){
	this->isSpecial = isSpecial;
	this->isFixed = isFixed;
	posX = 0;
	gadget = NULL;
	gadgetAmount = 0;
}

Block::Block(bool isSpecial, bool isFixed, Gadget ** gadgetType, int amount)
{
	posX = 0;
	gadget = gadgetType;
	gadgetAmount = amount;
	this->isSpecial = isSpecial;
	this->isFixed = isFixed;
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

string Block::getIsSpecialString(){
	if(isSpecial)
		return "true";
	else
		return "false";
}

bool Block::getIsFixed(){
	return isFixed;
}

string Block::getIsFixedString(){
	if(isFixed)
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

 Block::~Block(){
	for (int n = 0; n < gadgetAmount; n++)
	{
		string gadgetName = gadget[n]->getClassName();
		if(gadgetName == "Coin")
		{
			Coin * coin = (Coin *)gadget[n];
			delete coin;
			coin = NULL;
		}
		else if(gadgetName == "LiveUp")
		{
			LiveUp * liveUp = (LiveUp *)gadget[n];
			delete liveUp;
			liveUp = NULL;
		}
		else if(gadgetName == "Mushroom")
		{
			Mushroom * mushroom = (Mushroom *)gadget[n];
			delete mushroom;
			mushroom = NULL;
		}
		else if(gadgetName == "Flower")
		{
			Flower * flower = (Flower *)gadget[n];
			delete flower;
			flower = NULL;
		}
	}
 }
