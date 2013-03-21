#include "Mushroom.h"

Mushroom::Mushroom(POINT & pixelpnt)
{
	position = pixelpnt;
	progress = 0;
}

string Mushroom::getClassName(){
	return "Mushroom";
}

void Mushroom::updateGadget()
{
	if(progress < 32)
	{
		progress += 1;
		position.y -= 1;
	}
	else;//enter code here for walk function
}

Mushroom::~Mushroom(){}