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
	gameState->draw(graphics, debugMode);

	if (::GetAsyncKeyState(VK_RIGHT)){
		gameState->Mario->SetPosition((gameState->Mario->GetPosition().x+1),20);
	}

	if (::GetAsyncKeyState(VK_LEFT)){
		gameState->Mario->SetPosition((gameState->Mario->GetPosition().x-1),20);
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

