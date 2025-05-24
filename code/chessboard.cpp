#include"chessboard.h"


#define g_wide 25//���ӿ��
#define interval (3*g_wide)//�����С

void drawchessboard()//��������
{
	initgraph(600,480);
	IMAGE img_chessboard;
	loadimage(&img_chessboard, "./res/chessboard.jpg");
	putimage(0, 0, &img_chessboard);
	draw();
}
void draw()//���Ƹ���
{
	setlinecolor(BLACK);
	for (int i = 0; i < 15; i++)
	{
		//��������
		line(interval, interval+i*g_wide, g_wide * 14+interval , interval+i*g_wide);
		line(interval + i * g_wide, interval, interval + i * g_wide, interval + g_wide * 14);
	}
	//���ƾ��μӴֱ߿�
	setlinestyle(PS_SOLID, 2);
	rectangle(interval, interval, g_wide * 14 + interval, g_wide * 14 + interval);
	//������Ԫ����
	setfillcolor(BLACK);
	solidcircle(g_wide * 7 + interval, g_wide * 7 + interval,3);
	solidcircle(g_wide * 3 + interval, g_wide * 3 + interval, 3);
	solidcircle(g_wide * 3 + interval, g_wide * 11 + interval, 3);
	solidcircle(g_wide * 11 + interval, g_wide * 3 + interval, 3);
	solidcircle(g_wide * 11 + interval, g_wide * 11 + interval, 3);
}