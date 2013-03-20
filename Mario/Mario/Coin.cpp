#include "Coin.h"

Coin::Coin(POINT & pixelpnt)
{
	progress = 0;
	position = pixelpnt;
}

string Coin::getClassName()
{
	return "Coin";
}

void Coin::updateGadget()
{
	if (progress < 32)
	{
		progress += 2;
		position.y -= 2; 
	}
}

Coin::~Coin()
{

}