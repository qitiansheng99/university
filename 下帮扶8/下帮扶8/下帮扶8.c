#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int Hanshu(int n)
{
	int i = 1;
	int sum = 0, count=0;
	while (sum < n)
	{
		sum += (i + 2) * 2;
		i += 2;
		count++;
	}
	return count;
}

int hanshu(int n)
{
	int i;
	int sum = 1, num = 1;
	for (i = 0; i < n - 1; i++)
	{
		sum += (num + 2) * 2;
		num += 2;
	}
	return sum;
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int c = Hanshu(n);
	for (i = 0; i < c; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 1 + ((c - 1 - i) * 2); j++)
		{
			printf("*");
		}
		for (j = 0; j < i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < c - 1; i++)
	{
		for (j = 0; j < c - 2 - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j < 1 + ((i + 1) * 2); j++)
		{
			printf("*");
		}
		for (j = 0; j < c - 2 - i; j++)
		{
			printf(" ");
		}
		printf("\n");
	}
	printf("%d\n", n-hanshu(c));
	return 0;
}