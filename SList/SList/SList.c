#include"SList.h"

void SLTprintf(SLTNode* phead)
{
	SLTNode* ret = phead;
	while (ret != NULL)
	{
		printf("%d ", ret->data);
		ret = ret->next;
	}
}


void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	newnode->next = NULL;
	newnode->data = x;
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