#include"chessboard.h"


#define g_wide 25//格子宽度
#define interval (3*g_wide)//间隔大小

void drawchessboard()//绘制棋盘
{
	initgraph(600,480);
	IMAGE img_chessboard;
	loadimage(&img_chessboard, "./res/chessboard.jpg");
	putimage(0, 0, &img_chessboard);
	draw();
}
void draw()//绘制格子
{
	setlinecolor(BLACK);
	for (int i = 0; i < 15; i++)
	{
		//绘制线条
		line(interval, interval+i*g_wide, g_wide * 14+interval , interval+i*g_wide);
		line(interval + i * g_wide, interval, interval + i * g_wide, interval + g_wide * 14);
	}
	//绘制矩形加粗边框
	setlinestyle(PS_SOLID, 2);
	rectangle(interval, interval, g_wide * 14 + interval, g_wide * 14 + interval);
	//绘制天元、星
	setfillcolor(BLACK);
	solidcircle(g_wide * 7 + interval, g_wide * 7 + interval,3);
	solidcircle(g_wide * 3 + interval, g_wide * 3 + interval, 3);
	solidcircle(g_wide * 3 + interval, g_wide * 11 + interval, 3);
	solidcircle(g_wide * 11 + interval, g_wide * 3 + interval, 3);
	solidcircle(g_wide * 11 + interval, g_wide * 11 + interval, 3);
}