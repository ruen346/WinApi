//해더 모음집//
#include "variable.h"
#include "basic.h"


CImage character[2];
CImage ball_sp;
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

	hWnd = CreateWindow(lpszClass, "Project_BG", WS_POPUP, window_start_x, window_start_y, window_x, window_y, NULL, (HMENU)NULL, hInstance, NULL);

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

		sprintf(LoadText, "sprite\\ch.png");
		character[0].Load(LoadText);
		sprintf(LoadText, "sprite\\ch_swing.png");
		character[1].Load(LoadText);

		sprintf(LoadText, "sprite\\ball.png");
		ball_sp.Load(LoadText);


		sprintf(LoadText, "sprite\\back.png");
		back.Load(LoadText);


		//변수 초기화//
		srand(time(NULL));

		ch1.x = 500;
		ch2.x = 1340;


		//프레임 설정//
		SetTimer(hWnd, 1, prame, NULL);//기본 프레임


	}break;

	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1: //프레임
		{
			//이동
			if (ch1.left == 1)
				ch1.x -= 20;
			if (ch1.right == 1)
				ch1.x += 20;

			if (ch2.left == 1)
				ch2.x -= 20;
			if (ch2.right == 1)
				ch2.x += 20;

			//중력
			if (ch1.up == 1 && ch1.gravity >= -30)
			{
				ch1.y -= ch1.gravity;
				ch1.gravity -= 2;
			}
			else if (ch1.up == 1 && ch1.gravity < -30)
			{
				ch1.gravity = 0;
				ch1.up = 0;
			}

			if (ch2.up == 1 && ch2.gravity >= -30)
			{
				ch2.y -= ch2.gravity;
				ch2.gravity -= 2;
			}
			else if (ch2.up == 1 && ch2.gravity < -30)
			{
				ch2.gravity = 0;
				ch2.up = 0;
			}

			//공 이동, 중력
			if (ball.move != 0)
			{
				if (ball.move == 1)
				{
					ball.x -= ball.speed;
					ball.y -= ball.gravity;
				}
				else if (ball.move == 2)
				{
					ball.x += ball.speed;
					ball.y -= ball.gravity;
				}
				if (ball.delta % 3 > 0)
					ball.gravity--;
				if (ball.speed > 12)
				{
					if (ball.delta % 2 == 0)
						ball.speed--;
					if (ball.delta < 80)
					{
						if (ball.delta % 2 == 1)
							ball.speed--;
					}
				}
				ball.delta--;
			}

			//스윙
			if (ch1.play == 1)
			{
				if (ch1.x < ball.x && ch1.x + 160 > ball.x && ch1.y + 40 > ball.y && ch1.y - 80 < ball.y)
				{
					ball.move = 2;
					ball.gravity = 12;
					ball.speed = 40;
					ball.delta = 100;
				}
			}
			if (ch2.play == 1)
			{
				if (ch2.x + 80 > ball.x && ch2.x - 160 + 80 < ball.x && ch2.y + 40 > ball.y && ch2.y - 80 < ball.y)
				{
					ball.move = 1;
					ball.gravity = 12;
					ball.speed = 40;
					ball.delta = 100;
				}
			}

			InvalidateRect(hWnd, NULL, FALSE);
		}break;
		case 2: //스윙 ch1
		{
			ch1.play = 0;
			KillTimer(hWnd, 2);
		}break;
		case 3: //스윙 ch2
		{
			ch2.play = 0;
			KillTimer(hWnd, 3);
		}break;
		}
	}break;

	case  WM_KEYDOWN:
	{
		if (wParam == 'A' || wParam == 'a')
			ch1.left = 1;
		if (wParam == 'D' || wParam == 'd')
			ch1.right = 1;
		if ((wParam == 'W' || wParam == 'w') && ch1.up == 0)
		{
			ch1.up = 1;
			ch1.gravity = 30;
		}
		if ((wParam == 'G' || wParam == 'g') && ch1.play == 0)
		{
			ch1.play = 1;
			SetTimer(hWnd, 2, 500, NULL);
		}
		if (wParam == VK_LEFT)
			ch2.left = 1;
		if (wParam == VK_RIGHT)
			ch2.right = 1;
		if (wParam == VK_UP && ch2.up == 0)
		{
			ch2.up = 1;
			ch2.gravity = 30;
		}
		if (wParam == '1' && ch2.play == 0)
		{
			ch2.play = 1;
			SetTimer(hWnd, 3, 500, NULL);
		}

		if (wParam == 'p' || wParam == 'P')
		{
			ball.move = 1;
			ball.gravity = 10;
			ball.speed = 40;
			ball.x = 1500;
			ball.y = 600;
			ball.delta = 100;
		}
	}break;

	case  WM_KEYUP:
	{
		if (wParam == 'A' || wParam == 'a')
			ch1.left = 0;
		if (wParam == 'D' || wParam == 'd')
			ch1.right = 0;
		if (wParam == VK_LEFT)
			ch2.left = 0;
		if (wParam == VK_RIGHT)
			ch2.right = 0;
	}break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);


		back.Draw(memDC, 0, 0, 1920, 1080, 0, 0, 1920, 1080);
		character[ch1.play].Draw(memDC, ch1.x, ch1.y, 80, 100, 0, 0, 80, 100);
		character[ch2.play].Draw(memDC, ch2.x, ch2.y, 80, 100, 0, 0, 80, 100);
		ball_sp.Draw(memDC, ball.x, ball.y, 25, 25, 0, 0, 25, 25);


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
		KillTimer(hWnd, 2);
		KillTimer(hWnd, 3);
		PostQuitMessage(0);
	}break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}