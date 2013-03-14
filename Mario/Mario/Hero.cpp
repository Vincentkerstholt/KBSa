#include "Hero.h"

Hero::Hero()
{

	SetPosition(64, 400);
	textureNumber = 1;
	walkBehaviour = new FastWalk(); 
	setDirection('R');
	setTexturePosition(0,0);
	walkBehaviour = new FastWalk(); 
	jumpBehaviour = new NormalJump(); 
	texture = LoadImage(NULL, "res/bigMarioMoves.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}

