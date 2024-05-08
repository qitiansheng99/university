#include"list.h"

LTNode* BuyLTNode(typedata x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	return newnode;
}

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

void ListPushBack(struct ListNode* phead, typedata x)
{
	assert(phead);
	LTNode* newnode = BuyLTNode(x);
	LTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	phead->prev = newnode;
	newnode->next = phead;
}

void ListPopBack(struct ListNode* phead)
{
	assert(phead);
	LTNode* tail = phead->prev;
	tail->prev->next = phead;
	phead->prev = tail->prev;
	free(tail);
}

void ListPushFront(struct ListNode* phead, typedata x)
{
	LTNode* newnode = BuyLTNode(x);
	LTNode* next = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = next;
	next->prev = newnode;
}

void ListPopFront(struct ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);
	LTNode* next = phead->next;
	phead->next = next->next;
	next->prev = phead;
	free(next);
}

LTNode* ListFind(struct ListNode* phead, typedata x)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

void ListInsert(LTNode* pos, typedata x)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* newnode = BuyLTNode(x);
	posprev->next = newnode;
	newnode->prev = posprev;
	newnode->next = pos;
	pos->prev = newnode;
}

void ListErase(LTNode* pos)
{
	assert(pos);
	LTNode* posprev = pos->prev;
	LTNode* posnext = pos->next;
	posprev->next = posnext;
	posnext->prev = posprev;
	free(pos);
}

void ListDestory(struct ListNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;
		free(cur);
		cur = next;
	}
}