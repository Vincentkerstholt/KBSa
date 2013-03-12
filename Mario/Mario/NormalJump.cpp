#include "NormalJump.h"

POINT NormalJump::Jump(POINT CurPos)
{
	POINT returnPoint;
	returnPoint.x = (CurPos.x);
	returnPoint.y = (CurPos.y-16);

	return returnPoint;
}
