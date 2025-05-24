#include"play.h"

int map[15][15] = { 0 };//��¼����λ��
int player = 0;

void chess(COLORREF color, int x, int y)//������
{
	setfillcolor(color);
	solidcircle(x, y, 10);
}
void text(int player)
{
	if (player == 0) 
	{
		settextstyle(24, 12, _T("����"));
		outtextxy(500, 240, "��������");
	}
	else if (player != 0 && player % 2 == 0)
	{
		settextstyle(24, 12, _T("����"));
		settextcolor(WHITE);
		outtextxy(500, 240, "��������");
		outtextxy(500, 240, "��������");
	}
	else
	{
		settextstyle(24, 12, _T("����"));
		settextcolor(WHITE);
		outtextxy(500, 240, "��������");
		outtextxy(500, 240, "��������");
	}
}
bool winner(int a, int b)
{
	int i = 0;
	int j = 0;
	int c = 2 - (player % 2);//��ǰ��ɫ
	//left
	for (int j = 0; j <= 10; j++) 
	{
		if (map[a][j] == c && map[a][j + 1] == c && map[a][j + 2] == c && map[a][j + 3] == c && map[a][j + 4] == c)
		{
			return true;
		}
	}
	//up
	for (i = 0; i <= 10; i++) 
	{
		if (map[i][b] == c && map[i + 1][b] == c && map[i + 2][b] == c && map[i + 3][b] == c && map[i + 4][b] == c)
		{
			return true;
		}
	}
	//right-down
	for (i = 0; i <= 10; i++) 
	{
		for (j = 0; j <= 10; j++) 
		{
			if (map[i][j] == c && map[i + 1][j + 1] == c && map[i + 2][j + 2] == c && map[i + 3][j + 3] == c && map[i + 4][j + 4] == c)
			{
				return true;
			}
		}
	}
	//left-down
	for (i = 4; i < 15; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (map[i][j] == c && map[i - 1][j + 1] == c && map[i - 2][j + 2] == c && map[i - 3][j + 3] == c && map[i - 4][j + 4] == c)
			{
				return true;
			}
		}
	}
	return false;
}
void playchess()
{
	position pos = { 0,0 };
	while(1)
	{
		text(player);
		//��ȡ�����Ϣ
		ExMessage msg;//�����Ϣ�ṹ��
		msg = getmessage();
		//У׼��ǰ��������
		for (int i = 0; i < 15; i++)
		{
			for (int j = 0; j < 15; j++)
			{
				//��ÿ���������Ͻǵ�����
				int g_x = (j + 3) * g_wide;
				int g_y = (i + 3) * g_wide;
				if (abs(msg.x - g_x) < 12 && abs(msg.y - g_y) < 12)
				{
					pos.x = g_x;
					pos.y = g_y;
					pos.nx = i;
					pos.ny = j;
				}
			}
		}
		if (msg.message == WM_LBUTTONDOWN)//������
		{
			if (map[pos.nx][pos.ny] != 0)
			{
				MessageBox(NULL, "�������ӣ�������ѡ��", "���Ӵ���", MB_OK);
			}
			if (player % 2 == 0)//black
			{
				map[pos.nx][pos.ny] = 1;
				chess(BLACK, pos.x, pos.y);
			}
			else//white
			{
				map[pos.nx][pos.ny] = 2;
				chess(WHITE, pos.x, pos.y);
			}
			player++;
		}
		if (winner(pos.nx, pos.ny))
		{
			if (player % 2 == 0)
			{
				MessageBox(NULL, "��ϲ�������ʤ", "��Ϸ����", MB_OK);
				exit(0);
			}
			else
			{
				MessageBox(NULL, "��ϲ�������ʤ", "��Ϸ����", MB_OK);
				exit(0);
			}
		}
	}
}
		


	
	