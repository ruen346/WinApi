#pragma once

//�� �ڵ忡�� ���� ���� ����//

//ĳ���� ����ڽ� ����
#define start_x 170
#define start_y 150
#define end_x 280
#define end_y 270
#define size_x 450
#define size_y 450
#define nete_y 700

class Ch //ĳ����
{
public:
	int x;
	int y = 480;

	//�ൿ����
	int left = 0;
	int right = 0;
	int up = 0;
	int play = 0; //0.����x 1.���ڵ� 2.���ڵ�
	int plays = 0; //�̹����� �� ��
	int charge_now = 0; //������
	int charge_what = 0; //�� ���������� 1.���ڵ� 2.���ڵ�
	int charge = 0; //�����ܰ�
	int crash = 0; //0���� 20���� �浹 �ð�

	int skill = 0; //1.��ų1 2.��ų2  ����� �Ͻ�����
	int skill1 = 0; //1.���� 2.�½��޽� 3.�� 4.��

	int gravity = 0; //�߷�

	//�̹�������
	int run_sp = 0;
	int ready_sp = 0;
	int jump_sp = 0;
	int play1_sp = 0;
	int play1_charge_sp = 0;
	int skill1_sp = 0;
};

Ch ch1;
Ch ch2;


class Ball //��
{
public:
	int x;
	int y;

	int move = 0; //0.���� 1.���� 2.������
	float gravity = 0; //�߷�
	float speed; //�ӵ�
	int delta; //�߷ºб�, ��������

	//�浹 �ð��� ���� ���
	float play1_gravity(int charge)
	{
		if(charge == 1)
			return 7 + (gravity / 20 * 4);
		if (charge == 2)
			return 9 + (gravity / 20 * 4);
		if (charge == 3)
			return 11 + (gravity / 20 * 4);
	}
	float play1_speed(int charge)
	{
		if (charge == 1)
			return 35 - (speed / 20 * 6);
		if (charge == 2)
			return 39 - (speed / 20 * 6);
		if (charge == 3)
			return 44 - (speed / 20 * 6);
	}
	float play2_gravity(int charge)
	{
		if (charge == 1)
			return 12 + (gravity / 20 * 4);
		if (charge == 2)
			return 14 + (gravity / 20 * 4);
		if (charge == 3)
			return 16 + (gravity / 20 * 4);
	}
	float play2_speed(int charge)
	{
		if (charge == 1)
			return 28 - (speed / 20 * 6);
		if (charge == 2)
			return 32 - (speed / 20 * 6);
		if (charge == 3)
			return 37 - (speed / 20 * 6);
	}
};

Ball ball;


int ai_charge = 0;

int score_1 = 0;
int score_2 = 0;
int set_score_1 = 0;
int set_score_2 = 0;
int turn = 1; //0.���� 1.������
int play_mod = 1; //0.�޴� 1.1�ο� 2.2�ο�