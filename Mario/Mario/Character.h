#ifndef CHARACTER_H
#define CHARACTER_H

#include <windows.h>
#include "WalkBehaviour.h"
#include "NormalWalk.h"
#include <string>

using namespace std;

class Character
{
public:
	Character();
	virtual void Die();
	virtual void GetPowerUp();
	virtual void Move();
	virtual void Jump();
	virtual void Fly();
	virtual void Attack();
	virtual void Walk();
	virtual void SetPosition(int x ,int y);
	virtual POINT GetPosition();
	WalkBehaviour *walkBehaviour;
	virtual void setWalkBehaviour(WalkBehaviour *qb); 
private:
	string name;
	int Health;
	POINT Position;
	int Power;
	int Speed;
};

#endif