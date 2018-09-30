//�ش� ������//
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


//�����츦 ���� �⺻ �ڵ�//
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;  MSG Message;  WNDCLASSEX WndClass;  g_hInst = hInstance;
	// ������ Ŭ���� ����ü �� ����  
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


//�������� ó�� �ڵ�//
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


		//���� �ʱ�ȭ//
		srand(time(NULL));


		//������ ����//
		SetTimer(hWnd, 1, prame, NULL);//�⺻ ������
		SetTimer(hWnd, 5, prame, NULL);//ai���� ������


		//��Ʈ��//
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
				//����
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


				//�̹���
				if (ch1_racket_active2 == 1 || ch1_back_sps > 0)//ĳ��1 ���ڵ�
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

				if (ch1_racket_active1 == 1 || ch1_fo_sps > 0)//ĳ��1 ���ڵ�
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

				if ((ch1_left == 1 || ch1_right == 1) && ch1_jump == 1)//ĳ��1 �̵�
				{
					if (ch1_move_sps < 23)
						ch1_move_sps++;
					else
						ch1_move_sps = 0;
				}

				if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1)//ĳ��1 ����
				{
					if (ch1_ready_sps < 23)
						ch1_ready_sps++;
					else
						ch1_ready_sps = 0;
				}

				if (ch1_jump == 0)//ĳ��1 ����
				{
					if (ch1_jump_sps < 23)
						ch1_jump_sps++;
					else
						ch1_jump_sps = 0;
				}

				if (ch2_racket_active2 == 1 || ch2_back_sps > 0)//ĳ��2 ���ڵ�
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

				if (ch2_racket_active1 == 1 || ch2_fo_sps > 0)//ĳ��2 ���ڵ�
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

				if ((ch2_left == 1 || ch2_right == 1) && ch2_jump == 1)//ĳ��2 �̵�
				{
					if (ch2_move_sps < 23)
						ch2_move_sps++;
					else
						ch2_move_sps = 0;
				}

				if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1)//ĳ��2 ����
				{
					if (ch2_ready_sps < 23)
						ch2_ready_sps++;
					else
						ch2_ready_sps = 0;
				}

				if (ch2_jump == 0)//ĳ��2 ����
				{
					if (ch2_jump_sps < 23)
						ch2_jump_sps++;
					else
						ch2_jump_sps = 0;
				}

				//�߷�
				if (ch1_y < 650)//ĳ����1
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

				if (ch2_y < 650)//ĳ����2
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

				if (ball_direction == 1)//��
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

				//�̵�
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

				//��ǥ �缳��
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

				//�浹üũ
				if (ch1_racket_active1 == 1)//ĳ���� 1 �����
				{
					if (ball_x + ball_size_x > ch1_racket_x && ball_x < ch1_racket_x + ch1_racket_size_x && ball_y + ball_size_y > ch1_racket_y && ball_y < ch1_racket_y + ch1_racket_size_y)
					{
						if (ch1_jump == 1)//������ ����
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
						else if (ch1_jump == 0)//���߿��� ����
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
				else if (ch1_racket_active2 == 1)//ĳ���� 1 �����
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
				
				if (ch2_racket_active1 == 1)//ĳ���� 2 �����
					{
						if (ball_x + ball_size_x > ch2_racket_x && ball_x < ch2_racket_x + ch2_racket_size_x && ball_y + ball_size_y > ch2_racket_y && ball_y < ch2_racket_y + ch2_racket_size_y)
						{
							if (ch2_jump == 1)//������ ����
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
							else if (ch2_jump == 0)//���߿��� ����
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
				else if (ch2_racket_active2 == 1)//ĳ���� 2 �����
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
				

				//����
				if (ch1_racket_active1 == 1)//���ڵ��
				{
					if (ch1_racket_degree < -110)
						ch1_racket_degree += 12;
					else if (ch1_racket_degree < -60)
						ch1_racket_degree += 35;
					else if(ch1_racket_degree < 70)
						ch1_racket_degree += 55;
				}
				else if (ch1_racket_active2 == 1)//���ڵ��
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
					if (ch2_racket_active1 == 1)//���ڵ��
					{
						if (ch2_racket_degree > -70)
							ch2_racket_degree -= 12;
						else if (ch2_racket_degree > -120)
							ch2_racket_degree -= 35;
						else if (ch2_racket_degree > -250)
							ch2_racket_degree -= 55;
					}
					else if (ch2_racket_active2 == 1)//���ڵ��
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
					if (ch2_racket_active1 == 1)//���ڵ��
					{
						if (ch2_racket_degree > -70)
							ch2_racket_degree -= 12;
						else
							ch2_racket_degree -= 24;
					}
					else if (ch2_racket_active2 == 1)//���ڵ��
					{
						if (ch2_racket_degree < 140)
							ch2_racket_degree += 9;
						else
							ch2_racket_degree += 24;
					}
				}

				//�� �ٴ� �浹
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

				//�� ��Ʈ �浹
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

				//���� �غ���
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

		case 2://ĳ��1 ����
		{
			if (escape_on == 0)
			{
				if (ch1_charge == 1)
					ch1_charge = 2;
				else if (ch1_charge == 2)
					ch1_charge = 3;
			}
		}break;

		case 3://�� ��������
		{
			if (escape_on == 0)
			{
				ball_Dmove++;
				if (ball_move - ball_Dmove > 0)
					ball_move -= ball_Dmove;
				SetTimer(hWnd, 3, 250, NULL);
			}
		}break;

		case 4://ĳ��2 ����
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
					if (ch2_x > 1500)//�̵�
					{
						ch2_left = 1;
						ch2_right = 0;
					}
					else if (ch2_x < 1150)//�̵�
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
					if (ball_x > 960)//���������� �Ѿ����
					{
						if (((ball_move - ball_Dmove) / ball_gravity > 1) || ball_gravity < 1)
							ai_charge_choose = 0;
						else
							ai_charge_choose = 1;


						if (ai_charge_choose == 1)
						{
							if (ch2_x > ball_x + 30)//�̵�
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
							else if (ch2_x < ball_x + 30)//�̵�
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
							if (ch2_x > ball_x + 50)//�̵�
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
							else if (ch2_x < ball_x + 100)//�̵�
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


						if (ai_charge_start == 0)//�Ѿ���� ��������
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
							if (ball_x + 220 > ch2_x && ball_y > 370)//����
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
							if (ball_x + 200 > ch2_x && ball_y > 410)//����
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

					if (ball_x < 960) // �����̸�
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

				if (ball_direction == 0 && turn == 2)//����
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
		if (wParam == 'H')//�� �̵� �׽�Ʈ��
		{
			ball_x = 1500;
			ball_y = 600;
			ball_direction = 1;//0�̸� ����, 1�̸� ����, 2�̸� ������
			ball_move = 20;//���ӷ�
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
			//OnDraw(hWnd);//ĳ����

		hdc = BeginPaint(hWnd, &ps);
		memDC = CreateCompatibleDC(hdc);
		hBitmap = CreateCompatibleBitmap(hdc, window_x, window_y);
		SelectObject(memDC, (HBITMAP)hBitmap);

		if (room == 0)
		{
			memdc = CreateCompatibleDC(memDC);

			SelectObject(memdc, start_sp);
			//StretchBlt(memDC, 600, 850, 200, 100, memdc, 0, 0, 200, 100, SRCCOPY);

			background_sp.Draw(memDC, 0, 0, 1920, 1080);//���
			icon_sp[0].Draw(memDC, 0, 0, 1920, 1080);//������
			icon_sp[1].Draw(memDC, 560, 500, 798, 139);//������
			icon_sp[2].Draw(memDC, 560, 700, 798, 139);//������
			icon_sp[3].Draw(memDC, 560, 900, 798, 139);//������

			DeleteDC(memdc);
		}

		else if (room == 1)
		{

			memdc = CreateCompatibleDC(memDC);
			
			background_sp.Draw(memDC, 0, 0, 1920, 1080);//���

			if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1 && ch1_fo_sps == 0 && ch1_back_sps == 0)//ĳ��1 �Ϻ�����
			{
				ch1_ready_leg_sp[ch1_ready_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				ch1_ready_sp[ch1_ready_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			}
			else if (ch1_left == 0 && ch1_right == 0 && ch1_jump == 1)//ĳ��1 �����ٸ�
				ch1_leg_sp.Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			else if ((ch1_left == 1 || ch1_right == 1) && ch1_jump == 1)//ĳ��1 �̵�
			{
				ch1_move_leg_sp[ch1_move_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				if (ch1_fo_sps == 0 && ch1_back_sps == 0)
				{
					ch1_move_sp[ch1_move_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				}
			}
			else if (ch1_jump == 0)//ĳ��1 ����
			{
				ch1_jump_leg_sp[ch1_jump_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				if (ch1_fo_sps == 0 && ch1_back_sps == 0)
				{
					ch1_jump_sp[ch1_jump_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
				}
			}
			if (ch1_back_sps != 0)//ĳ��1 ���ڵ�
				ch1_back_sp[ch1_back_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);
			if (ch1_fo_sps != 0)//ĳ��1 ���ڵ�
				ch1_fo_sp[ch1_fo_sps].Draw(memDC, ch1_x - 150, ch1_y - 150, 450, 450);


			if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1 && ch2_fo_sps == 0 && ch2_back_sps == 0)//ĳ��2 �Ϻ�����
			{
				ch2_ready_leg_sp[ch2_ready_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				ch2_ready_sp[ch2_ready_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			}
			else if (ch2_left == 0 && ch2_right == 0 && ch2_jump == 1)//ĳ��2 �����ٸ�
				ch2_leg_sp.Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			else if ((ch2_left == 1 || ch2_right == 1) && ch2_jump == 1)//ĳ��2 �̵�
			{
				ch2_move_leg_sp[ch2_move_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				if (ch2_fo_sps == 0 && ch2_back_sps == 0)
				{
					ch2_move_sp[ch2_move_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				}
			}
			else if (ch2_jump == 0)//ĳ��2 ����
			{
				ch2_jump_leg_sp[ch2_jump_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				if (ch2_fo_sps == 0 && ch2_back_sps == 0)
				{
					ch2_jump_sp[ch2_jump_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
				}
			}
			if (ch2_back_sps != 0)//ĳ��2 ���ڵ�
				ch2_back_sp[ch2_back_sps].Draw(memDC, ch2_x - 150, ch2_y - 150, 450, 450);
			if (ch2_fo_sps != 0)//ĳ��2 ���ڵ�
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
			ball_sp[gogogo].Draw(memDC, ball_x, ball_y, ball_size_x, ball_size_y);//��


			scores_sp.Draw(memDC, 585, 50, 750, 150);//������
			score_sp[score_ch1 / 10].Draw(memDC, 620, 75, 100, 100);//����
			score_sp[score_ch1 % 10].Draw(memDC, 775, 75, 100, 100);//����
			score_sp[score_ch2 / 10].Draw(memDC, 1045, 75, 100, 100);//����
			score_sp[score_ch2 % 10].Draw(memDC, 1200, 75, 100, 100);//����


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
				pause_sp.Draw(memDC, 0, 0, 1920, 1080);//�Ͻ�����


			//SelectObject(memdc, ch_sp);
			//StretchBlt(memDC, ch1_x, ch1_y, 100, 150, memdc, 0, 0, 100, 150, SRCCOPY);//ĳ��1
			//SelectObject(memdc, ch2_sp);
			//StretchBlt(memDC, ch2_x, ch2_y, 100, 150, memdc, 0, 0, 100, 150, SRCCOPY);//ĳ��2


			
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
		//TextOut(memDC, 200, 200, score1, 1);//ĳ��1 ����
		//TextOut(memDC, 600, 200, score2, 1);//ĳ��2 ����

		//�ӽ� ���� , ��, ����
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

		//�ӽ� ����
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
			SetTimer(hWnd, 1, prame, NULL);//�⺻ ������
			SetTimer(hWnd, 5, prame, NULL);//ai���� ������

			room = 0;//0�� ����ȭ�� 1�� ����ȭ��
			score_ch1 = 0;//ĳ��1 ���ھ�
			score_ch2 = 0;//ĳ��2 ���ھ�
			win_ch1 = 0;//ĳ��1 ��Ʈ��
			win_ch2 = 0;//ĳ��2 ��Ʈ��
			views = 0;//1�̸� ������
			turn = 1;//0 �÷�����, 1 ĳ��1����, 2 ĳ��2����
			escape_on = 0; //esc������ 1

							   //ĳ���� 1
			 ch1_x = 200;
			 ch1_y = 650;
			 ch1_jump = 1;//������ 0�̾ �������� ����
			 ch1_gravity = 0;//�߷°� -�� ���
			 ch1_left = 0;//'a'Ű ������� �����̵�
			 ch1_right = 0;//'a'Ű ������� �����̵�
			 ch1_charge = 0;
			 ch1_charge_on = 0;//'G'Ű ������ 1
			 ch1_skill_charge = 0;

			 ch1_racket_size_x = 70;
			 ch1_racket_size_y = 70;
			 ch1_racket_x = 0;
			 ch1_racket_y = 0;
			 ch1_racket_active1 = 0;//���ڵ� �ֵθ��� 1
			 ch1_racket_active2 = 0;//���ڵ� �ֵθ��� 1
			 ch1_racket_degree = 0;//ȸ����

								  //ĳ���� 2
			 ch2_x = 1620;
			 ch2_y = 650;
			 ch2_jump = 1;//������ 0�̾ �������� ����
			 ch2_gravity = 0;//�߷°� -�� ���
			 ch2_left = 0;//'a'Ű ������� �����̵�
			 ch2_right = 0;//'a'Ű ������� �����̵�
			 ch2_charge = 0;
			 ch2_charge_on = 0;//'G'Ű ������ 1
			 ch2_skill_charge = 0;

			 ch2_racket_size_x = 70;
			 ch2_racket_size_y = 70;
			 ch2_racket_x = 0;
			 ch2_racket_y = 0;
			 ch2_racket_active1 = 0;//���ڵ� �ֵθ��� 1
			 ch2_racket_active2 = 0;//���ڵ� �ֵθ��� 1
			 ch2_racket_degree = 180;//ȸ����

									//��
			 ball_size_x = 39;
			 ball_size_y = 39;
			 ball_x = 1500;
			 ball_y = 600;
			 ball_direction = 0;//0 ����, 1 ����, 2 ������
			 ball_gravity = -20;//�߷°� -�� ���
			 ball_move = 20;//���ӷ�
			 ball_Dmove = 0;//��������, �ӵ� = ���ӵ�-��������
			 ball_degree = 0;//ȸ����

							//ai
			 ai_mod = 0;//1�̸� ai���
			 ai_charge_choose = 0;//0�̸� ����� 1�̸� �����
			 ai_charge_start = 0;//������ 1
			 ai_swing = 0;//������ 1
			 ai_count = 0;//����� ī��Ʈ 

						 //�̹���
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