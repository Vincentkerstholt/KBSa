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
	::GetClientRect(m_hWnd, &rect);
	gameState->drawBackground(graphics);
	gameState->drawGrid(graphics);
	gameState->drawCharacters(graphics);
	gameState->drawWorld(graphics);
	if(debugMode)
		gameState->drawGrid(graphics);

	if (::GetAsyncKeyState(VK_RIGHT)){
		int onzin = 0;
	}

	if (::GetAsyncKeyState(VK_LEFT)){

	}

	if (::GetAsyncKeyState(VK_DOWN)){

	}

	if (::GetAsyncKeyState(VK_UP)){

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
		Sleep(50);
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

