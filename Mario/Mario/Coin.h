#ifndef COIN_H
#define COIN_H
#include "Gadget.h"

class Coin : public Gadget
{
public:
	Coin();
	~Coin();
	string getClassName();
};

#endif //COIN_H