#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

using namespace std;

class Gameobject
{
public:
	virtual string getClassName() = 0;
	virtual int getSpriteX() = 0;
	virtual int getSpriteY() = 0;
private:
};

#endif