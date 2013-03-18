#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character{
private:
	int coins;
	int score;
	int lives;
	int jumping;
	string name;
public:
	Hero();
	~Hero();
	HANDLE texture;
	int textureNumber;
	POINT collisionPoint[8];

	void setName(string name);
	string getClassName();
	string getName();
	int getCoins();
	int getLives();
	void Die();
};

#endif