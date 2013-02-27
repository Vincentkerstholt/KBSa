#include "WalkBehaviour.h"
#include "Skeleton.h"
#include <WinDef.h>

class Character
{
public:
	 
	void Die();
	void GetPowerUp();
	void Move();
	void Jump();
	void Fly();
	void Attack();
	void Walk();
	void SetPosition(int x ,int y);
	POINT GetPosition();
	WalkBehaviour *walkBehaviour;
	void setWalkBehaviour(WalkBehaviour *qb); 

private:
	string name;
	int Health;
	POINT Position;
	int Power;
	int Speed;
	


};
