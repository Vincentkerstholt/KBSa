#ifndef CHARACTER_H
#define CHARACTER_H

#include "character.h"

void Character :: Walk ()
{
	this->WalkBehaviour->Walk(); 
}

#endif