#include "Ground.h"

Ground::Ground(int textureType){
	this->textureType = textureType;
}

string Ground::getClassName(){
	return "Ground";
}

int Ground::getTextureType(){
	return textureType;
}