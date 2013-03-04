#ifndef GROUND_H
#define GROUND_H

#include "Obstacle.h"

class Ground : public Obstacle{
public:
	Ground(int spriteX, int spriteY);
	string getClassName();
	int getSpriteX();
	int getSpriteY();
private:
	int spriteX;
	int spriteY;
};

#endif
