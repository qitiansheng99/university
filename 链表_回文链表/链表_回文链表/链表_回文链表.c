#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* SLT_turn(SLTNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	SLTNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	n3 = head->next;
	while (n2)
	{
		n2->next = n1;

		n1 = n2;
		n2 = n3;
		if (n3)
		{
			n3 = n3->next;
		}
	}
	return n1;
}

void SLT_IsPalindrome(SLTNode* plist1,SLTNode* plist2)
{
	if (plist1 == NULL)
	{
		printf("Ture\n");
		return;
	}
	SLTNode* cur1 = plist1;
	SLTNode* cur2 = plist2;
	while (cur1)
	{
		if (cur1->data != cur2->data)
		{
			printf("False\n");
			return;
		}
		else
		{
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
	}
	printf("Ture\n");
}

int main()
{
	SLTNode* plist1 = NULL;
	SLTNode* plist2 = NULL;
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 2;
	n5->data = 1;
	plist1 = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	//翻转
	plist2 = SLT_turn(plist1);
	//比较是否相等
	SLT_IsPalindrome(plist1, plist2);
	return 0;
}