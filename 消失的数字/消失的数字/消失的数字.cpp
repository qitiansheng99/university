#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i, n;
	int num = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		num ^= arr[i];
	}
	for (i = 0; i < n + 1; i++)
	{
		num ^= i;
	}
	printf("%d\n", num);
	return 0;
}