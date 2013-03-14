#ifndef GOOMBA_H
#define GOOMBA_H

#include "Enemy.h"

class Goomba : public Enemy
{
public:
	Goomba(int endPointX, int endPointY);
	~Goomba();
	int getEndPoint(char valuePoint);
	string getClassName();
private:
	int endPointX;
	int endPointY;
};

#endif