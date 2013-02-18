#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
}

CSkeleton::~CSkeleton()
{
}

void CSkeleton::GameInit()
{
	SetFPS(60);
}

void CSkeleton::GameLoop()
{
	RECT rect;
	::GetClientRect(m_hWnd, &rect);

	if (::GetAsyncKeyState(VK_RIGHT)){

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

