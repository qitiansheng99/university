#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	int i, n,m;
	int ans = 0;
	scanf("%d",&n);
	for (i = 1; i <= n; i++)
	{
		int ret = i;
		int size = 0;
		int flag = 0;
		while (ret)
		{
			m = ret % 10;
			size++;
			if (size % 2 == 0)
			{
				if (m % 2 == 0)
				{
					ret /= 10;
					continue;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else
			{
				if (m % 2 != 0)
				{
					ret /= 10;
					continue;
				}
				else
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag == 0)
		{
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}