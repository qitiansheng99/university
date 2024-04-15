#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("***************************\n");
	printf("********  1. play  ********\n");
	printf("********  0. exit  ********\n");
	printf("***************************\n");
	printf("\n");
	printf("请选择\n");
}
void game()
{
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Setmine(mine,ROW,COL);
	Display(show,ROW,COL);
	//Display(mine, ROW, COL);
	Findmine(mine,show,ROW,COL);
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		    case 1:
				game();
				break;
			case 0:
				printf("游戏已退出\n");
				break;
			default :
				printf("输入错误，请重新输入\n");
				break;
		}
	} while (input);
}
int main()
{
	
	test();
	return 0;
}