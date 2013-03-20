#ifndef HERO_H
#define HERO_H

#include "character.h"

class Hero : public Character{
private:
	int coins;
	int score;
	int lives;
	int jumping;
	bool powerUp;
public:
	Hero();
	~Hero();
	HANDLE texture;
	int textureNumber;
	POINT collisionPoint[8];
	void grabcoin();
	int getCoins();
	int getLives();
	bool getPowerUp();
	void grabPowerUp();
	void hurt();
	void addLive();
	void Die();
	void increaseScore(int points);
};

#endif