#include "Skeleton.h"

/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
CSkeleton::CSkeleton()
{
<<<<<<< HEAD
	gameState = new Gamestate(200, 22);
=======
	gameState = new Gamestate(40, 22);
>>>>>>> feature-scroll
}

CSkeleton::~CSkeleton()
{
	delete gameState;
	gameState = NULL;
}

void CSkeleton::GameInit()
{
	debugMode = false;
	SetFPS(0);
}

void CSkeleton::GameLoop()
{
	int mariopixX = 0;
	int mariopixY = 0;
	int marioindex = 0, marioindex2 = 0;
	RECT rect;
	POINT mario , mario1;
	::GetClientRect(m_hWnd, &rect);

	gameState->draw(graphics, debugMode);

	if (::GetAsyncKeyState(VK_RIGHT))
	{

		gameState->Mario->setTexturePosition(1,0);
		mario = gameState->Mario-> GetPositionPixel();
		mario.x = ((mario.x+33)/32);
		mario.y = ((mario.y+31)/32);
		marioindex = gameState->getIndex(mario.x,mario.y);


		string check = gameState->BoxCheck(marioindex);

		if (check == "Ground" || check == "Block")
		{
		 int onzin  = 1;		
		}		
		else
		{

			gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());
		}
	}
	if (::GetAsyncKeyState(VK_LEFT))
	{
		gameState->Mario->setTexturePosition(14,0);
		mario = gameState->Mario-> GetPositionPixel();
		mario.x = ((mario.x-1)/32);
		mario.y = ((mario.y+31)/32);
		marioindex = gameState->getIndex(mario.x,mario.y);
	

		string check = gameState->BoxCheck(marioindex);

		if (check == "Ground" || check == "Block")
		{
		
		}		
		else
		{
		gameState->Mario->Move('L', gameState->Mario->GetPositionPixel());
		}
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
		Sleep(60);
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
