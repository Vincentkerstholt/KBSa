#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include <Windows.h>

using namespace std;

class Gameobject
{
public:
	virtual string getClassName() = 0;
private:
};

#endif