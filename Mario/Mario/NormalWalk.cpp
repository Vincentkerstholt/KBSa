#include "NormalWalk.h"

POINT NormalWalk::Walk(char Direction, POINT CurPos)
{
	POINT returnPoint;
	switch(Direction)
	{
	case 'R': //Move Right
		returnPoint.x = (CurPos.x+1);
		returnPoint.y = (CurPos.y);
		break;
	case 'L': //Move Left
		returnPoint.x = (CurPos.x-1);
		returnPoint.y = (CurPos.y);
		break;
	case 'U': //Move UP
		returnPoint.x = (CurPos.x);
		returnPoint.y = (CurPos.y+50);
		break;
	case 'D': //Move UP
		returnPoint.x = (CurPos.x);
		returnPoint.y = (CurPos.y-16);
		break;
	}
	return returnPoint;
}
