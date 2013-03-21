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
	SetBkMode(graphics,TRANSPARENT);
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
		mario = gameState->Mario-> GetPositionPixel();
		if ( 0 < mario.y && mario.y < 670)
		{

			//gameState->Mario->setTexturePosition(1,1);
			MarioDown.x = ((mario.x+33)/32);
			MarioDown.y = ((mario.y+31)/32);
			MarioUp.x = ((mario.x+33)/32);
			MarioUp.y = ((mario.y)/32);

			string DownPoint = gameState->BoxCheck(gameState->getIndex(MarioDown.x,MarioDown.y));
			string UpPoint = gameState->BoxCheck(gameState->getIndex(MarioUp.x,MarioUp.y));

			if (DownPoint == "Block" || UpPoint == "Block")
			{
				int onzin  = 1;		
			}
			else if (DownPoint == "Ground" || UpPoint == "Ground")
			{

			}
			else
			{

				gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());
			}
		}
	}
	if (::GetAsyncKeyState(VK_LEFT))
	{
		mario = gameState->Mario-> GetPositionPixel();
		if ( 0 < mario.y && mario.y < 670)
		{
			//gameState->Mario->setTexturePosition(1,0);
			MarioDown.x = ((mario.x-1)/32);
			MarioDown.y = ((mario.y+31)/32);
			MarioUp.x = ((mario.x-1)/32);
			MarioUp.y = ((mario.y)/32);

			string DownPoint = gameState->BoxCheck(gameState->getIndex(MarioDown.x,MarioDown.y));
			string UpPoint = gameState->BoxCheck(gameState->getIndex(MarioUp.x,MarioUp.y));
	

			if (DownPoint == "Block" || UpPoint == "Block")
			{
		
			}		
			else if (DownPoint == "Ground" || UpPoint == "Ground")
			{

			}
			else
			{
				gameState->Mario->Move('L', gameState->Mario->GetPositionPixel());
			}
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
