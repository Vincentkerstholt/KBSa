#ifndef CHARACTER_H
#define CHARACTER_H

#include "character.h"

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

#endif
