#include "FastWalk.h"

POINT FastWalk::Walk(char Direction, POINT CurPos)
{
	POINT returnPoint;
	switch(Direction)
	{
	case 'R': //Move Right
		returnPoint.x = (CurPos.x+10);
		returnPoint.y = (CurPos.y);
		break;
	case 'L': //Move Left
		returnPoint.x = (CurPos.x-10);
		returnPoint.y = (CurPos.y);
		break;
	}
	return returnPoint;
}
