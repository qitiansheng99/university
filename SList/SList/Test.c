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
		printf("请输入操作数:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入需要添加的元素:>");
			scanf("%d", &x);
			SLTPushFront(&plist, x);
			printf("添加成功\n");
			break;
		case 2:
			printf("请输入需要添加的元素:>");
			scanf("%d", &x);
			SLTPushBack(&plist, x);
			printf("添加成功\n");
			break;
		case 3:
			SLTPopFront(&plist);
			printf("删除成功\n");
			break;
		case 4:
			SLTPopBack(&plist);
			printf("删除成功\n");
			break;
		case 5:
			printf("请输入要在哪个元素前插入:>");
			scanf("%d", &x);
			pos = SLTFind(plist, x);
			printf("请输入需要添加的元素:>");
			scanf("%d", &x);
			SLTInsert(&plist, pos, x);
			printf("添加成功\n");
			break;
		case 6:
			printf("请输入删除的元素:>");
			scanf("%d", &x);
			pos = SLTFind(plist, x);
			SLTErase(&plist,pos);
			printf("删除成功\n");
			break;
		case 7:
			printf("请输入需要查找的元素:>");
			scanf("%d", &x);
			SLTFindAll(plist, x);
			break;
		case 8:
			SLTprintf(plist);
			break;
		case 0:
			SLTDestory(&plist);
			printf("感谢您的使用，再见\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			input = 1;
			break;
		}
	} while (input);
	return 0;
}