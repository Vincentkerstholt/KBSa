#ifndef GROUND_H
#define GROUND_H

#include "Obstacle.h"

class Ground : public Obstacle{
public:
	Ground(int spriteX, int spriteY, string textureType);
	string getClassName();
	int getSpriteX();
	int getSpriteY();
	string getTextureType();
private:
	int spriteX;
	int spriteY;
	string textureType;
};

#endif
