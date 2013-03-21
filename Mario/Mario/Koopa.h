#ifndef KOOPA_H
#define KOOPA_H

#include "Enemy.h"

class Koopa : public Enemy
{
public:
	Koopa(int startPointX, int startPointY, int endPointX, int endPointY);
	~Koopa();
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