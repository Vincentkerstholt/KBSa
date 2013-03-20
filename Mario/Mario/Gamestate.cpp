#include "Gamestate.h"

const int multiplier = 32;
const int GROUND_TOPLEFT = 1;
const int GROUND_TOPCENTER = 2;
const int GROUND_TOPRIGHT = 3;
const int GROUND_CENTERLEFT = 4;
const int GROUND_CENTERCENTER = 5;
const int GROUND_CENTERRIGHT = 6;
const int GROUND_BOTTOMLEFT = 7;
const int GROUND_BOTTOMCENTER = 8;
const int GROUND_BOTTOMRIGHT = 9;

const int PIPE_TOPLEFT = 1;
const int PIPE_TOPCENTER = 2;
const int PIPE_TOPRIGHT = 3;
const int PIPE_BOTTOMLEFT = 4;
const int PIPE_BOTTOMCENTER = 5;
const int PIPE_BOTTOMRIGHT = 6;



Gamestate::Gamestate()
{
	CreateWorld(0);

	SpecialSheet = LoadImage(NULL, "res/heart.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	firsttime = false;
	frames = 0;
	curTime = 0;
	fps = 0;
	selector = 0;
}

void Gamestate::draw(HDC & hdc, bool debugMode)
{
	frames++;

	camera.setXMidPosition(Mario->GetPositionPixel().x);
	Collision();
	UpDownCollision();
	drawBackground(hdc);
	drawCharacters(hdc);
	drawHUD(hdc);
	drawWorld(hdc);

	if (debugMode == true)
	{
		drawGrid(hdc);
		drawStatistics(hdc);
	}
}

IThemeFactory * Gamestate::getFactory(string name){
	if(name == "landscape")
		return new LandThemeFactory();
	else if(name == "dungeon")
		return new DungeonThemeFactory();
	else if(name == "sky")
		return new SkyThemeFactory();
	else if(name == "water")
		return new WaterThemeFactory();
	return new LandThemeFactory();
}

int Gamestate::ConvertIndexToXY(int index){
	return (index*multiplier);
}

int Gamestate::getIndex(int n, int m){
	return (m*x)+n;
}

void Gamestate::DrawHorizontalBorder(int y){
	MoveToEx(hdc, ConvertIndexToXY(0), ConvertIndexToXY(y), &point);
	LineTo(hdc, ConvertIndexToXY(43), ConvertIndexToXY(y));
}

void Gamestate::DrawVerticalBorder(int x){
	MoveToEx(hdc, ConvertIndexToXY(x)- camera.getXPosition()%multiplier, ConvertIndexToXY(0), &point);
	LineTo(hdc, ConvertIndexToXY(x)- camera.getXPosition()%multiplier, ConvertIndexToXY(22));
}

void Gamestate::drawGrid(HDC & hdc){
	this->hdc = hdc;
	for (int n = 0; n < 44; n++)
		DrawVerticalBorder(n);

	for(int m = 0; m < 22; m++)
		DrawHorizontalBorder(m);
}

void Gamestate::drawCharacters(HDC & hdc){
	this->hdc = hdc;
	hCharacterDC = CreateCompatibleDC(hdc);
	GetObject(this->Mario->texture, sizeof(BITMAP), &bitmap);
	SelectObject(hCharacterDC, this->Mario->texture);
	TransparentBlt(hdc, (Mario->GetPositionPixel().x - camera.getXPosition()), (Mario->GetPositionPixel().y), 32, 32, hCharacterDC, (Mario->getTexturePosition().x*multiplier), Mario->getTexturePosition().y*multiplier, 32,32, GetPixel(hCharacterDC, 0,0));
	DeleteDC(hCharacterDC);
}

void Gamestate::drawStatistics(HDC & hdc){
	SetBkMode(hdc,TRANSPARENT);
	int xValue = this->Mario->GetPositionPixel().x;
	int yValue = this->Mario->GetPositionPixel().y;
	ostringstream oss;

	oss << xValue << " " << yValue;
	TextOut(hdc, 10, 10, "Pos. Mario: ", 16);
	TextOut(hdc, 85, 10, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	int xValueTexture = this->Mario->getTexturePosition().x;
	int yValueTexture = this->Mario->getTexturePosition().y;
	oss << xValueTexture << " " << yValueTexture;
	TextOut(hdc, 10, 30, "TexturePos. Mario: ", strlen("TexturePos. Mario: "));
	TextOut(hdc, 140, 30, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	oss << Mario->getDirection();
	TextOut(hdc, 10, 50, "Direction Mario: ", strlen("Direction Mario: "));
	TextOut(hdc, 120, 50, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");

	POINT p;
	GetCursorPos(&p);

	oss << "Cursor X: " << (p.x-3) << " Y: " << (p.y-26);
	TextOut(hdc,  10, 70, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");

	oss << "Cursor X: " << (p.x-3) << " Y: " << (p.y-26);
	TextOut(hdc,  10, 70, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");
	oss.clear();

}

void Gamestate::drawHUD(HDC & hdc){
	SetBkMode(hdc,TRANSPARENT);
	ostringstream oss;

	oss << "Coins: " << Mario->getCoins() ;
	TextOut(hdc, 600, 10, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	oss << "Lives: " << Mario->getLives() ;
	TextOut(hdc, 600, 30, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");

	SIZE imgSize;

	hLivesDC = CreateCompatibleDC(hdc);
	GetObject(SpecialSheet, sizeof(BITMAP), &bitmap);
	SelectObject(hLivesDC, SpecialSheet);

	imgSize.cx = bitmap.bmWidth;
	imgSize.cy = bitmap.bmHeight;


	int x = 660;
	for (int i = 0; i < Mario->getLives(); i++)
	{
		TransparentBlt(hdc, x, 30, 16, 16, hLivesDC, 0, 0, 32, 32, RGB(255,174,201));
		x += 18;
	}

	DeleteDC(hLivesDC);
}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();
	
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, 1362, 702, hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	
	DeleteDC(hBackgroundDC);

	hBackgroundBitmap2 = factory->getBackgroundImage2();
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap2, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap2);

	TransparentBlt(hdc, -camera.getXPosition()/2%bitmap.bmWidth, 230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	TransparentBlt(hdc, bitmap.bmWidth - camera.getXPosition() / 2 % bitmap.bmWidth, 230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
	DeleteDC(hBackgroundDC);
}

void Gamestate::drawWorld(HDC & hdc){

	for(int n = camera.getXPosition()/32; n < camera.getXPosition()/32 + 44  && n < x; n++){
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			if(level[index] == NULL)
			continue;

			
			if(level[index]->getClassName() == "Block")
			{
				hObstacleBitmap = factory->getBlock();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				Block * block = (Block *)level[index];

				int blockX = block->getPosX() * 34;
				int blockY = 0;
				
				if(!block->getIsSpecial())
					blockY = 32;
				
				TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,blockX,blockY,32,32,RGB(255,174,201));
			}
			else if(level[index]->getClassName() == "Pipe")
			{
				Pipe * pipe = (Pipe*)level[index];
				hObstacleBitmap = factory->getPipe();
				
				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);
				
				int textTureType = pipe->getTextureType();

				switch(textTureType)
				{
				case PIPE_TOPLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
					break;

				case PIPE_TOPCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,0,32,32,RGB(255,174,201));
					break;

				case PIPE_TOPRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,0,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,32,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,32,32,32,RGB(255,174,201));
					break;

				case PIPE_BOTTOMRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,32,32,32,RGB(255,174,201));
					break;
				}
			}
			else if(level[index]->getClassName() == "Ground")
			{
				Ground * ground = (Ground*)level[index];
				hObstacleBitmap = factory->getGround();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				int textTureType = ground->getTextureType();

				switch(textTureType){
				case GROUND_TOPLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
					break;

				case GROUND_TOPCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,0,32,32,RGB(255,174,201));
					break;

				case GROUND_TOPRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,0,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,32,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,32,32,32,RGB(255,174,201));
					break;

				case GROUND_CENTERRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,32,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMLEFT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,64,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMCENTER:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,32,64,32,32,RGB(255,174,201));
					break;

				case GROUND_BOTTOMRIGHT:
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,64,64,32,32,RGB(255,174,201));
					break;
				}
			}
			else if(level[index]->getClassName() == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[index];
				hObstacleBitmap = factory->getGoomba();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				TransparentBlt(hdc, (goomba->GetPositionPixel().x - camera.getXPosition()), (goomba->GetPositionPixel().y), 32, 32, hObstacleDC, (goomba->getTexturePosition().x*multiplier), goomba->getTexturePosition().y*multiplier, 32,32, RGB(255,174,201));
				UpdateEnemy(index);
								
			}
			
			DeleteDC(hObstacleDC);
			//DeleteObject(hObstacleBitmap);
		}
	}

}

void Gamestate::changeFactory(char firstLetter){
	factory->delImage();
	factory = NULL;
	switch(firstLetter){
	case 'D':
		factory = new DungeonThemeFactory();
		break;
	case 'L':
		factory = new LandThemeFactory();
		break;
	case 'S':
		factory = new SkyThemeFactory();
		break;
	case 'W':
		factory = new WaterThemeFactory();
		break;
	}
}

void Gamestate::CreateWorld(int number){
	firsttime = false;
	switch(number)
	{
	case 0:
		xml = new XmlParser("res/Landscape.xml");
	break;
	case 1:
		xml = new XmlParser("res/Landscape2.xml");
	break;
	default:
	break;
	}

	XmlParserNode * levelXml = xml->getNode("level");
	x = stoi( levelXml->getAttribute("width") );
	y = stoi( levelXml->getAttribute("height") );

	level = new Gameobject*[(x * y)];

	for(int n = 0; n < x; n++)
	{
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			level[index] = NULL;
		}
	}

	XmlParserNode * marioXml = xml->getNode("hero");

	Mario = new Hero();

	int xMario = stoi(marioXml->getAttribute("x"));
	int yMario = stoi(marioXml->getAttribute("y"));

	Mario->SetPosition(xMario * 32, yMario * 32);

	XmlParserNode * factoryXml = xml->getNode("factory");
	factory = getFactory(factoryXml->getAttribute("name"));

	XmlParserNode * blocks = xml->getNode("blocks");
	XmlParserNode ** childs = blocks->getChilds();

	for(int i = 0; i < blocks->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));

		if (child->getAttribute("isSpecial") == "true")
			level[index] = new Block(true);
		else
			level[index] = new Block(false);
	}

	XmlParserNode * grounds = xml->getNode("grounds");
	childs = grounds->getChilds();
	for(int i = 0; i < grounds->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int x = stoi(childLocation->getAttribute("x"));
		int y = stoi(childLocation->getAttribute("y"));
		int index = getIndex(x, y);
		level[index] = new Ground(0,0, stoi(child->getAttribute("type")));
	}

	XmlParserNode * pipes = xml->getNode("pipes");
	childs = pipes->getChilds();
	for(int i = 0; i < pipes->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));
		level[index] = new Pipe(stoi(child->getAttribute("type")));
	}

	XmlParserNode * enemies = xml->getNode("enemies");
	childs = enemies->getChilds();
	for(int i = 0; i < enemies->getChildsLength(); i++)
	{
		XmlParserNode * child = childs[i];

		XmlParserNode * childLocation = child->getNode("location");
		XmlParserNode * childEndPath = child->getNode("endPath");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));

		if(child->getAttribute("character") == "goomba")
		{
			POINT P;
			level[index] = new Goomba(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")), stoi(childEndPath->getAttribute("x")), stoi(childEndPath->getAttribute("y")));
			Goomba * goomba = (Goomba*)level[index];
			P.x = goomba->getStartPoint('x') *32;	
			P.y = goomba->getStartPoint('y') *32;	
			level[index] = NULL;
			goomba->Move('R', P);
			level[getIndex(goomba->GetPositionIndex())] = goomba;
		}
	}
}

void Gamestate::menu(HDC & hdc)
{
	Sleep(100);

	if(GetAsyncKeyState(VK_UP))	{
		selector--;
	}
	if(GetAsyncKeyState(VK_DOWN))	{
		selector++;
	}
	if (GetAsyncKeyState(VK_ESCAPE))	{
		if(inMenu == false)
		{
			Sleep(150);
			inMenu = true;
		}
	}

	//clear the async key to prevent interacting with the game while in menu
	GetAsyncKeyState(VK_RIGHT);
	GetAsyncKeyState(VK_LEFT);
	GetAsyncKeyState(VK_F1);
	GetAsyncKeyState(VK_F2);
	GetAsyncKeyState(VK_F3);
	GetAsyncKeyState(VK_F4);
	GetAsyncKeyState(VK_F12);



	if (selector < 0)
		selector = 0;
	if (selector > 3)
		selector = 3;

	if (GetAsyncKeyState(VK_RETURN))
	{
		switch (selector)
		{
		case 0:
			// reset lvl
			destroyWorld();
			CreateWorld(1);
			inMenu = false;
		break;
		case 1:
			//save game
		break;
		case 2:
			//load game
		break;
		case 3:
			{
				//Continue game
				int lives = Mario->getLives();
				if(lives > 0)
				{
					inMenu = false;
				}
			}
			break;
		default:
		break;
		}
	}

	hBackgroundBitmap = LoadImage(NULL, "res/menu.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	BitBlt(hdc,0,0,1362,702,hBackgroundDC,0,0,SRCCOPY);

	DeleteObject(hBackgroundBitmap);

	hBackgroundBitmap = LoadImage(NULL, "res/Arrows.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);
	TransparentBlt(hdc,365 , 110 + (selector * 75) , bitmap.bmWidth , bitmap.bmHeight,hBackgroundDC,0,0,bitmap.bmWidth,bitmap.bmHeight,GetPixel(hBackgroundDC,0,0));
	
	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap);
}

void Gamestate::destroyWorld()
{
	int index = 0;
	for(int i = 0 ; i < x ; i++)
	{
		for (int j = 0 ; j < y ; j++)
		{
			index = getIndex(i,j);
			if (level[index] != NULL)
			{
				delete level[index];
				level[index] = NULL;
			}
		}
	}
}

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;

	delete factory;
	factory = NULL;
	delete xml;
	xml = NULL;
}

void Gamestate::UpDownCollision()
{
	/* This collision detection is based on points. This function checks for every point in witch tile it is and what's in that tile.
	*/

	POINT mario;
	POINT MarioRightFeet;
	POINT MarioLeftFeet;
	POINT MarioRightHead;
	POINT MarioLeftHead;
	POINT MarioMidHead;
	BOOL selfjump;

	selfjump=false;

	//down points for collision
	mario = Mario->GetPositionPixel();
	MarioRightFeet.x = ((mario.x+23)/32); // Rightfeet x
	MarioRightFeet.y = ((mario.y+32)/32); //rightfeet y
	MarioLeftFeet.x = ((mario.x+ 4)/32); //left feet x
	MarioLeftFeet.y = ((mario.y+32)/32); //left feet y
	//up point for collision
	MarioRightHead.x = ((mario.x+23)/32); //Righthead x
	MarioRightHead.y = ((mario.y)/32); //Righthead y
	MarioLeftHead.x = ((mario.x+4)/32); //Lefthead x
	MarioLeftHead.y = ((mario.y)/32); //leftthead y
	MarioMidHead.x = ((mario.x+16)/32);
	MarioMidHead.y = ((mario.y)/32);
	
	if (mario.y < 662 && mario.y > 0 )
	{
	string RightFeet = BoxCheck(getIndex(MarioRightFeet.x,MarioRightFeet.y));
	string LeftFeet = BoxCheck(getIndex(MarioLeftFeet.x,MarioLeftFeet.y));
	string RightHead = BoxCheck(getIndex(MarioRightHead.x,MarioRightHead.y));
	string LeftHead = BoxCheck(getIndex(MarioLeftHead.x,MarioLeftHead.y));
	string MidHead = BoxCheck(getIndex(MarioMidHead.x,MarioMidHead.y));
		
		
		if (RightHead == "Block" || LeftHead == "Block" )
		{			
			int index = getIndex(MarioMidHead.x,MarioMidHead.y);
			delete level[index];
			level[index] = NULL;
			Mario->JumpAbility = false;
			Mario->Jumped = 15;	
			
		}

		else if (RightHead == "Ground" || LeftHead == "Ground" )
		{			
		Mario->JumpAbility = false; 	
		Mario->Jumped = 15;	
	
		}
				
		else if (RightFeet == "Goomba" || LeftFeet == "Goomba" )
		{

			if (RightFeet == "Goomba")
			{
					Goomba * goomba = (Goomba*)level[getIndex(MarioRightFeet.x,MarioRightFeet.y)];
					POINT goom = goomba->GetPositionPixel();
					POINT mari = Mario->GetPositionPixel();
					mari.y = goom.y - mari.y;
					mari.x = goom.x - mari.x;
					
					if(mari.y < 33)
					{
						if(mari.x < 20)
						{
						delete level[getIndex(MarioRightFeet.x,MarioRightFeet.y)];
						level[getIndex(MarioRightFeet.x,MarioRightFeet.y)]= NULL;
						Mario->SetPosition(mario.x, (mario.y-32)); // let mario jump

						selfjump=true;
						}
					
					}
			}
			else if (LeftFeet == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.y = goom.y - mari.y;
				mari.x = goom.x - mari.x;

				if(mari.y < 33)
				{
					if(mari.x < 20)
					{
					delete level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)];
					level[getIndex(MarioLeftFeet.x,MarioLeftFeet.y)]= NULL;
					Mario->SetPosition(mario.x, (mario.y-32)); // let mario jump

					selfjump=true;
					}
					
				}
			}
		}
		
		if (RightFeet == "NULL" && LeftFeet == "NULL" ) // if there is no block below mario
		{
			if(Mario->Jumped == 0)
			{
			Mario->JumpAbility = false;
			}
			else
			{
			Mario->JumpAbility = true;
			}
			if(selfjump)
			{
			Mario->JumpAbility = true;
			}
			Mario->SetPosition(mario.x, (mario.y+4)); // let mario fall
			/*}*/
		}
		else
		{
			Mario->Jumped=0; // if there is no air below, let mario jump again. 
			Mario->JumpAbility = true; 
		}
		
	}
	else
	{
		if ( mario.y < 662) // if mario is not at the ground, so must be at the top of the level.
		{
			Mario->Jumped = 15; // max jump position. Mario can't jump anymore
			Mario->SetPosition(mario.x, (mario.y+4)); // let mario fall
		}
		else
		{
			HeroDie();
		}
		Mario->JumpAbility = false; // stop mario from jumping 
	}	
}

string Gamestate::BoxCheck(int index)
{
	string type;
	if (level[index] != NULL)
	{
		type = level[index]->getClassName();
	}
	else
	{
	type = "NULL";
	}

	/*if (type=="Block")  //preparation for the special check
	{ 
	level[index]->
	}*/

	return type;
	
}

void Gamestate::HeroDie()
{
	
	if(Mario->getLives() == 0)
	{
		Mario->Die();
		inMenu = true;
	}
	else
	{
		
		int lives = Mario->getLives();
		destroyWorld();
		CreateWorld(1);
		Mario->Die();
		Mario->setLives(lives);
	}
}

void Gamestate::Collision()
{
	POINT mario , MarioUp, MarioDown;
	mario = Mario->GetPositionPixel();
	if ( 0 < mario.y && mario.y < 670)
	{

		//gameState->Mario->setTexturePosition(1,1);
		MarioDown.x = ((mario.x+28)/32);
		MarioDown.y = ((mario.y+31)/32);
		MarioUp.x = ((mario.x+28)/32);
		MarioUp.y = ((mario.y)/32);

		string DownPoint = BoxCheck(getIndex(MarioDown.x,MarioDown.y));
		string UpPoint = BoxCheck(getIndex(MarioUp.x,MarioUp.y));

		if (DownPoint == "Block" || UpPoint == "Block")
		{
			int onzin  = 1;		
			Mario->MoveAbilityR = false;
			
		}
		else if (DownPoint == "Ground" || UpPoint == "Ground")
		{
			Mario->MoveAbilityR = false;
		}
		else if (DownPoint == "Pipe" || UpPoint == "Pipe")
		{
			Mario->MoveAbilityR = false;
		}
		else if (DownPoint == "Goomba" || UpPoint == "Goomba")
		{
			if(DownPoint == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioDown.x,MarioDown.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.x = goom.x - mari.x;
				if(mari.x < 15)
				{
					HeroDie();
				}
				else
				{
					Mario->MoveAbilityR = true;
				}
			}
			else if(UpPoint == "Goomba")
			{
				Goomba * goomba = (Goomba*)level[getIndex(MarioUp.x,MarioUp.y)];
				POINT goom = goomba->GetPositionPixel();
				POINT mari = Mario->GetPositionPixel();
				mari.x = goom.x - mari.x;
				if(mari.x < 15)
				{
					HeroDie();
				}
				else
				{
					Mario->MoveAbilityR = true;
				}
			}
		}
		else
		{
			Mario->MoveAbilityR = true;
			
		}
	}


	mario = Mario->GetPositionPixel();
	if ( 0 < mario.y && mario.y < 670)
	{
		
		MarioDown.x = ((mario.x+2)/32);
		MarioDown.y = ((mario.y+31)/32);
		MarioUp.x = ((mario.x+2)/32);
		MarioUp.y = ((mario.y)/32);

		string DownPoint = BoxCheck(getIndex(MarioDown.x,MarioDown.y));
		string UpPoint = BoxCheck(getIndex(MarioUp.x,MarioUp.y));


		if (DownPoint == "Block" || UpPoint == "Block")
		{
			Mario->MoveAbilityL = false;
		}		
		else if (DownPoint == "Ground" || UpPoint == "Ground")
		{
			Mario->MoveAbilityL = false;
		}
		else if (DownPoint == "Pipe" || UpPoint == "Pipe")
		{
			Mario->MoveAbilityL = false;
		}
		else if (DownPoint == "Goomba" || UpPoint == "Goomba")
		{
			HeroDie();
		}
		else
		{
			Mario->MoveAbilityL = true;
		}
	}

}

void Gamestate::UpdateEnemy(int index)
{
	Goomba * goomba = (Goomba*)level[index];
		
		if (goomba->GetPositionIndex().x > goomba->getEndPoint('x') && goomba->getDirection() == 'R')
		{
			goomba->setDirection('L');
		}
		if (goomba->GetPositionIndex().x < goomba->getStartPoint('x') && goomba->getDirection() == 'L')
		{
			goomba->setDirection('R');
		}
		
			level[getIndex(goomba->GetPositionIndex())] = NULL;
			goomba->Move(goomba->getDirection(), goomba->GetPositionPixel());
			level[getIndex(goomba->GetPositionIndex())] = goomba;


}

int Gamestate::getIndex(POINT & pnt)
{
	return (pnt.y*x)+pnt.x;
}