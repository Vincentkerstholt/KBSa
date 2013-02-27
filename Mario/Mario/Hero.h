#include "character.h"


class Hero : public Character {
private:
	int coins;
	int score;
	int lives;
public:
	Hero();
	~Hero();
};