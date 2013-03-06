#ifndef THEMEFACTORY_H
#define THEMEFACTORY_H

#include "Obstacle.h"
#include <string>
#include "win.h"

using namespace std;

class IThemeFactory{
public:
	virtual HANDLE getPipe(int x, int y) = 0;
	virtual HANDLE getBlock(int x, int y) = 0;
	virtual HANDLE getGround(int x, int y) = 0;
	virtual HANDLE getBackgroundImage() = 0;
	virtual HANDLE getBackgroundImage2() = 0;
};

#endif