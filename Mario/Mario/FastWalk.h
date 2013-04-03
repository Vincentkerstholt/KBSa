#ifndef FASTWALK_H
#define FASTWALK_H

#include "WalkBehaviour.h"

class FastWalk : public WalkBehaviour 
{
private:

public:
	POINT Walk(char Direction, POINT CurPos);
};

#endif // FASTWALK_H