#ifndef Skeleton_H
#define Skeleton_H

#include "Win.h"
#include <sstream>
#include "Gamestate.h"

using namespace std;

class CSkeleton : public CWin
{
private:
	Gamestate * gameState;
	bool debugMode;
public:
	CSkeleton();
	~CSkeleton();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);

	void GameInit();
	void GameLoop();
	void GameEnd(); 
};

#endif
