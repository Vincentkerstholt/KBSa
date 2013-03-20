#ifndef BLOCKCOIN_H
#define BLOCKCOIN_H
#include "Gadget.h"


class BlockCoin : public Gadget
{
public:
	BlockCoin();
	~BlockCoin();
	string getClassName();
	int getSprite();
private:
	int sprite;
};

#endif //BLOCKCOIN_H