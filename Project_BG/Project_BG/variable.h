#pragma once

//�� �ڵ忡�� ���� ���� ����//

class Ch //ĳ����
{
public:
	int x;
	int y = 600;

	//�ൿ����
	int left = 0;
	int right = 0;
	int up = 0;
	int play = 0; //1.���ڵ� 2.���ڵ�
	int charge_now = 0; //������
	int charge = 0; //�����ܰ�

	int gravity = 0; //�߷�
};

Ch ch1;
Ch ch2;


class Ball //��
{
public:
	int x;
	int y;

	int move = 0; //0.���� 1.���� 2.������
	int gravity = 0; //�߷�
	int speed; //�ӵ�
	int delta; //�߷ºб�, ��������
};

Ball ball;


class Game
{
public:

};