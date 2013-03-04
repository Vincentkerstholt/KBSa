#include "Win.h"
#include <tchar.h>

//////////////////////////////////////////////////////////////////
// Static Initialisation
//////////////////////////////////////////////////////////////////
static CWin * g_pCWin		= NULL;
HINSTANCE CWin::m_hInstance = GetModuleHandle(NULL);

//////////////////////////////////////////////////////////////////
// Connectivity WIN32 -> Class
//////////////////////////////////////////////////////////////////
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_pCWin->MsgProc(hWnd, uMsg, wParam, lParam);
}

//////////////////////////////////////////////////////////////////
// Constructors/Destructors
//////////////////////////////////////////////////////////////////
CWin::CWin()
{
	g_pCWin		 = this;

	this->m_hWnd = NULL;
	this->m_dwCreationFlags		= 0L;
	this->m_dwWindowStyle		= WS_OVERLAPPEDWINDOW;
	this->m_dwExWindowStyle		= WS_EX_OVERLAPPEDWINDOW;
	this->m_dwCreationFlags		= SW_MAXIMIZE;
	this->m_PosX				= CW_USEDEFAULT;	
	this->m_PosY				= CW_USEDEFAULT;	
	this->m_dwCreationWidth		= CW_USEDEFAULT;
	this->m_dwCreationHeight	= CW_USEDEFAULT;
	this->m_hbrWindowColor		= (HBRUSH)(COLOR_WINDOW+1);
	this->m_hIcon				= LoadIcon(m_hInstance, (LPCTSTR)IDI_APPLICATION);
	this->m_strWindowTitle		= _T("Super Mario!");
	this->m_hMenu				= NULL; 	

	::QueryPerformanceFrequency((LARGE_INTEGER*)&freq);

	fps = freq;
}

CWin::~CWin()
{
}


//////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////
int CWin::Run()
{
	MSG msg = {0};

	GameInit();

	while(msg.message != WM_QUIT)
	{
		if (::PeekMessage(&msg, NULL, 0u, 0u, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			::QueryPerformanceCounter((LARGE_INTEGER*)&start);
			stop = start;
			while(stop - start < freq/fps)
				::QueryPerformanceCounter((LARGE_INTEGER*)&stop);

			::FillRect(graphics, &rect, (HBRUSH)RGB(255,255,255));
			GameLoop();
			::BitBlt(hDC, rect.left, rect.top, rect.right, rect.bottom, graphics, 0, 0, SRCCOPY);
		}
	}

	GameEnd();

	return msg.wParam;
}

HRESULT CWin::Create()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInstance;
	wcex.hIcon			= m_hIcon;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= m_hbrWindowColor;
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= _T("Skeleton");
	wcex.hIconSm		= NULL;

	::RegisterClassEx(&wcex);

	m_hWnd = ::CreateWindowEx(m_dwExWindowStyle,_T("Skeleton"), m_strWindowTitle, m_dwWindowStyle,
	  m_PosX, m_PosY, m_dwCreationWidth, m_dwCreationHeight, NULL, m_hMenu, m_hInstance, NULL);

	if (!m_hWnd)
	{
	  return FALSE;
	}

	::ShowWindow(m_hWnd, m_dwCreationFlags);

	hDC = ::GetDC(m_hWnd);
	::GetClientRect(m_hWnd, &rect);
	hBuf = ::CreateCompatibleBitmap(hDC, rect.right, rect.bottom);
	graphics = ::CreateCompatibleDC(hDC);
	::SelectObject(graphics, hBuf);

	::UpdateWindow(m_hWnd);

	return TRUE;

}

LRESULT CWin::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	int wmId;
	int wmEvent;

	if (!m_hWnd)
		m_hWnd = hWnd;

	switch (uMsg) 
	{
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			break;
		case WM_ERASEBKGND:
			return true;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
   }
   return 0;
}

void CWin::SetFPS(int fps)
{
	if (fps > 0 && fps <= freq)
		this->fps = fps;
}