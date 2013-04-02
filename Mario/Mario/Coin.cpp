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
		progress += 4;
		position.y -= 4; 
	}
}

Coin::~Coin()
{

}