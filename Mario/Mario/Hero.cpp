#include "Hero.h"

Hero::Hero()
{
	SetPosition(0, 640);
	textureNumber = 1;
	walkBehaviour = new FastWalk(); 
	texture = LoadImage(NULL, "res/mario_sprite_by.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}