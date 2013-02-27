#include "Hero.h"


Hero::Hero()
{
	SetPosition(43, 22);
	walkBehaviour = new NormalWalk(); 
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}

