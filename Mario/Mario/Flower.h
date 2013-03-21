#ifndef FLOWER_H
#define FLOWER_H

#include "Powerup.h"

class Flower : public PowerUp
{
public:
	Flower(POINT & pixelpnt);
	~Flower();
	string getClassName();
	void updateGadget();
};
#endif //FLOWER_H