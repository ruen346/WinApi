#pragma once

//본 코드에서 쓰는 변수 모음//

//캐릭터 가상박스 관련
#define start_x 170
#define start_y 150
#define end_x 280
#define end_y 270
#define size_x 450
#define size_y 450
#define nete_y 700

class Ch //캐릭터
{
public:
	int x;
	int y = 480;

	//행동관련
	int left = 0;
	int right = 0;
	int up = 0;
	int play = 0; //0.스윙x 1.포핸드 2.백핸드
	int plays = 0; //이미지가 더 길어서
	int charge_now = 0; //차지중
	int charge_what = 0; //뭐 차지중인지 1.포핸드 2.백핸드
	int charge = 0; //차지단계
	int crash = 0; //0부터 20까지 충돌 시간

	int skill = 0; //1.스킬1 2.스킬2  사용중 일시정지
	int skill1 = 0; //1.차지 2.좌스메쉬 3.중 4.우

	int gravity = 0; //중력

	//이미지관련
	int run_sp = 0;
	int ready_sp = 0;
	int jump_sp = 0;
	int play1_sp = 0;
	int play1_charge_sp = 0;
	int skill1_sp = 0;
};

Ch ch1;
Ch ch2;


class Ball //공
{
public:
	int x;
	int y;

	int move = 0; //0.정지 1.왼쪽 2.오른쪽
	float gravity = 0; //중력
	float speed; //속도
	int delta; //중력분기, 공기저항

	//충돌 시간에 따른 계산
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
int turn = 1; //0.왼쪽 1.오른쪽
int play_mod = 1; //0.메뉴 1.1인용 2.2인용