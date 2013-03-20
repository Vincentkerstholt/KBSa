#ifndef XMLPARSERNODE_H
#define XMLPARSERNODE_H

#include <sstream>
#include <map>

using namespace std;

class XmlParserNode
{
public:
	XmlParserNode();
	~XmlParserNode();
	void setTitle(string title);
	string getTitle();
	void addChild(XmlParserNode * child);
	XmlParserNode ** getChilds();
	int getChildsLength();
	void setEndTag();
	bool getEndTag();
	XmlParserNode * getParent();
	void setParent(XmlParserNode * parent);
	string toString();
	void setAttribute(string key, string setValue);
	XmlParserNode * getNode(string tagName);
	string getAttribute(string key);
	string toXML(int depth);
private:
	string title;
	int childsLength;
	int childsTotalLength;
	bool hasEndTag;
	XmlParserNode ** childs;
	XmlParserNode * parent;
	map<string, string> * attributes;

	void setChildsLength();
};

#endif