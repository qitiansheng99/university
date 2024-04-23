#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* SLT_turn(SLTNode* head)
{
	SLTNode* n1, * n2, * n3;
	if (head == NULL)
	{
		return NULL;
	}
	n1 = NULL;
	n2 = head;
	n3 = head->next;
	while (n2 != 0)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
		{
			n3 = n3->next;
		}
	}
	return n1;
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
	//直接进行翻转
	plist = SLT_turn(plist);
	while (plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;
	}
	return 0;
}