#ifndef BLOCK_H
#define BLOCK_H

#include "Obstacle.h"
#include "Gadget.h"
#include "Coin.h"
#include "Flower.h"
#include "Mushroom.h"
#include "LiveUp.h"

class Block : public Obstacle{
public:
	Block();
	Block(bool isSpecial, bool isFixed);
	Block(bool isSpecial, bool isFixed, Gadget ** gadgetType, int amount);
	~Block();
	Gadget * getGadget();
	string getClassName();
	bool getIsSpecial();
	string getIsSpecialString();
	bool getIsFixed();
	string getIsFixedString();
	int getPosX();
private:
	Gadget ** gadget;
	int gadgetAmount;
	bool isSpecial;
	bool isFixed;
	int posX;
};

#endif
