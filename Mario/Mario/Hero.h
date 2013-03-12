#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character{
private:
	int coins;
	int score;
	int lives;
	
public:
	Hero();
	~Hero();
	HANDLE texture;
	int textureNumber;
	POINT collisionPoint[8];
	
};

#endif