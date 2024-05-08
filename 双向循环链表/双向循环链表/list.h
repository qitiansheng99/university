#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int typedata;

typedef struct ListNode
{
	typedata data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

LTNode* LTNodeInit();

void LTNodePrint(struct ListNode* phead);
LTNode* BuyLTNode(typedata x);

void ListPushBack(struct ListNode* phead, typedata x);
void ListPopBack(struct ListNode* phead);
void ListPushFront(struct ListNode* phead, typedata x);
void ListPopFront(struct ListNode* phead);

LTNode* ListFind(struct ListNode* phead, typedata x);

void ListInsert(LTNode* pos,typedata x);
void ListErase(LTNode* pos);

void ListDestory(struct ListNode* phead);