#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "Powerup.h"

class Mushroom : public PowerUp
{
public:
	Mushroom(POINT & pixelpnt);
	~Mushroom();
	string getClassName();
	void updateGadget();
};

#endif //MUSHROOM_H