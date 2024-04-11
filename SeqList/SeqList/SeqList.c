#include"SeqList.h"

void Cheakseqlist(Sl* ps)
{
	if (ps->capacity == ps->size)
	{
		custom* ret = (custom*)realloc(ps->a, sizeof(custom) * ADD * ps->capacity);
		if (ret == NULL)
		{
			perror;
			exit(-1);
		}
		ps->a = ret;
		ps->capacity += ADD;
	}
}

void SeqlistInfo(Sl* ps)
{
	ps->a = (custom*)malloc(sizeof(custom) * N);
	if (ps->a == NULL)
	{
		perror;
		exit(-1);
	}
	ps->capacity = N;
	ps->size = 0;
}

void Seqlistpushfoint(Sl* ps,custom num)
{
	Cheakseqlist(ps);
	if (ps->size == 0)
	{
		ps->a[ps->size] = num;
		ps->size++;
	}
	else
	{
		int i;
		for (i = ps->size - 1; i >= 0; i--)
		{
			ps->a[i + 1] = ps->a[i];
		}
		ps->a[0] = num;
		ps->size++;
	}
}

void Seqlistpopfoint(Sl* ps)
{
	if (ps->size == 0)
	{
		printf("该表中没有数据，请重新选择\n");
		return;
	}
	else
	{
		int i;
		for (i = 1; i < ps->size; i++)
		{
			ps->a[i - 1] = ps->a[i];
		}
		ps->size--;
	}
}

void Seqlistpushback(Sl* ps, custom num)
{
	Cheakseqlist(ps);
	ps->a[ps->size] = num;
	ps->size++;
}

void Seqlistpopback(Sl* ps)
{
	if (ps->size == 0)
	{
		printf("该表中没有数据，请重新选择\n");
		return;
	}
	else
	{
		ps->size--;
	}
}

void Seqlistpushappoint(Sl* ps, custom num, int slot)
{
	Cheakseqlist(ps);
	if (slot > ps->size)
	{
		printf("超出范围，请重新选择\n");
		return;
	}
	else
	{
		int i;
		for (i = slot - 1; i < ps->size; i++)
		{
			ps->a[i] = ps->a[i + 1];
		}
		ps->a[slot - 1] = num;
		ps->size++;
	}
}

void Seqlistpopappoint(Sl* ps, int slot)
{
	if (slot == ps->size)
	{
		printf("该表中没有数据，请重新选择\n");
		return;
	}
	else
	{
		int i;
		for (i = slot; i < ps->size; i++)
		{
			ps->a[i - 1] = ps->a[i];
		}
		ps->size--;
	}
}

void Seqlistsearch(Sl* ps, custom num)
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == num)
			break;
	}
	if (i < ps->size)
	{
		printf("该数据所在的位置为 %d\n", i + 1);
	}
	else
	{
		printf("抱歉，没有找到该数据\n");
	}
}

void Seqlistprint(Sl* ps)
{
	int i;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}