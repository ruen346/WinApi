#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <time.h>
#include <atlImage.h> 
#include <MMSystem.h> 
#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "winmm.lib")
using namespace std;

HINSTANCE g_hInst;
LPCTSTR lpszClass = "Window Class Name";
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

//기본코드
int window_x = 1920;
int window_y = 1080;
int window_start_x = 0;
int window_start_y = 0;
int mouse_x = 0;
int mouse_y = 0;
int prame = 20;//프레임(1초는 1000으로 줄일수록 프레임 증가)
int cleck = 0;