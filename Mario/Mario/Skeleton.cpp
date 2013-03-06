#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
	gameState = new Gamestate(43, 22);
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
	gameState->drawCharacters(graphics);
	gameState->drawWorld(graphics);
	if(debugMode)
	{
		gameState->drawGrid(graphics);
		gameState->drawStatistics(graphics);
	}
	if(::GetAsyncKeyState(VK_RIGHT)){
		gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());
	}

	else if (::GetAsyncKeyState(VK_LEFT)){
		gameState->Mario->Move('L', gameState->Mario->GetPositionPixel());
	}

	else if (::GetAsyncKeyState(VK_DOWN)){
		gameState->Mario->Move('D', gameState->Mario->GetPositionPixel());
	}

	else if (::GetAsyncKeyState(VK_UP)){
		gameState->Mario->Move('U', gameState->Mario->GetPositionPixel());
	}

	else if(gameState->Mario->getDirection() == 'R') {
		gameState->Mario->setTexturePosition(0,0);
	}
	else if(gameState->Mario->getDirection() == 'L') {
		gameState->Mario->setTexturePosition(14,0);
	}
	else {
		gameState->Mario->setTexturePosition(0,0);
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