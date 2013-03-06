#include "XMLParser.h"

XmlParser::XmlParser(string fileLocation){
	parse(fileLocation);
}

void XmlParser::parse(string fileLocation){
	file = fopen(fileLocation.c_str(), "r");
	buffer = new char[100];
	tagNamesLength = 0;
	int lineNumber = 0;
	ostringstream oss;
	XmlParserNode * currentNode;
	
	if (file == NULL) parseError("Error opening file");
	else{
		while (!feof(file))
		{
			if(fgets(buffer, 100, file) == NULL) break;
			fputs(buffer, stdout);
			string line = buffer;
			string cleanLine;
			lineNumber++;

			bool hasAttributes;

			int closingTagStart = -1;
			int beginningTagStart = -1;
			int singletonTagEnd = -1;
			int beginningTagEnd = -1;

			closingTagStart = line.find("<\/");
			if(closingTagStart == -1){
				beginningTagStart = line.find("<");
				cleanLine = line.substr(beginningTagStart, line.length());
				beginningTagStart = 0;
			}
			else{
				cleanLine = line.substr(closingTagStart, line.length());
				closingTagStart = 1;
			}
			singletonTagEnd = cleanLine.find("\/>");
			if(singletonTagEnd == -1) beginningTagEnd = cleanLine.find(">");

			int firstWhiteSpace = cleanLine.find(" ");
			
			string tagName;

			if(closingTagStart > -1){
				//Close tag '</'
				tagName = cleanLine.substr(closingTagStart + 1, beginningTagEnd - 2);
				if(tagName == "superMario"){
					root->setEndTag();
					break;
				}
				else{
					if(tagNames[tagNamesLength - 1] == tagName){
						tagNames[tagNamesLength - 1] = "";
						tagNamesLength--;
						currentNode->setEndTag();
						currentNode = currentNode->getParent();
					}
					else{
						oss << "The tagName \"" << tagName << "\" doesn't match \"" << tagNames[tagNamesLength - 1] << "\" at line " << lineNumber;
						parseError(oss.str());
						oss.str("");
						oss.clear();
						break;
					}
				}
			}
			else if(beginningTagStart > -1){
				//Open tag '<'
				string remaining;

				if(firstWhiteSpace == -1 && singletonTagEnd == -1){
					tagName = cleanLine.substr(beginningTagStart + 1, beginningTagEnd - 1);
				}
				else if(firstWhiteSpace == -1 && singletonTagEnd > -1){
					tagName = cleanLine.substr(beginningTagStart + 1, singletonTagEnd - 1);
				}
				else{
					tagName = cleanLine.substr(beginningTagStart + 1, firstWhiteSpace - 1);
					if(beginningTagEnd > -1)
						remaining = cleanLine.substr(firstWhiteSpace + 1, beginningTagEnd - firstWhiteSpace - 1);
					else
						remaining = cleanLine.substr(firstWhiteSpace + 1, singletonTagEnd - firstWhiteSpace - 1);
				}

				if(tagName == "superMario"){
					root = new XmlParserNode();
					root->setTitle(tagName);
					currentNode = root;
				}
				else{
					XmlParserNode * xpn;
					if(singletonTagEnd > -1){
						//Singleton Node
						xpn = new XmlParserNode();
						xpn->setTitle(tagName);
						xpn->setEndTag();
						xpn->setParent(currentNode);

						if(remaining.length() > 0){
							while (true)
							{
								int whiteSpace = remaining.find(" ");
								int quote;
								string key;
								string attrValue;
								string attribute;
								if(whiteSpace == -1){
									attribute = remaining;
									quote = attribute.find("\"");
									key = attribute.substr(0, attribute.find("="));
									attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 2);

									xpn->setAttribute(key, attrValue);
									break;
								}
								attribute = remaining.substr(0, whiteSpace - 1);
								quote = attribute.find("\"");
								key = attribute.substr(0, attribute.find("="));
								attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 1);

								xpn->setAttribute(key,attrValue);

								remaining = remaining.substr(whiteSpace + 1, remaining.length() - whiteSpace);
							}
						}

						currentNode->addChild(xpn);
					}
					else{
						//Node
						tagNames[tagNamesLength] = tagName;
						tagNamesLength++;
						xpn = new XmlParserNode();
						xpn->setTitle(tagName);
						xpn->setParent(currentNode);

						if(remaining.length() > 0){
							while (true)
							{
								int whiteSpace = remaining.find(" ");
								int quote;
								string key;
								string attrValue;
								string attribute;
								if(whiteSpace == -1){
									attribute = remaining;
									quote = attribute.find("\"");
									key = attribute.substr(0, attribute.find("="));
									attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 2);

									xpn->setAttribute(key, attrValue);
									break;
								}
								attribute = remaining.substr(0, whiteSpace - 1);
								quote = attribute.find("\"");
								key = attribute.substr(0, attribute.find("="));
								attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 1);

								xpn->setAttribute(key,attrValue);

								remaining = remaining.substr(whiteSpace + 1, remaining.length() - whiteSpace);
							}
						}

						currentNode->addChild(xpn);
						currentNode = xpn;
					}
				}
			}
			else{
				parseError("There is no beginning!");
				break;
			}
		}
		fclose(file);
		//oss << root->toString();
		//MessageBox(NULL, oss.str().c_str(), "Tree", NULL);
	}
}

void XmlParser::parseError(string eMessage){
	MessageBox(NULL, eMessage.c_str(),"Error", NULL);
}

XmlParserNode * XmlParser::getNode(string tagName){
	XmlParserNode * xpn = root->getNode(tagName);
	return xpn;
}

XmlParser::~XmlParser(){
	delete buffer;
	delete root;

	file = NULL;
	buffer = NULL;
	root = NULL;
}