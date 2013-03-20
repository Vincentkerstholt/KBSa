#ifndef POWERUP_H
#define POWERUP_H

#include "Gadget.h"

class PowerUp : public Gadget
{
public:
	virtual string getClassName() = 0;
};

#endif