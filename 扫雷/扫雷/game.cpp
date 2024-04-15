#include"game.h"
void Initboard(char board[ROWS][COLS], int r, int c, char set)
{
	int i;
	int j;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			board[i][j] = set;
		}
	}
}
void Setmine(char board[ROWS][COLS], int r, int c)
{
	int flag = count;
	while (flag)
	{
		int x = rand() % r + 1;
		int y = rand() % c + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			flag--;
		}
	}
}
void Display(char board[ROWS][COLS], int r, int c)
{
	int i;
	int j;
	for (i = 0; i <= r; i++)
	{
		printf(" %d  ", i);
	}
	printf("\n");
	for (i = 0; i <= r; i++)
	{
		printf("--- ");
	}
	printf("\n");
	for (i = 1; i <= r; i++)
	{
		printf("%d  |", i);
		for (j = 1; j <= c; j++)
		{
			printf(" %c |", board[i][j]);
		}
		printf("\n");
			for (j = 0; j <= c; j++)
			{
				if (i < r)
				{
					printf("---");
					printf("|");
				}
			}
		printf("\n");
	}
}
int get_mine_count(char board[ROWS][COLS],int x, int y)
{
		int i, j;
		int sum = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= y + 1; j++)
			{
				sum += board[i][j];
			}
		}
		return sum - 9 * '0';
}
void Digui(char mine[ROWS][COLS],char show[ROWS][COLS],int x,int y)
{
	if (x >= 0 && x <= ROWS && y >= 0 && y <= COLS)
	{
		int a = get_mine_count(mine, x, y);
		if (a == 0)
		{
			show[x][y] = ' ';
			int i, j;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')
					{
						Digui(mine, show, i, j);
					}
				}
			}
		}
		else
		{
			show[x][y] = a + '0';
		}
	}
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int r, int c)
{
	int i, j;
	int win = 0;
	int flag = 0;
	int x, y;
	while (1)
	{
		printf("ÇëÊäÈë×ø±ê\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= r && y >= 1 && y <= c)
		{
			if (mine[x][y] == '1')
			{
				printf("ºÜÒÅº¶£¬²Èµ½À×ÁË\n");
				Display(mine, r, c);
				flag = 1;
				break;
			}
			else
			{
				Digui(mine,show,x,y);
				system("cls");
				Display(show, r, c);
			}
		}
		else
		{
			printf("¸Ã×ø±ê³¬³öÆåÅÌ·¶Î§£¬ÇëÖØÐÂÊäÈë\n");
		}
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c; j++)
			{
				if (show[i][j] == '*')
					win++;
			}
		}
		if (win == 10)
		{
			flag = 0;
			break;
		}
	}
	if (flag == 0)
	{
		printf("¹§Ï²Äã£¬ÓÎÏ·Ê¤Àû\n");
	}
}