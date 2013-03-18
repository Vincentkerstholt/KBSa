#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include "XMLParserNode.h"
#include "characters.h"
#include "obstacles.h"
#include "Gamestate.h"

using namespace std;

class Gamestate;

class XmlParser
{
public:
	XmlParser();
	XmlParserNode * getNode(string tagName);
	void saveGame(Gamestate * gameState);
	void parse(string fileLocation);
	~XmlParser();
private:
	FILE * file;
	char * buffer;
	XmlParserNode * root;
	string tagNames[300];
	int tagNamesLength;

	void parseError(string eMessage);
};

#endif