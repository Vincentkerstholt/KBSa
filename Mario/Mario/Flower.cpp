#include "Flower.h"


Flower::Flower(POINT & pixelpnt)
{
	progress = 0;
	position = pixelpnt;
}

string Flower::getClassName(){
	return "Flower";
}

void Flower::updateGadget()
{
	if (progress < 32)
	{
		progress += 1;
		position.y -= 1;
	}
	else; //enter code here for walk function
}

Flower::~Flower(){}