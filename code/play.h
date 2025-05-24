#pragma once
#include<graphics.h>
#include<iostream>
#include<cmath>
#include <windows.h>

#define g_wide 25//格子宽度
#define interval (3*g_wide)//间隔大小

using namespace std;

void playchess();
void chess(COLORREF color, int x, int y);
void text(int player);
bool winner(int a, int b);

struct position
{
	int x;
	int y;
	int nx;
	int ny;

};


