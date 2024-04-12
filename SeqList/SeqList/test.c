#include"SeqList.h"

void menu()
{
	printf("*******************************\n");
	printf("*****  1.前插     2.前删  *****\n");
	printf("*****  3.后插     4.后删  *****\n");
	printf("*****  5.中插     6.中删  *****\n");
	printf("*****  7.查找     8.显示  *****\n");
	printf("*****  0.exit             *****\n");
	printf("*******************************\n");
}
int main()
{
	int input;
	Sl sl;
	SeqlistInfo(&sl);
	custom x;
	do
	{
		int i;
		menu();
		printf("请选择操作数:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入添加的数:>\n");
			scanf("%d", &x);
			Seqlistpushfoint(&sl,x);
			break;
		case 2:
			Seqlistpopfoint(&sl);
			break;
		case 3:
			printf("请输入添加的数:>\n");
			scanf("%d", &x);
			Seqlistpushback(&sl,x);
			break;
		case 4:
			Seqlistpopback(&sl);
			break;
		case 5:
			printf("请输入添加的数和添加的位置:>\n");
			scanf("%d%d", &x,&i);
			Seqlistpushappoint(&sl,x,i);
			break;
		case 6:
			printf("请输入删除的位置:>\n");
			scanf("%d",&i);
			Seqlistpopappoint(&sl,i);
			break;
		case 7:
			printf("请输入需要查找的数:>\n");
			scanf("%d", &x);
			Seqlistsearch(&sl,x);
			break;
		case 8:
			Seqlistprint(&sl);
			break;
		case 0:
			printf("感谢您的使用，再见\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
	free(sl.a);
	sl.a = NULL;
	return 0;
}