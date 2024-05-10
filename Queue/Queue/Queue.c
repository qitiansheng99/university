#include"Queue.h"

void QueueInit(Queue* pd)
{
	assert(pd);
	pd->head = NULL;
	pd->tail = NULL;
	pd->size = 0;
}

void QueueDestroy(Queue* pd)
{
	assert(pd);
	QueueNode* cur = pd->head;
	while (cur)
	{
		QueueNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pd->tail = NULL;
	pd->head = NULL;
}

void QueuePush(Queue* pd, QDatatype x)
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->val = x;
	newnode->next = NULL;
	if (pd->head == NULL)
	{
		pd->head = newnode;
		pd->tail = newnode;
		pd->size++;
	}
	else
	{
		pd->tail->next = newnode;
		pd->tail = newnode;
		pd->size++;
	}
}

void QueuePop(Queue* pd)
{
	assert(pd);
	assert(pd->head != NULL);
	if (pd->head == pd->tail)
	{
		pd->tail = NULL;
	}
	QueueNode* cur = pd->head;
	pd->head = pd->head->next;
	free(cur);
	pd->size--;
}

QDatatype QueueFront(Queue* pd)
{
	assert(pd);
	assert(pd->head != NULL);

	return pd->head->val;
}

QDatatype QueueBack(Queue* pd)
{
	assert(pd);
	assert(pd->head != NULL);

	return pd->tail->val;
}

int QueueSize(Queue* pd)
{
	return pd->size;
}

bool QueueEmpty(Queue* pd)
{
	assert(pd);
	return pd->head == NULL;
}