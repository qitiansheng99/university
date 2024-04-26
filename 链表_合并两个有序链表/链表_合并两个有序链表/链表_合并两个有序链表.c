#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* SLT_Combine(SLTNode* l1, SLTNode* l2)
{
	if (l1 == NULL)
	{
		return l2;
	}
	if (l2 == NULL)
	{
		return l1;
	}
	SLTNode* newHead = NULL;
	SLTNode* tail = newHead;
	while (l1 && l2)
	{
		if (l1->data < l2->data)
		{
			if (newHead == NULL)
			{
				newHead = l1;
				tail = l1;
			}
			else
			{
				tail->next = l1;
				tail = tail->next;
			}
			l1 = l1->next;
		}
		else
		{
			if (newHead == NULL)
			{
				newHead = l2;
				tail = l2;
			}
			else
			{
				tail->next = l2;
				tail = tail->next;
			}
			l2 = l2->next;
		}
	}
	if (l1)
	{
		tail = l2;
	}
	if(l2)
	{
		tail = l1;
	}
	return newHead;
}

int main()
{
	SLTNode* plist1 = NULL;
	SLTNode* plist2 = NULL;
	SLTNode* n1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* n3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* s1 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* s2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* s3 = (SLTNode*)malloc(sizeof(SLTNode));
	n1->data = 1;
	n2->data = 2;
	n3->data = 5;
	s1->data = 1;
	s2->data = 3;
	s3->data = 5;
	plist1 = n1;
	plist2 = s1;
	n1->next = n2;
	n2->next = n3;
	n3->next = NULL;
	s1->next = s2;
	s2->next = s3;
	s3->next = NULL;
	SLTNode* newHead = SLT_Combine(plist1, plist2);
	while (newHead)
	{
		printf("%d ", newHead->data);
		newHead = newHead->next;
	}
	return 0;
}