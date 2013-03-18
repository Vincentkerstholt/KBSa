#ifndef BLOCK_H
#define BLOCK_H

#include "Obstacle.h"

class Block : public Obstacle{
public:
	Block();
	Block(bool isSpecial);
	string getClassName();
	bool getIsSpecial();
	string getIsSpecialString();
	int getPosX();
private:
	bool isSpecial;
	int posX;
};

#endif
