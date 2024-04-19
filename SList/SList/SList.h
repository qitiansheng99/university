#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SLTNode;

void SLTprintf(SLTNode* phead);
void SLTPushBack(SLTNode* phead, SLTDataType x);
void SLTPushPoint(SLTNode* phead, SLTDataType x);