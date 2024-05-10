#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int QDatatype;

typedef struct QueueNode
{
	QDatatype val;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* head;
	QueueNode* tail;
	int size;
}Queue;


void QueueInit(Queue* pd);
void QueueDestroy(Queue* pd);
void QueuePush(Queue* pd, QDatatype x);
void QueuePop(Queue* pd);
QDatatype QueueFront(Queue* pd);
QDatatype QueueBack(Queue* pd);
int QueueSize(Queue* pd);
bool QueueEmpty(Queue* pd);