#ifndef BLOCK_H
#define BLOCK_H

#include "Obstacle.h"

class Block : public Obstacle{
public:
	Block(bool isSpecial);
	string getClassName();
	bool getIsSpecial();
private:
	bool isSpecial;
};

#endif
