#ifndef COIN_H
#define COIN_H
#include "Gadget.h"

class Coin : public Gadget
{
public:
	Coin(POINT & pixelpnt);
	~Coin();
	string getClassName();
	void updateGadget();
};

#endif //COIN_H