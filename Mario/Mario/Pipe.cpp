#include "Pipe.h"

Pipe::Pipe(string textureType){
	this->textureType = textureType;
}

string Pipe::getClassName(){
	return "Pipe";
}

string Pipe::getTextureType(){
	return textureType;
}