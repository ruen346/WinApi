#pragma once

//�� �ڵ忡�� ���� ���� ����//

int room = 0;//0�� ����ȭ�� 1�� ����ȭ��
int score_ch1 = 0;//ĳ��1 ���ھ�
int score_ch2 = 0;//ĳ��2 ���ھ�
int win_ch1 = 0;//ĳ��1 ��Ʈ��
int win_ch2 = 0;//ĳ��2 ��Ʈ��
int views = 0;//1�̸� ������
int turn = 1;//0 �÷�����, 1 ĳ��1����, 2 ĳ��2����
int escape_on = 0; //esc������ 1

//ĳ���� 1
int ch1_x = 200;
int ch1_y = 650;
int ch1_jump = 1;//������ 0�̾ �������� ����
int ch1_gravity = 0;//�߷°� -�� ���
int ch1_left = 0;//'a'Ű ������� �����̵�
int ch1_right = 0;//'a'Ű ������� �����̵�
int ch1_charge = 0;
int ch1_charge_on = 0;//'G'Ű ������ 1
int ch1_skill_charge = 0;

//���� 1
int ch1_racket_size_x = 70;
int ch1_racket_size_y = 70;
int ch1_racket_x = 0;
int ch1_racket_y = 0;
int ch1_racket_active1 = 0;//���ڵ� �ֵθ��� 1
int ch1_racket_active2 = 0;//���ڵ� �ֵθ��� 1
int ch1_racket_degree = 0;//ȸ����

//ĳ���� 2
int ch2_x = 1620;
int ch2_y = 650;
int ch2_jump = 1;//������ 0�̾ �������� ����
int ch2_gravity = 0;//�߷°� -�� ���
int ch2_left = 0;//'a'Ű ������� �����̵�
int ch2_right = 0;//'a'Ű ������� �����̵�
int ch2_charge = 0;
int ch2_charge_on = 0;//'G'Ű ������ 1
int ch2_skill_charge = 0;

//���� 2
int ch2_racket_size_x = 70;
int ch2_racket_size_y = 70;
int ch2_racket_x = 0;
int ch2_racket_y = 0;
int ch2_racket_active1 = 0;//���ڵ� �ֵθ��� 1
int ch2_racket_active2 = 0;//���ڵ� �ֵθ��� 1
int ch2_racket_degree = 180;//ȸ����

//��
int ball_size_x = 39;
int ball_size_y = 39;
int ball_x = 1500;
int ball_y = 600;
int ball_direction = 0;//0 ����, 1 ����, 2 ������
int ball_gravity = -20;//�߷°� -�� ���
int ball_move = 20;//���ӷ�
float ball_Dmove = 0;//��������, �ӵ� = ���ӵ�-��������
int ball_degree = 0;//ȸ����

//ai
int ai_mod = 0;//1�̸� ai���
int ai_charge_choose = 0;//0�̸� ����� 1�̸� �����
int ai_charge_start = 0;//������ 1
int ai_swing = 0;//������ 1
int ai_count = 0;//����� ī��Ʈ 

//�̹���
int ch1_fo_sps = 0;
int ch1_back_sps = 0;
int ch1_jump_sps = 0;
int ch1_move_sps = 0;
int ch1_ready_sps = 0;

int ch2_fo_sps = 0;
int ch2_back_sps = 0;
int ch2_jump_sps = 0;
int ch2_move_sps = 0;
int ch2_ready_sps = 0;
int ball_sps = 0;