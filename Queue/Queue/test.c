#include"Queue.h"

void test1()
{
	Queue pd;
	QueueInit(&pd);
	QueuePush(&pd, 1);
	QueuePush(&pd, 2);
	QueuePush(&pd, 3);
	QueuePush(&pd, 4);
	//printf("%d ", QueueFront(&pd));
	QueuePop(&pd);
	QueuePop(&pd);
	//printf("%d ", QueueBack(&pd));
	printf("%d ", QueueSize(&pd));
	//printf("%s ", QueueEmpty(&pd));
	QueueDestroy(&pd);
}

int main()
{
	test1();
	return 0;
}