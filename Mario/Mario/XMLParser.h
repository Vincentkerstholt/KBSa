#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <stdio.h>
#include <sstream>
#include <Windows.h>
#include "XMLParserNode.h"

using namespace std;

class XmlParser
{
public:
	XmlParser(string fileLocation);
	XmlParserNode * getNode(string tagName);
	~XmlParser();
private:
	FILE * file;
	char * buffer;
	XmlParserNode * root;
	string tagNames[300];
	int tagNamesLength;

	void parse(string fileLocation);
	void parseError(string eMessage);
};

#endif