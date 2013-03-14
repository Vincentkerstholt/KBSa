#ifndef CHARACTER_H
#define CHARACTER_H

#include <windows.h>
#include "WalkBehaviour.h"
#include "NormalWalk.h"
#include "FastWalk.h"
#include "JumpBehaviour.h"
#include "NormalJump.h"
#include <string>

using namespace std;

class Character
{
public:
	Character();
	virtual void Die() =0;
	virtual void GetPowerUp();
	virtual void Move(char Direction, POINT curPos);
	virtual void Jump(POINT curPos);
	virtual void Fly();
	virtual void Attack();
	virtual void Walk(char Direction, POINT curPos);
	virtual void SetPosition(int x ,int y);
	virtual void SetPosition(POINT newPos);
	virtual POINT GetPositionIndex();
	virtual POINT GetPositionPixel();
	WalkBehaviour *walkBehaviour;
	void SetWalkBlock(char side, bool mode);
	JumpBehaviour *jumpBehaviour;
	virtual void setWalkBehaviour(WalkBehaviour *qb);
	virtual void setJumpBehaviour(JumpBehaviour *jb);
	void setTexturePosition(POINT newPoint);
	void setTexturePosition(int x, int y);
	void setDirection(char Direction);
	char getDirection();
	POINT getTexturePosition();
	HANDLE texture;
	BOOL JumpAbility;
	int JumpHeight;
	int Jumped;
	int textureNumber;
	
private:
	
	string Name;
	char Direction;
	int Health;
	POINT Position;
	int Power;
	int Speed;
	POINT texturePosition;
};
#endif