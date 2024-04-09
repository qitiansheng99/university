#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int n, i, j, ret, flag;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	int* brr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	memcpy(brr, arr, sizeof(int) * n);
	//将复制得到的数组冒泡排序得到升序
	for (i = 0; i < n - 1; i++)
	{
		flag = 0;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (brr[j] > brr[j + 1])
			{
				ret = brr[j];
				brr[j] = brr[j + 1];
				brr[j + 1] = ret;
				flag = 1;
			}
		}
		if (!flag)
		{
			break;
		}
	}
	int k;
	scanf("%d", &k);
	//在排过序的数组中进行二分查找
	int left = 0;
	int right = n - 1;
	int mid, count;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (brr[mid] < k)
		{
			left = mid + 1;
		}
		if (brr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			mid;
			count = 1;
			break;
		}
	}
	//从找到的数找到在原数组中的位置
	if (count)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[j] == brr[mid])
			{
				printf("该元素的下标为%d\n", j);
			}
		}
	}
	else
	{
		printf("该数组中未找到此数\n");
	}
	return 0;
}