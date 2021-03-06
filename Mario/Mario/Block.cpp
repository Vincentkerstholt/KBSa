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

		// when its a special block and now empty change to fixed block
		if (gadgetAmount == 0 && isSpecial == true) 
		{
			isSpecial = false;
			isFixed = true;
			posX = 0;
		}
		return gadget[gadgetAmount];
	}
	return NULL;
}

Gadget * Block::getGadgetPoint(int index){
	return gadget[index];
}

int Block::getGadgetAmount(){
	return gadgetAmount;
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
	//posX is sprite X location
	if(isSpecial)
		posX++;

	if(posX == 56)
		posX = 0;

	return posX/2;
}

Block::~Block(){
	//Destroy all gadgets
	for (int i = 0; i < gadgetAmount; i++)
	{
		string gadgetName = gadget[i]->getClassName();
		if(gadgetName == "Coin")
		{
			Coin * coin = (Coin *)gadget[i];
			delete coin;
			coin = NULL;
		}
		else if(gadgetName == "Mushroom")
		{
			Mushroom * mushroom = (Mushroom *)gadget[i];
			delete mushroom;
			mushroom = NULL;
		}
		else if(gadgetName == "Flower")
		{
			Flower * flower = (Flower *)gadget[i];
			delete flower;
			flower = NULL;
		}
		else if(gadgetName == "LiveUp")
		{
			LiveUp * liveUp = (LiveUp *)gadget[i];
			delete liveUp;
			liveUp = NULL;
		}
	}
}