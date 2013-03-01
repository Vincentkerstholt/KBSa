#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>

using namespace std;

class Gameobject
{
public:
	virtual string getClassName() = 0;
	virtual int getSpriteX();
	virtual int getSpriteY();
private:
	virtual int spriteX = 0;
	virtual int spriteY = 0;
};

#endif