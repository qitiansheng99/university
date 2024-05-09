#include"Stack.h"

void test1()
{
	ST st;
	StackInit(&st); 
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);
	StackPop(&st);
	StackPop(&st);
	while (!StackEmpty(&st))
	{
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}
	StackDestory(&st);
}

int main()
{
	test1();
	return 0;
}