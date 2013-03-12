#include "Hero.h"

Hero::Hero()
{
	SetPosition(160, 640);
	textureNumber = 1;
	walkBehaviour = new FastWalk(); 
	SetWalkBlock('L', false);
	SetWalkBlock('R', false);


	texture = LoadImage(NULL, "res/mario_sprite_by.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}

