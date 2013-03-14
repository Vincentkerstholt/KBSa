#include "NormalJump.h"

POINT NormalJump::Jump(POINT CurPos, int Height)
{
	POINT returnPoint;
	returnPoint.x = (CurPos.x);
	returnPoint.y = (CurPos.y-Height);

	return returnPoint;
}
