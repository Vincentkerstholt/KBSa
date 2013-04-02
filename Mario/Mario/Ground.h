#ifndef GROUND_H
#define GROUND_H

#include "Obstacle.h"

class Ground : public Obstacle{
public:
	Ground(int textureType);
	string getClassName();
	int getTextureType();
private:
	int textureType;
};

#endif
