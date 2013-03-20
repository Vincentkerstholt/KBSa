
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
		progress += 1;
		position.y -= 1;
	}
	else; //enter code here for walk function
}

LiveUp::~LiveUp(){}