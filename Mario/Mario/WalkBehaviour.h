#ifndef WALKBEHAVIOUR_H
#define WALKBEHAVIOUR_H

#include <Windows.h>

class WalkBehaviour 
{
private:

public:
	virtual POINT Walk(char Direction, POINT CurPos) = 0;
};

#endif
