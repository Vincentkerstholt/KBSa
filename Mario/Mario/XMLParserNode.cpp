#include "XMLParserNode.h"

XmlParserNode::XmlParserNode(){
	childsLength = 0;
	childsTotalLength = 0;
	hasEndTag = false;
	attributes = new map<string, string>();
}

void XmlParserNode::setTitle(string title){
	//Setting the title
	this->title = title;
}

string XmlParserNode::getTitle(){
	//Returning the title
	return title;
}

void XmlParserNode::addChild(XmlParserNode * child){
	//If childs array length equals total array length
	if(childsLength == childsTotalLength){
		//Resizing the array
		setChildsLength();
	}
	//Adding the child to the childs array
	childs[childsLength] = child;
	childsLength++;

	//Setting the child it's parent to this node
	child->setParent(this);
}

int XmlParserNode::getChildsLength(){
	//Returning the childs array length
	return childsLength;
}

void XmlParserNode::setEndTag(){
	//Setting a singleton node
	hasEndTag = true;
}

bool XmlParserNode::getEndTag(){
	//Returning if node is singleton
	return hasEndTag;
}

void XmlParserNode::setChildsLength(){
	XmlParserNode ** ghostArray;

	//If childs array is filled
	if(childsLength > 0){
		//Creating a ghost array
		ghostArray = new XmlParserNode * [childsTotalLength];
		for(int i = 0; i < childsLength; i++){
			//Filling the ghostarray with the childs array
			ghostArray[i] = childs[i];
		}
	}
	
	//Updating childs array totallength
	childsTotalLength = (childsTotalLength * 2) + 1;

	//Creating a new array for the childs
	childs = new XmlParserNode * [childsTotalLength];

	//If childs array is filled
	if(childsLength > 0){
		for(int i = 0; i < childsLength; i++){
			//Filling the childs array with the ghostarray
			childs[i] = ghostArray[i];
		}
		delete ghostArray;
	}
}

XmlParserNode * XmlParserNode::getParent(){
	//Returning the parent node
	return parent;
}

void XmlParserNode::setParent(XmlParserNode * parent){
	//Setting the parent node
	this->parent = parent;
}

void XmlParserNode::setAttribute(string key, string setValue){
	//Setting the attribute
	(*attributes)[key] = setValue;
}

string XmlParserNode::getAttribute(string key){
	//Returning the attribute value
	return (* attributes)[key];
}

XmlParserNode * XmlParserNode::getNode(string tagName){
	//Creating a returning node
	XmlParserNode * node = NULL;
	
	//For each child
	for (int i = 0; i < childsLength; i++)
	{
		//Creating a reference to the child node
		XmlParserNode * xpn = childs[i];

		//If child title equals search tagname
		if(xpn->getTitle() == tagName){
			//Returning node is childnode 
			node = xpn;
			break;
		}
		//If child title doesn't equals search tagname
		else{
			//Returning node is the childs children node
			node = xpn->getNode(tagName);
		}
	}
	//Returning the returning node
	return node;
}

XmlParserNode ** XmlParserNode::getChilds(){
	//Returning the children nodes
	return childs;
}

string XmlParserNode::toString(){
	ostringstream oss;
	//Adding the title to the string
	oss << title;
	//For each attribute
	for(map<string, string>::iterator it = (*attributes).begin(); it !=(*attributes).end(); ++it){
		//Adding the attribute to the string
		oss << " " << it->first << ": " << it->second;
	}
	//Adding a line end to the string
	oss << endl;
	
	//For each child
	for(int i = 0; i < childsLength; i++){
		//Creating a reference to the child node
		XmlParserNode * child = childs[i];

		//Adding the child node string to the string
		oss << child->toString();
	}

	//Returning the string
	return oss.str();
}

string XmlParserNode::toXML(int depth){
	ostringstream oss;

	//Adding the start node to the XML string
	oss << "<" << title;

	//For each attribute
	for(map<string, string>::iterator it = (*attributes).begin(); it !=(*attributes).end(); ++it){
		//Adding the attribute to the XML string
		oss << " " << it->first << "=\"" << it->second << "\"";
	}

	//If node is singleton node
	if (hasEndTag)
	{
		//Adding closing tag to the XML string
		oss << "/>";
	}
	//If node is not a singleton node
	else
	{
		//Adding closing tag to the XML string
		oss << ">" << endl;

		//For each child
		for(int i = 0; i < childsLength; i++){
			//Creating a reference to the child
			XmlParserNode * child = childs[i];

			//For each depth
			for(int j = 0; j <= depth; j++){
				//Adding a tab to the XML string
				oss << "\t";
			}
			//Adding the child XML and a line end to the XML string
			oss << child->toXML(depth + 1) << endl;
		}
		//For each depth
		for(int j = 0; j < depth; j++){
			//Adding a tab to the XML string
			oss << "\t";
		}
		//Adding a closing node to the XML string
		oss << "</" << title << ">";
	}

	//Returning the XML string
	return oss.str();
}

XmlParserNode::~XmlParserNode(){
	//For each child
	for(int i = 0; i < childsLength; i++)
	{
		//Creating a reference to the child
		XmlParserNode * child = childs[i];

		//Remove child
		delete child;
		child = NULL;
	}
	
	//If childs array has children
	if(childsLength > 0){
		//Removing the array
		delete [] childs;
	}

	//Removing the attributes
	delete attributes;
	childs = NULL;
	attributes = NULL;
}