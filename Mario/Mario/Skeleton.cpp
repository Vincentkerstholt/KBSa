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
	SetFPS(0);
}

void CSkeleton::GameLoop()
{
	int mariopixX = 0;
	int mariopixY = 0;
	int marioindex = 0, marioindex2 = 0;
	RECT rect;
	POINT mario , mario1, mario2;
	::GetClientRect(m_hWnd, &rect);

	if (gameState->inMenu)
	{
		gameState->menu(graphics);
		return;
	}
	

	gameState->draw(graphics, debugMode);

	if (::GetAsyncKeyState(VK_RIGHT))
	{

		gameState->Mario->setTexturePosition(1,1);
		mario = gameState->Mario-> GetPositionPixel();
		mario1.x = ((mario.x+33)/32);
		mario1.y = ((mario.y+31)/32);
		mario2.x = ((mario.x+33)/32);
		mario2.y = ((mario.y)/32);
		marioindex = gameState->getIndex(mario1.x,mario1.y);
		marioindex2 = gameState->getIndex(mario2.x,mario2.y);


		string check = gameState->BoxCheck(marioindex);
		string check2 = gameState->BoxCheck(marioindex2);

		if (check == "Block" || check2 == "Block")
		{
		 int onzin  = 1;		
		}
		else if (check == "Ground" || check2 == "Ground")
		{

		}
		else
		{

			gameState->Mario->Move('R', gameState->Mario->GetPositionPixel());
		}
	}
	if (::GetAsyncKeyState(VK_LEFT))
	{
		gameState->Mario->setTexturePosition(1,0);
		mario = gameState->Mario-> GetPositionPixel();
		mario1.x = ((mario.x-1)/32);
		mario1.y = ((mario.y+31)/32);
		mario2.x = ((mario.x-1)/32);
		mario2.y = ((mario.y)/32);
		marioindex = gameState->getIndex(mario1.x,mario1.y);
		marioindex2 = gameState->getIndex(mario2.x,mario2.y);


		string check = gameState->BoxCheck(marioindex);
		string check2 = gameState->BoxCheck(marioindex2);
	

		if (check == "Block" || check2 == "Block")
		{
		
		}		
		else if (check == "Ground" || check2 == "Ground")
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
		Sleep(200);
	}
	if (::GetAsyncKeyState(VK_ESCAPE)){
		gameState->inMenu = true;
		Sleep(200);
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
