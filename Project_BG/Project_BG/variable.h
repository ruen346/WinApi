#pragma once

//본 코드에서 쓰는 변수 모음//

class Ch //캐릭터
{
public:
	int x;
	int y = 600;

	//행동관련
	int left = 0;
	int right = 0;
	int up = 0;
	int play = 0; //1.포핸드

	int gravity = 0; //중력
};

Ch ch1;
Ch ch2;


class Ball //공
{
public:
	int x;
	int y;

	int move = 0; //0.정지 1.왼쪽 2.오른쪽
	int gravity = 0; //중력
	int speed; //속도
	int delta; //중력분기, 공기저항
};

Ball ball;


class Game
{
public:

};