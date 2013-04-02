#ifndef Skeleton_H
#define Skeleton_H

#include "Win.h"
#include <sstream>
#include "Gamestate.h"

using namespace std;

class Gamestate;

class CSkeleton : public CWin
{
private:
	Gamestate * gameState;
	bool debugMode;
	HANDLE splashscreenBitmap;
	HDC hSplashscreenDC;
	BITMAP bitmap;
	bool startUp;
	int loop;
public:
	CSkeleton();
	~CSkeleton();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void GameInit();
	bool GameLoop();
	void GameEnd(); 
};

#endif
