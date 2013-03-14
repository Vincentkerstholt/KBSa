#include "Hero.h"

Hero::Hero()
{
	SetPosition(64, 400);
	textureNumber = 1;
	coins = 0;
	lives = 5;
	walkBehaviour = new FastWalk(); 
	setDirection('R');
	setTexturePosition(0,0);
	walkBehaviour = new FastWalk(); 
	jumpBehaviour = new NormalJump(); 
	texture = LoadImage(NULL, "res/bigMarioMoves.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
}

string Hero::getClassName(){
	return "Hero";
}

Hero::~Hero()
{
	delete walkBehaviour;
	walkBehaviour = 0;
}

int Hero::getCoins()
{
	return coins;
}

int Hero::getLives()
{
	return this->lives;
}

void Hero::Die()
{
	this->lives -= 1;
}
