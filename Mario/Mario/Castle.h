#ifndef CASTLE_H
#define CASTLE_H

#include "GameObject.h"

class Castle : public Gameobject
{
public:
	Castle(int textureType);
	string getClassName();
	int getTextureType();
	~Castle();
private:
	int textureType;
};
#endif