//해더 모음집//
#include "variable.h"
#include "basic.h"


//////////////////////////////////////////////
CImage ch1_run_upper_sp[35];
CImage ch1_run_lower_sp[35];
CImage ch1_run_hair_sp[35];

CImage ch1_ready_upper_sp[41];
CImage ch1_ready_lower_sp[41];
CImage ch1_ready_hair_sp[41];

CImage ch1_jump_upper_sp[41];
CImage ch1_jump_lower_sp[41];
CImage ch1_jump_hair_sp[41];

CImage ch1_forH_strong_upper_sp[30];
CImage ch1_forH_strong_hair_sp[30];
CImage ch1_forH_middle_upper_sp[30];
CImage ch1_forH_middle_hair_sp[30];
CImage ch1_forH_weak_upper_sp[30];
CImage ch1_forH_weak_hair_sp[30];
CImage ch1_forH_charge_upper_sp[41];
CImage ch1_forH_charge_hair_sp[41];

CImage ch1_backH_strong_upper_sp[30];
CImage ch1_backH_middle_upper_sp[30];
CImage ch1_backH_weak_upper_sp[30];
CImage ch1_backH_charge_upper_sp[41];

CImage ch1_backH_hair_sp;

CImage ch1_skill1_sp[21];

CImage ch1_walk_lower[41];
CImage ch1_walk_hair[41];

CImage ch1_stay_lower_sp;
CImage ch1_stay_hair_sp;

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


CImage button_sp[4];
CImage buttons_sp[4];
CImage ball_sp[8];
CImage crash_ball_sp;
CImage crash_ball2_sp;
CImage back[2];
CImage charge;

CImage ser_sp[3];
CImage sm_sp[3];
CImage big_sp[6];

CImage burn_sp[2];
CImage perfect_sp;

CImage charge_gauge_sp;

CImage skill_gauge_sp[2];

CImage how_sp[3];

CImage win_sp[3];


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

		for (int i = 0; i < 35; i++)
		{
			sprintf(LoadText, "sprite\\run\\upper\\skeleton-1-run_%d.png", i);
			ch1_run_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\run\\lower\\skeleton-1-run_%d.png", i);
			ch1_run_lower_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\run\\hair\\skeleton-1-run_%d.png", i);
			ch1_run_hair_sp[i].Load(LoadText);

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
			sprintf(LoadText, "sprite\\ready\\hair\\skeleton-1-ready_%d.png", i);
			ch1_ready_hair_sp[i].Load(LoadText);
			
			sprintf(LoadText, "sprite\\jump\\upper\\skeleton-1-jump_%d.png", i);
			ch1_jump_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\jump\\lower\\skeleton-1-jump_%d.png", i);
			ch1_jump_lower_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\jump\\hair\\skeleton-1-jump_%d.png", i);
			ch1_jump_hair_sp[i].Load(LoadText);


			sprintf(LoadText, "sprite\\forH_charge\\skeleton-1-forH_charge_%d.png", i);
			ch1_forH_charge_upper_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\forH_charge\\hair\\skeleton-1-forH_charge_%d.png", i);
			ch1_forH_charge_hair_sp[i].Load(LoadText);
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
			sprintf(LoadText, "sprite\\forH_strong\\hair\\skeleton-1-forH_strong_%d.png", i);
			ch1_forH_strong_hair_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\forH_middle\\hair\\skeleton-1-forH_middle_%d.png", i);
			ch1_forH_middle_hair_sp[i].Load(LoadText);
			sprintf(LoadText, "sprite\\forH_weak\\hair\\skeleton-1-forH_weak_%d.png", i);
			ch1_forH_weak_hair_sp[i].Load(LoadText);

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


		sprintf(LoadText, "sprite\\skeleton-1-backH_charge_0.png");
		ch1_backH_hair_sp.Load(LoadText);
		for (int i = 1; i < 5; i++)
		{
			sprintf(LoadText, "sprite\\button%d.png", i);
			button_sp[i - 1].Load(LoadText);
			sprintf(LoadText, "sprite\\buttons%d.png", i);
			buttons_sp[i - 1].Load(LoadText);
		}

		sprintf(LoadText, "sprite\\서비스off.png");
		ser_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\서비스on1.png");
		ser_sp[1].Load(LoadText);
		sprintf(LoadText, "sprite\\서비스on2.png");
		ser_sp[2].Load(LoadText);
		sprintf(LoadText, "sprite\\작은0.png");
		sm_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\작은1.png");
		sm_sp[1].Load(LoadText);
		sprintf(LoadText, "sprite\\작은2.png");
		sm_sp[2].Load(LoadText);
		sprintf(LoadText, "sprite\\큰0.png");
		big_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\큰1.png");
		big_sp[1].Load(LoadText);
		sprintf(LoadText, "sprite\\큰2.png");
		big_sp[2].Load(LoadText);
		sprintf(LoadText, "sprite\\큰3.png");
		big_sp[3].Load(LoadText);
		sprintf(LoadText, "sprite\\큰4.png");
		big_sp[4].Load(LoadText);
		sprintf(LoadText, "sprite\\큰5.png");
		big_sp[5].Load(LoadText);

		for (int i = 0; i < 8; i++)
		{
			sprintf(LoadText, "sprite\\ball%d.png",i);
			ball_sp[i].Load(LoadText);
		}

		sprintf(LoadText, "sprite\\ball_crash.png");
		crash_ball_sp.Load(LoadText);
		sprintf(LoadText, "sprite\\ball_crash2.png");
		crash_ball2_sp.Load(LoadText);

		sprintf(LoadText, "sprite\\back_start.png");
		back[0].Load(LoadText);
		sprintf(LoadText, "sprite\\back.png");
		back[1].Load(LoadText);

		sprintf(LoadText, "sprite\\charge.png");
		charge.Load(LoadText);

		sprintf(LoadText, "sprite\\스킬게이지1.png");
		skill_gauge_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\스킬게이지2.png");
		skill_gauge_sp[1].Load(LoadText);

		sprintf(LoadText, "sprite\\대박.png");
		perfect_sp.Load(LoadText);

		sprintf(LoadText, "sprite\\빠이어.png");
		burn_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\빠이어2.png");
		burn_sp[1].Load(LoadText);

		sprintf(LoadText, "sprite\\차지게이지.png");
		charge_gauge_sp.Load(LoadText);

		sprintf(LoadText, "sprite\\패널.png");
		how_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\끄기버튼.png");
		how_sp[1].Load(LoadText);
		sprintf(LoadText, "sprite\\On끄기버튼.png");
		how_sp[2].Load(LoadText);

		sprintf(LoadText, "sprite\\HOME팀.png");
		win_sp[0].Load(LoadText);
		sprintf(LoadText, "sprite\\AWAY팀.png");
		win_sp[1].Load(LoadText);
		sprintf(LoadText, "sprite\\승리.png");
		win_sp[2].Load(LoadText);


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
			if (background == 1)
			{
				//-------------------AI-start------------------//

				if (play_mod == 1)
				{
					if (ai_serve != 0)//서브 1초 대기
						ai_serve--;
					if (ball.move == 0 && turn == 1 && ai_serve == 0) //서브
					{
						if (ch2.x < 1920 / 2 + 150) //서브할만한 위치이동
						{
							ch2.left = 0;
							ch2.right = 1;
						}
						else if (ch2.x > 1920 - 700) //서브할만한 위치이동
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
						if (ball.x > 1920 / 2 - 100)//위치잡기
						{
							if (ball.x > ch2.x + start_x - 80)
							{
								ch2.left = 0;
								ch2.right = 1;
							}
							else if (ball.x < ch2.x + start_x - 120)
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

						if (ball.x > 1920 / 2 + 320 && ball.y < ch2.y + start_y - 100 && ch2.charge_what != 2 && ball.speed > 25)//점프
						{
							if (ch2.up == 0 && ch2.plays == 0)
							{
								ch2.up = 1;
								ch2.gravity = 30;
							}
						}

						if (ch2.gravity < 25 && ch2.plays == 0 && ch2.charge_now == 0 && ch2.up == 1 && ball.move == 2 && ai_skill1 == 0 && ch2.skill_gauge >= 1)//스킬1
						{
							ch2.skill = 1;
							ch2.skill1 = 1;
							ai_skill1 = 1;
							ch2.skill_gauge -= 1;
						}
						else if (ai_skill1 == 30 && ch2.skill == 1)
						{
							ch2.skill1 = rand() % 3 + 1;
							ch2.skill = 0;
							ai_skill1 = 0;
						}
						else if (ch2.skill == 1)
							ai_skill1++;

						if (ball.speed > 18 || ball.x > 1920 / 2 + 400 || (ball.speed < 10 && ball.gravity < -3))//포핸드차지
						{
							if (ball.x > 1920 / 2 && ball.x > ch2.x + start_x - 140 && ball.y > 480 + start_y - 140 && ch2.plays == 0 && ch2.charge_now == 0 && ball.gravity < 0 && ch2.skill == 0 && ch2.skill_gauge < 1)//차지
							{
								ch2.charge = 1;
								ch2.charge_now = 1;
								ch2.charge_what = 1;
								SetTimer(hWnd, 5, 250, NULL);
							}
						}
						else//백핸드차지
						{
							if (ball.x > 1920 / 2 && ball.x > ch2.x + start_x - 150 && ball.y > 480 + start_y - 120 && ch2.plays == 0 && ch2.charge_now == 0 && ball.gravity < -2 && ch2.skill == 0)//차지
							{
								ch2.charge = 1;
								ch2.charge_now = 1;
								ch2.charge_what = 2;
								SetTimer(hWnd, 5, 250, NULL);
								ch2.right = 1;
							}
						}
						if (ch2.charge_what == 1)//포핸드
						{
							if (((ball.x > ch2.x + start_x - 80 && ball.y > 480 + start_y - 90) || (ch2.up == 1 && ball.x > ch2.x + start_x - 100)) && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
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
							if (ball.x > ch2.x + start_x - 120 && ball.y > 480 + start_y - 60 && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
							{
								ch2.charge_now = 0;
								ch2.charge_what = 0;
								ch2.play = 2;
								ch2.plays = 2;
								ch2.play1_charge_sp = 0;
								ch2.right = 0;
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

				if (ball_pa_sp != 0)
					ball_pa_sp--;
				if (ball_pa2_sp != 0)
					ball_pa2_sp--;


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
							if (ball.x - ball.speed < 1920 / 2 && ball.y - ball.gravity + 25 > nete_y && ball.x > 1920 / 2)
							{
								ball.speed *= -1;

							}
							else
							{
								ball.x -= ball.speed;
								ball.y -= ball.gravity;
							}
						}
						else if (ball.move == 2)
						{
							if (ball.x + ball.speed + 25 > 1920 / 2 && ball.y - ball.gravity + 25 > nete_y && ball.x + 25 < 1920 / 2)
							{
								ball.speed *= -1;

							}
							else
							{
								ball.x += ball.speed;
								ball.y -= ball.gravity;
							}
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

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
					}
					else if (ch1.skill1 == 3)
					{
						ball.speed = 80;
						ball.gravity = -16;
						ball.move = 2;
						ch1.skill1_sp = 19;

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
					}
					else if (ch1.skill1 == 4)
					{
						ball.speed = 90;
						ball.gravity = -14;
						ball.move = 2;
						ch1.skill1_sp = 19;

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
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

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
					}
					else if (ch2.skill1 == 3)
					{
						ball.speed = 80;
						ball.gravity = -16;
						ball.move = 1;
						ch2.skill1_sp = 19;

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
					}
					else if (ch2.skill1 == 4)
					{
						ball.speed = 90;
						ball.gravity = -14;
						ball.move = 1;
						ch2.skill1_sp = 19;

						ball_pa2_sp = 5;
						ball_pa2_x = ball.x - 30;
						ball_pa2_y = ball.y - 30;
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

				//스윙
				if (ch1.play == 1)
				{
					if (ch1.x + start_x + 40 < ball.x && ch1.x + start_x + 160 > ball.x && ch1.y + start_y + 80 > ball.y && ch1.y + start_y - 80 < ball.y)
					{
						ball.gravity = ball.play1_gravity(ch1.charge, ch1.crash);
						ball.speed = ball.play1_speed(ch1.charge, ch1.crash);
						ball.move = 2;
						ball.delta = 100;
						ball_pa_sp = 5;
						ball_pa_x = ball.x;
						ball_pa_y = ball.y;

						if (ch1.crash > 6 && ch1.crash < 14)
						{
							if(ch1.skill_gauge < 2.7)
								ch1.skill_gauge += 0.3;
							else
								ch1.skill_gauge = 3.0;
						}
						else
						{
							if (ch1.skill_gauge < 2.9)
								ch1.skill_gauge += 0.1;
							else
								ch1.skill_gauge = 3.0;
						}
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
						ball.gravity = ball.play2_gravity(ch1.charge, ch1.crash);
						ball.speed = ball.play2_speed(ch1.charge, ch1.crash);
						ball.move = 2;
						ball.delta = 100;
						ball_pa_sp = 5;
						ball_pa_x = ball.x;
						ball_pa_y = ball.y;

						if (ch1.crash > 6 && ch1.crash < 14)
						{
							if (ch1.skill_gauge < 2.7)
								ch1.skill_gauge += 0.3;
							else
								ch1.skill_gauge = 3.0;
						}
						else
						{
							if (ch1.skill_gauge < 2.9)
								ch1.skill_gauge += 0.1;
							else
								ch1.skill_gauge = 3.0;
						}
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
						ball.gravity = ball.play1_gravity(ch2.charge, ch2.crash);
						ball.speed = ball.play1_speed(ch2.charge, ch2.crash);
						ball.move = 1;
						ball.delta = 100;
						ball_pa_sp = 5;
						ball_pa_x = ball.x;
						ball_pa_y = ball.y;

						if (ch2.crash > 6 && ch2.crash < 14)
						{
							if (ch2.skill_gauge < 2.7)
								ch2.skill_gauge += 0.3;
							else
								ch2.skill_gauge = 3.0;
						}
						else
						{
							if (ch2.skill_gauge < 2.9)
								ch2.skill_gauge += 0.1;
							else
								ch2.skill_gauge = 3.0;
						}
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
						ball.gravity = ball.play2_gravity(ch2.charge, ch2.crash);
						ball.speed = ball.play2_speed(ch2.charge, ch2.crash);
						ball.move = 1;
						ball.delta = 100;
						ball_pa_sp = 5;
						ball_pa_x = ball.x;
						ball_pa_y = ball.y;

						if (ch2.crash > 6 && ch2.crash < 14)
						{
							if (ch2.skill_gauge < 2.7)
								ch2.skill_gauge += 0.3;
							else
								ch2.skill_gauge = 3.0;
						}
						else
						{
							if (ch2.skill_gauge < 2.9)
								ch2.skill_gauge += 0.1;
							else
								ch2.skill_gauge = 3.0;
						}
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
					ai_serve = 50;

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
					ai_serve = 50;

					SetTimer(hWnd, 1, prame, NULL);
				}

				//5점되면
				if (score_1 == 5)
				{
					score_1 = 0;
					score_2 = 0;
					set_score_1++;
				}
				else if (score_2 == 5)
				{
					score_1 = 0;
					score_2 = 0;
					set_score_2++;
				}

				if (set_score_1 == 2)
					wins_sp = 1;
				else if (set_score_2 == 2)
					wins_sp = 2;
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
		if (background == 1)
		{
			if (ch1.skill1 == 0)
			{
				if (wParam == 'A')
					ch1.left = 1;
				if (wParam == 'D')
					ch1.right = 1;
				if ((wParam == 'W') && ch1.up == 0 && ch1.plays == 0)
				{
					ch1.up = 1;
					ch1.gravity = 30;
				}
				if ((wParam == 'G') && ch1.plays == 0 && ch1.charge_now == 0)
				{
					ch1.charge = 1;
					ch1.charge_now = 1;
					ch1.charge_what = 1;
					SetTimer(hWnd, 4, 250, NULL);
				}
				if ((wParam == 'H') && ch1.plays == 0 && ch1.charge_now == 0)
				{
					ch1.charge = 1;
					ch1.charge_now = 1;
					ch1.charge_what = 2;
					SetTimer(hWnd, 4, 250, NULL);
				}
				if ((wParam == 'T') && ch1.plays == 0 && ch1.charge_now == 0 && ch1.up == 1 && ball.move == 1 && ch1.skill_gauge >= 1)
				{
					ch1.skill = 1;
					ch1.skill1 = 1;
					ch1.skill_gauge -= 1;
				}
				if ((wParam == 'Y') && ch1.skill != 2 && ball.move == 1 && ch1.skill_gauge >= 1)
				{
					ch1.skill = 2;
					SetTimer(hWnd, 1, 100, NULL);
					ch1.skill_gauge -= 1;
				}
			}
			else if (ch1.skill == 1)
			{
				if (ch1.skill1 == 1)
				{
					if (wParam == 'A')
					{
						ch1.skill1 = 2;
						ch1.skill = 0;
					}
					if (wParam == 'D')
					{
						ch1.skill1 = 4;
						ch1.skill = 0;
					}
					if (wParam == 'W')
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
				if (wParam == VK_NUMPAD1 && ch2.plays == 0 && ch2.charge_now == 0)
				{
					ch2.charge = 1;
					ch2.charge_now = 1;
					ch2.charge_what = 1;
					SetTimer(hWnd, 5, 250, NULL);
				}
				if (wParam == VK_NUMPAD2 && ch2.plays == 0 && ch2.charge_now == 0)
				{
					ch2.charge = 1;
					ch2.charge_now = 1;
					ch2.charge_what = 2;
					SetTimer(hWnd, 5, 250, NULL);
				}
				if (wParam == VK_NUMPAD4 && ch2.plays == 0 && ch2.charge_now == 0 && ch2.up == 1 && ball.move == 2 && ch2.skill_gauge >= 1)
				{
					ch2.skill = 1;
					ch2.skill1 = 1;
					ch2.skill_gauge -= 1;
				}
				if (wParam == VK_NUMPAD5 && ch2.skill != 2 && ball.move == 2 && ch2.skill_gauge >= 1)
				{
					ch2.skill = 2;
					SetTimer(hWnd, 1, 100, NULL);
					ch2.skill_gauge -= 1;
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
		}
	}break;

	case  WM_KEYUP:
	{
		if (background == 1)
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
			if (wParam == VK_NUMPAD1 && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
			{
				ch2.charge_now = 0;
				ch2.charge_what = 0;
				ch2.play = 1;
				ch2.plays = 1;
				ch2.play1_charge_sp = 0;
			}
			if (wParam == VK_NUMPAD2 && ch2.plays == 0 && ch2.plays == 0 && ch2.charge_now == 1)
			{
				ch2.charge_now = 0;
				ch2.charge_what = 0;
				ch2.play = 2;
				ch2.plays = 2;
				ch2.play1_charge_sp = 0;
			}
		}
	}break;

	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);

		if (background == 0)
		{
			back[0].Draw(memDC, 0, 0, 1920, 1080, 0, 0, 1920, 1080);

			if(button1_sp == 0)
				button_sp[0].Draw(memDC, 312, 400, 1296, 173, 0, 0, 1296, 173);
			else if (button1_sp == 1)
				buttons_sp[0].Draw(memDC, 312, 400, 1296, 173, 0, 0, 1296, 173);

			if (button2_sp == 0)
				button_sp[1].Draw(memDC, 312, 600, 1296, 173, 0, 0, 1296, 173);
			else if(button2_sp == 1)
				buttons_sp[1].Draw(memDC, 312, 600, 1296, 173, 0, 0, 1296, 173);

			if (button3_sp == 0)
				button_sp[2].Draw(memDC, 312, 800, 630, 170, 0, 0, 630, 170);
			else if (button3_sp == 1)
				buttons_sp[2].Draw(memDC, 312, 800, 630, 170, 0, 0, 630, 170);

			if (button4_sp == 0)
				button_sp[3].Draw(memDC, 978, 800, 630, 170, 0, 0, 630, 170);
			else if (button4_sp == 1)
				buttons_sp[3].Draw(memDC, 978, 800, 630, 170, 0, 0, 630, 170);

			if (how1_sp == 1)
			{
				how_sp[0].Draw(memDC, 43, 20, 1834, 1040, 0, 0, 1834, 1040);
				if(how2_sp == 0)
					how_sp[1].Draw(memDC, 1320, 860, 504, 135, 0, 0, 504, 135);
				else
					how_sp[2].Draw(memDC, 1320, 860, 504, 135, 0, 0, 504, 135);
			}
		}
		else if (background == 1)
		{
			back[1].Draw(memDC, 0, 0, 1920, 1080, 0, 0, 1920, 1080);

			big_sp[score_1].Draw(memDC, 790, 48, 50, 68, 0, 0, 50, 68);
			big_sp[score_2].Draw(memDC, 1086, 48, 50, 68, 0, 0, 50, 68);
			sm_sp[set_score_1].Draw(memDC, 870, 60, 31, 44, 0, 0, 31, 44);
			sm_sp[set_score_2].Draw(memDC, 1023, 60, 31, 44, 0, 0, 31, 44);
			if (turn == 0 && ball.move == 0)
				ser_sp[1].Draw(memDC, 935, 80, 57, 33, 0, 0, 57, 33);
			else if (turn == 1 && ball.move == 0)
				ser_sp[2].Draw(memDC, 935, 80, 57, 33, 0, 0, 57, 33);
			else
				ser_sp[0].Draw(memDC, 935, 80, 57, 33, 0, 0, 57, 33);


			hBrush = CreateSolidBrush(RGB(255, 100, 100));
			oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
			hPen = CreatePen(PS_SOLID, 0, RGB(0, 0, 0));
			oldPen = (HPEN)SelectObject(memDC, hPen);
			Rectangle(memDC, 30 + 50, 25 + 50, (453 - 30) / 3 * ch1.skill_gauge + 50 + 30, 61 + 50);
			skill_gauge_sp[0].Draw(memDC, 50, 50, 482, 87, 0, 0, 482, 87);
			hBrush = CreateSolidBrush(RGB(100, 100, 255));
			oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
			Rectangle(memDC, 30 + 1388, 25 + 50, (453 - 30) / 3 * ch2.skill_gauge + 1388 + 30, 61 + 50);
			skill_gauge_sp[1].Draw(memDC, 1388, 50, 482, 87, 0, 0, 482, 87);

			if(ch1.skill == 1)
				burn_sp[0].Draw(memDC, ch1.x + start_x - 20, ch1.y + start_y - 50, 137, 201, 0, 0, 137, 201);
			if (ch2.skill == 1)
				burn_sp[1].Draw(memDC, ch2.x + start_x - 20, ch2.y + start_y - 50, 137, 201, 0, 0, 137, 201);


			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
			Rectangle(memDC, 25 + 50, 19 + 951, (337 - 19) / 3 * ch1.charge + 50 + 19, 59 + 951);
			charge_gauge_sp.Draw(memDC, 50, 951, 365, 79, 0, 0, 365, 79);
			Rectangle(memDC, 25 + 1505, 19 + 951, (337 - 19) / 3 * ch2.charge + 1505 + 19, 59 + 951);
			charge_gauge_sp.Draw(memDC, 1505, 951, 365, 79, 0, 0, 365, 79);


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
				ch1_forH_weak_hair_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_forH_weak_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.plays == 1 && ch1.charge == 2)
			{
				ch1_forH_middle_hair_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_forH_middle_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.plays == 1 && ch1.charge == 3)
			{
				ch1_forH_strong_hair_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_forH_strong_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.plays == 2 && ch1.charge == 1)
			{
				ch1_backH_hair_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_backH_weak_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.plays == 2 && ch1.charge == 2)
			{
				ch1_backH_hair_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_backH_middle_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.plays == 2 && ch1.charge == 3)
			{
				ch1_backH_hair_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_stay_lower_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_backH_strong_upper_sp[ch1.play1_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.charge_now == 1 && ch1.charge_what == 1)
			{
				ch1_forH_charge_hair_sp[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_walk_lower[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_forH_charge_upper_sp[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.charge_now == 1 && ch1.charge_what == 2)
			{
				ch1_backH_hair_sp.Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_walk_lower[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_backH_charge_upper_sp[ch1.play1_charge_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.up == 1)
			{
				ch1_jump_hair_sp[ch1.jump_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_jump_lower_sp[ch1.jump_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_jump_upper_sp[ch1.jump_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else if (ch1.left + ch1.right == 1)
			{
				ch1_run_hair_sp[ch1.run_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_run_lower_sp[ch1.run_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
				ch1_run_upper_sp[ch1.run_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
			}
			else
			{
				ch1_ready_hair_sp[ch1.ready_sp].Draw(memDC, ch1.x, ch1.y, size_x, size_y, 0, 0, size_x, size_y);
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

			if (ball_pa_sp != 0)
				crash_ball_sp.Draw(memDC, ball_pa_x - 10, ball_pa_y - 12, 51, 62, 0, 0, 51, 62);
			if (ball_pa2_sp != 0)
				crash_ball2_sp.Draw(memDC, ball_pa2_x, ball_pa2_y, 104, 126, 0, 0, 104, 126);

			int gogogo = 0;
			if (ball.gravity > 0)
			{
				if (ball.speed < abs(ball.gravity))
					gogogo = 0;
				else
				{
					if (ball.move == 1)
						gogogo = 7;
					else
						gogogo = 1;
				}
			}
			else
			{
				if (ball.speed < abs(ball.gravity))
				{
					if (ball.move == 1)
						gogogo = 5;
					else
						gogogo = 3;
				}
				else
				{
					if (ball.move == 1)
						gogogo = 6;
					else
						gogogo = 2;
				}
			}
			ball_sp[gogogo].Draw(memDC, ball.x, ball.y, 25, 25, 0, 0, 25, 25);

			if (wins_sp == 1)
			{
				win_sp[0].Draw(memDC, 472, 240, 1014, 319, 0, 0, 1014, 319);
				win_sp[2].Draw(memDC, 625, 565, 619, 335, 0, 0, 619, 335);
			}
			else if (wins_sp == 2)
			{
				win_sp[1].Draw(memDC, 472, 240, 1014, 319, 0, 0, 1014, 319);
				win_sp[2].Draw(memDC, 625, 565, 619, 335, 0, 0, 619, 335);
			}

			/*
			for (int i = 0; i < ch1.charge; i++)
				charge.Draw(memDC, 50 + i * 40, 930, 30, 100, 0, 0, 30, 100);
			for (int i = 0; i < ch2.charge; i++)
				charge.Draw(memDC, 1700 + i * 40, 930, 30, 100, 0, 0, 30, 100);
			*/
		}


		BitBlt(hdc, 0, 0, window_x, window_y, memDC, 0, 0, SRCCOPY);
		DeleteDC(memDC);
		DeleteObject(hBitmap);
		EndPaint(hWnd, &ps);

	}break;

	case WM_LBUTTONDOWN:
	{
		if (background == 0)
		{
			if (mouse_x > 312 && mouse_x < 312 + 1296 && mouse_y > 400 && mouse_y < 400 + 173)
			{
				background = 1;
				play_mod = 1;
			}
			else if (mouse_x > 312 && mouse_x < 312 + 1296 && mouse_y > 600 && mouse_y < 600 + 173)
			{
				background = 1;
				play_mod = 2;
			}
			else if (mouse_x > 312 && mouse_x < 312 + 630 && mouse_y > 800 && mouse_y < 800 + 173)
				how1_sp = 1;
			else if (mouse_x > 978 && mouse_x < 978 + 630 && mouse_y > 800 && mouse_y < 800 + 173)
				exit(1);

			if (how1_sp == 0)
			{
				if (mouse_x > 43 && mouse_x < 43 + 1834 && mouse_y > 20 && mouse_y < 20 + 1040)
					how1_sp = 1;
			}
			else
			{
				if (mouse_x > 1320 && mouse_x < 1320 + 504 && mouse_y > 860 && mouse_y < 860 + 135)
					how1_sp = 0;
			}
		}
	}break;

	case WM_MOUSEMOVE:
	{
		mouse_x = LOWORD(lParam);
		mouse_y = HIWORD(lParam);

		button1_sp = 0;
		button2_sp = 0;
		button3_sp = 0;
		button4_sp = 0;
		how2_sp = 0;

		if (mouse_x > 312 && mouse_x < 312 + 1296 && mouse_y > 400 && mouse_y < 400 + 173)
			button1_sp = 1;
		else if (mouse_x > 312 && mouse_x < 312 + 1296 && mouse_y > 600 && mouse_y < 600 + 173)
			button2_sp = 1;
		else if (mouse_x > 312 && mouse_x < 312 + 630 && mouse_y > 800 && mouse_y < 800 + 173)
			button3_sp = 1;
		else if (mouse_x > 978 && mouse_x < 978 + 630 && mouse_y > 800 && mouse_y < 800 + 173)
			button4_sp = 1;

		if (mouse_x > 1320 && mouse_x < 1320 + 504 && mouse_y > 860 && mouse_y < 860 + 135)
			how2_sp = 1;
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