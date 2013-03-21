#include "Koopa.h"

Koopa::Koopa(int startPointX, int startPointY, int endPointX, int endPointY){
	this->startPointX = startPointX;
	this->startPointY = startPointY;
	this->endPointX = endPointX;
	this->endPointY = endPointY;
	walkBehaviour = new NormalWalk(); 
	setDirection('R');
};

Koopa::~Koopa(){

};

int Koopa::getEndPoint(char valuePoint){
	if (valuePoint == 'x')
		return endPointX;
	else if(valuePoint == 'y')
		return endPointY;
};

int Koopa::getStartPoint(char valuePoint){
	if (valuePoint == 'x')
		return startPointX;
	else if(valuePoint == 'y')
		return startPointY;
};

string Koopa::getClassName(){
	return "Koopa";
}

void Koopa::Die(){

}