#ifndef PIPE_H
#define PIPE_H

#include "Obstacle.h"

class Pipe : public Obstacle{
public:
	Pipe(int textureType);
	string getClassName();
	int getTextureType();
private:
	int textureType;
};

#endif