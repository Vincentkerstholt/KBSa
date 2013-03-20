#include "Koopa.h"

Koopa::Koopa(int endPointX, int endPointY){
	this->endPointX = endPointX;
	this->endPointY = endPointY;
};

Koopa::~Koopa(){

};

int Koopa::getEndPoint(char valuePoint){
	if (valuePoint == 'x')
		return endPointX;
	else if(valuePoint == 'y')
		return endPointY;
};

string Koopa::getClassName(){
	return "Koopa";
}

void Koopa::Die(){

}