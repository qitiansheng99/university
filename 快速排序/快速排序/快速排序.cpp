#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void q_sort(int* arr, int left, int right)
{
	int ret;
	if (left >= right)
	{
		return;
	}
	int l = left;
	int r = right;
	int key = arr[l];
	while (l < r)
	{

		while (l < r && arr[r] >= key)
		{
			r--;
		}
		arr[l] = arr[r];
		while (l < r && arr[l] <= key)
		{
			l++;
		}
		arr[r] = arr[l];
	}
	arr[l] = key;
	q_sort(arr, left, l - 1);
	q_sort(arr, l + 1, right);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	q_sort(arr, 0, n - 1);
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}