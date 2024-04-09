#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, i, j, ret;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 1; i < n; i++)
	{
		j = i - 1;
		ret = arr[i];
		while (j >= 0 && arr[j] > ret)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = ret;
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}