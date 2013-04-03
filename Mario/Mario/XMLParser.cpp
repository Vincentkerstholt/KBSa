#include "XMLParser.h"

XmlParser::XmlParser(){
	buffer = NULL;
	root = NULL;
}

void XmlParser::saveGame(Gamestate * gameState){
	ostringstream oss;
	
	//Creating a reference to the levelmap
	Gameobject ** gameStateLevel = gameState->getLevel();

	//Creating the root node
	XmlParserNode * root = new XmlParserNode();
	root->setTitle("superMario");
	
	//Creating the factory node
	XmlParserNode * factory = new XmlParserNode();
	
	//Setting the title for the factory node
	factory->setTitle("factory");

	//Setting the attribute name for the factory node
	factory->setAttribute("name",gameState->getCurrentFactory());

	//Creating a singleton node of the factory node
	factory->setEndTag();
	
	//Adding the factory node to the root node
	root->addChild(factory);

	//Getting the grid position of the hero
	int marioX = (int)(gameState->Mario->GetPositionPixel().x) / 32;
	int marioY = (int)(gameState->Mario->GetPositionPixel().y) / 32;
	
	//Creating the hero node
	XmlParserNode * hero = new XmlParserNode();

	//Setting the title for the hero node
	hero->setTitle("hero");
	
	//Setting the attribute character
	hero->setAttribute("character",gameState->Mario->getName());
	
	//Setting the attribute x for the hero node
	oss << marioX;
	hero->setAttribute("x",oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute y for the hero node
	oss << marioY;
	hero->setAttribute("y","" + oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute coins for the hero node
	oss << gameState->Mario->getCoins();
	hero->setAttribute("coins", "" + oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute points for the hero node
	oss << gameState->Mario->getScore();
	hero->setAttribute("points", "" + oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute lives for the hero node
	oss << gameState->Mario->getLives();
	hero->setAttribute("lives", "" + oss.str());
	oss.str("");
	oss.clear();

	//Creating a singleton node of the hero node
	hero->setEndTag();

	//Adding the hero node to the root node
	root->addChild(hero);

	//Creating the level node
	XmlParserNode * level = new XmlParserNode();
	
	//Setting the title of the level node
	level->setTitle("level");

	//Setting the attribute width for the level node
	oss << gameState->getX();
	level->setAttribute("width", oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute height for the level node
	oss << gameState->getY();
	level->setAttribute("height", oss.str());
	oss.str("");
	oss.clear();

	//Setting the attribute nr for the level node
	oss << gameState->getCurrentLevel();
	level->setAttribute("nr", oss.str());
	oss.str("");
	oss.clear();
	
	//Creating the blocks node
	XmlParserNode * blocks = new XmlParserNode();
	
	//Setting the title for the blocks node
	blocks->setTitle("blocks");

	//Creating the pipes node
	XmlParserNode * pipes = new XmlParserNode();
	
	//Setting the title for the pipes node
	pipes->setTitle("pipes");

	//Creating the grounds node
	XmlParserNode * grounds = new XmlParserNode();
	
	//Setting the title for the grounds node
	grounds->setTitle("grounds");

	//Creating the castles node
	XmlParserNode * castles = new XmlParserNode();
	
	//Setting the title for the castles node
	castles->setTitle("castles");

	//Creating the enemies node
	XmlParserNode * enemies = new XmlParserNode();
	
	//Setting the title for the enemies node
	enemies->setTitle("enemies");

	//For each column
	for(int i = 0; i < gameState->getX(); i++){
		//For each row
		for(int j = 0; j < gameState->getY(); j++){
			//Getting the index with the column number and row number
			int index = gameState->getIndex(i,j);
			
			//Creating a new reference to a gameobject
			Gameobject * gameObject = gameStateLevel[index];

			//If gameobject exist
			if(gameObject != NULL){
				//Getting the classname of the gameobject
				string classname = gameObject->getClassName();

				//If classname equals Block
				if(classname == "Block")
				{
					//Creating a new reference to the Block object
					Block * block = (Block *)gameStateLevel[index];

					//Creating a block node
					XmlParserNode * blockXPN = new XmlParserNode();
					
					//Setting the title for the block node
					blockXPN->setTitle("block");

					//Setting the attribute isSpecial for the block node
					blockXPN->setAttribute("isSpecial", block->getIsSpecialString());
					
					//Setting the attribute isFixed for the block node
					blockXPN->setAttribute("isFixed", block->getIsFixedString());

					//Creating the location node
					XmlParserNode * location = new XmlParserNode();
					
					//Setting the title for the location node
					location->setTitle("location");

					//Creating a singleton node of the location node
					location->setEndTag();

					//Setting the attribute x for the location node
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					//Setting the attribute y for the location node
					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Creating the gadget node
					XmlParserNode * gadgetXPN = new XmlParserNode();
					
					//Setting the title of the gadget node
					gadgetXPN->setTitle("gadget");
					
					//For each gadget in the block object
					for(int i = 0; i < block->getGadgetAmount(); i++)
					{
						//Creating a reference to the gadget object
						Gadget * gadget = block->getGadgetPoint(i);
						
						//Getting the classname of the gadget object
						string gadgetName = gadget->getClassName();

						//If the gadgetname equals Coin
						if(gadgetName == "Coin")
						{
							//Creating a coin node
							XmlParserNode * coinXPN = new XmlParserNode();
							
							//Setting the title for the coin node
							coinXPN->setTitle("coin");

							//Creating a singleton node of the coin node
							coinXPN->setEndTag();

							//Adding the coin node to the gadget node
							gadgetXPN->addChild(coinXPN);
						}
						//If the gadgetname equals Mushroom
						else if(gadgetName == "Mushroom")
						{
							//Creating a powerup node
							XmlParserNode * powerUpXPN = new XmlParserNode();

							//Setting the title for the powerup node
							powerUpXPN->setTitle("powerup");

							//Creating a singleton node of the powerup node
							powerUpXPN->setEndTag();

							//Adding the powerup node to the gadget node
							gadgetXPN->addChild(powerUpXPN);
						}
						//If the gadgetname equals LiveUp
						else if(gadgetName == "LiveUp")
						{
							//Creating a liveup node
							XmlParserNode * liveUpXPN = new XmlParserNode();
							
							//Setting the title for the liveup node
							liveUpXPN->setTitle("liveup");

							//Creating a singleton node of the liveup node
							liveUpXPN->setEndTag();

							//Adding the liveup node to the gadget node
							gadgetXPN->addChild(liveUpXPN);
						}
					}

					//Adding the location node to the block node
					blockXPN->addChild(location);

					//Adding the gadget node to the block node
					blockXPN->addChild(gadgetXPN);
					
					//Adding the block node to the blocks node
					blocks->addChild(blockXPN);
				}
				//If classname equals Pipe
				else if(classname == "Pipe")
				{
					//Creating a reference to the pipe object
					Pipe * pipe = (Pipe *)gameStateLevel[index];

					//Creating a pipe node
					XmlParserNode * pipeXPN = new XmlParserNode();
					
					//Setting the title for the pipe node
					pipeXPN->setTitle("pipe");

					//Setting the attribute type for the pipe node
					oss << pipe->getTextureType();
					pipeXPN->setAttribute("type",oss.str());
					oss.str("");
					oss.clear();

					//Creating a location node;
					XmlParserNode * location = new XmlParserNode();
					
					//Setting the title for the location node
					location->setTitle("location");

					//Creating a singleton node of the location node
					location->setEndTag();
					
					//Setting the attribute x for the location node
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					//Setting the attribute y for the location node
					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Adding the location node to the pipe node
					pipeXPN->addChild(location);

					//Adding the pipe node to the pipes node
					pipes->addChild(pipeXPN);
				}
				//If classname equals Ground
				else if(classname == "Ground")
				{
					//Creating a reference to the ground object
					Ground * ground = (Ground *)gameStateLevel[index];
					
					//Creating a ground node
					XmlParserNode * groundXPN = new XmlParserNode();
					
					//Setting the title of the ground node
					groundXPN->setTitle("ground");

					//Setting the attribute type for the ground node
					oss << ground->getTextureType();
					groundXPN->setAttribute("type",oss.str());
					oss.str("");
					oss.clear();

					//Creating a location node
					XmlParserNode * location = new XmlParserNode();
					
					//Setting the title for the location node
					location->setTitle("location");

					//Creating a singleton node of the location node
					location->setEndTag();

					//Setting the attribute x for the location node
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					//Setting the attribute y for the location node
					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Adding the location node to the ground node
					groundXPN->addChild(location);

					//Adding the ground node to the grounds node
					grounds->addChild(groundXPN);
				}
				//If classname equals Castle
				else if(classname == "Castle")
				{
					//Creating a reference to the castle object
					Castle * castle = (Castle *)gameStateLevel[index];

					//Creating a castle node
					XmlParserNode * castleXPN = new XmlParserNode();
					
					//Setting the title of the castle node
					castleXPN->setTitle("ground");

					//Setting the attribute type of the castle node
					oss << castle->getTextureType();
					castleXPN->setAttribute("type",oss.str());
					oss.str("");
					oss.clear();

					//Creating a location node
					XmlParserNode * location = new XmlParserNode();
					
					//Setting the title of the location node
					location->setTitle("location");

					//Creating a singleton node of the location node
					location->setEndTag();

					//Setting the attribute x for the location node
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					//Setting the attribute y for the location node
					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Adding the location node to the castle node
					castleXPN->addChild(location);

					//Adding the castle node to the castles node
					castles->addChild(castleXPN);
				}
				//If classname equals Goomba or classname equals Koopa
				else if(classname == "Goomba" || classname == "Koopa"){
					//Creating a reference to the enemy object
					Enemy * enemy = (Enemy *)gameStateLevel[index];

					//Creating a enemy node
					XmlParserNode * enemyXPN = new XmlParserNode();
					
					//Setting the title of the enemy node
					enemyXPN->setTitle("enemy");
					
					//Setting the attribute character of the enemy node
					if(classname == "Goomba")
						enemyXPN->setAttribute("character","goomba");
					else if(classname == "Koopa")
						enemyXPN->setAttribute("character", "koopa");

					//Creating a location node
					XmlParserNode * location = new XmlParserNode();
					
					//Setting the title of the location node
					location->setTitle("location");

					//Creating a singleton node of the location node
					location->setEndTag();

					//Setting the attribute x for the location node
					oss << i;
					location->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();

					//Setting the attribute y for the location node
					oss << j;
					location->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Adding the location node to the enemy node
					enemyXPN->addChild(location);

					//Creating an endpath node
					XmlParserNode * endPath = new XmlParserNode();
					
					//Setting the title of the endpath node
					endPath->setTitle("endPath");

					//Creating a singleton node of the endpath node
					endPath->setEndTag();

					//Setting the attribute x of the endpath node
					oss << enemy->getEndPoint('x');
					endPath->setAttribute("x",oss.str());
					oss.str("");
					oss.clear();
					
					//Setting the attribute y of the endpath node
					oss << enemy->getEndPoint('y');
					endPath->setAttribute("y",oss.str());
					oss.str("");
					oss.clear();

					//Adding the endpath node to the enemy node
					enemyXPN->addChild(endPath);

					//Adding the enemy node to the enemies node
					enemies->addChild(enemyXPN);
				}
			}
		}
	}

	//Adding the blocks node to the level node
	level->addChild(blocks);

	//Adding the pipes node to the level node
	level->addChild(pipes);

	//Adding the grounds node to the level node
	level->addChild(grounds);

	//Adding the castles node to the level node
	level->addChild(castles);

	//Adding the enemies node to the root node
	root->addChild(enemies);

	//Adding the level node to the root node
	root->addChild(level);

	//Creating a xml string from the root
	string xml = root->toXML(0);
	ofstream myfile;

	//Opening the file saveGame.xml, if it doesn't exist than it will be created
	myfile.open ("res/levels/saveGame.xml");

	//Filling the file with the xml string
	myfile << "<?xml version=\"1.0\"?>" << endl << xml;
	
	//Closing the file
	myfile.close();

	//Deleting the root node
	delete root;
	root = NULL;
}

void XmlParser::parse(string fileLocation){
	file = fopen(fileLocation.c_str(), "r");
	buffer = new char[100];
	tagNamesLength = 0;
	int lineNumber = 0;
	ostringstream oss;
	
	//Creating a reference to the current node
	XmlParserNode * currentNode;
	
	//If there is no file
	if (file == NULL) parseError("Error opening file");
	else{
		//While end of file is not there
		while (!feof(file))
		{
			//If current row in file is empty
			if(fgets(buffer, 100, file) == NULL) break;
			
			//Putting the current row in the buffer
			fputs(buffer, stdout);

			//Creating a string of the buffer;
			string line = buffer;
			string cleanLine;

			lineNumber++;

			int closingTagStart = -1;
			int beginningTagStart = -1;
			int singletonTagEnd = -1;
			int beginningTagEnd = -1;

			//Index of closing tag "</node>"
			closingTagStart = line.find("</");
			
			//If closing tag doesn't exist
			if(closingTagStart == -1){
				//Index of opening tag "<node>"
				beginningTagStart = line.find("<");

				//Removing start tag
				cleanLine = line.substr(beginningTagStart, line.length());
				beginningTagStart = 0;
			}
			else{
				//Removing closing start tag
				cleanLine = line.substr(closingTagStart, line.length());
				closingTagStart = 1;
			}
			//Index of singleton end tag "<node/>"
			singletonTagEnd = cleanLine.find("/>");

			//If singleton end tag doesn't exist
			if(singletonTagEnd == -1){
				//Index of end tag "<node>"
				beginningTagEnd = cleanLine.find(">");
			}
			//Index of first whiteSpace
			int firstWhiteSpace = cleanLine.find(" ");
			
			string tagName;

			//If closing start tag exist "</node>"
			if(closingTagStart > -1){
				//Getting the tagname "node"
				tagName = cleanLine.substr(closingTagStart + 1, beginningTagEnd - 2);

				//If tagname doesn't equals superMario
				if(tagName != "superMario"){
					//If the current tagname equals the last tagname
					if(tagNames[tagNamesLength - 1] == tagName){
						//Removing the last tagname
						tagNames[tagNamesLength - 1] = "";
						tagNamesLength--;

						//Current node is the current node it's parent
						currentNode = currentNode->getParent();
					}
					//If the current tagname doesn't equals the last tagname
					else{
						//Give error message
						oss << "The tagName \"" << tagName << "\" doesn't match \"" << tagNames[tagNamesLength - 1] << "\" at line " << lineNumber;
						parseError(oss.str());
						oss.str("");
						oss.clear();
						break;
					}
				}
			}
			//If opening start tag exist "<node>"
			else if(beginningTagStart > -1){
				string remaining;

				//If firstWhiteSpace doesn't exist and the singleton end tag doesn't exist
				if(firstWhiteSpace == -1 && singletonTagEnd == -1){
					tagName = cleanLine.substr(beginningTagStart + 1, beginningTagEnd - 1);
				}
				//If firstWhiteSpace doesn't exist and the singleton end tag exist
				else if(firstWhiteSpace == -1 && singletonTagEnd > -1){
					tagName = cleanLine.substr(beginningTagStart + 1, singletonTagEnd - 1);
				}
				else{
					tagName = cleanLine.substr(beginningTagStart + 1, firstWhiteSpace - 1);
					//If first character equals ?
					if(tagName[0] == '?')
						continue;
					//If end tag exist "<node>"
					if(beginningTagEnd > -1)
						remaining = cleanLine.substr(firstWhiteSpace + 1, beginningTagEnd - firstWhiteSpace - 1);
					else
						remaining = cleanLine.substr(firstWhiteSpace + 1, singletonTagEnd - firstWhiteSpace - 1);
				}

				//If tagname equals superMario
				if(tagName == "superMario"){
					//Setting the root node
					root = new XmlParserNode();

					//Setting the title of the root node
					root->setTitle(tagName);

					//Setting the current node to the root node
					currentNode = root;
				}
				else{

					XmlParserNode * xpn;
					//If singleton end tag exist "<node/>"
					if(singletonTagEnd > -1){
						//Creating new node
						xpn = new XmlParserNode();

						//Setting the title for the new node
						xpn->setTitle(tagName);

						//Creating a singleton tag of the new node
						xpn->setEndTag();

						//If there are attributes
						if(remaining.length() > 0){
							//Infinite loop
							while (true)
							{
								//The index of the next whitespace
								int whiteSpace = remaining.find(" ");
								int quote;
								string key;
								string attrValue;
								string attribute;

								//If there is no whitespace
								if(whiteSpace == -1){
									attribute = remaining;

									//The index of the " character
									quote = attribute.find("\"");

									//The key name of the attribute
									key = attribute.substr(0, attribute.find("="));
									
									//The value of the attribute
									attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 2);

									//Setting the attribute for the new node
									xpn->setAttribute(key, attrValue);
									break;
								}

								//The next attribute string
								attribute = remaining.substr(0, whiteSpace - 1);
								
								//The index of the "character
								quote = attribute.find("\"");

								//The key name of the attribute
								key = attribute.substr(0, attribute.find("="));
								
								//The value of the attribute
								attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 1);

								//Setting the attribute of the new node
								xpn->setAttribute(key,attrValue);

								//Removing the attribute of the string
								remaining = remaining.substr(whiteSpace + 1, remaining.length() - whiteSpace);
							}
						}

						//Adding the new node to the current node
						currentNode->addChild(xpn);
					}
					//If node is normal start node "<node>"
					else{
						tagNames[tagNamesLength] = tagName;
						tagNamesLength++;

						//Creating a new node
						xpn = new XmlParserNode();
						
						//Setting the title of the node
						xpn->setTitle(tagName);

						//If there attributes
						if(remaining.length() > 0){
							//Infinite loop
							while (true)
							{
								//Finding the next whitespace
								int whiteSpace = remaining.find(" ");
								int quote;
								string key;
								string attrValue;
								string attribute;

								//If there is no whitespace
								if(whiteSpace == -1){
									attribute = remaining;
									
									//The index of the " character
									quote = attribute.find("\"");

									//The key name of the attribute
									key = attribute.substr(0, attribute.find("="));
									
									//The value of the attribute
									attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 2);

									//Setting the attribute to the new node
									xpn->setAttribute(key, attrValue);
									break;
								}
								//The next attribute string
								attribute = remaining.substr(0, whiteSpace - 1);
								
								//The index of the " character
								quote = attribute.find("\"");

								//The key name of the attribute
								key = attribute.substr(0, attribute.find("="));
								
								//The value of the attribute
								attrValue = attribute.substr(quote + 1, (attribute.length() - quote) - 1);


								//Setting the attribute to the new node
								xpn->setAttribute(key,attrValue);

								//Removing the attribute of the string
								remaining = remaining.substr(whiteSpace + 1, remaining.length() - whiteSpace);
							}
						}

						//Adding the new node to the current node
						currentNode->addChild(xpn);

						//Current node is new node
						currentNode = xpn;
					}
				}
			}
			//There is no superMario root node
			else{
				//Give error
				parseError("There is no beginning!");
				break;
			}
		}
		fclose(file);
	}
}

void XmlParser::parseError(string eMessage){
	//Show error
	MessageBox(NULL, eMessage.c_str(),"Error", NULL);
}

XmlParserNode * XmlParser::getNode(string tagName){
	//Getting the node by tagname
	XmlParserNode * xpn = root->getNode(tagName);
	return xpn;
}

void XmlParser::Clear(){
	//Deleting the buffer
	if (buffer != NULL)
		delete buffer;

	//Deleting the root node
	if (root != NULL)
		delete root;

	file = NULL;
	buffer = NULL;
	root = NULL;
}

XmlParser::~XmlParser(){
	Clear();
}