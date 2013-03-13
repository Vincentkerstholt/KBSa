#include "Pipe.h"

Pipe::Pipe(int textureType){
	this->textureType = textureType;
}

string Pipe::getClassName(){
	return "Pipe";
}

int Pipe::getTextureType(){
	return textureType;
}