#ifndef NORMALJUMP_H
#define NORMALJUMP_H

#include "JumpBehaviour.h"

class NormalJump : public JumpBehaviour 
{
private:

public:
	POINT Jump(POINT CurPos, int Height);
};


#endif //NORMALJUMP_H