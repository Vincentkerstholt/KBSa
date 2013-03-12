#include "Gamestate.h"

Gamestate::Gamestate(int x, int y)
{
	this->x = x;
	this->y = y;
	
	Mario = new Hero();
	multiplier = 32;
	hBackgroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);

	level = new Gameobject*[(x * y)];
	factory = new LandThemeFactory();

	multiplier = 32;
	frames = 0;

	CreateWorld();
}

void Gamestate::draw(HDC & hdc, bool debugMode)
{

	frames++;
	camera.setXMidPosition(Mario->GetPositionPixel().x);
	DownCollision();
	drawBackground(hdc);
	drawCharacters(hdc);
	drawWorld(hdc);
	if (debugMode == true)
	{
		drawGrid(hdc);
		drawStatistics(hdc);
	}
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
	LineTo(hdc, ConvertIndexToXY(x)- camera.getXPosition()%multiplier, ConvertIndexToXY(23));
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
	TransparentBlt(hdc, (Mario->GetPositionPixel().x), (Mario->GetPositionPixel().y), 32, 32, hCharacterDC, (Mario->getTexturePosition().x*multiplier), Mario->getTexturePosition().y*multiplier, 32,32, GetPixel(hCharacterDC, 0,0));
	DeleteDC(hCharacterDC);
}

void Gamestate::drawStatistics(HDC & hdc){
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
	oss.clear();

}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();

	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, ConvertIndexToXY(43), ConvertIndexToXY(22), hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	DeleteDC(hBackgroundDC);
	DeleteObject(hBackgroundBitmap);
}

void Gamestate::drawWorld(HDC & hdc){
	for(int n = camera.getXPosition()/32; n < camera.getXPosition()/32 + 44  && n < x; n++){
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);
			if(level[index] == NULL)
				continue;
			if(level[index]->getClassName() == "Block")
			{
				hObstacleBitmap = factory->getBlock(n, m);

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				BitBlt(hdc, ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32, 32, hObstacleDC, 68, 50, SRCCOPY);

				DeleteDC(hObstacleDC);
				DeleteObject(hObstacleBitmap);
			}

			else if(level[index]->getClassName() == "Pipe")
				hObstacleBitmap = factory->getPipe(n, m);
			else if(level[index]->getClassName() == "Ground")
			{
				hObstacleBitmap = factory->getGround(n, m);

			hObstacleDC = CreateCompatibleDC(hdc);

			GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
			SelectObject(hObstacleDC, hObstacleBitmap);

			BitBlt(hdc, ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32, 32, hObstacleDC, 68, 0, SRCCOPY);

			DeleteDC(hObstacleDC);
			DeleteObject(hObstacleBitmap);
			}
		}
	}
}

void Gamestate::changeFactory(char firstLetter){
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

void Gamestate::CreateWorld(){
	for(int n = 0; n < x; n++)
	{
		for(int m = 0; m < y; m++){
			int index = getIndex(n,m);

			if(m == y-1 && n == 10 )
				level[index] = NULL;
			else if(m == y-3 && n == 2 )
				level[index] = new Block(68,0);
			else if(m == y-2 && n == 15 )
				level[index] = new Ground(68,0);
			else if(m == y-1 )
				level[index] = new Ground(68,0);
			else
				level[index] = NULL;
		}
	}
}

Gamestate::~Gamestate(){
	delete [] level;
	level = NULL;

	delete factory;
	factory = NULL;
}

void Gamestate::DownCollision()
{
	POINT mario;
	POINT mario1;
	POINT mario2;
	POINT mario3;
	POINT mario4;
	int marioindex = 0 , marioindex2 = 0, marioindex3 = 0 , marioindex4 = 0;
	//down
	mario = Mario->GetPositionPixel();
	mario1.x = ((mario.x+31)/32);
	mario1.y = ((mario.y+33)/32);
	mario2.x = ((mario.x+2)/32);
	mario2.y = ((mario.y+33)/32);
	//up
	mario3.x = ((mario.x+31)/32);
	mario3.y = ((mario.y)/32);
	mario4.x = ((mario.x+2)/32);
	mario4.y = ((mario.y)/32);

	marioindex = getIndex(mario1.x,mario1.y);
	marioindex2 = getIndex(mario2.x,mario2.y);
	marioindex3 = getIndex(mario3.x,mario3.y);
	marioindex4 = getIndex(mario4.x,mario4.y);


	string check = BoxCheck(marioindex);
	string check2 = BoxCheck(marioindex2);
	string check3 = BoxCheck(marioindex3);
	string check4 = BoxCheck(marioindex4);
	
	if ( mario.y < 670)
	{
		if(Mario->Jumped < Mario->JumpHeight )
		{
			Mario->JumpAbility = true;
		}

		if (check3 == "Block" || check4 == "Block")
		{
			Mario->JumpAbility = false;
						
		}

		if (check == "NULL" && check2 == "NULL" )
		{
			if (Mario->Jumped == 0)
			{
				Mario->JumpAbility = false;
			}
			Mario->SetPosition(mario.x, (mario.y+8));
		}
		else
		{
			Mario->Jumped=0;
			Mario->JumpAbility = true;
		}
		
	}
	else
	{
		Mario->JumpAbility = false;
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

	return type;
	
}

