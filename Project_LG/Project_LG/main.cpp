//해더 모음집//
#include "variable.h"
#include "basic.h"


CImage character;
CImage slime;
CImage back;


//윈도우를 위한 기본 코드//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;  MSG Message;  WNDCLASSEX WndClass;  g_hInst = hInstance;
	// 윈도우 클래스 구조체 값 설정  
	WndClass.cbSize = sizeof(WndClass);
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = lpszClass;
	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&WndClass);

	hWnd = CreateWindow(lpszClass, "windows", WS_POPUP, window_start_x, window_start_y, window_x, window_y, NULL, (HMENU)NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}

	return Message.wParam;
}


//본격적인 처리 코드//
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC memdc, hdc, memDC;
	PAINTSTRUCT ps;
	RECT rect;
	char set;
	static SIZE size;
	HPEN hPen, oldPen;
	HBRUSH hBrush, oldBrush;
	static HBITMAP hBitmap;

	switch (uMsg)
	{
	case WM_CREATE:
	{
		//png//
		CHAR LoadText[100];

		sprintf(LoadText, "sprite\\character.png");
		character.Load(LoadText);

		sprintf(LoadText, "sprite\\slime.png");
		slime.Load(LoadText);

		sprintf(LoadText, "sprite\\back.png");
		back.Load(LoadText);
		
		
		//변수 초기화//
		srand(time(NULL));
		
		ch1.x = 500;
		ch1.y = 500;
		ch1.ad = 5;
		ch1.hp = 3000;
		ch1.rehp = 0.1;
		ch1.speed = 5;


		//프레임 설정//
		SetTimer(hWnd, 1, prame, NULL);//기본 프레임


	}break;

	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			if (ch1.up == 1)
				ch1.y -= ch1.speed;
			if (ch1.down == 1)
				ch1.y += ch1.speed;
			if (ch1.left == 1)
				ch1.x -= ch1.speed;
			if (ch1.right == 1)
				ch1.x += ch1.speed;
			InvalidateRect(hWnd, NULL, FALSE);
		}break;
		}
	}break;

	case  WM_KEYDOWN:
	{
		if (wParam == 'W' || wParam == 'w')
			ch1.up = 1;
		if (wParam == 'S' || wParam == 's')
			ch1.down = 1;
		if (wParam == 'A' || wParam == 'a')
			ch1.left = 1;
		if (wParam == 'D' || wParam == 'd')
			ch1.right = 1;
	}break;

	case  WM_KEYUP:
	{
		if (wParam == 'W' || wParam == 'w')
			ch1.up = 0;
		if (wParam == 'S' || wParam == 's')
			ch1.down = 0;
		if (wParam == 'A' || wParam == 'a')
			ch1.left = 0;
		if (wParam == 'D' || wParam == 'd')
			ch1.right = 0;
	}break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);


		back.Draw(memDC, 0, 0, 1920, 1080, 0, 0, 1920, 1080);
		slime.Draw(memDC, 500, 600, 65, 43, 0, 0, 130, 86);
		character.Draw(memDC, ch1.x, ch1.y, 48, 90, 0, 0, 48, 90);


		BitBlt(hdc, 0, 0, window_x, window_y, memDC, 0, 0, SRCCOPY);
		DeleteDC(memDC);
		DeleteObject(hBitmap);
		EndPaint(hWnd, &ps);

	}break;

	case WM_LBUTTONDOWN:
	{

	}break;

	case WM_MOUSEMOVE:
	{
		mouse_x = LOWORD(lParam);
		mouse_y = HIWORD(lParam);
	}break;

	case WM_DESTROY:
	{
		KillTimer(hWnd, 1);
		PostQuitMessage(0);
	}break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}