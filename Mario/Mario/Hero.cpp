#include "Hero.h"

Hero::Hero()
{
	SetPosition(160, 640);
	walkBehaviour = new FastWalk(); 
	texture = LoadImage(NULL, "res/mario_sprite_by.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	setDirection('R');
	setTexturePosition(0,0);
	walkBehaviour = new FastWalk(); 
	jumpBehaviour = new NormalJump(); 
	texture = LoadImage(NULL, "res/smb3-mario_sheet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}

