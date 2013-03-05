#include "character.h"

Character::Character()
{
}

void Character :: Walk ()
{
	walkBehaviour->Walk(); 
}

void Character :: setWalkBehaviour(WalkBehaviour *qb)
{
	walkBehaviour = qb;
}


POINT Character :: GetPosition()
{
	return Position;
}

void Character :: SetPosition(int x, int y)
{
	Position.x = x;
	Position.y = y;
}

void Character::Die()
{
}

void Character::GetPowerUp()
{
}

void Character::Move()
{
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
