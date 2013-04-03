#ifndef HIGHJUMP_H
#define HIGHJUMP_H

#include "JumpBehaviour.h"

class HighJump : public JumpBehaviour
{
private:
public:
	POINT Jump(POINT CurPos, int Height);
};
#endif //HIGHJUMP_H