#include<stdio.h>
#include<stdlib.h>

//利用快慢指针来找到中间值，只需遍历一次

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

SLTNode* seek_mid(SLTNode* head)
{
	SLTNode* fast, * slow;
	fast = head;
	slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
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
	SLTNode* pos = seek_mid(plist);
	printf("%d\n", pos->data);
	return 0;
}