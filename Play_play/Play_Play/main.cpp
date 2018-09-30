//해더 모음집//
#include "resource.h"
#include "variable.h"
#include "basic.h"


CImage ch1_back_sp[34];
CImage ch1_fo_sp[26];
CImage ch1_leg_sp;
CImage ch1_move_leg_sp[24];
CImage ch1_move_sp[24];
CImage ch1_ready_leg_sp[24];
CImage ch1_ready_sp[24];
CImage ch1_jump_leg_sp[24];
CImage ch1_jump_sp[24];

CImage ch2_back_sp[34];
CImage ch2_fo_sp[26];
CImage ch2_leg_sp;
CImage ch2_move_leg_sp[24];
CImage ch2_move_sp[24];
CImage ch2_ready_leg_sp[24];
CImage ch2_ready_sp[24];
CImage ch2_jump_leg_sp[24];
CImage ch2_jump_sp[24];

CImage ball_sp[8];
CImage pause_sp;
CImage vs_sp[5];
CImage background_sp;
CImage score_sp[10];
CImage scores_sp;
CImage icon_sp[4];


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
	static HBITMAP hBitmap, start_sp, ch_sp, ch2_sp;

	switch (uMsg)
	{
	case WM_CREATE:
	{
		//png//
		CHAR LoadText[100];
		for (int i = 0; i < 34; i++)
		{
			sprintf(LoadText, "back\\skeleton-backhand_%d.png", i);
			ch1_back_sp[i].Load(LoadText);
		}
		for (int i = 0; i < 26; i++)
		{
			sprintf(LoadText, "forhand\\skeleton-forhand_%d.png", i);
			ch1_fo_sp[i].Load(LoadText);
		}
		for (int i = 0; i < 24; i++)
		{
			sprintf(LoadText, "move\\lower\\skeleton-move_%d.png", i);
			ch1_move_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "move\\upper\\skeleton-move_%d.png", i);
			ch1_move_sp[i].Load(LoadText);
			sprintf(LoadText, "ready\\lower\\skeleton-ready_%d.png", i);
			ch1_ready_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "ready\\upper\\skeleton-ready_%d.png", i);
			ch1_ready_sp[i].Load(LoadText);
			sprintf(LoadText, "jump\\lower\\skeleton-jump_%d.png", i);
			ch1_jump_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "jump\\upper\\skeleton-jump_%d.png", i);
			ch1_jump_sp[i].Load(LoadText);
		}
		ch1_leg_sp.Load(TEXT("leg_normal.png"));

		for (int i = 0; i < 34; i++)
		{
			sprintf(LoadText, "2\\backhand\\skeleton-2-backhand_%d.png", i);
			ch2_back_sp[i].Load(LoadText);
		}
		for (int i = 0; i < 26; i++)
		{
			sprintf(LoadText, "2\\forhand\\skeleton-2-forhand_%d.png", i);
			ch2_fo_sp[i].Load(LoadText);
		}
		for (int i = 0; i < 24; i++)
		{
			sprintf(LoadText, "2\\move\\lower\\skeleton-2-move_%d.png", i);
			ch2_move_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "2\\move\\upper\\skeleton-2-move_%d.png", i);
			ch2_move_sp[i].Load(LoadText);
			sprintf(LoadText, "2\\ready\\lower\\skeleton-2-ready_%d.png", i);
			ch2_ready_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "2\\ready\\upper\\skeleton-2-ready_%d.png", i);
			ch2_ready_sp[i].Load(LoadText);
			sprintf(LoadText, "2\\jump\\lower\\skeleton-2-jump_%d.png", i);
			ch2_jump_leg_sp[i].Load(LoadText);
			sprintf(LoadText, "2\\jump\\upper\\skeleton-2-jump_%d.png", i);
			ch2_jump_sp[i].Load(LoadText);
		}
		ch2_leg_sp.Load(TEXT("2\\leg_normal2.png"));

		for (int i = 0; i < 8; i++)
		{
			sprintf(LoadText, "ball\\ball%d.png", i);
			ball_sp[i].Load(LoadText);
		}

		for (int i = 1; i < 6; i++)
		{
			sprintf(LoadText, "vs%d.png", i);
			vs_sp[i-1].Load(LoadText);
		}

		for (int i = 0; i < 10; i++)
		{
			sprintf(LoadText, "score\\score%d.png", i);
			score_sp[i].Load(LoadText);
		}
		background_sp.Load(TEXT("bg.png"));
		scores_sp.Load(TEXT("score\\board.png"));
		
		pause_sp.Load(TEXT("pause.png"));


		for (int i = 0; i < 4; i++)
		{
			sprintf(LoadText, "icon%d.png", i);
			icon_sp[i].Load(LoadText);
		}




		PlaySound("bgm.wav", NULL, SND_ASYNC | SND_NODEFAULT);


		//변수 초기화//
		srand(time(NULL));


		//프레임 설정//
		SetTimer(hWnd, 1, prame, NULL);//기본 프레임
		SetTimer(hWnd, 5, prame, NULL);//ai전용 프레임


		//비트맵//
		start_sp = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP1));
		ch_sp = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));
		ch2_sp = (HBITMAP)LoadBitmap(g_hInst, MAKEINTRESOURCE(IDB_BITMAP2));

	}break;

	case WM_TIMER:
	{
		switch (wParam)
		{
		case 1:
		{
			if (room == 1)
			{
				//점수
				if (score_ch1 == 17)
				{
					score_ch1 = 0;
					score_ch2 = 0;
					win_ch1++;
					views = 1;
					SetTimer(hWnd, 6, 2000, NULL);
				}
				if (score_ch2 == 17)
				{
					score_ch1 = 0;
					score_ch2 = 0;
					win_ch2++;
					views = 1;
					SetTimer(hWnd, 6, 2000, NULL);
				}


				//이미지
				if (ch1_racket_active2 == 1 || ch1_back_sps > 0)//캐릭1 벡핸드
				{
					if (ch1_back_sps < 17)
						ch1_back_sps++;
					else if (ch1_back_sps < 30)
					{
						ch1_back_sps++;
						ch1_racket_active2 = 0;
					}
					else
					{
						ch1_racket_degree = 0;
						if (ch1_charge_on == 0)
							ch1_charge = 0;
						ch1_back_sps = 0;
					}
				}

				if (ch1_racket_active1 == 1 || ch1_fo_sps > 0)//캐릭1 포핸드
				{
					if (ch1_fo_sps < 11)
						ch1_fo_sps++;
					else if (ch1_fo_sps < 23)
					{
						ch1_fo_sps++;
						ch1_racket_active1 = 0;
					}
					else
					{
						ch1_racket_degree = 0;
						if (ch1_charge_on == 0)
							ch1_charge = 0;
						ch1_fo_sps = 0;
					}
				}

				if ((ch1_left == 1 || ch1_right == 1) && ch1_jump == 1)//캐릭1 이동
				{
					if (ch1_move_sps < 23)
						ch1_move_sps++;
					else
						ch1_move_sps = 0;
				}

				if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1)//캐릭1 정지
				{
					if (ch1_ready_sps < 23)
						ch1_ready_sps++;
					else
						ch1_ready_sps = 0;
				}

				if (ch1_jump == 0)//캐릭1 점프
				{
					if (ch1_jump_sps < 23)
						ch1_jump_sps++;
					else
						ch1_jump_sps = 0;
				}

				if (ch2_racket_active2 == 1 || ch2_back_sps > 0)//캐릭2 벡핸드
				{
					if (ch2_back_sps < 17)
						ch2_back_sps++;
					else if (ch2_back_sps < 30)
					{
						ch2_back_sps++;
						ch2_racket_active2 = 0;
					}
					else
					{
						ch2_racket_degree = 180;
						if (ch2_charge_on == 0)
							ch2_charge = 0;
						ch2_back_sps = 0;
					}
				}

				if (ch2_racket_active1 == 1 || ch2_fo_sps > 0)//캐릭2 포핸드
				{
					if (ch2_fo_sps < 11)
						ch2_fo_sps++;
					else if (ch2_fo_sps < 23)
					{
						ch2_fo_sps++;
						ch2_racket_active1 = 0;
					}
					else
					{
						ch2_racket_degree = 180;
						if (ch2_charge_on == 0)
							ch2_charge = 0;
						ch2_fo_sps = 0;
					}
				}

				if ((ch2_left == 1 || ch2_right == 1) && ch2_jump == 1)//캐릭2 이동
				{
					if (ch2_move_sps < 23)
						ch2_move_sps++;
					else
						ch2_move_sps = 0;
				}

				if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1)//캐릭2 정지
				{
					if (ch2_ready_sps < 23)
						ch2_ready_sps++;
					else
						ch2_ready_sps = 0;
				}

				if (ch2_jump == 0)//캐릭2 점프
				{
					if (ch2_jump_sps < 23)
						ch2_jump_sps++;
					else
						ch2_jump_sps = 0;
				}

				//중력
				if (ch1_y < 650)//캐릭터1
				{
					if (ch1_y + ch1_gravity / 2 > 650)
						ch1_y = 650;
					else
					{
						ch1_gravity += 7;
						ch1_y += ch1_gravity / 2;
						ch1_jump = 0;
					}
				}
				else if (ch1_y >= 650)
					ch1_jump = 1;

				if (ch2_y < 650)//캐릭터2
				{
					if (ch2_y + ch2_gravity / 2 > 650)
						ch2_y = 650;
					else
					{
						ch2_gravity += 7;
						ch2_y += ch2_gravity / 2;
						ch2_jump = 0;
					}
				}
				else if (ch2_y >= 650)
					ch2_jump = 1;

				if (ball_direction == 1)//공
				{
					ball_x -= ball_move;
					ball_y += ball_gravity;
					ball_gravity += 1;
				}
				else if (ball_direction == 2)
				{
					ball_x += ball_move;
					ball_y += ball_gravity;
					ball_gravity += 1;
				}

				//이동
				if (ch1_left == 1)
				{
					if (ch1_x > 0)
						ch1_x -= 15;
				}
				if (ch1_right == 1)
				{
					if(ch1_x < 760)
						ch1_x += 15;
				}

				if (ch2_left == 1)
				{
					if (ch2_x > 1005)
						ch2_x -= 15;
				}
				if (ch2_right == 1)
				{
					if (ch2_x < 1800)
						ch2_x += 15;
				}

				//좌표 재설정
				ch1_racket_x = ch1_x + 20 + 130 * cos(ch1_racket_degree * 3.14 / 180);
				ch1_racket_y = ch1_y + 40 + 130 * sin(ch1_racket_degree * 3.14 / 180);


				if (ai_mod == 1)
				{
					ch2_racket_x = ch2_x + 55 + 130 * cos(ch2_racket_degree * 3.14 / 180);
					ch2_racket_y = ch2_y + 40 + 130 * sin(ch2_racket_degree * 3.14 / 180);
					ch2_racket_size_x = 100;
					ch2_racket_size_y = 100;
				}
				if (ai_mod == 0)
				{
					ch2_racket_x = ch2_x + 40 + 130 * cos(ch2_racket_degree * 3.14 / 180);
					ch2_racket_y = ch2_y + 25 + 130 * sin(ch2_racket_degree * 3.14 / 180);
					ch2_racket_size_x = 70;
					ch2_racket_size_y = 70;
				}

				//충돌체크
				if (ch1_racket_active1 == 1)//캐릭터 1 포헨드
				{
					if (ball_x + ball_size_x > ch1_racket_x && ball_x < ch1_racket_x + ch1_racket_size_x && ball_y + ball_size_y > ch1_racket_y && ball_y < ch1_racket_y + ch1_racket_size_y)
					{
						if (ch1_jump == 1)//땅에서 스윙
						{
							if (ch1_charge == 1)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 18;
									ball_gravity = -28;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 22;
									ball_gravity = -22;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 18;
									ball_gravity = -18;
								}
							}
							else if (ch1_charge == 2)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 20;
									ball_gravity = -30;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 25;
									ball_gravity = -25;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 20;
									ball_gravity = -20;
								}
							}
							else if (ch1_charge == 3)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 22;
									ball_gravity = -33;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 27;
									ball_gravity = -27;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 22;
									ball_gravity = -22;
								}
							}
						}
						else if (ch1_jump == 0)//공중에서 스윙
						{
							if (ch1_charge == 1)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 20;
									ball_gravity = -10;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 25;
									ball_gravity = -8;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 20;
									ball_gravity = -5;
								}
							}
							else if (ch1_charge == 2)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 23;
									ball_gravity = -9;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 28;
									ball_gravity = -7;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 23;
									ball_gravity = -4;
								}
							}
							else if (ch1_charge == 3)
							{
								if (ch1_fo_sps < 7)
								{
									ball_move = 27;
									ball_gravity = -8;
								}
								else if (ch1_fo_sps == 7 || ch1_fo_sps == 8)
								{
									ball_move = 32;
									ball_gravity = -6;
								}
								else if (ch1_back_sps > 8)
								{
									ball_move = 27;
									ball_gravity = -3;
								}
							}
						}
						ball_direction = 2;
						ch1_charge = 0;
						SetTimer(hWnd, 3, 1200, NULL);
						ball_Dmove = 0;
						turn = 0;
					}
				}
				else if (ch1_racket_active2 == 1)//캐릭터 1 백헨드
				{
					if (ball_x + ball_size_x > ch1_racket_x && ball_x < ch1_racket_x + ch1_racket_size_x && ball_y + ball_size_y > ch1_racket_y && ball_y < ch1_racket_y + ch1_racket_size_y)
					{
						if (ch1_charge == 1)
						{
							if (ch1_back_sps < 14)
							{
								ball_move = 15;
								ball_gravity = -30;
							}
							else if (ch1_back_sps == 14 || ch1_back_sps == 15)
							{
								ball_move = 20;
								ball_gravity = -22;
							}
							else if (ch1_back_sps > 15)
							{
								ball_move = 15;
								ball_gravity = -18;
							}
						}
						else if (ch1_charge == 2)
						{
							if (ch1_back_sps < 14)
							{
								ball_move = 18;
								ball_gravity = -32;
							}
							else if (ch1_back_sps == 14 || ch1_back_sps == 15)
							{
								ball_move = 23;
								ball_gravity = -24;
							}
							else if (ch1_back_sps > 15)
							{
								ball_move = 18;
								ball_gravity = -20;
							}
						}
						else if (ch1_charge == 3)
						{
							if (ch1_back_sps < 14)
							{
								ball_move = 20;
								ball_gravity = -35;
							}
							else if (ch1_back_sps == 14 || ch1_back_sps == 15)
							{
								ball_move = 25;
								ball_gravity = -27;
							}
							else if (ch1_back_sps > 15)
							{
								ball_move = 20;
								ball_gravity = -23;
							}
						}
						ball_direction = 2;
						ch1_charge = 0;
						SetTimer(hWnd, 3, 1200, NULL);
						ball_Dmove = 0;
						turn = 0;
					}
				}
				
				if (ch2_racket_active1 == 1)//캐릭터 2 포헨드
					{
						if (ball_x + ball_size_x > ch2_racket_x && ball_x < ch2_racket_x + ch2_racket_size_x && ball_y + ball_size_y > ch2_racket_y && ball_y < ch2_racket_y + ch2_racket_size_y)
						{
							if (ch2_jump == 1)//땅에서 스윙
							{
								if (ch2_charge == 1)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 18;
										ball_gravity = -28;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 22;
										ball_gravity = -22;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 18;
										ball_gravity = -18;
									}
								}
								else if (ch2_charge == 2)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 20;
										ball_gravity = -30;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 25;
										ball_gravity = -25;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 20;
										ball_gravity = -20;
									}
								}
								else if (ch2_charge == 3)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 22;
										ball_gravity = -33;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 27;
										ball_gravity = -27;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 22;
										ball_gravity = -22;
									}
								}
							}
							else if (ch2_jump == 0)//공중에서 스윙
							{
								if (ch2_charge == 1)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 20;
										ball_gravity = -10;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 25;
										ball_gravity = -8;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 20;
										ball_gravity = -5;
									}
								}
								else if (ch2_charge == 2)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 23;
										ball_gravity = -9;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 28;
										ball_gravity = -7;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 23;
										ball_gravity = -4;
									}
								}
								else if (ch2_charge == 3)
								{
									if (ch2_fo_sps < 7)
									{
										ball_move = 27;
										ball_gravity = -8;
									}
									else if (ch2_fo_sps == 7 || ch2_fo_sps == 8)
									{
										ball_move = 32;
										ball_gravity = -6;
									}
									else if (ch2_fo_sps > 8)
									{
										ball_move = 27;
										ball_gravity = -3;
									}
								}
							}
							ball_direction = 1;
							ch2_charge = 0;
							SetTimer(hWnd, 3, 1200, NULL);
							ball_Dmove = 0;
							turn = 0;
						}
					}
				else if (ch2_racket_active2 == 1)//캐릭터 2 백헨드
					{
						if (ball_x + ball_size_x > ch2_racket_x && ball_x < ch2_racket_x + ch2_racket_size_x && ball_y + ball_size_y > ch2_racket_y && ball_y < ch2_racket_y + ch2_racket_size_y)
						{
							if (ch2_charge == 1)
							{
								if (ch2_back_sps < 14)
								{
									ball_move = 15;
									ball_gravity = -30;
								}
								else if (ch2_back_sps == 14 || ch2_back_sps == 15)
								{
									ball_move = 20;
									ball_gravity = -22;
								}
								else if (ch2_back_sps > 15)
								{
									ball_move = 15;
									ball_gravity = -18;
								}
							}
							else if (ch2_charge == 2)
							{
								if (ch1_back_sps < 14)
								{
									ball_move = 18;
									ball_gravity = -32;
								}
								else if (ch2_back_sps == 14 || ch2_back_sps == 15)
								{
									ball_move = 23;
									ball_gravity = -24;
								}
								else if (ch2_back_sps > 15)
								{
									ball_move = 18;
									ball_gravity = -20;
								}
							}
							else if (ch2_charge == 3)
							{
								if (ch2_back_sps < 14)
								{
									ball_move = 20;
									ball_gravity = -35;
								}
								else if (ch2_back_sps == 14 || ch2_back_sps == 15)
								{
									ball_move = 25;
									ball_gravity = -27;
								}
								else if (ch2_back_sps > 15)
								{
									ball_move = 20;
									ball_gravity = -23;
								}
							}
							ball_direction = 1;
							ch2_charge = 0;
							SetTimer(hWnd, 3, 1200, NULL);
							ball_Dmove = 0;
							turn = 0;
						}
					}
				

				//라켓
				if (ch1_racket_active1 == 1)//포핸드시
				{
					if (ch1_racket_degree < -110)
						ch1_racket_degree += 12;
					else if (ch1_racket_degree < -60)
						ch1_racket_degree += 35;
					else if(ch1_racket_degree < 70)
						ch1_racket_degree += 55;
				}
				else if (ch1_racket_active2 == 1)//백핸드시
				{
					if (ch1_racket_degree > 90)
						ch1_racket_degree -= 9;
					else if(ch1_racket_degree > 40)
						ch1_racket_degree -= 12;
					else if (ch1_racket_degree > 10)
						ch1_racket_degree -= 24;
					else
						ch1_racket_degree -= 60;
				}

				if (ai_mod == 0)
				{
					if (ch2_racket_active1 == 1)//포핸드시
					{
						if (ch2_racket_degree > -70)
							ch2_racket_degree -= 12;
						else if (ch2_racket_degree > -120)
							ch2_racket_degree -= 35;
						else if (ch2_racket_degree > -250)
							ch2_racket_degree -= 55;
					}
					else if (ch2_racket_active2 == 1)//백핸드시
					{
						if (ch2_racket_degree < 90)
							ch2_racket_degree += 9;
						else if (ch2_racket_degree < 140)
							ch2_racket_degree += 12;
						else if (ch2_racket_degree < 170)
							ch2_racket_degree += 24;
						else
							ch2_racket_degree += 60;
					}
				}
				else if (ai_mod == 1)
				{
					if (ch2_racket_active1 == 1)//포핸드시
					{
						if (ch2_racket_degree > -70)
							ch2_racket_degree -= 12;
						else
							ch2_racket_degree -= 24;
					}
					else if (ch2_racket_active2 == 1)//백핸드시
					{
						if (ch2_racket_degree < 140)
							ch2_racket_degree += 9;
						else
							ch2_racket_degree += 24;
					}
				}

				//공 바닥 충돌
				if (ball_y > 800 && ball_x < 960 - 20 && ball_x > 246 - 20)
				{
					score_ch2++;
					ball_direction = 0;
					ai_charge_choose = 0;
					ai_charge_start = 0;
					ai_swing = 0;
					ai_count = 0;
					turn = 2;
				}
				else if (ball_y > 800 && ball_x > 1678 - 20)
				{
					score_ch2++;
					ball_direction = 0;
					ai_charge_choose = 0;
					ai_charge_start = 0;
					ai_swing = 0;
					ai_count = 0;
					turn = 2;
				}
				else if (ball_y > 800 && ball_x > 960 - 20 && ball_x < 1678 - 20)
				{
					score_ch1++;
					ball_direction = 0;
					turn = 1;
				}
				else if (ball_y > 800 && ball_x < 256 - 20)
				{
					score_ch1++;
					ball_direction = 0;
					turn = 1;
				}

				//공 네트 충돌
				if (ball_y + ball_size_y > 600 && ball_y < 700 && ball_x + ball_size_x > 960 && ball_x < 960)
				{
					if (ball_direction == 1)
						ball_direction = 2;
					else if (ball_direction == 2)
						ball_direction = 1;
					if (ball_move - ball_Dmove - 3 > 0)
						ball_move = 3;
					if (ch1_gravity < 0)
						ch1_gravity = 0;
				}

				//서브 준비중
				if (turn == 1)
				{
					ball_x = ch1_x + 60 + 100;
					ball_y = ch1_y + 50;
				}
				else if (turn == 2)
				{
					ball_x = ch2_x - 20 - ball_size_x;
					ball_y = ch2_y + 50;
				}
			}

			InvalidateRect(hWnd, NULL, FALSE);
		}break;

		case 2://캐릭1 차지
		{
			if (escape_on == 0)
			{
				if (ch1_charge == 1)
					ch1_charge = 2;
				else if (ch1_charge == 2)
					ch1_charge = 3;
			}
		}break;

		case 3://공 공기저항
		{
			if (escape_on == 0)
			{
				ball_Dmove++;
				if (ball_move - ball_Dmove > 0)
					ball_move -= ball_Dmove;
				SetTimer(hWnd, 3, 250, NULL);
			}
		}break;

		case 4://캐릭2 차지
		{
			if (escape_on == 0)
			{
				if (ch2_charge == 1)
					ch2_charge = 2;
				else if (ch2_charge == 2)
					ch2_charge = 3;
			}
		}break;

		case 5://ai
		{
			if (ai_mod == 1)
			{
				if (ball_direction == 0 || ball_direction == 1)
				{
					if (ch2_x > 1500)//이동
					{
						ch2_left = 1;
						ch2_right = 0;
					}
					else if (ch2_x < 1150)//이동
					{
						ch2_left = 0;
						ch2_right = 1;
					}
					else
					{
						ch2_left = 0;
						ch2_right = 0;
					}
				}
				else if (ball_direction == 2)
				{
					if (ball_x > 960)//오른쪽으로 넘어오면
					{
						if (((ball_move - ball_Dmove) / ball_gravity > 1) || ball_gravity < 1)
							ai_charge_choose = 0;
						else
							ai_charge_choose = 1;


						if (ai_charge_choose == 1)
						{
							if (ch2_x > ball_x + 30)//이동
							{
								if (ch2_x > 1005)
								{
									ch2_left = 1;
									ch2_right = 0;
								}
								else
								{
									ch2_left = 0;
									ch2_right = 0;
								}
							}
							else if (ch2_x < ball_x + 30)//이동
							{
								if (ch2_x < 1750)
								{
									ch2_left = 0;
									ch2_right = 1;
								}
								else
								{
									ch2_left = 0;
									ch2_right = 0;
								}
							}
						}
						else if (ai_charge_choose == 0)
						{
							if (ch2_x > ball_x + 50)//이동
							{
								if (ch2_x > 1050)
								{
									ch2_left = 1;
									ch2_right = 0;
								}
								else
								{
									ch2_left = 0;
									ch2_right = 0;
								}
							}
							else if (ch2_x < ball_x + 100)//이동
							{
								if (ch2_x < 1750)
								{
									ch2_left = 0;
									ch2_right = 1;
								}
								else
								{
									ch2_left = 0;
									ch2_right = 0;
								}
							}
						}


						if (ai_charge_start == 0)//넘어오면 차지시작
						{
							if (ch2_charge_on == 0 && ch2_fo_sps == 0 && ch2_back_sps == 0)
							{
								ch2_charge_on = 1;
								ch2_charge = 1;
								SetTimer(hWnd, 4, 500, NULL);
								ai_charge_start = 1;
							}
						}

						if (ai_charge_choose == 1)
						{
							if (ball_x + 220 > ch2_x && ball_y > 370)//스윙
							{
								if (ai_swing == 0)
								{
									ai_swing = 1;

									ch2_racket_degree = -10;
									ch2_racket_active2 = 1;

									ch2_charge_on = 0;
									KillTimer(hWnd, 4);
								}
							}
						}
						else if (ai_charge_choose == 0)
						{
							if (ball_x + 200 > ch2_x && ball_y > 410)//스윙
							{
								if (ai_swing == 0)
								{
									ai_swing = 1;

									ch2_racket_degree = 10;
									ch2_racket_active1 = 1;

									ch2_charge_on = 0;
									KillTimer(hWnd, 4);
								}
							}
						}
					}

					if (ball_x < 960) // 왼쪽이면
					{
						ai_charge_start = 0;
						ai_swing = 0;
					}
				}
				else if (ball_direction == 1 || ball_direction == 0)
				{
					ch2_left = 0;
					ch2_right = 0;
				}

				if (ball_direction == 0 && turn == 2)//서브
				{
					if (ai_count < 25)
					{
						if (ai_count == 0)
						{
							ai_charge_start = 1;

							ch2_charge_on = 1;
							ch2_charge = 1;
							SetTimer(hWnd, 4, 500, NULL);
						}
						ai_count++;
					}
					else if (ai_count == 25)
					{
						if (ai_swing == 0)
						{
							ai_swing = 1;

							ch2_racket_degree = -330;
							ch2_racket_active2 = 1;

							ch2_charge_on = 0;
							KillTimer(hWnd, 4);
							turn = 0;
						}
					}
				}
			}
		}break;

		case 6:
		{
			views = 0;
			KillTimer(hWnd, 6);
		}break;
		}
	}break;

	case  WM_KEYDOWN:
	{
		if (wParam == 'W')
		{
			if (ch1_jump == 1)
			{
				ch1_gravity = -100;
				ch1_y = 649;
				ch1_jump == 0;
			}
		}
		if (wParam == 'A')
		{
			ch1_left = 1;
		}
		if (wParam == 'D')
		{
			ch1_right = 1;
		}
		if (wParam == 'F' && turn == 0)
		{
			if (ch1_charge_on == 0 && ch1_fo_sps == 0 && ch1_back_sps == 0)
			{
				ch1_charge_on = 1;
				ch1_charge = 1;
				SetTimer(hWnd, 2, 500, NULL);
			}
		}
		if (wParam == 'G')
		{
			if (ch1_charge_on == 0 && ch1_fo_sps == 0 && ch1_back_sps == 0)
			{
				ch1_charge_on = 1;
				ch1_charge = 1;
				SetTimer(hWnd, 2, 500, NULL);
			}
		}
		/*
		if (wParam == 'H')//공 이동 테스트용
		{
			ball_x = 1500;
			ball_y = 600;
			ball_direction = 1;//0이면 정지, 1이면 왼쪽, 2이면 오른쪽
			ball_move = 20;//가속력
			ball_gravity = -20;
			ball_Dmove = 0;
			SetTimer(hWnd, 3, 1200, NULL);
		}
		*/
		if (wParam == VK_UP)
		{
			if (ch2_jump == 1)
			{
				ch2_gravity = -100;
				ch2_y = 649;
				ch2_jump == 0;
			}
		}
		if (wParam == VK_LEFT)
		{
			ch2_left = 1;
		}
		if (wParam == VK_RIGHT)
		{
			ch2_right = 1;
		}
		if (wParam == 'O' && turn == 0)
		{
			if (ch2_charge_on == 0 && ch2_fo_sps == 0 && ch2_back_sps == 0)
			{
				ch2_charge_on = 1;
				ch2_charge = 1;
				SetTimer(hWnd, 4, 500, NULL);
			}
		}
		if (wParam == 'P')
		{
			if (ch2_charge_on == 0 && ch2_fo_sps == 0 && ch2_back_sps == 0)
			{
				ch2_charge_on = 1;
				ch2_charge = 1;
				SetTimer(hWnd, 4, 500, NULL);
			}
		}
		if (wParam == VK_ESCAPE)
		{
			if (escape_on == 0)
			{
				escape_on = 1;
				KillTimer(hWnd, 1);
				KillTimer(hWnd, 5);
			}
			else if (escape_on == 1)
			{
				escape_on = 0;
				SetTimer(hWnd, 1, prame, NULL);
				SetTimer(hWnd, 5, prame, NULL);
			}
		}
		InvalidateRect(hWnd, NULL, FALSE);
	}break;

	case  WM_KEYUP:
	{
		if (wParam == 'A')
		{
			ch1_left = 0;
		}
		if (wParam == 'D')
		{
			ch1_right = 0;
		}
		if (wParam == 'F' && turn == 0)
		{
			if (ch1_fo_sps == 0 && ch1_back_sps == 0)
			{
				ch1_racket_degree = -170;
				ch1_racket_active1 = 1;
				ch1_charge_on = 0;
				KillTimer(hWnd, 2);
			}
		}
		if (wParam == 'G')
		{
			if (ch1_fo_sps == 0 && ch1_back_sps == 0)
			{
				ch1_racket_degree = 170;
				ch1_racket_active2 = 1;
				ch1_charge_on = 0;
				KillTimer(hWnd, 2);
			}
		}
		if (wParam == VK_LEFT)
		{
			ch2_left = 0;
		}
		if (wParam == VK_RIGHT)
		{
			ch2_right = 0;
		}
		if (wParam == 'O' && turn == 0)
		{
			if (ch2_fo_sps == 0 && ch2_back_sps == 0)
			{
				ch2_racket_degree = -10;
				ch2_racket_active1 = 1;
				ch2_charge_on = 0;
				KillTimer(hWnd, 4);
			}
		}
		if (wParam == 'P')
		{
			if (ch2_fo_sps == 0 && ch2_back_sps == 0)
			{
				ch2_racket_degree = 10;
				ch2_racket_active2 = 1;
				ch2_charge_on = 0;
				KillTimer(hWnd, 4);
			}
		}
	}

	case WM_PAINT:
	{
		//if (room == 1)
			//OnDraw(hWnd);//캐릭터

		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);

		if (room == 0)
		{
			memdc = CreateCompatibleDC(memDC);

			SelectObject(memdc, start_sp);
			//StretchBlt(memDC, 600, 850, 200, 100, memdc, 0, 0, 200, 100, SRCCOPY);

			background_sp.Draw(memDC, 0, 0, 1920, 1080);//배경
			icon_sp[0].Draw(memDC, 0, 0, 1920, 1080);//아이콘
			icon_sp[1].Draw(memDC, 560, 500, 798, 139);//아이콘
			icon_sp[2].Draw(memDC, 560, 700, 798, 139);//아이콘
			icon_sp[3].Draw(memDC, 560, 900, 798, 139);//아이콘

			DeleteDC(memdc);
		}

		else if (room == 1)
		{

			memdc = CreateCompatibleDC(memDC);
			
			background_sp.Draw(memDC, 0, 0, 1920, 1080);//배경

			if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1 && ch1_fo_sps == 0 && ch1_back_sps == 0)//캐릭1 완벽정지
			{
				ch1_ready_leg_sp[ch1_ready_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				ch1_ready_sp[ch1_ready_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			}
			else if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1)//캐릭1 정지다리
				ch1_leg_sp.Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			else if ((ch1_left == 1 || ch1_right == 1) && ch1_jump == 1)//캐릭1 이동
			{
				ch1_move_leg_sp[ch1_move_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				if (ch1_fo_sps == 0 && ch1_back_sps == 0)
				{
					ch1_move_sp[ch1_move_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				}
			}
			else if (ch1_jump == 0)//캐릭1 점프
			{
				ch1_jump_leg_sp[ch1_jump_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				if (ch1_fo_sps == 0 && ch1_back_sps == 0)
				{
					ch1_jump_sp[ch1_jump_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				}
			}
			if (ch1_back_sps != 0)//캐릭1 벡핸드
				ch1_back_sp[ch1_back_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			if (ch1_fo_sps != 0)//캐릭1 포핸드
				ch1_fo_sp[ch1_fo_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);


			if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1 && ch2_fo_sps == 0 && ch2_back_sps == 0)//캐릭2 완벽정지
			{
				ch2_ready_leg_sp[ch2_ready_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				ch2_ready_sp[ch2_ready_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			}
			else if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1)//캐릭2 정지다리
				ch2_leg_sp.Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			else if ((ch2_left == 1 || ch2_right == 1) && ch2_jump == 1)//캐릭2 이동
			{
				ch2_move_leg_sp[ch2_move_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				if (ch2_fo_sps == 0 && ch2_back_sps == 0)
				{
					ch2_move_sp[ch2_move_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				}
			}
			else if (ch2_jump == 0)//캐릭2 점프
			{
				ch2_jump_leg_sp[ch2_jump_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				if (ch2_fo_sps == 0 && ch2_back_sps == 0)
				{
					ch2_jump_sp[ch2_jump_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				}
			}
			if (ch2_back_sps != 0)//캐릭2 벡핸드
				ch2_back_sp[ch2_back_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			if (ch2_fo_sps != 0)//캐릭2 포핸드
				ch2_fo_sp[ch2_fo_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);

			int gogogo = 0;
			if (ball_gravity < 0)
			{
				if (ball_move - ball_Dmove < abs(ball_gravity))
					gogogo = 0;
				else
				{
					if (ball_direction == 1)
						gogogo = 7;
					else
						gogogo = 1;
				}
			}
			else
			{
				if (ball_move - ball_Dmove < abs(ball_gravity))
				{
					if (ball_direction == 1)
						gogogo = 5;
					else
						gogogo = 3;
				}
				else
				{
					if (ball_direction == 1)
						gogogo = 6;
					else
						gogogo = 2;
				}
			}
			ball_sp[gogogo].Draw(memDC, ball_x, ball_y, ball_size_x, ball_size_y);//공


			scores_sp.Draw(memDC, 585, 50, 750, 150);//점수판
			score_sp[score_ch1 / 10].Draw(memDC, 620, 75, 100, 100);//점수
			score_sp[score_ch1 % 10].Draw(memDC, 775, 75, 100, 100);//점수
			score_sp[score_ch2 / 10].Draw(memDC, 1045, 75, 100, 100);//점수
			score_sp[score_ch2 % 10].Draw(memDC, 1200, 75, 100, 100);//점수


			if (win_ch1 == 1 && win_ch2 == 0 && views == 1)
				vs_sp[0].Draw(memDC, 0, 0, 1920, 1080);
			if (win_ch1 == 0 && win_ch2 == 1 && views == 1)
				vs_sp[1].Draw(memDC, 0, 0, 1920, 1080);
			if (win_ch1 == 1 && win_ch2 == 1 && views == 1)
				vs_sp[2].Draw(memDC, 0, 0, 1920, 1080);
			if (win_ch1 == 2)
			{
				vs_sp[3].Draw(memDC, 0, 0, 1920, 1080);
				KillTimer(hWnd, 1);
				KillTimer(hWnd, 2);
				KillTimer(hWnd, 3);
				KillTimer(hWnd, 4);
				KillTimer(hWnd, 5);
			}
			if (win_ch2 == 2)
			{
				vs_sp[4].Draw(memDC, 0, 0, 1920, 1080);
				KillTimer(hWnd, 1);
				KillTimer(hWnd, 2);
				KillTimer(hWnd, 3);
				KillTimer(hWnd, 4);
				KillTimer(hWnd, 5);
			}


			if(escape_on == 1)
				pause_sp.Draw(memDC, 0, 0, 1920, 1080);//일시정지


			//SelectObject(memdc, ch_sp);
			//StretchBlt(memDC, ch1_x, ch1_y, 100, 150, memdc, 0, 0, 100, 150, SRCCOPY);//캐릭1
			//SelectObject(memdc, ch2_sp);
			//StretchBlt(memDC, ch2_x, ch2_y, 100, 150, memdc, 0, 0, 100, 150, SRCCOPY);//캐릭2


			
			/*
			XFORM xFormRotate; 
			int degree = 130;
			SetGraphicsMode(hdc, GM_ADVANCED);  
			xFormRotate.eM11 = (float)cos(degree*3.14/180);
			xFormRotate.eM12 = (float)sin(degree*3.14/180);  
			xFormRotate.eM21 = (float)-sin(degree*3.14/180);  
			xFormRotate.eM22 = (float)cos(degree*3.14/180);  
			xFormRotate.eDx = 00;  
			xFormRotate.eDy = 00;  
			SetWorldTransform (hdc, &xFormRotate);
			*/



			DeleteDC(memdc);
		}

		COLORREF text_color;
		text_color = RGB(255, 255, 255);
		SetTextColor(hdc, text_color);
		text_color = RGB(0, 0, 0);
		SetBkColor(hdc, text_color);
		char score1[1];
		score1[0] = score_ch1 + 48;
		char score2[1];
		score2[0] = score_ch2 + 48;
		//TextOut(memDC, 200, 200, score1, 1);//캐릭1 점수
		//TextOut(memDC, 600, 200, score2, 1);//캐릭2 점수

		//임시 라켓 , 공, 차지
		if (room == 1)
		{
			hBrush = CreateSolidBrush(RGB(255, 0, 0));
			oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
			oldPen = (HPEN)SelectObject(memDC, hPen);

			//Rectangle(memDC, ch1_racket_x, ch1_racket_y, ch1_racket_x + ch1_racket_size_x, ch1_racket_y + ch1_racket_size_y);
			//Rectangle(memDC, ch2_racket_x, ch2_racket_y, ch2_racket_x + ch2_racket_size_x, ch2_racket_y + ch2_racket_size_y);
			//Ellipse(memDC, ball_x, ball_y, ball_x + ball_size_x, ball_y + ball_size_y);

			if (ch1_charge >= 1)
				Rectangle(memDC, 50, 1000, 70, 1060);
			if (ch1_charge >= 2)
				Rectangle(memDC, 80, 1000, 100, 1060);
			if (ch1_charge >= 3)
				Rectangle(memDC, 110, 1000, 130, 1060);

			if (ch2_charge >= 1)
				Rectangle(memDC, 1810, 1000, 1830, 1060);
			if (ch2_charge >= 2)
				Rectangle(memDC, 1840, 1000, 1860, 1060);
			if (ch2_charge >= 3)
				Rectangle(memDC, 1870, 1000, 1890, 1060);

			SelectObject(memDC, oldPen);
			DeleteObject(hPen);
			SelectObject(memDC, oldBrush);
			DeleteObject(hBrush);
		}
		//

		//임시 라인
		/*
		if (room == 1)
		{
			hBrush = CreateSolidBrush(RGB(0, 0, 0));
			oldBrush = (HBRUSH)SelectObject(memDC, hBrush);
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 255, 255));
			oldPen = (HPEN)SelectObject(memDC, hPen);

			MoveToEx(memDC, 0, 800, NULL);
			LineTo(memDC, 1920, 800);
			MoveToEx(memDC, 960, 600, NULL);
			LineTo(memDC, 960, 800);

			SelectObject(memDC, oldPen);
			DeleteObject(hPen);
			SelectObject(memDC, oldBrush);
			DeleteObject(hBrush);
		}
		*/
		//

		BitBlt(hdc, 0, 0, window_x, window_y, memDC, 0, 0, SRCCOPY);
		DeleteDC(memDC);
		DeleteObject(hBitmap);
		EndPaint(hWnd, &ps);

	}break;

	case WM_LBUTTONDOWN:
	{
		if (room == 0)
		{
			if (mouse_x > 560 && mouse_x < 1360 && mouse_y > 500 && mouse_y < 640)
			{
				room = 1;
				ai_mod = 1;
			}
			if (mouse_x > 560 && mouse_x < 1360 && mouse_y > 700 && mouse_y < 840)
			{
				room = 1;
				ai_mod = 0;
			}
			if (mouse_x > 560 && mouse_x < 1360 && mouse_y > 900 && mouse_y < 1040)
			{
				exit(1);
			}
		}
		if (win_ch1 == 2 || win_ch2 == 2)
		{
			SetTimer(hWnd, 1, prame, NULL);//기본 프레임
			SetTimer(hWnd, 5, prame, NULL);//ai전용 프레임

			room = 0;//0은 시작화면 1은 게임화면
			score_ch1 = 0;//캐릭1 스코어
			score_ch2 = 0;//캐릭2 스코어
			win_ch1 = 0;//캐릭1 세트승
			win_ch2 = 0;//캐릭2 세트승
			views = 0;//1이면 보여줌
			turn = 1;//0 플레이중, 1 캐릭1선공, 2 캐릭2선공
			escape_on = 0; //esc누르면 1

							   //캐릭터 1
			 ch1_x = 200;
			 ch1_y = 650;
			 ch1_jump = 1;//점프시 0이어서 더블점프 방지
			 ch1_gravity = 0;//중력값 -면 상승
			 ch1_left = 0;//'a'키 누를경우 왼쪽이동
			 ch1_right = 0;//'a'키 누를경우 왼쪽이동
			 ch1_charge = 0;
			 ch1_charge_on = 0;//'G'키 누를시 1
			 ch1_skill_charge = 0;

			 ch1_racket_size_x = 70;
			 ch1_racket_size_y = 70;
			 ch1_racket_x = 0;
			 ch1_racket_y = 0;
			 ch1_racket_active1 = 0;//포핸드 휘두르면 1
			 ch1_racket_active2 = 0;//백핸드 휘두르면 1
			 ch1_racket_degree = 0;//회전각

								  //캐릭터 2
			 ch2_x = 1620;
			 ch2_y = 650;
			 ch2_jump = 1;//점프시 0이어서 더블점프 방지
			 ch2_gravity = 0;//중력값 -면 상승
			 ch2_left = 0;//'a'키 누를경우 왼쪽이동
			 ch2_right = 0;//'a'키 누를경우 왼쪽이동
			 ch2_charge = 0;
			 ch2_charge_on = 0;//'G'키 누를시 1
			 ch2_skill_charge = 0;

			 ch2_racket_size_x = 70;
			 ch2_racket_size_y = 70;
			 ch2_racket_x = 0;
			 ch2_racket_y = 0;
			 ch2_racket_active1 = 0;//포핸드 휘두르면 1
			 ch2_racket_active2 = 0;//백핸드 휘두르면 1
			 ch2_racket_degree = 180;//회전각

									//공
			 ball_size_x = 39;
			 ball_size_y = 39;
			 ball_x = 1500;
			 ball_y = 600;
			 ball_direction = 0;//0 정지, 1 왼쪽, 2 오른쪽
			 ball_gravity = -20;//중력값 -면 상승
			 ball_move = 20;//가속력
			 ball_Dmove = 0;//공기저항, 속도 = 가속도-공기저항
			 ball_degree = 0;//회전각

							//ai
			 ai_mod = 0;//1이면 ai모드
			 ai_charge_choose = 0;//0이면 포헨드 1이면 백헨드
			 ai_charge_start = 0;//차지시 1
			 ai_swing = 0;//스윙시 1
			 ai_count = 0;//서브용 카운트 

						 //이미지
			 ch1_fo_sps = 0;
			 ch1_back_sps = 0;
			 ch1_jump_sps = 0;
			 ch1_move_sps = 0;
			 ch1_ready_sps = 0;

			 ch2_fo_sps = 0;
			 ch2_back_sps = 0;
			 ch2_jump_sps = 0;
			 ch2_move_sps = 0;
			 ch2_ready_sps = 0;
			 ball_sps = 0;
		}
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
		KillTimer(hWnd, 4);
		KillTimer(hWnd, 5);
		KillTimer(hWnd, 6);
		PostQuitMessage(0);
	}break;

	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}