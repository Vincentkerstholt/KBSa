#include "FastWalk.h"

POINT FastWalk::Walk(char Direction, POINT CurPos)
{
	POINT returnPoint;
	switch(Direction)
	{
	case 'R': //Move Right
		returnPoint.x = (CurPos.x+16);
		returnPoint.y = (CurPos.y);
		break;
	case 'L': //Move Left
		returnPoint.x = (CurPos.x-16);
		returnPoint.y = (CurPos.y);
		break;
	case 'U': //Move UP
		returnPoint.x = (CurPos.x);
		returnPoint.y = (CurPos.y-16);
		break;
	case 'D': //Move UP
		returnPoint.x = (CurPos.x);
		returnPoint.y = (CurPos.y-16);
		break;
	}
	return returnPoint;
}
