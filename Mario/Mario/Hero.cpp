#ifndef HERO_H
#define HERO_H

#include "Hero.h"

Hero::Hero()
{
	walkBehaviour = new NormalWalk();

}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = NULL;
}

#endif