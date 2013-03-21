
#include "LiveUp.h"

LiveUp::LiveUp(POINT & pixelpnt)
{
	position = pixelpnt;
	progress = 0;
}

string LiveUp::getClassName()
{
	return "LiveUp";
}

void LiveUp::updateGadget()
{
	if (progress < 32)
	{
		progress += 2;
		position.y -= 2;
	}
	else; //enter code here for walk function
}

LiveUp::~LiveUp(){}