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
	bool powerUp;
public:
	Hero();
	~Hero();
	HANDLE texture;
	int textureNumber;
	POINT collisionPoint[8];

	void setName(string name);
	string getClassName();
	string getName();
	void grabcoin();
	int getCoins();
	void setCoins(int coins);
	int getLives();
	void setLives(int lives);
	bool getPowerUp();
	void grabPowerUp();
	bool hurt();
	void addLive();
	void Die();
	void increaseScore(int points);
	int getScore();
	void setScore(int score);
};

#endif