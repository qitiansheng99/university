#include"game.h"
void Initbroad(char arr[row][col], int r, int c)
{
	int j;
	int i;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void Display(char arr[row][col], int r, int c)
{
	int i;
	int x = 1;
	int y = 1;
	for (i = 0; i < col; i++)
	{
		printf(" %d  ",x );
		x++;
	}
	printf("\n");
	for (i = 0; i < row; i++)
	{
		int j;
		for (j = 0; j < col; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf(" %d", y);
		y++;
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}
void Player1(char arr[row][col], int r, int c)
{
	int x;
	int y;
	printf("该玩家1下棋了\n");
	while (1)
	{
		printf("请输入所下位置的坐标:>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入:>\n");
			}
		}
		else
		{
			printf("该坐标超出棋盘范围，请重新输入:>\n");
		}
	}
}
void Player2(char arr[row][col], int r, int c)
{
	int x;
	int y;
	printf("该玩家2下棋了\n");
	while (1)
	{
		printf("请输入所下位置的坐标:>\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标已被占用，请重新输入:>\n");
			}
		}
		else
		{
			printf("该坐标超出棋盘范围，请重新输入:>\n");
		}
	}
}
void Computer(char arr[row][col], int r, int c)
{
	int x;
	int y;
	while (1)
	{
		x = rand() % col;
		y = rand() % row;
		if (arr[x][y] == ' ')
		{
			arr[x][y] = '#';
			break;
		}
	}
}
int Isfull(char arr[row][col],int r,int c)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		for (j = 0 ; j < col; j++)
		{
			if (arr[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char Iswin(char arr[row][col], int r, int c)
{
	int i;
	int j;
	for (i = 0; i < row; i++)
	{
		int x;
		for (x=2;x<=col-3;x++)
		{
			if (arr[i][x-2] == arr[i][x-1] && arr[i][x-1] == arr[i][x] && arr[i][x] == arr[i][x+1] && arr[i][x+1]==arr[i][x+2] && arr[i][x] != ' ')
			{
				return arr[i][x];
			}
		}
	}
	for (j = 0; j < col; j++)
	{
		int y;
		for (y=2;y<=row-3;y++)
		{
			if (arr[y-2][j] == arr[y-1][j] && arr[y-1][j] == arr[y][j] && arr[y][j]==arr[y+1][j] && arr[y+1][j]==arr[y+2][j] && arr[y][j] != ' ')
			{
				return arr[y][j];
			}
		}
	}
	for (i = 0; i < col; i++)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
	{
		for (j = 0; j < row; j++)
		{
			if (arr[i][j] == arr[i + 1][j + 1] && arr[i + 1][j + 1] == arr[i + 2][j + 2] && arr[i + 3][j + 3] == arr[i + 2][j + 2] && arr[i + 3][j + 3] == arr[i + 4][j + 4] && arr[i][j] != ' ')
			{
				return arr[i][j];
			}
		}
	}
	for (i = col-1; i >= 0; i--)
	{
		for (j = 0; j < row; j++)
		{
			if (arr[i][j] == arr[i + 1][j - 1] && arr[i + 1][j - 1] == arr[i + 2][j - 2] && arr[i + 3][j - 3] == arr[i + 2][j - 2] && arr[i + 3][j - 3] == arr[i + 4][j - 4] && arr[i][j] != ' ')
			{
				return arr[i][j];
			}
		}
	}
	if (1 == Isfull(arr,row,col))
	{
		return 'Q';
	}
	return 'c';
}