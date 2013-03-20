#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character{
private:
	int coins;
	int score;
	int lives;
	int jumping;
	
public:
	Hero();
	~Hero();
	HANDLE texture;
	int textureNumber;
	POINT collisionPoint[8];
	string getClassName();
	int getCoins();
	int getLives();
	void setLives(int lives);
	void Die();
};

#endif