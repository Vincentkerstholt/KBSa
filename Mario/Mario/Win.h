#ifndef WIN_H
#define WIN_H

#include <windows.h>
#include <StdAfx.h>

class CWin
{
private:
	HDC hDC;
	HANDLE hBuf;
	RECT rect;
	INT64 start, stop, freq;

protected:
	static HINSTANCE m_hInstance;
	HWND  m_hWnd;
	
	DWORD m_PosX;
	DWORD m_PosY;
	DWORD m_dwWindowStyle;
	DWORD m_dwExWindowStyle;
 	DWORD m_dwCreationFlags;
	DWORD m_dwCreationHeight;
	DWORD m_dwCreationWidth;
	TCHAR * m_strWindowTitle;
	HBRUSH m_hbrWindowColor;
	HICON  m_hIcon;
	HMENU  m_hMenu;
	HACCEL m_hAccelTable;
	HDC graphics;
	int fps;

public:
	 CWin();
	 HRESULT Create();
	 int Run();
	 virtual ~CWin();
	 virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	 virtual void GameInit() = 0;
	 virtual void GameLoop() = 0;
	 virtual void GameEnd() = 0;
	 void SetFPS(int);
};

#endif
