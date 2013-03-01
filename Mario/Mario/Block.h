#ifndef BLOCK_H
#define BLOCK_H

#include "Obstacle.h"

class Block : public Obstacle{
public:
	Block(int spriteX, int spriteY);
	string getClassName();
	int getSpriteX();
	int getSpriteY();
private:
	int spriteX;
	int spriteY;
};

#endif
