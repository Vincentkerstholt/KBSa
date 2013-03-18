#include "XMLParser.h"

XmlParser::XmlParser(){
}

void XmlParser::saveGame(Gamestate * gameState){
	ostringstream oss;

	//Creating the root node
	XmlParserNode * root = new XmlParserNode();
	root->setTitle("superMario");
	
	//Creating the factory node
	XmlParserNode * factory = new XmlParserNode();
	factory->setTitle("factory");
	factory->setAttribute("name",gameState->getCurrentFactory());

	factory->setParent(root);
	factory->setEndTag();
	//Adding the factory node to the root node
	root->addChild(factory);

	//Creating the hero node
	int marioX = (int)(gameState->Mario->GetPositionPixel().x) / 32;
	int marioY = (int)(gameState->Mario->GetPositionPixel().y) / 32;
	XmlParserNode * hero = new XmlParserNode();
	hero->setTitle("hero");
	hero->setAttribute("character",gameState->Mario->getName());
	oss << marioX;
	hero->setAttribute("x",oss.str());
	oss.str("");
	oss.clear();

	oss << marioY;
	hero->setAttribute("y","" + oss.str());
	oss.str("");
	oss.clear();

	hero->setParent(root);
	hero->setEndTag();
	//Adding the hero node to the root node
	root->addChild(hero);

	XmlParserNode * level = new XmlParserNode();
	level->setTitle("level");
	oss << gameState->getX();
	level->setAttribute("width", oss.str());
	oss.str("");
	oss.clear();

	oss << gameState->getY();
	level->setAttribute("height", oss.str());
	oss.str("");
	oss.clear();

	XmlParserNode * blocks = new XmlParserNode();
	blocks->setTitle("blocks");

	XmlParserNode * pipes = new XmlParserNode();
	pipes->setTitle("pipes");

	XmlParserNode * grounds = new XmlParserNode();
	grounds->setTitle("grounds");

	XmlParserNode * enemies = new XmlParserNode();
	enemies->setTitle("enemies");

	for(int i = 0; i < gameState->getX(); i++){
		for(int j = 0; j < gameState->getY(); j++){
			int index = gameState->getIndex(i,j);
			if(gameState->getLevel()[index] != NULL){
				if(gameState->getLevel()[index]->getClassName() == "Block")
				{
					Block * block = (Block *)gameState->getLevel()[index];
					XmlParserNode * blockXPN = new XmlParserNode();
					blockXPN->setTitle("block");
					blockXPN->setAttribute("isSpecial", block->getIsSpecialString());

					XmlParserNode * location = new XmlParserNode();
					location->setTitle("location");
					location->setEndTag();
					location->setParent(blockXPN);
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					XmlParserNode * gadget = new XmlParserNode();
					gadget->setTitle("gadget");
					gadget->setParent(blockXPN);

					XmlParserNode * coin = new XmlParserNode();
					coin->setTitle("coin");
					coin->setEndTag();
					coin->setParent(gadget);
					coin->setAttribute("value","5");

					gadget->addChild(coin);

					blockXPN->addChild(location);
					blockXPN->addChild(gadget);
					
					blockXPN->setParent(blocks);
					blocks->addChild(blockXPN);
				}
				else if(gameState->getLevel()[index]->getClassName() == "Pipe")
				{
					Pipe * pipe = (Pipe *)gameState->getLevel()[index];
					XmlParserNode * pipeXPN = new XmlParserNode();
					pipeXPN->setTitle("pipe");
					oss << pipe->getTextureType();
					pipeXPN->setAttribute("type",oss.str());
					oss.str("");
					oss.clear();

					XmlParserNode * location = new XmlParserNode();
					location->setTitle("location");
					location->setEndTag();
					location->setParent(pipeXPN);
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					pipeXPN->addChild(location);
					pipes->addChild(pipeXPN);
				}
				else if(gameState->getLevel()[index]->getClassName() == "Ground")
				{
					Ground * ground = (Ground *)gameState->getLevel()[index];
					XmlParserNode * groundXPN = new XmlParserNode();
					groundXPN->setTitle("ground");
					oss << ground->getTextureType();
					groundXPN->setAttribute("type",oss.str());
					oss.str("");
					oss.clear();

					XmlParserNode * location = new XmlParserNode();
					location->setTitle("location");
					location->setEndTag();
					location->setParent(groundXPN);
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					groundXPN->addChild(location);

					groundXPN->setParent(grounds);
					grounds->addChild(groundXPN);
				}
				else if(gameState->getLevel()[index]->getClassName() == "Goomba"){
					Goomba * goomba = (Goomba *)gameState->getLevel()[index];
					XmlParserNode * goombaXPN = new XmlParserNode();
					goombaXPN->setTitle("enemy");
					goombaXPN->setAttribute("character","goomba");

					XmlParserNode * location = new XmlParserNode();
					location->setTitle("location");
					location->setEndTag();
					location->setParent(goombaXPN);
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();
					goombaXPN->addChild(location);

					XmlParserNode * endPath = new XmlParserNode();
					endPath->setTitle("endPath");
					endPath->setEndTag();
					endPath->setParent(goombaXPN);
					oss << goomba->getEndPoint('x');
					endPath->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();
					oss << goomba->getEndPoint('y');
					endPath->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();
					goombaXPN->addChild(endPath);

					goombaXPN->setParent(enemies);
					enemies->addChild(goombaXPN);
				}
			}
		}
	}

	level->addChild(blocks);
	level->addChild(pipes);
	level->addChild(grounds);

	root->addChild(enemies);
	root->addChild(level);

	string xml = root->toXML(0);
	ofstream myfile;
	myfile.open ("res/saveGame.xml");
	myfile << "<?xml version=\"1.0\"?>" << endl << xml;
	myfile.close();

	delete root;
	root = NULL;
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
					if(tagName[0] == '?')
						continue;
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