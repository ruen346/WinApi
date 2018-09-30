#pragma once

//본 코드에서 쓰는 변수 모음//

int room = 0;//0은 시작화면 1은 게임화면
int score_ch1 = 0;//캐릭1 스코어
int score_ch2 = 0;//캐릭2 스코어
int win_ch1 = 0;//캐릭1 세트승
int win_ch2 = 0;//캐릭2 세트승
int views = 0;//1이면 보여줌
int turn = 1;//0 플레이중, 1 캐릭1선공, 2 캐릭2선공
int escape_on = 0; //esc누르면 1

//캐릭터 1
int ch1_x = 200;
int ch1_y = 650;
int ch1_jump = 1;//점프시 0이어서 더블점프 방지
int ch1_gravity = 0;//중력값 -면 상승
int ch1_left = 0;//'a'키 누를경우 왼쪽이동
int ch1_right = 0;//'a'키 누를경우 왼쪽이동
int ch1_charge = 0;
int ch1_charge_on = 0;//'G'키 누를시 1
int ch1_skill_charge = 0;

//라켓 1
int ch1_racket_size_x = 70;
int ch1_racket_size_y = 70;
int ch1_racket_x = 0;
int ch1_racket_y = 0;
int ch1_racket_active1 = 0;//포핸드 휘두르면 1
int ch1_racket_active2 = 0;//백핸드 휘두르면 1
int ch1_racket_degree = 0;//회전각

//캐릭터 2
int ch2_x = 1620;
int ch2_y = 650;
int ch2_jump = 1;//점프시 0이어서 더블점프 방지
int ch2_gravity = 0;//중력값 -면 상승
int ch2_left = 0;//'a'키 누를경우 왼쪽이동
int ch2_right = 0;//'a'키 누를경우 왼쪽이동
int ch2_charge = 0;
int ch2_charge_on = 0;//'G'키 누를시 1
int ch2_skill_charge = 0;

//라켓 2
int ch2_racket_size_x = 70;
int ch2_racket_size_y = 70;
int ch2_racket_x = 0;
int ch2_racket_y = 0;
int ch2_racket_active1 = 0;//포핸드 휘두르면 1
int ch2_racket_active2 = 0;//백핸드 휘두르면 1
int ch2_racket_degree = 180;//회전각

//공
int ball_size_x = 39;
int ball_size_y = 39;
int ball_x = 1500;
int ball_y = 600;
int ball_direction = 0;//0 정지, 1 왼쪽, 2 오른쪽
int ball_gravity = -20;//중력값 -면 상승
int ball_move = 20;//가속력
float ball_Dmove = 0;//공기저항, 속도 = 가속도-공기저항
int ball_degree = 0;//회전각

//ai
int ai_mod = 0;//1이면 ai모드
int ai_charge_choose = 0;//0이면 포헨드 1이면 백헨드
int ai_charge_start = 0;//차지시 1
int ai_swing = 0;//스윙시 1
int ai_count = 0;//서브용 카운트 

//이미지
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