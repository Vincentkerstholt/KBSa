#ifndef GOOMBA_H
#define GOOMBA_H

#include "Enemy.h"

class Goomba : public Enemy
{
public:
	Goomba(int startPointX, int startPointY, int endPointX, int endPointY);
	~Goomba();
	int getStartPoint(char valuePoint);
	int getEndPoint(char valuePoint);
	string getClassName();
	void Die();
private:
	int startPointX;
	int startPointY;
	int endPointX;
	int endPointY;
};

#endif