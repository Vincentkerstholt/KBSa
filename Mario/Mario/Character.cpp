#include "character.h"

Character::Character()
{
}


void Character :: Walk (char Direction, POINT curPos)
{
	if (Direction == 'L' && !WalkBlock[1])
	{
	SetPosition(walkBehaviour->Walk(Direction, curPos));
	}
	if (Direction == 'R' && !WalkBlock[2])
	{
	SetPosition(walkBehaviour->Walk(Direction, curPos)); 
	}
	if (Direction == 'U' )
	{
		SetPosition(walkBehaviour->Walk(Direction, curPos)); 
	}
	if (Direction == 'D' )
	{
		SetPosition(walkBehaviour->Walk(Direction, curPos)); 
	}
	
}

void Character :: SetWalkBlock (char naam , bool mode)
{
	if (naam == 'L')
	{
		WalkBlock[1] = mode;
	}

	if (naam == 'R')
	{
		WalkBlock[2] = mode;
	}


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
	POINT Position2;
	Position2 = Position;
	return Position2;
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
	case 'U':
		this->Walk('U', curPos);//Move Up
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


