#ifndef ULTRAWALK_H
#define ULTRAWALK_H

#include "WalkBehaviour.h"

class UltraWalk : public WalkBehaviour
{
public:
	POINT Walk(char Direction, POINT CurPos);
};
#endif //ULTRAWALK_H