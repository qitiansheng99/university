#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("#################################\n");
	printf("#####1.开始游戏   2.退出游戏#####\n");
	printf("#################################\n");
}
void game()
{
	int f = 6;
	int i;
	int guess;
	int ret = rand() % 100 + 1;
	int xz;
	printf("猜数字\n");
	printf("开始猜吧,你只有七次机会哦\n");
	for (i = 0; i < 7; i++)
	{
		scanf("%d", &guess);
		getchar();
		if (guess > ret)
		{
			printf("猜大了,你还剩%d次机会\n",f);
		}
		else if (guess < ret)
		{
			printf("猜小了,你还剩%d次机会\n",f);
		}
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
		f--;
	}
	if (i == 7)
	{
		printf("不好意思哦，失败了\n正确答案是%d\n",ret);
	}

}
int main()
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
		case 2:
			printf("欢迎下次来玩\n");
			input = 0;
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}