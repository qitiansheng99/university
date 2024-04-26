#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* SLT_Partition(SLTNode * phead, int x)
{
	SLTNode* lessHead, * greaterHead, * lessTail, * greaterTail;
	lessHead = (SLTNode*)malloc(sizeof(SLTNode));
	greaterHead = (SLTNode*)malloc(sizeof(SLTNode));
	lessTail = lessHead;
	greaterTail = greaterHead;
	SLTNode* ret = phead;
	while (ret)
	{
		if (ret->data < x)
		{
			lessTail->next = ret;
			lessTail = ret;
		}
		else
		{
			greaterTail->next = ret;
			greaterTail = ret;
		}
		ret = ret->next;
	}
	greaterTail->next = NULL;
	lessTail->next = greaterHead->next;
	SLTNode* cur = lessHead->next;
	free(lessHead);
	free(greaterHead);
	return cur;
}

int main()
{
	SLTNode* plist1 = NULL;
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n6 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 2;
	n2->data = 3;
	n3->data = 5;
	n4->data = 1;
	n5->data = 7;
	n6->data = 2;
	plist1 = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = NULL;
	int x;
	scanf("%d", &x);
	SLTNode* newHead = SLT_Partition(plist1, x);
	while (newHead)
	{
		printf("%d ", newHead->data);
		newHead = newHead->next;
	}
	return 0;
}