

#include "HighJump.h"

POINT HighJump::Jump(POINT CurPos, int Height)
{
	POINT returnPoint;
	returnPoint.x = (CurPos.x);
	returnPoint.y = (CurPos.y-(Height+4));

	return returnPoint;
}