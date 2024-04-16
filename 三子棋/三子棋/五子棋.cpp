#include"game.h"
void menu1()
{
	printf("***********************************\n");
	printf("*****    1.play      0.exit   *****\n");
	printf("***********************************\n");
}
void menu2()
{
	printf("***********************************\n");
	printf("*****  1.双人对战 0.电脑对战  *****\n");
	printf("***********************************\n");
	printf("注：电脑是个弱智\n");
}
void game()
{
	int input2;
	
	do
	{
		char ret;
		menu2();
		scanf("%d", &input2);
		char broad[row][col];
		Initbroad(broad, row, col);
		Display(broad, row, col);
		
		switch (input2)
		{
		case 1:
		{
			while (1)
			{
				Player1(broad, row, col);
				Display(broad, row, col);
		        ret = Iswin(broad,row,col);
				if (ret != 'c')
				{
					break;
				}
				Player2(broad, row, col);
				Display(broad, row, col);
				ret = Iswin(broad,row,col);
				if (ret != 'c')
				{
					break;
				}
			}
			if (ret == '*')
			{
				printf("玩家1获胜\n");
			}
			else if (ret == '#')
			{
				printf("玩家2获胜\n");
			}
			else
			{
				printf("平局\n");
			}
			input2 = 0;
			break;
		}
		case 0:
		{
			while (1)
			{
				Player1(broad, row, col);
				Display(broad, row, col);
				ret = Iswin(broad, row, col);
				if (ret != 'c')
				{
					break;
				}
				Computer(broad, row, col);
				Display(broad, row, col);
				ret = Iswin(broad, row, col);
				if (ret != 'c')
				{
					break;
				}
			}
			if (ret == '*')
			{
				printf("玩家1获胜\n");
			}
			else if (ret == '#')
			{
				printf("电脑获胜\n");
			}
			else
			{
				printf("平局\n");
			}
			break;
		}
		default:
		{
			printf("输入错误，请重新输入\n");
			input2 = 1;
			break;
		}
		}

	} while (input2);
}
void test()
{
	srand((unsigned int)time(NULL));
	int input1;
	do
	{
		menu1();
		scanf("%d", &input1);
		printf("\n");
		printf("\n");
		switch (input1)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default :
			printf("输入错误，请重新输入\n");
			break;
		}
	} while (input1);
}
int main()
{
	test();
	return 0;
}