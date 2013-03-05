#include "character.h"

Character::Character()
{
}

void Character :: Walk (char Direction, POINT curPos)
{
	SetPosition(walkBehaviour->Walk(Direction, curPos)); 
}

void Character :: setWalkBehaviour(WalkBehaviour *qb)
{
	walkBehaviour = qb;
}

POINT Character :: GetPositionIndex()
{
	POINT returnValue;

	returnValue.x = (Position.x/32);
	returnValue.y = (Position.y/32);
	return returnValue;
}

POINT Character :: GetPositionPixel()
{
	return Position;
}

void Character :: SetPosition(int x, int y)
{
	Position.x = x;
	Position.y = y;
}

void Character :: SetPosition(POINT newPos)
{
	Position = newPos;
}

void Character::Die()
{
}

void Character::GetPowerUp()
{
}

void Character::Move(char Direction, POINT curPos)
{
	switch(Direction)
	{
	case 'R': //Move Right
		this->Walk('R', curPos);
		break;
	case 'L': //Move Left
		this->Walk('L', curPos);
		break;
	case 'D': //Move Down
		break;
	case 'U': //Move Up
		break;
	}
}

void Character::Jump()
{
}

void Character::Fly()
{
}

void Character::Attack()
{
}
