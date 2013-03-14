#include "Goomba.h"

Goomba::Goomba(int endPointX, int endPointY){
	this->endPointX = endPointX;
	this->endPointY = endPointY;
};

Goomba::~Goomba(){

};

int Goomba::getEndPoint(char valuePoint){
	if (valuePoint == 'x')
		return endPointX;
	else if(valuePoint == 'y')
		return endPointY;
};

string Goomba::getClassName(){
	return "Goomba";
}