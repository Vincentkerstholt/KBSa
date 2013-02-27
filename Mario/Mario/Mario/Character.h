#ifndef WALKBEHAVIOUR_H
#define WALKBEHAVIOUR_H

#include "WalkBehaviour.h"


using namespace std;

class Character
{
private:
	int Health;
	int Power;
	int Speed;
	
public:
	WalkBehaviour *WalkBehaviour; 
	void Die();
	void GetPowerUp();
	void Move();
	void Jump();
	void Fly();
	void Attack();
	void Walk();
};
#endif