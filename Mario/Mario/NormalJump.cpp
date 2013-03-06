#include "NormalJump.h"

POINT NormalJump::Jump(char Direction, POINT CurPos)
{
	POINT returnPoint;
	switch(Direction)
	{
	case 'U': //Move Up
		returnPoint.x = (CurPos.x);
		returnPoint.y = (CurPos.y-8);
		break;
	case 'R': //Move Right
		returnPoint.x = (CurPos.x+8);
		returnPoint.y = (CurPos.y-8);
		break;
	case 'L': //Move Left
		returnPoint.x = (CurPos.x-8);
		returnPoint.y = (CurPos.y-8);
		break;
	}
	return returnPoint;
}
