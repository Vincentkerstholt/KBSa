#include "Goomba.h"

Goomba::Goomba(int startPointX, int startPointY, int endPointX, int endPointY){
	this->startPointX = startPointX;
	this->startPointY = startPointY;
	this->endPointX = endPointX;
	this->endPointY = endPointY;
	walkBehaviour = new NormalWalk(); 
	setDirection('L');
	
};

Goomba::~Goomba(){
	delete walkBehaviour;
	walkBehaviour = 0;

};

int Goomba::getEndPoint(char valuePoint){
	if (valuePoint == 'x')
		return endPointX;
	else if(valuePoint == 'y')
		return endPointY;
	return -1;
};

int Goomba::getStartPoint(char valuePoint){
	if (valuePoint == 'x')
		return startPointX;
	else if(valuePoint == 'y')
		return startPointY;
	return -1;
};

string Goomba::getClassName(){
	return "Goomba";
}

void Goomba::Die(){

}
