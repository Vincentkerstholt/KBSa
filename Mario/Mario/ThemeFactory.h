#ifndef THEMEFACTORY_H
#define THEMEFACTORY_H

#include "Obstacle.h"
#include <string>
#include "win.h"

using namespace std;

class IThemeFactory{
public:
	virtual ~IThemeFactory(){}
	virtual Obstacle createPipe(){return Obstacle();}
	virtual Obstacle createBlock(){return Obstacle();}
	virtual HANDLE getBackgroundImage(){return HANDLE();}
};

#endif