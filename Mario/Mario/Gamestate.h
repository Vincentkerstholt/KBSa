
#include "Gameobject.h"

const int OBSTACLE = 1;
const int PIPE = 2;
const int BLOCK = 4;
const int 



class Gamestate:public Gameobject
{
public:
	


	Obstacle GetObstacle(int x, int y);

private:

	const int XLENGTH;
	const int YLENGTH;
	Obstacle field[XLENGTH][YLENGTH];
	int state;

	Gamestate();
	~Gamestate();

	void NewLevel();

};