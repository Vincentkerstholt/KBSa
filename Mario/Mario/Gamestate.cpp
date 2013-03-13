#include "Gamestate.h"

Gamestate::Gamestate()
{
	xml = new XmlParser("res/Landscape.xml");

	XmlParserNode * levelXml = xml->getNode("level");
	string width = levelXml->getAttribute("width");
	string height = levelXml->getAttribute("height");
	int x = stoi( width );
	int y = stoi( height );

	this->x = x;
	this->y = y;

	Mario = new Hero();

	multiplier = 32;
	hBackgroundBitmap = LoadImage(NULL, "res/backgroundSky.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	hBackgroundBitmap2 = LoadImage(NULL, "res/backgroundhills.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	level = new Gameobject*[(x * y)];

	XmlParserNode * factoryXml = xml->getNode("factory");
	factory = getFactory(factoryXml->getAttribute("name"));

	frames = 0;
	curTime = 0;
	fps = 0;

	CreateWorld();
}

void Gamestate::draw(HDC & hdc, bool debugMode)
{
	camera.setXMidPosition(Mario->GetPositionPixel().x);
	drawBackground(hdc);
	drawCharacters(hdc);
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

	TransparentBlt(hdc, (Mario->GetPositionPixel().x)- camera.getXPosition(), (Mario->GetPositionPixel().y), 32, 32, hCharacterDC, (Mario->textureNumber*multiplier), 0, 32,32, GetPixel(hCharacterDC, 0,0));

	DeleteDC(hCharacterDC);
}

void Gamestate::drawBackground(HDC & hdc){
	hBackgroundBitmap = factory->getBackgroundImage();
	

	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap);

	StretchBlt(hdc, 0, 0, ConvertIndexToXY(43), ConvertIndexToXY(22), hBackgroundDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	
	DeleteDC(hBackgroundDC);

	hBackgroundBitmap2 = factory->getBackgroundImage2();
	hBackgroundDC = CreateCompatibleDC(hdc);

	GetObject(hBackgroundBitmap2, sizeof(BITMAP), &bitmap);
	SelectObject(hBackgroundDC, hBackgroundBitmap2);

	TransparentBlt(hdc, -camera.getXPosition()/2%bitmap.bmWidth,				230, bitmap.bmWidth,bitmap.bmHeight, hBackgroundDC, 0, 0, bitmap.bmWidth,bitmap.bmHeight, GetPixel(hBackgroundDC, 0,0));
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

				BitBlt(hdc, ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32, 32, hObstacleDC, 0, 0, SRCCOPY);
			}
			else if(level[index]->getClassName() == "Pipe")
			{
				hObstacleBitmap = factory->getPipe();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
			}
			else if(level[index]->getClassName() == "Ground")
			{
				Ground * ground = (Ground*)level[index];
				hObstacleBitmap = factory->getGround();

				hObstacleDC = CreateCompatibleDC(hdc);

				GetObject(hObstacleBitmap, sizeof(BITMAP), &bitmap);
				SelectObject(hObstacleDC, hObstacleBitmap);

				string textTureType = ground->getTextureType();

				if(textTureType == "topleft")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,0,32,32,RGB(255,174,201));
				}
				else if(textTureType == "topcenter")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,34,0,32,32,RGB(255,174,201));
				}
				else if(textTureType == "topright")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,68,0,32,32,RGB(255,174,201));
				}
				else if(textTureType == "centerleft")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,34,32,32,RGB(255,174,201));
				}
				else if(textTureType == "centercenter")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,34,34,32,32,RGB(255,174,201));
				}
				else if(textTureType == "centerright")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,68,34,32,32,RGB(255,174,201));
				}
				else if(textTureType == "bottomleft")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,0,68,32,32,RGB(255,174,201));
				}
				else if(textTureType == "bottomcenter")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,34,68,32,32,RGB(255,174,201));
				}
				else if(textTureType == "bottomright")
				{
					TransparentBlt(hdc,ConvertIndexToXY(n) - camera.getXPosition(), ConvertIndexToXY(m), 32,32,hObstacleDC,68,68,32,32,RGB(255,174,201));
				}
			}
			
			DeleteDC(hObstacleDC);
			//DeleteObject(hObstacleBitmap);
		}
	}

}

void Gamestate::drawStatistics(HDC & hdc){
	

	int xValue = this->Mario->GetPositionPixel().x;
	int yValue = this->Mario->GetPositionPixel().y;
	ostringstream oss;

	oss << "Pos. Mario: " << xValue << " " << yValue;
	TextOut(hdc, 10, 10, oss.str().c_str(), strlen(oss.str().c_str()));
	oss.str("");
	oss.clear();

	oss << "screen position: " << camera.getXPosition();
	TextOut(hdc, 10, 30, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");
	oss.clear();

	frames++;
	if (curTime != time(NULL))
	{
		curTime = time(NULL);
		fps = frames;
		frames = 0;
	}

	oss << "fps: " << fps;
	TextOut(hdc, 10, 50, oss.str().c_str(), strlen(oss.str().c_str()));

	oss.str("");
	oss.clear();
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
			level[index] = NULL;
		}
	}

	XmlParserNode * blocks = xml->getNode("blocks");
	XmlParserNode ** childs = blocks->getChilds();

	for(int i = 0; i < blocks->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));
		level[index] = new Block(0,0);
	}

	XmlParserNode * grounds = xml->getNode("grounds");
	childs = grounds->getChilds();
	for(int i = 0; i < grounds->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));
		level[index] = new Ground(0,0, child->getAttribute("type"));
	}

	XmlParserNode * pipes = xml->getNode("pipes");
	childs = pipes->getChilds();
	for(int i = 0; i < pipes->getChildsLength(); i++){
		XmlParserNode * child = childs[i];
		XmlParserNode * childLocation = child->getNode("location");
		int index = getIndex(stoi(childLocation->getAttribute("x")), stoi(childLocation->getAttribute("y")));
		level[index] = new Pipe(0,0);
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