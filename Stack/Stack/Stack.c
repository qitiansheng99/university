#include"Stack.h"

void StackInit(ST* ps)
{
	assert(ps);
	ps->a = (typedata*)malloc(sizeof(typedata) * 4);
	ps->capacity = 4;
	ps->top = 0;
}

void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
}

void StackPush(ST* ps, typedata x)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		typedata* ret = (typedata*)realloc(ps->a, sizeof(typedata) * ps->capacity * 2);
		if (ret == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a = ret;
			ps->capacity = ps->capacity * 2;
		}
	}

	ps->a[ps->top] = x;
	(ps->top)++;
}

void StackPop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

typedata StackTop(ST* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
	assert(ps);

	return ps->top;
}

bool StackEmpty(ST* ps)
{
	assert(ps);

	return ps->top == 0;
}