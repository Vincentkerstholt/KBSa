#include "XMLParserNode.h"

XmlParserNode::XmlParserNode(){
	childsLength = 0;
	childsTotalLength = 0;
	hasEndTag = false;
	attributes = new map<string, string>();
}

void XmlParserNode::setTitle(string title){
	this->title = title;
}

string XmlParserNode::getTitle(){
	return title;
}

void XmlParserNode::addChild(XmlParserNode * child){
	if(childsLength == childsTotalLength) setChildsLength();
	childs[childsLength] = child;
	childsLength++;
}

int XmlParserNode::getChildsLength(){
	return childsLength;
}

void XmlParserNode::setEndTag(){
	hasEndTag = true;
}

bool XmlParserNode::getEndTag(){
	return hasEndTag;
}

void XmlParserNode::setChildsLength(){
	XmlParserNode ** ghostArray;
	if(childsLength > 0){
		ghostArray = new XmlParserNode * [childsTotalLength];
		for(int i = 0; i < childsLength; i++){
			ghostArray[i] = childs[i];
		}
	}
	
	childsTotalLength = (childsTotalLength * 2) + 1;
	childs = new XmlParserNode * [childsTotalLength];

	if(childsLength > 0){
		for(int i = 0; i < childsLength; i++){
			childs[i] = ghostArray[i];
		}
		delete ghostArray;
	}
}

XmlParserNode * XmlParserNode::getParent(){
	return parent;
}

void XmlParserNode::setParent(XmlParserNode * parent){
	this->parent = parent;
}

void XmlParserNode::setAttribute(string key, string setValue){
	(*attributes)[key] = setValue;
}

string XmlParserNode::getAttribute(string key){
	return (* attributes)[key];
}

XmlParserNode * XmlParserNode::getNode(string tagName){
	XmlParserNode * node = NULL;
	for (int i = 0; i < childsLength; i++)
	{
		XmlParserNode * xpn = childs[i];
		if(xpn->getTitle() == tagName){
			node = xpn;
			break;
		}
		else{
			node = xpn->getNode(tagName);
		}
	}
	return node;
}

XmlParserNode ** XmlParserNode::getChilds(){
	return childs;
}

string XmlParserNode::toString(){
	ostringstream oss;
	oss << title;
	for(map<string, string>::iterator it = (*attributes).begin(); it !=(*attributes).end(); ++it){
		oss << " " << it->first << ": " << it->second;
	}
	oss << endl;
	for(int i = 0; i < childsLength; i++){
		XmlParserNode * child = childs[i];
		oss << child->toString();
	}
	return oss.str();
}

string XmlParserNode::toXML(int depth){
	ostringstream oss;

	oss << "<" << title;
	for(map<string, string>::iterator it = (*attributes).begin(); it !=(*attributes).end(); ++it){
		oss << " " << it->first << "=\"" << it->second << "\"";
	}
	if (childsLength == 0)
	{
		oss << "/>";
	} 
	else
	{
		oss << ">" << endl;
		for(int i = 0; i < childsLength; i++){
			XmlParserNode * child = childs[i];
			for(int j = 0; j <= depth; j++){
				oss << "\t";
			}
			oss << child->toXML(depth + 1) << endl;
		}
		for(int j = 0; j < depth; j++){
			oss << "\t";
		}
		oss << "</" << title << ">";
	}

	return oss.str();
}

XmlParserNode::~XmlParserNode(){
	delete [] childs;
	delete attributes;
	childs = NULL;
	attributes = NULL;
}