#ifndef JUMPBEHAVIOUR_H
#define JUMPBEHAVIOUR_H

#include <Windows.h>

class JumpBehaviour 
{
private:

public:
	virtual POINT Jump(POINT CurPos,int height) = 0;
};

#endif