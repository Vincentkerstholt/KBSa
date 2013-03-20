#ifndef GADGET_H
#define GADGET_H

#include "GameObject.h"

const int COIN = 1;
const int LIVEUP = 2;
const int FLOWER = 3;
const int MUSHROOM = 4;

class Gadget :public Gameobject
{
public:
	POINT position;
	int progress;
	virtual string getClassName() = 0;
	virtual void updateGadget() = 0;
};
#endif //GADGET_H