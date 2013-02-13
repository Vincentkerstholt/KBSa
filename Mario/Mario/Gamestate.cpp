#include <iostream>
#include <fstream>
#include "Gamestate.h"

using namespace std;

Gamestate::Gamestate()
{
	YLENGTH = 24;
	XLENGTH = 214;

}


void Gamestate::NewLevel()
{
	

	ifstream input;
	switch (state)
	{
	case 0:
		return;
	break;
	case 1:
		input = ifstream( "levels/lvl1" );
	break;
	case 2:
		input = ifstream ( "levels/lvl2" );
	break;
	case 3:
		input = ifstream ( "levels/lvl3" );
	break;
	case 4:
		input = ifstream ( "levels/lvl4" );
	break;
	case 5:
		input = ifstream ( "levels/lvl5" );
	break;
	default:
	break;
	}
	
	int temp;
	for (int x=0 ; x<XLENGTH ; x++)
	{
		for (int y=0 ; y<YLENGTH ; y++)
		{
			do 
			{
				input >> temp;
				switch (temp)
				{
					if (cotains(temp,BLOCK))
					{

					}
				}

			} while (input);
		}
	}




}

Gamestate::~Gamestate()
{

}


