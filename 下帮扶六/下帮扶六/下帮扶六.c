#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, i;
	int ans = 0, sum = 0;
	scanf("%d", &n);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	int ave = sum / n;
	for (i = 0; i < n ; i++)
	{
		arr[i] = arr[i] - ave;
		if (arr[i] == 0)
		{
			continue;
		}
		else
		{
			arr[i + 1] += arr[i];
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}