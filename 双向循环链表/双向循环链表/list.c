#include"list.h"

LTNode* LTNodeInit()
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	LTNode* phead = newnode;
	newnode->next = phead;
	newnode->prev = phead;
	return phead;
}

void LTNodePrint(struct ListNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTNodePushBack(struct ListNode* phead, typedata x)
{
	assert(phead);
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void LTNodePopBack(struct ListNode* phead)
{
	assert(phead);
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
}