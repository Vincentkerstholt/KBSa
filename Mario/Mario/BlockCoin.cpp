#include "BlockCoin.h"



BlockCoin::BlockCoin()
{
	sprite = -1;
}

string BlockCoin::getClassName()
{
	return "BlockCoin";
}

int BlockCoin::getSprite()
{
	sprite++;
	return sprite;
}

BlockCoin::~BlockCoin()
{

}