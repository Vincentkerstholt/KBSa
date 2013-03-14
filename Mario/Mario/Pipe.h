#ifndef PIPE_H
#define PIPE_H

#include "Obstacle.h"

class Pipe : public Obstacle{
public:
	Pipe(string textureType);
	string getClassName();
	string getTextureType();
private:
	string textureType;
};

#endif