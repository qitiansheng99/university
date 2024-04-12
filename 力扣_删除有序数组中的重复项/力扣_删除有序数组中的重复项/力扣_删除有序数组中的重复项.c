#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int removeDuplicates(int* nums, int numsSize)
{
	if (numsSize == 0)
	{
		return 0;
	}
	else
	{
		int dst = 0, begin = 0, end = 1;
		while (end <= numsSize)
		{
			if (nums[begin] == nums[end])
			{
				if (end == numsSize)
				{
					nums[dst] = nums[begin];
					break;
				}
				end++;
			}
			else
			{
				nums[dst] = nums[begin];
				if (end < numsSize)
				{
					dst++;
				}
				begin = end++;
			}
		}
		return dst + 1;
	}
}
int main()
{
	int size;
	scanf("%d", &size);
	int* nums = (int*)malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
	{
		scanf("%d", &nums[i]);
	}
	int n = removeDuplicates(nums, size);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
	return 0;
}