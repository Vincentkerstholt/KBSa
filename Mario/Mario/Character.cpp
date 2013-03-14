#include "character.h"

Character::Character()
{
	setTexturePosition(0,1);
	textureNumber = 0;
	Jumped = 0;
	JumpHeight = 15;
}


void Character :: Walk (char Direction, POINT curPos)
{
	

	if (Direction == 'L')
	{
		int x = textureNumber;

		switch (x)
		{
		case 0:
			setTexturePosition(1,0);
			textureNumber++;
			break;
		case 1:
			setTexturePosition(2,0);
			textureNumber++;
			break;
		case 2:
			setTexturePosition(2,0);
			textureNumber++;
			break;
		case 3:
			setTexturePosition(3,0);
			textureNumber++;
			break;
		case 4:
			setTexturePosition(3,0);
			textureNumber++;
			break;
		case 5:
			setTexturePosition(0,0);
			textureNumber++;
			break;
		case 6:
			setTexturePosition(0,0);
			textureNumber = 0;
			break;
		default:
			break;

		}
	SetPosition(walkBehaviour->Walk(Direction, curPos));

	}
	if (Direction == 'R')
	{
		//POINT pos = getTexturePosition();
		int x = textureNumber;

		switch (x)
		{
		case 0:
			setTexturePosition(1,1);
			textureNumber++;
			break;
		case 1:
			setTexturePosition(2,1);
			textureNumber++;
			break;
		case 2:
			setTexturePosition(2,1);
			textureNumber++;
			break;
		case 3:
			setTexturePosition(3,1);
			textureNumber++;
			break;
		case 4:
			setTexturePosition(3,1);
			textureNumber++;
			break;
		case 5:
			setTexturePosition(0,1);
			textureNumber++;
			break;
		case 6:
			setTexturePosition(0,1);
			textureNumber = 0;
			break;
		default:
			break;

	}
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
		this->setTexturePosition(2,1);
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
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 1:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 2:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 3:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 4:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 5:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 6:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 7:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 8:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;		
	case 9:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 10:
		SetPosition(jumpBehaviour->Jump(curPos, 16));
		break;
	case 11:
		SetPosition(jumpBehaviour->Jump(curPos, 8));
		break;
	case 12:
		SetPosition(jumpBehaviour->Jump(curPos, 8));
		break;
	case 13:
		SetPosition(jumpBehaviour->Jump(curPos, 8));
		break;
	case 14:
		SetPosition(jumpBehaviour->Jump(curPos, 8));
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

