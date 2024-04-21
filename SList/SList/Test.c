#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

void menu()
{
	printf("*******************************************\n");
	printf("***** 1.insert_head     2.insert_tail *****\n");
	printf("***** 3.delete_head     4.delete_tail *****\n");
	printf("***** 5.insert_spec     6.delete_spec *****\n");
	printf("***** 7.search          8.show        *****\n");
	printf("***** 0.exit                          *****\n");
	printf("*******************************************\n");
}

int main()
{
	int input;
	int x;
	SLTNode* pos = NULL;
	SLTNode* plist = NULL;
	do
	{
		menu();
		printf("�����������:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ҫ��ӵ�Ԫ��:>");
			scanf("%d", &x);
			SLTPushFront(&plist, x);
			printf("��ӳɹ�\n");
			break;
		case 2:
			printf("��������Ҫ��ӵ�Ԫ��:>");
			scanf("%d", &x);
			SLTPushBack(&plist, x);
			printf("��ӳɹ�\n");
			break;
		case 3:
			SLTPopFront(&plist);
			printf("ɾ���ɹ�\n");
			break;
		case 4:
			SLTPopBack(&plist);
			printf("ɾ���ɹ�\n");
			break;
		case 5:
			printf("������Ҫ���ĸ�Ԫ��ǰ����:>");
			scanf("%d", &x);
			pos = SLTFind(plist, x);
			printf("��������Ҫ��ӵ�Ԫ��:>");
			scanf("%d", &x);
			SLTInsert(&plist, pos, x);
			printf("��ӳɹ�\n");
			break;
		case 6:
			printf("������ɾ����Ԫ��:>");
			scanf("%d", &x);
			pos = SLTFind(plist, x);
			SLTErase(&plist,pos);
			printf("ɾ���ɹ�\n");
			break;
		case 7:
			printf("��������Ҫ���ҵ�Ԫ��:>");
			scanf("%d", &x);
			SLTFindAll(plist, x);
			break;
		case 8:
			SLTprintf(plist);
			break;
		case 0:
			SLTDestory(&plist);
			printf("��л����ʹ�ã��ټ�\n");
			break;
		default:
			printf("�����������������\n");
			input = 1;
			break;
		}
	} while (input);
	return 0;
}