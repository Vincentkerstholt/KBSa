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
public:
	CSkeleton();
	~CSkeleton();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void GameInit();
	void GameLoop();
	void GameEnd(); 
};

#endif
