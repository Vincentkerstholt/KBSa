#ifndef PIPE_H
#define PIPE_H

#include "Obstacle.h"

class Pipe : public Obstacle{
public:
	Pipe(int spriteX, int spriteY);
	string getClassName();
	int getSpriteX();
	int getSpriteY();
	//Pipe(PiranhaPlant piranhaPlant);
private:
	//PiranhaPlant piranhaPlant;
	int spriteX;
	int spriteY;
};

#endif