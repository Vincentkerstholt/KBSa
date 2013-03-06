#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
	gameState = new Gamestate(200, 22);
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

	gameState->draw(graphics, debugMode);

	if (::GetAsyncKeyState(VK_RIGHT)){
		gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());
		if(gameState->Mario->textureNumber == 8)
		{
			gameState->Mario->textureNumber = 1;
		}
		else
		{
			gameState->Mario->textureNumber += 1;
		}
	}

	if (::GetAsyncKeyState(VK_LEFT)){
		gameState->Mario->Move('L', gameState->Mario->GetPositionPixel());
	}

	if (::GetAsyncKeyState(VK_DOWN)){
		gameState->Mario->Move('D', gameState->Mario->GetPositionPixel());
	}

	if (::GetAsyncKeyState(VK_UP)){
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

