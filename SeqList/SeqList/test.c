#include"SeqList.h"

void menu()
{
	printf("*******************************\n");
	printf("*****  1.ǰ��     2.ǰɾ  *****\n");
	printf("*****  3.���     4.��ɾ  *****\n");
	printf("*****  5.�в�     6.��ɾ  *****\n");
	printf("*****  7.����     8.��ʾ  *****\n");
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
		printf("��ѡ�������:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������ӵ���:>\n");
			scanf("%d", &x);
			Seqlistpushfoint(&sl,x);
			break;
		case 2:
			Seqlistpopfoint(&sl);
			break;
		case 3:
			printf("��������ӵ���:>\n");
			scanf("%d", &x);
			Seqlistpushback(&sl,x);
			break;
		case 4:
			Seqlistpopback(&sl);
			break;
		case 5:
			printf("��������ӵ�������ӵ�λ��:>\n");
			scanf("%d%d", &x,&i);
			Seqlistpushappoint(&sl,x,i);
			break;
		case 6:
			printf("������ɾ����λ��:>\n");
			scanf("%d",&i);
			Seqlistpopappoint(&sl,i);
			break;
		case 7:
			printf("��������Ҫ���ҵ���:>\n");
			scanf("%d", &x);
			Seqlistsearch(&sl,x);
			break;
		case 8:
			Seqlistprint(&sl);
			break;
		case 0:
			printf("��л����ʹ�ã��ټ�\n");
			break;
		default:
			printf("������ѡ��\n");
			break;
		}
	} while (input);
	free(sl.a);
	sl.a = NULL;
	return 0;
}