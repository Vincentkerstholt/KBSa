#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{


	gameState = new Gamestate();


}

 CSkeleton::~CSkeleton()
{
	delete gameState;
	gameState = NULL;
}

void CSkeleton::GameInit()
{
	debugMode = false;
	SetFPS(60);
}

void CSkeleton::GameLoop()
{
	
	RECT rect;
	POINT mario , MarioUp, MarioDown;
	::GetClientRect(m_hWnd, &rect);

	if (gameState->inMenu)
	{
		gameState->menu(graphics);
		return;
	}
	

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

	if (::GetAsyncKeyState(VK_DOWN)){
		gameState->Mario->Move('D', gameState->Mario->GetPositionPixel());
	}

	if (::GetAsyncKeyState(VK_UP))
	{
	
		gameState->Mario->Move('U', gameState->Mario->GetPositionPixel());

	}

	if (::GetAsyncKeyState(VK_F1)){
		gameState->changeFactory('D');
	}

	if (::GetAsyncKeyState(VK_F2)){
		gameState->changeFactory('L');
	}

	if (::GetAsyncKeyState(VK_F3)){
		gameState->changeFactory('S');
	}

	if (::GetAsyncKeyState(VK_F4)){
		gameState->changeFactory('W');
	}

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
