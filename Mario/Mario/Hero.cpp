#include "Hero.h"

Hero::Hero()
{
	SetPosition(0, 640);
	setDirection('R');
	setTexturePosition(0,0);
	walkBehaviour = new FastWalk(); 
	texture = LoadImage(NULL, "res/smb3-mario_sheet.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}