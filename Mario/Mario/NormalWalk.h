#ifndef NORMALWALK_H
#define NORMALWALK_H

#include "WalkBehaviour.h"

class NormalWalk : public WalkBehaviour 
{
private:

public:
	POINT Walk(char Direction, POINT CurPos);
};

#endif 