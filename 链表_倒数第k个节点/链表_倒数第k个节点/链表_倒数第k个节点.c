#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//利用双指针，先使快指针行走k步，使快慢指针相距k格，当快指针走完时，慢指针即是倒数第k个节点的位置，只需遍历一次

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* seek_k(SLTNode* head,int x)
{
	SLTNode* fast, * slow;
	slow = head;
	fast = head;
	for (int i = 0; i < x; i++)
	{
		fast = fast->next;
	}
	while (fast != NULL)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main()
{
	SLTNode* plist = NULL;
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n4 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n5 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	plist = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = NULL;
	int x;
	scanf("%d", &x);
	SLTNode* pos = seek_k(plist,x);
	printf("%d\n", pos->data);
	return 0;
}