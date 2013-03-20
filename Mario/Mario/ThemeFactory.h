#ifndef THEMEFACTORY_H
#define THEMEFACTORY_H

#include "Obstacle.h"
#include <string>
#include "win.h"

using namespace std;

class IThemeFactory{
public:
	virtual HANDLE getPipe() = 0;
	virtual HANDLE getBlock() = 0;
	virtual HANDLE getGround() = 0;
	virtual HANDLE getGoomba() = 0;
	virtual HANDLE getGadget() = 0;
	virtual HANDLE getBackgroundImage() = 0;
	virtual HANDLE getBackgroundImage2() = 0;
	virtual void delImage() = 0;
	virtual string getName() = 0;
};

#endif