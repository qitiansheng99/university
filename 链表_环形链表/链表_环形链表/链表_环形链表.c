#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode;

// 定义快慢指针，慢指针一次走一步，快指针一次走两步，当两个指针都进环后，因为快指针
// 的速度始终比慢指针多一，所以当他们每走一次，两者间的距离都会减少一，直到相等


void hasCycle(SLTNode* head)
{
	SLTNode* fast = head, * slow = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			printf("true\n");
			return ;
		}
	}
	printf("false\n");
	return;
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
	hasCycle(plist);
	return 0;
}