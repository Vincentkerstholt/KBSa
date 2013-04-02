#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character {
private:

public:
	virtual int getStartPoint(char valuePoint) = 0;
	virtual int getEndPoint(char valuePoint) = 0; 
};

#endif