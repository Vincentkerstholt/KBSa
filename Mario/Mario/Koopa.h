#ifndef KOOPA_H
#define KOOPA_H

#include "Enemy.h"

class Koopa : public Enemy
{
public:
	Koopa(int endPointX, int endPointY);
	~Koopa();
	int getEndPoint(char valuePoint);
	string getClassName();
	void Die();
private:
	int endPointX;
	int endPointY;
};
#endif