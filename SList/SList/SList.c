#include"SList.h"

SLTNode* BuyListNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror;
		exit(-1);
	}
	newnode->next = NULL;
	newnode->data = x;
	return newnode;
}

void SLTprintf(SLTNode* phead)
{
	if (phead == NULL)
	{
		printf("NULL\n");
	}
	else
	{
		SLTNode* ret = phead;
		while (ret != NULL)
		{
			printf("%d ", ret->data);
			ret = ret->next;
		}
		printf("\n");
	}
}


void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	if ((*pphead) == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLTNode* ret = *pphead;
		while (ret->next != NULL)
		{
			ret = ret->next;
		}

		ret->next = newnode;

	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuyListNode(x);
	newnode->next = *pphead;
	*pphead = newnode;

}

void SLTPopBack(SLTNode** pphead)
{
	if ((*pphead) == NULL)
	{
		printf("该链表中没有元素\n");
	}
	else if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* ret = *pphead;
		SLTNode* prev = NULL;
		while (ret->next != NULL)
		{
			prev = ret;
			ret = ret->next;
		}
		free(ret);
		ret = NULL;
		prev->next = NULL;
	}
}

void SLTPopFront(SLTNode** pphead)
{
	if ((*pphead) == NULL)
	{
		printf("该链表中没有元素\n");
	}
	else
	{
		SLTNode* ret = (*pphead)->next;
		free(*pphead);
		*pphead = ret;
	}
}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* ret = phead;
	while (ret != NULL)
	{
		if (ret->data == x)
		{
			return ret;
		}
		else
		{
			ret = ret->next;
		}
	}
	return NULL;
}

void SLTFindAll(SLTNode* phead, SLTDataType x)
{
	int i = 1;
	SLTNode* pos = SLTFind(phead, x);
	while(pos != NULL)
	{
		printf("第%d个该元素所在地址：%p\n",i++, pos);
		pos = SLTFind(pos->next, x);
	}
}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLTNode* newnode = BuyListNode(x);
		SLTNode* posprev = *pphead;
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		newnode->next = pos;
		posprev->next = newnode;
	}
}

void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* posprev = *pphead;
		while (posprev->next != pos)
		{
			posprev = posprev->next;
		}
		posprev->next = pos->next;
		free(pos);
	}
}

void SLTDestory(SLTNode** pphead)
{
	SLTNode* ret = *pphead;
	SLTNode* pos = NULL;
	while (*pphead != NULL)
	{ 
		ret = *pphead;
		*pphead = (*pphead)->next;
		free(ret);
	}
}