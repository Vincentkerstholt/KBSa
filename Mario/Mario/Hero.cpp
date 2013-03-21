#include "Hero.h"

Hero::Hero()
{
	textureNumber = 1;
	coins = 0;
	lives = 5;
	score = 0;
	walkBehaviour = new FastWalk(); 
	setDirection('R');
	setTexturePosition(0,0);
	walkBehaviour = new FastWalk(); 
	jumpBehaviour = new NormalJump(); 
	texture = LoadImage(NULL, "res/bigMarioMoves.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	powerUp = false;
}

string Hero::getClassName(){
	return "Hero";
}

void Hero::setName(string name){
	this->name = name;
}

string Hero::getName(){
	return name;
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
void Hero::setLives(int lives)
{
	this->lives = lives;
}

void Hero::Die()
{
	this->lives -= 1;
}

void Hero::grabcoin()
{
	this->coins += 1;
	score += 100;
}

void Hero::grabPowerUp()
{
	powerUp = true;
}

bool Hero::getPowerUp()
{
	return powerUp;
}

bool Hero::hurt()
{
	if (powerUp == true)
		powerUp = false;
	else
		Die();

	if(lives == -1)
		return true;
	return false;
}

void Hero::addLive()
{
	this->lives++;
}

void Hero::increaseScore(int points)
{
	score += points;
}

int Hero::getScore()
{
	return score;
}
