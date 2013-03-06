#include "character.h"

Character::Character()
{
}

void Character :: Walk (char Direction, POINT curPos)
{
	SetPosition(walkBehaviour->Walk(Direction, curPos));
	setDirection(Direction);
	switch(Direction)
	{
	case 'L':
		if(getTexturePosition().y == 0 && getTexturePosition().x == 14)
		{
			setTexturePosition(15,0);
		}
		else if(getTexturePosition().y == 0 && getTexturePosition().x == 15)
		{
			setTexturePosition(14,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 14)
		{
			setTexturePosition(15,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 15)
		{
			setTexturePosition(14,1);
		}
		break;
	case 'R':
		if(getTexturePosition().y == 0 && getTexturePosition().x == 0)
		{
			setTexturePosition(1,0);
		}
		else if(getTexturePosition().y == 0 && getTexturePosition().x == 1)
		{
			setTexturePosition(0,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 0)
		{
			setTexturePosition(1,1);
		}
		else if(getTexturePosition().y == 1 && getTexturePosition().x == 1)
		{
			setTexturePosition(0,1);
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
		this->setTexturePosition(13,1);
		break;
	case 'U': //Move Up
		this->Jump(curPos);
		break;
	}
}

void Character::Jump(POINT curPos)
{
	SetPosition(jumpBehaviour->Jump(this->getDirection(), curPos));
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