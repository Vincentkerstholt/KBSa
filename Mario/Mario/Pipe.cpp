#include "Pipe.h"

Pipe::Pipe(int spriteX, int spriteY){
	this->spriteX = spriteX;
	this->spriteY = spriteY;
	//piranhaPlant = NULL;
}

//Pipe::Pipe(PiranhaPlant piranhaPlant){
	//this->piranhaPlant = piranhaPlant;
//}

string Pipe::getClassName(){
	return "Pipe";
}

int Pipe::getSpriteX(){
	return spriteX;
}

int Pipe::getSpriteY(){
	return spriteY;
}