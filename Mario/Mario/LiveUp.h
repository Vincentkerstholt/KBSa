#ifndef LIVEUP_H
#define LIVEUP_H

#include "Gadget.h"

class LiveUp : public Gadget
{
public:
	LiveUp(POINT & pixelpnt);
	~LiveUp();
	string getClassName();
	void updateGadget();
};

#endif //LIVEUP_H