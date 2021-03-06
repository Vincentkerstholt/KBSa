#include "UltraWalk.h"

POINT UltraWalk::Walk(char Direction, POINT CurPos)
{
	POINT returnPoint;
	switch(Direction)
	{
	case 'R': //Move Right
		returnPoint.x = (CurPos.x+8);
		returnPoint.y = (CurPos.y);
		break;
	case 'L': //Move Left
		returnPoint.x = (CurPos.x-8);
		returnPoint.y = (CurPos.y);
		break;
	}
	return returnPoint;
}