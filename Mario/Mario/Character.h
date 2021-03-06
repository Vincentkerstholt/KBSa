#ifndef CHARACTER_H
#define CHARACTER_H

#include <windows.h>
#include "WalkBehaviour.h"
#include "NormalWalk.h"
#include "FastWalk.h"
#include "UltraWalk.h"
#include "JumpBehaviour.h"
#include "NormalJump.h"
#include "HighJump.h"
#include <string>
#include "GameObject.h"

using namespace std;

class Character : public Gameobject
{
public:
	Character();
	virtual void Die() = 0;
	virtual void GetPowerUp();
	virtual void Move(char Direction, POINT curPos);
	virtual void Jump(POINT curPos);
	virtual void Fly();
	virtual void Attack();
	virtual void Walk(char Direction, POINT curPos);
	virtual void SetPosition(int x ,int y);
	virtual void SetPosition(POINT newPos);
	virtual void SetStartPosition(int x ,int y);
	virtual void SetStartPosition(POINT point);
	virtual POINT GetPositionIndex();
	virtual POINT GetPositionPixel();
	virtual void ResetPosition();
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
	bool MoveAbilityL;
	bool MoveAbilityR;
	string side;
	bool MustDie;
	
private:
	
	string Name;
	char Direction;
	int Health;
	POINT StartPosition;
	POINT Position;
	int Power;
	int Speed;
	POINT texturePosition;
};
#endif