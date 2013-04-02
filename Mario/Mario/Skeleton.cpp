#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
	splashscreenBitmap = LoadImage(NULL, "res/splashscreen.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	gameState = new Gamestate();
}

 CSkeleton::~CSkeleton()
{
	delete gameState;
	gameState = NULL;
}

void CSkeleton::GameInit()
{
	startUp = true;
	gameState->inMenu = false;
	debugMode = false;
	SetFPS(60);
	SetBkMode(graphics,TRANSPARENT);
	loop = 0;
}

bool CSkeleton::GameLoop()
{
	RECT rect;
	POINT mario , MarioUp, MarioDown;
	::GetClientRect(m_hWnd, &rect);

	if(startUp && loop == 0){
		hSplashscreenDC = CreateCompatibleDC(graphics);

		GetObject(splashscreenBitmap, sizeof(BITMAP), &bitmap);
		SelectObject(hSplashscreenDC, splashscreenBitmap);

		BitBlt(graphics,0,0,1362,702,hSplashscreenDC,0,0,SRCCOPY);

		DeleteDC(hSplashscreenDC);
	}
	else if(startUp && loop > 0)
	{
		Sleep(2000);

		startUp = false;
		gameState->inMenu = true;
		return gameState->getQuit();
	}
 	else if (gameState->inMenu)
 	{
 		gameState->menu(graphics);
 		return gameState->getQuit();
 	}
	else
		gameState->draw(graphics, debugMode);

	if (::GetAsyncKeyState(VK_RIGHT))
	{		
		gameState->Mario->side = "Right";
		gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());

	}
	if (::GetAsyncKeyState(VK_LEFT))
	{	
		gameState->Mario->side = "Left";
		gameState->Mario->Move('L', gameState->Mario->GetPositionPixel());		
	}

	if (::GetAsyncKeyState(VK_DOWN))
	{
		gameState->Mario->Move('D', gameState->Mario->GetPositionPixel());
	}

	if (::GetAsyncKeyState(VK_UP))
	{
		gameState->Mario->Move('U', gameState->Mario->GetPositionPixel());
	}

	if (::GetAsyncKeyState(VK_F1))
		gameState->changeFactory('D');

	if (::GetAsyncKeyState(VK_F2))
		gameState->changeFactory('L');

	if (::GetAsyncKeyState(VK_F3))
		gameState->changeFactory('S');

	if (::GetAsyncKeyState(VK_F4))
		gameState->changeFactory('C');

	if (::GetAsyncKeyState(VK_F12)){
		debugMode = !debugMode;
		Sleep(200);
	}

	if (::GetAsyncKeyState(VK_ESCAPE)){
		if(gameState->inMenu != true)
		{
			gameState->inMenu = true;
			Sleep(200);
		}
	}
	
	loop++;

	return gameState->getQuit();
}

void CSkeleton::GameEnd() 
{

}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

LRESULT CSkeleton::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return CWin::MsgProc(hWnd, uMsg, wParam, lParam);
}
