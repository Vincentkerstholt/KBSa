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
	SetFPS(60);
}

void CSkeleton::GameLoop()
{
	RECT rect;
	::GetClientRect(m_hWnd, &rect);
	gameState->drawBackground(graphics);
	gameState->drawGrid(graphics);
	gameState->drawCharacters(graphics);
	if (::GetAsyncKeyState(VK_RIGHT)){
		int onzin = 0;
	}

	if (::GetAsyncKeyState(VK_LEFT)){

	}

	if (::GetAsyncKeyState(VK_DOWN)){

	}

	if (::GetAsyncKeyState(VK_UP)){

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

