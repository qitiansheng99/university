#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef struct SLTNode
{
	int data;
	struct SLTNode* next;
}SLTNode; 

SLTNode* SLTFind(SLTNode* phead,int x)
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

void SLTDataBack(SLTNode** pphead, SLTNode* pos)
{
	if (pos == NULL)
	{
		return;
	}
	else if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* ret = *pphead;
		SLTNode* prev = NULL;
		while (ret != pos)
		{
			prev = ret;
			ret = ret->next;
		}
		prev->next = pos->next;
		free(pos);
	}
}

void SLTAdd(SLTNode** pphead, int x)
{
	if (*pphead == NULL)
	{
		SLTNode* newdata = (SLTNode*)malloc(sizeof(SLTNode));
		newdata->data = x;
		newdata->next = NULL;
		*pphead = newdata;
	}
	else
	{
		SLTNode* newdata = (SLTNode*)malloc(sizeof(SLTNode));
		newdata->data = x;
		newdata->next = NULL;
		SLTNode* ret = *pphead;
		while (ret->next!= NULL)
		{
			ret = ret->next;
		}
		ret->next = newdata;
	}

}

int main()
{
	 SLTNode* plist = NULL;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d", &x);
		SLTAdd(&plist,x);
	}
	int m;
	scanf("%d", &m);
	SLTNode* pos = plist;
	while (pos != NULL)
	{
		pos = SLTFind(plist, m);
		SLTDataBack(&plist, pos);
	}
	while(plist != NULL)
	{
		printf("%d ", plist->data);
		plist = plist->next;	
	}
	return 0;
}