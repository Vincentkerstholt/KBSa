#include "Castle.h"

Castle::Castle(int textureType){
	this->textureType = textureType;
}

string Castle::getClassName(){
	return "Castle";
}

int Castle::getTextureType(){
	return textureType;
}

Castle::~Castle(){

}