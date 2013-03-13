#include "character.h"

Character::Character()
{
	Jumped = 0;
	JumpHeight = 8;
}


void Character :: Walk (char Direction, POINT curPos)
{

	if (Direction == 'L')
	{
	SetPosition(walkBehaviour->Walk(Direction, curPos));
	}
	if (Direction == 'R')
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

	setDirection(Direction);
	switch(Direction)
	{
	case 'L':
		if(getTexturePosition().y == 0 && getTexturePosition().x == 1)
		{
			setTexturePosition(2,0);
		}
		else if(getTexturePosition().y == 0 && getTexturePosition().x == 2)
		{
			setTexturePosition(3,0);
		}
		else if(getTexturePosition().y == 0 && getTexturePosition().x == 3)
		{
			setTexturePosition(4,0);
		}
		else if(getTexturePosition().y == 0 && getTexturePosition().x == 4)
		{
			setTexturePosition(3,0);
		}
		break;
	case 'R':
		if(getTexturePosition().y == 1 && getTexturePosition().x == 1)
		{
			setTexturePosition(2,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 2)
		{
			setTexturePosition(3,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 3)
		{
			setTexturePosition(4,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 4)
		{
			setTexturePosition(3,1);
		}
		break;
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
		this->setTexturePosition(13,1);
		break;
	case 'U': 
		if(JumpAbility)
		{
		this->Jump(curPos); //Move Up
		Jumped++;
		}
		break;
	}
}

void Character::Jump(POINT curPos)
{
	switch(Jumped)
	{
	case 0:
		SetPosition(jumpBehaviour->Jump(curPos, 24));
		break;
	case 1:
		SetPosition(jumpBehaviour->Jump(curPos, 32));
		break;
	case 2:
		SetPosition(jumpBehaviour->Jump(curPos, 0));
		break;

	}

}

void Character :: setJumpBehaviour(JumpBehaviour *jb)
{
	jumpBehaviour = jb;
}

void Character::Fly()
{
}

void Character::Attack()
{
}

void Character::setTexturePosition(POINT newPoint)
{
	texturePosition = newPoint;
}

void Character::setTexturePosition(int x, int y)
{
	texturePosition.x = x;
	texturePosition.y = y;
}

POINT Character::getTexturePosition()
{
	return texturePosition;
}

void Character::setDirection(char Direction)
{
	this->Direction = Direction;
}

char Character::getDirection()
{
	return Direction;
}

