#include "JumpBehaviour.h"

class NormalJump : public JumpBehaviour 
{
private:

public:
	POINT Jump(char Direction, POINT CurPos);
};