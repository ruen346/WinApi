//해더 모음집//
#include "variable.h"
#include "basic.h"


CImage character[3];


//////////////////////////////////////////////
CImage ch1_run_upper_sp[35];
CImage ch1_run_lower_sp[35];

CImage ch1_ready_upper_sp[41];
CImage ch1_ready_lower_sp[41];

CImage ch1_jump_upper_sp[41];
CImage ch1_jump_lower_sp[41];

CImage ch1_forH_strong_upper_sp[30];
CImage ch1_forH_middle_upper_sp[30];
CImage ch1_forH_weak_upper_sp[30];
CImage ch1_forH_charge_upper_sp[41];

CImage ch1_backH_strong_upper_sp[30];
CImage ch1_backH_middle_upper_sp[30];
CImage ch1_backH_weak_upper_sp[30];
CImage ch1_backH_charge_upper_sp[41];

CImage ch1_skill1_sp[21];

CImage ch1_walk_lower[41];

CImage ch1_stay_lower_sp;

//////////////////////////////////////////////
CImage ch2_run_upper_sp[35];
CImage ch2_run_lower_sp[35];

CImage ch2_ready_upper_sp[41];
CImage ch2_ready_lower_sp[41];

CImage ch2_jump_upper_sp[41];
CImage ch2_jump_lower_sp[41];

CImage ch2_forH_strong_upper_sp[30];
CImage ch2_forH_middle_upper_sp[30];
CImage ch2_forH_weak_upper_sp[30];
CImage ch2_forH_charge_upper_sp[41];

CImage ch2_backH_strong_upper_sp[30];
CImage ch2_backH_middle_upper_sp[30];
CImage ch2_backH_weak_upper_sp[30];
CImage ch2_backH_charge_upper_sp[41];

CImage ch2_skill1_sp[21];

CImage ch2_walk_lower[41];

CImage ch2_stay_lower_sp;


CImage ball_sp;
CImage back;
CImage charge;


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
		character[2].Load(LoadText);

		for (int i = 0; i < 35; i++)
		{
			sprintf(LoadText, "sprite\\run\\upper\\skeleton-1-run_%d.png", i);
			ch1_run_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\run\\lower\\skeleton-1-run_%d.png", i);
			ch1_run_lower_sp[i].Load(LoadText);

			//////////////////////////////////////////////

			sprintf(LoadText, "sprite\\ch2\\run\\upper\\skeleton-2-run_%d.png", i);
			ch2_run_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\run\\lower\\skeleton-2-run_%d.png", i);
			ch2_run_lower_sp[i].Load(LoadText);
		}

		for (int i = 0; i < 41; i++)
		{
			sprintf(LoadText, "sprite\\ready\\upper\\skeleton-1-ready_%d.png", i);
			ch1_ready_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ready\\lower\\skeleton-1-ready_%d.png", i);
			ch1_ready_lower_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\jump\\upper\\skeleton-1-jump_%d.png", i);
			ch1_jump_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\jump\\lower\\skeleton-1-jump_%d.png", i);
			ch1_jump_lower_sp[i].Load(LoadText);

			sprintf(LoadText, "sprite\\forH_charge\\skeleton-1-forHcharge_%d.png", i);
			ch1_forH_charge_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\backH_charge\\skeleton-1-backH_charge_%d.png", i);
			ch1_backH_charge_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\walk_lower\\skeleton-1-forHcharge_%d.png", i);
			ch1_walk_lower[i].Load(LoadText);

			//////////////////////////////////////////////

			sprintf(LoadText, "sprite\\ch2\\ready\\upper\\skeleton-2-ready_%d.png", i);
			ch2_ready_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\ready\\lower\\skeleton-2-ready_%d.png", i);
			ch2_ready_lower_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\jump\\upper\\skeleton-2-jump_%d.png", i);
			ch2_jump_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\jump\\lower\\skeleton-2-jump_%d.png", i);
			ch2_jump_lower_sp[i].Load(LoadText);

			sprintf(LoadText, "sprite\\ch2\\forH_charge\\skeleton-2-forH_charge_%d.png", i);
			ch2_forH_charge_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\backH_charge\\skeleton-2-backH_charge_%d.png", i);
			ch2_backH_charge_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\walk_lower\\skeleton-2-forH_charge_%d.png", i);
			ch2_walk_lower[i].Load(LoadText);
		}

		for (int i = 0; i < 30; i++)
		{
			sprintf(LoadText, "sprite\\forH_strong\\skeleton-1-forH_strong_%d.png", i);
			ch1_forH_strong_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\forH_middle\\skeleton-1-forH_middle_%d.png", i);
			ch1_forH_middle_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\forH_weak\\skeleton-1-forH_weak_%d.png", i);
			ch1_forH_weak_upper_sp[i].Load(LoadText);

			if(i < 14)
				sprintf(LoadText, "sprite\\backH_strong\\skeleton-1-backH_strong_%d.png", i);
			else
				sprintf(LoadText, "sprite\\backH_strong\\skeleton-1-backH_strong_%d.png", i + 14);
			ch1_backH_strong_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\backH_middle\\skeleton-1-backH_middle_%d.png", i);
			ch1_backH_middle_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\backH_weak\\skeleton-1-backH_weak_%d.png", i);
			ch1_backH_weak_upper_sp[i].Load(LoadText);

			//////////////////////////////////////////////

			sprintf(LoadText, "sprite\\ch2\\forH_strong\\skeleton-2-forH_strong_%d.png", i);
			ch2_forH_strong_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\forH_middle\\skeleton-2-forH_middle_%d.png", i);
			ch2_forH_middle_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\forH_weak\\skeleton-2-forH_weak_%d.png", i);
			ch2_forH_weak_upper_sp[i].Load(LoadText);

			if (i < 14)
				sprintf(LoadText, "sprite\\ch2\\backH_strong\\skeleton-2-backH_strong_%d.png", i);
			else
				sprintf(LoadText, "sprite\\ch2\\backH_strong\\skeleton-2-backH_strong_%d.png", i + 14);
			ch2_backH_strong_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\backH_middle\\skeleton-2-backH_middle_%d.png", i);
			ch2_backH_middle_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\ch2\\backH_weak\\skeleton-2-backH_weak_%d.png", i);
			ch2_backH_weak_upper_sp[i].Load(LoadText);
		}

		for (int i = 14; i < 34; i++)
		{
			sprintf(LoadText, "sprite\\skill1\\skeleton-1-skill1_%d.png", i);
			ch1_skill1_sp[i - 14].Load(LoadText);

			//////////////////////////////////////////////

			sprintf(LoadText, "sprite\\ch2\\skill1\\skeleton-2-skill1_%d.png", i);
			ch2_skill1_sp[i - 14].Load(LoadText);
		}

		sprintf(LoadText, "sprite\\stay_lower.png");
		ch1_stay_lower_sp.Load(LoadText);

		//////////////////////////////////////////////

		sprintf(LoadText, "sprite\\ch2\\stay_lower.png");
		ch2_stay_lower_sp.Load(LoadText);



		sprintf(LoadText, "sprite\\ball.png");
		ball_sp.Load(LoadText);

		sprintf(LoadText, "sprite\\back.png");
		back.Load(LoadText);

		sprintf(LoadText, "sprite\\charge.png");
		charge.Load(LoadText);


		//변수 초기화//
		srand(time(NULL));

		ch1.x = 200;
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
			//-------------------AI-start------------------//

			if (play_mod == 1)
			{
				if (ball.move == 0 && turn == 1) //서브
				{
					if (ch2.x < 1920 / 2 + 150) //서브할만한 위치이동
					{
						ch2.left = 0;
						ch2.right = 1;
					}
					else if(ch2.x > 1920 - 700) //서브할만한 위치이동
					{
						ch2.left = 1;
						ch2.right = 0;
					}
					else if (ch2.plays == 0 && ch2.charge_now == 0)//차지
					{
						ch2.left = 0;
						ch2.right = 0;

						ch2.charge = 1;
						ch2.charge_now = 1;
						ch2.charge_what = 2;
						SetTimer(hWnd, 5, 250, NULL);
						ai_charge = rand() % 2 + 1;
					}
					else if (ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1 && ch2.charge == ai_charge)//서브발사
					{
						ch2.charge_now = 0;
						ch2.charge_what = 0;
						ch2.play = 2;
						ch2.plays = 2;
						ch2.play1_charge_sp = 0;
						ai_charge = 0;
					}
				}
				else if (ball.move != 2)//코트에서 너무 나갔을때 다시 부르기
				{
					if (ch2.x + start_x < 1920 / 2 + 150)
						ch2.right = 1;
					else
						ch2.right = 0;

					if (ch2.x + start_x > 1920 - 250)
						ch2.left = 1;
					else
						ch2.left = 0;
				}

				if (ball.move == 2)//스윙관련
				{
					if (ball.x > 1920 / 2)//위치잡기
					{
						if (ball.x > ch2.x + start_x - 25)
						{
							ch2.left = 0;
							ch2.right = 1;
						}
						else if (ball.x < ch2.x + start_x - 100)
						{
							ch2.left = 1;
							ch2.right = 0;
						}
						else
						{
							ch2.left = 0;
							ch2.right = 0;
						}
					}
					if (ball.speed > 25 || ball.x > 1920 / 2 + 450 || (ball.speed < 15 && ball.gravity < -5))//포핸드차지
					{
						if (ball.x > 1920 / 2 && ball.y > 480 + start_y - 180 && ch2.plays == 0 && ch2.charge_now == 0 && ball.gravity < 0)//차지
						{
							ch2.charge = 1;
							ch2.charge_now = 1;
							ch2.charge_what = 1;
							SetTimer(hWnd, 5, 250, NULL);
						}
					}
					else//백핸드차지
					{
						if (ball.x > 1920 / 2 && ball.y > 480 + start_y - 140 && ch2.plays == 0 && ch2.charge_now == 0 && ball.gravity < 0)//차지
						{
							ch2.charge = 1;
							ch2.charge_now = 1;
							ch2.charge_what = 2;
							SetTimer(hWnd, 5, 250, NULL);
						}
					}
					if (ch2.charge_what == 1)//포핸드
					{
						if (ball.x > ch2.x + start_x - 40 && ball.y > 480 + start_y - 60 && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
						{
							ch2.charge_now = 0;
							ch2.charge_what = 0;
							ch2.play = 1;
							ch2.plays = 1;
							ch2.play1_charge_sp = 0;
						}
					}
					else//백핸드
					{
						if (ball.x > ch2.x + start_x - 80 && ball.y > 480 + start_y - 40 && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
						{
							ch2.charge_now = 0;
							ch2.charge_what = 0;
							ch2.play = 2;
							ch2.plays = 2;
							ch2.play1_charge_sp = 0;
						}
					}
				}
			}

			//--------------------AI-end-------------------//

			//이미지
			if (ch1.run_sp == 34)
				ch1.run_sp = 0;
			else
				ch1.run_sp++;
			if (ch2.run_sp == 34)
				ch2.run_sp = 0;
			else
				ch2.run_sp++;

			if (ch1.ready_sp == 40)
				ch1.ready_sp = 0;
			else
				ch1.ready_sp++;
			if (ch2.ready_sp == 40)
				ch2.ready_sp = 0;
			else
				ch2.ready_sp++;

			if (ch1.plays > 0)
				ch1.play1_sp++;
			if (ch2.plays > 0)
				ch2.play1_sp++;

			if (ch1.charge_now == 1 && ch1.play1_charge_sp < 40)
				ch1.play1_charge_sp++;
			if (ch2.charge_now == 1 && ch2.play1_charge_sp < 40)
				ch2.play1_charge_sp++;

			if (ch1.skill1 > 1 && ch1.skill1_sp < 19)
				ch1.skill1_sp++;
			else if (ch1.skill1_sp >= 19)
			{
				ch1.skill1_sp = 0;
				ch1.skill1 = 0;
			}
			if (ch2.skill1 > 1 && ch2.skill1_sp < 19)
				ch2.skill1_sp++;
			else if (ch2.skill1_sp >= 19)
			{
				ch2.skill1_sp = 0;
				ch2.skill1 = 0;
			}


			//이동
			if (ch1.skill1 == 0)
			{
				if (ch1.left == 1 && ch1.x > (-start_x + 16) && ch1.plays == 0)
				{
					if (ch1.charge_now == 0)
						ch1.x -= 16;
					else
						ch1.x -= 6;
				}
				if (ch1.right == 1 && ch1.x < (1920 / 2 - end_x - 16 - 50/*라켓보정값*/) && ch1.plays == 0)
				{
					if (ch1.charge_now == 0)
						ch1.x += 16;
					else
						ch1.x += 6;
				}
			}

			if (ch2.skill1 == 0)
			{
				if (ch2.left == 1 && ch2.x > (1920 / 2 - start_x + 16 + 50/*라켓보정값*/) && ch2.plays == 0)
				{
					if (ch2.charge_now == 0)
						ch2.x -= 16;
					else
						ch2.x -= 6;
				}
				if (ch2.right == 1 && ch2.x < (1920 - end_x - 16) && ch2.plays == 0)
				{
					if (ch2.charge_now == 0)
						ch2.x += 16;
					else
						ch2.x += 6;
				}
			}


			//중력
			if (ch1.skill1 == 0)
			{
				if (ch1.up == 1 && ch1.gravity >= -30)
				{
					ch1.y -= ch1.gravity;
					ch1.gravity -= 2;
					ch1.jump_sp++;
				}
				else if (ch1.up == 1 && ch1.gravity < -30)
				{
					ch1.gravity = 0;
					ch1.up = 0;
					ch1.jump_sp = 0;
				}
			}

			if (ch2.skill == 0)
			{
				if (ch2.up == 1 && ch2.gravity >= -30)
				{
					ch2.y -= ch2.gravity;
					ch2.gravity -= 2;
					ch2.jump_sp++;
				}
				else if (ch2.up == 1 && ch2.gravity < -30)
				{
					ch2.gravity = 0;
					ch2.up = 0;
					ch2.jump_sp = 0;
				}
			}


			//공 이동, 중력
			if (ch1.skill != 1 && ch2.skill != 1)
			{
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
			}
			if (ch1.x + start_x < ball.x && ch1.x + start_x + 200 > ball.x && ch1.y + start_y + 120 > ball.y && ch1.y + start_y - 80 < ball.y)
			{
				if (ch1.skill1 == 2)
				{
					ball.speed = 70;
					ball.gravity = -18;
					ball.move = 2;
					ch1.skill1_sp = 19;
				}
				else if (ch1.skill1 == 3)
				{
					ball.speed = 80;
					ball.gravity = -16;
					ball.move = 2;
					ch1.skill1_sp = 19;
				}
				else if (ch1.skill1 == 4)
				{
					ball.speed = 90;
					ball.gravity = -14;
					ball.move = 2;
					ch1.skill1_sp = 19;
				}
			}
			if (ch2.x + end_x > ball.x && ch2.x + end_x - 200 < ball.x && ch2.y + start_y + 120 > ball.y && ch2.y + start_y - 80 < ball.y)
			{
				if (ch2.skill1 == 2)
				{
					ball.speed = 70;
					ball.gravity = -18;
					ball.move = 1;
					ch2.skill1_sp = 19;
				}
				else if (ch2.skill1 == 3)
				{
					ball.speed = 80;
					ball.gravity = -16;
					ball.move = 1;
					ch2.skill1_sp = 19;
				}
				else if (ch2.skill1 == 4)
				{
					ball.speed = 90;
					ball.gravity = -14;
					ball.move = 1;
					ch2.skill1_sp = 19;
				}
			}
			if (turn == 0 && ball.move == 0)//서브시 공위치
			{
				ball.x = ch1.x + end_x - 20;
				ball.y = ch1.y + start_y + 80;
			}
			else if (turn == 1 && ball.move == 0)//서브시 공위치
			{
				ball.x = ch2.x + start_x + 20;
				ball.y = ch2.y + start_y + 80;
			}

			if (ball.y + 25 > nete_y)//네트충돌
			{
				if (ball.move == 1)
				{
					if (ball.x < 1920 / 2 + 25)
						ball.speed = -1;
				}
				else if (ball.move == 2)
				{
					if (ball.x > 1920 / 2 + 25)
						ball.speed = -1;
				}
			}

			//스윙
			if (ch1.play == 1)
			{
				if (ch1.x + start_x + 40 < ball.x && ch1.x + start_x + 160 > ball.x && ch1.y + start_y + 80 > ball.y && ch1.y + start_y - 80 < ball.y)
				{
					ball.gravity = ball.play1_gravity(ch1.charge);
					ball.speed = ball.play1_speed(ch1.charge);
					ball.move = 2;
					ball.delta = 100;
				}
				ch1.crash++;
				if (ch1.skill == 2)
				{
					SetTimer(hWnd, 1, prame, NULL);
					ch1.skill = 0;
				}
			}
			else if (ch1.play == 2)
			{
				if (ch1.x + start_x < ball.x && ch1.x + start_x + 160 > ball.x && ch1.y + start_y + 120 > ball.y && ch1.y + start_y + 10 < ball.y)
				{
					ball.gravity = ball.play2_gravity(ch1.charge);
					ball.speed = ball.play2_speed(ch1.charge);
					ball.move = 2;
					ball.delta = 100;
				}
				ch1.crash++;
				if (ch1.skill == 2)
				{
					SetTimer(hWnd, 1, prame, NULL);
					ch1.skill = 0;
				}
			}
			if (ch2.play == 1)
			{
				if (ch2.x + end_x - 40 > ball.x && ch2.x + end_x - 160 < ball.x && ch2.y + start_y + 80 > ball.y && ch2.y + start_y - 80 < ball.y)
				{
					ball.gravity = ball.play1_gravity(ch2.charge);
					ball.speed = ball.play1_speed(ch2.charge);
					ball.move = 1;
					ball.delta = 100;
				}
				ch2.crash++;
				if (ch2.skill == 2)
				{
					SetTimer(hWnd, 1, prame, NULL);
					ch2.skill = 0;
				}
			}
			else if (ch2.play == 2)
			{
				if (ch2.x + end_x > ball.x && ch2.x + end_x - 160 < ball.x && ch2.y + start_y + 120 > ball.y && ch2.y + start_y + 10 < ball.y)
				{
					ball.gravity = ball.play2_gravity(ch2.charge);
					ball.speed = ball.play2_speed(ch2.charge);
					ball.move = 1;
					ball.delta = 100;
				}
				ch2.crash++;
				if (ch2.skill == 2)
				{
					SetTimer(hWnd, 1, prame, NULL);
					ch2.skill = 0;
				}
			}

			if (ch1.crash == 20)
			{
				ch1.play = 0;
				ch1.crash = 0;
			}
			if (ch2.crash == 20)
			{
				ch2.play = 0;
				ch2.crash = 0;
			}
			if (ch1.play1_sp == 30)
			{
				ch1.plays = 0;
				ch1.charge = 0;
				ch1.play1_sp = 0;
			}
			if (ch2.play1_sp == 30)
			{
				ch2.plays = 0;
				ch2.charge = 0;
				ch2.play1_sp = 0;
			}


			//공이 땅에 충돌하였는가?
			if (ball.y > 770 && (ball.x < 0 || (ball.x > 1920 / 2 && ball.x < 1920 - 25)))
			{
				turn = 0;
				score_1++;
				ball.move = 0;

				ch1.play = 0;
				ch1.plays = 0;
				ch1.charge_now = 0;
				ch1.charge_what = 0;
				ch1.charge = 0;
				ch1.crash = 0;
				ch1.skill = 0;
				ch1.skill1 = 0;
				ch1.jump_sp = 0;
				ch1.play1_sp = 0;
				ch1.play1_charge_sp = 0;
				ch1.skill1_sp = 0;

				ch2.play = 0;
				ch2.plays = 0;
				ch2.charge_now = 0;
				ch2.charge_what = 0;
				ch2.charge = 0;
				ch2.crash = 0;
				ch2.skill = 0;
				ch2.skill1 = 0;
				ch2.jump_sp = 0;
				ch2.play1_sp = 0;
				ch2.play1_charge_sp = 0;
				ch2.skill1_sp = 0;

				SetTimer(hWnd, 1, prame, NULL);
			}
			else if (ball.y > 770 && ((ball.x > 0 && ball.x < 1920 / 2 - 25) || ball.x > 1920))
			{
				turn = 1;
				score_2++;
				ball.move = 0;

				ch1.play = 0;
				ch1.plays = 0;
				ch1.charge_now = 0;
				ch1.charge_what = 0;
				ch1.charge = 0;
				ch1.crash = 0;
				ch1.skill = 0;
				ch1.skill1 = 0;
				ch1.jump_sp = 0;
				ch1.play1_sp = 0;
				ch1.play1_charge_sp = 0;
				ch1.skill1_sp = 0;

				ch2.play = 0;
				ch2.plays = 0;
				ch2.charge_now = 0;
				ch2.charge_what = 0;
				ch2.charge = 0;
				ch2.crash = 0;
				ch2.skill = 0;
				ch2.skill1 = 0;
				ch2.jump_sp = 0;
				ch2.play1_sp = 0;
				ch2.play1_charge_sp = 0;
				ch2.skill1_sp = 0;

				SetTimer(hWnd, 1, prame, NULL);
			}

			InvalidateRect(hWnd, NULL, FALSE);
		}break;
		case 4: //차지 ch1
		{
			if (ch1.charge_now == 1)
			{
				if (ch1.charge < 3)
					ch1.charge++;
			}
		}break;
		case 5: //차지 ch2
		{
			if (ch2.charge_now == 1)
			{
				if (ch2.charge < 3)
					ch2.charge++;
			}
		}break;
		}
	}break;

	case  WM_KEYDOWN:
	{
		if (ch1.skill1 == 0)
		{
			if (wParam == 'A' || wParam == 'a')
				ch1.left = 1;
			if (wParam == 'D' || wParam == 'd')
				ch1.right = 1;
			if ((wParam == 'W' || wParam == 'w') && ch1.up == 0 && ch1.plays == 0)
			{
				ch1.up = 1;
				ch1.gravity = 30;
			}
			if ((wParam == 'G' || wParam == 'g') && ch1.plays == 0 && ch1.charge_now == 0)
			{
				ch1.charge = 1;
				ch1.charge_now = 1;
				ch1.charge_what = 1;
				SetTimer(hWnd, 4, 250, NULL);
			}
			if ((wParam == 'H' || wParam == 'h') && ch1.plays == 0 && ch1.charge_now == 0)
			{
				ch1.charge = 1;
				ch1.charge_now = 1;
				ch1.charge_what = 2;
				SetTimer(hWnd, 4, 250, NULL);
			}
			if ((wParam == 'T' || wParam == 't') && ch1.plays == 0 && ch1.charge_now == 0 && ch1.up == 1 && ball.move == 1)
			{
				ch1.skill = 1;
				ch1.skill1 = 1;
			}
			if ((wParam == 'Y' || wParam == 'y') && ch1.skill != 2 && ball.move == 1)
			{
				ch1.skill = 2;
				SetTimer(hWnd, 1, 100, NULL);
			}
		}
		else if (ch1.skill == 1)
		{
			if (ch1.skill1 == 1)
			{
				if (wParam == 'A' || wParam == 'a')
				{
					ch1.skill1 = 2;
					ch1.skill = 0;
				}
				if (wParam == 'D' || wParam == 'd')
				{
					ch1.skill1 = 4;
					ch1.skill = 0;
				}
				if (wParam == 'W' || wParam == 'w')
				{
					ch1.skill1 = 3;
					ch1.skill = 0;
				}
			}
		}

		if (ch2.skill1 == 0)
		{
			if (wParam == VK_LEFT)
				ch2.left = 1;
			if (wParam == VK_RIGHT)
				ch2.right = 1;
			if (wParam == VK_UP && ch2.up == 0 && ch2.plays == 0)
			{
				ch2.up = 1;
				ch2.gravity = 30;
			}
			if (wParam == '1' && ch2.plays == 0 && ch2.charge_now == 0)
			{
				ch2.charge = 1;
				ch2.charge_now = 1;
				ch2.charge_what = 1;
				SetTimer(hWnd, 5, 250, NULL);
			}
			if (wParam == '2' && ch2.plays == 0 && ch2.charge_now == 0)
			{
				ch2.charge = 1;
				ch2.charge_now = 1;
				ch2.charge_what = 2;
				SetTimer(hWnd, 5, 250, NULL);
			}
			if (wParam == '4' && ch2.plays == 0 && ch2.charge_now == 0 && ch2.up == 1 && ball.move == 2)
			{
				ch2.skill = 1;
				ch2.skill1 = 1;
			}
			if (wParam == '5' && ch2.skill != 2 && ball.move == 2)
			{
				ch2.skill = 2;
				SetTimer(hWnd, 1, 100, NULL);
			}
		}
		else if (ch2.skill == 1)
		{
			if (ch2.skill1 == 1)
			{
				if (wParam == VK_LEFT)
				{
					ch2.skill1 = 2;
					ch2.skill = 0;
				}
				if (wParam == VK_RIGHT)
				{
					ch2.skill1 = 4;
					ch2.skill = 0;
				}
				if (wParam == VK_UP)
				{
					ch2.skill1 = 3;
					ch2.skill = 0;
				}
			}
		}
		

		if (wParam == 'p' || wParam == 'P')//임시 공 시작
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
		if ((wParam == 'G' || wParam == 'g') && ch1.plays == 0 && ch1.charge_now == 1)
		{
			ch1.charge_now = 0;
			ch1.charge_what = 0;
			ch1.play = 1;
			ch1.plays = 1;
			ch1.play1_charge_sp = 0;
		}
		if ((wParam == 'H' || wParam == 'h') && ch1.plays == 0 && ch1.charge_now == 1)
		{
			ch1.charge_now = 0;
			ch1.charge_what = 0;
			ch1.play = 2;
			ch1.plays = 2;
			ch1.play1_charge_sp = 0;
		}

		if (wParam == VK_LEFT)
			ch2.left = 0;
		if (wParam == VK_RIGHT)
			ch2.right = 0;
		if (wParam == '1' && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
		{
			ch2.charge_now = 0;
			ch2.charge_what = 0;
			ch2.play = 1;
			ch2.plays = 1;
			ch2.play1_charge_sp = 0;
		}
		if (wParam == '2' && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
		{
			ch2.charge_now = 0;
			ch2.charge_what = 0;
			ch2.play = 2;
			ch2.plays = 2;
			ch2.play1_charge_sp = 0;
		}
	}break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);


		back.Draw(memDC, 0, 0, 1920, 1080, 0, 0, 1920, 1080);
		character[ch1.play].Draw(memDC, ch1.x, ch1.y, 80, 100, 0, 0, 80, 100);//임시
		character[ch2.play].Draw(memDC, ch2.x, ch2.y, 80, 100, 0, 0, 80, 100);//임시
		ball_sp.Draw(memDC, ball.x, ball.y, 25, 25, 0, 0, 25, 25);

		for (int i = 0; i < ch1.charge; i++)
			charge.Draw(memDC, 50 + i * 40, 930, 30, 100, 0, 0, 30, 100);
		for (int i = 0; i < ch2.charge; i++)
			charge.Draw(memDC, 1700 + i * 40, 930, 30, 100, 0, 0, 30, 100);

		//캐릭1 그리기
		if (ch1.skill == 1 && ch1.skill1 == 1)
		{
			ch1_skill1_sp[0].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.skill1 > 1)
		{
			ch1_skill1_sp[ch1.skill1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 1 && ch1.charge == 1)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_forH_weak_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 1 && ch1.charge == 2)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_forH_middle_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 1 && ch1.charge == 3)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_forH_strong_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 2 && ch1.charge == 1)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_backH_weak_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 2 && ch1.charge == 2)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_backH_middle_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.plays == 2 && ch1.charge == 3)
		{
			ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_backH_strong_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.charge_now == 1 && ch1.charge_what == 1)
		{
			ch1_walk_lower[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_forH_charge_upper_sp[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.charge_now == 1 && ch1.charge_what == 2)
		{
			ch1_walk_lower[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_backH_charge_upper_sp[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.up == 1)
		{
			ch1_jump_lower_sp[ch1.jump_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_jump_upper_sp[ch1.jump_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch1.left + ch1.right == 1)
		{
			ch1_run_lower_sp[ch1.run_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_run_upper_sp[ch1.run_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else
		{
			ch1_ready_lower_sp[ch1.ready_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			ch1_ready_upper_sp[ch1.ready_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
		}

		//캐릭2 그리기
		if (ch2.skill == 1 && ch2.skill1 == 1)
		{
			ch2_skill1_sp[0].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.skill1 > 1)
		{
			ch2_skill1_sp[ch2.skill1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 1 && ch2.charge == 1)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_forH_weak_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 1 && ch2.charge == 2)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_forH_middle_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 1 && ch2.charge == 3)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_forH_strong_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 2 && ch2.charge == 1)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_backH_weak_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 2 && ch2.charge == 2)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_backH_middle_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.plays == 2 && ch2.charge == 3)
		{
			ch2_stay_lower_sp.Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_backH_strong_upper_sp[ch2.play1_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.charge_now == 1 && ch2.charge_what == 1)
		{
			ch2_walk_lower[ch2.play1_charge_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_forH_charge_upper_sp[ch2.play1_charge_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.charge_now == 1 && ch2.charge_what == 2)
		{
			ch2_walk_lower[ch2.play1_charge_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_backH_charge_upper_sp[ch2.play1_charge_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.up == 1)
		{
			ch2_jump_lower_sp[ch2.jump_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_jump_upper_sp[ch2.jump_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else if (ch2.left + ch2.right == 1)
		{
			ch2_run_lower_sp[ch2.run_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_run_upper_sp[ch2.run_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}
		else
		{
			ch2_ready_lower_sp[ch2.ready_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
			ch2_ready_upper_sp[ch2.ready_sp].Draw(memDC, ch2.x, ch2.y, size_x, size_y, 0, 0, size_x, size_y);
		}


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
		KillTimer(hWnd, 4);
		KillTimer(hWnd, 5);
		PostQuitMessage(0);
	}break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}