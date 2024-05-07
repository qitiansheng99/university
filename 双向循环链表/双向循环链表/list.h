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

void LTNodePushBack(struct ListNode* phead, typedata x);
void LTNodePopBack(struct ListNode* phead);
void LTNodePushFront(struct ListNode* phead, typedata x);
void LTNodePopFront(struct ListNode* phead);
