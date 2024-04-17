#include<stdio.h>
void merge(int* nums1, int m, int* nums2, int n)
{
	int fir = m - 1, sec = n - 1;
	while (fir != -1 || sec != -1)
	{
		if (sec == -1)
		{
			break;
		}
		if (fir == -1)
		{
			while (m + n - 1 != -1)
			{
				nums1[m + n - 1] = nums2[sec];
				m--;
				sec--;
			}
			break;
		}
		if (nums1[fir] <= nums2[sec])
		{
			nums1[m + n - 1] = nums2[sec];
			m--;
			sec--;
		}
		else
		{
			nums1[m + n- 1] = nums1[fir];
			m--;
			fir--;
		}

	}
}
int main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int* nums1 = (int*)malloc(sizeof(int) * (m + n));
	int* nums2 = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < m + n; i++)
	{
		scanf("%d", &nums1[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &nums2[i]);
	}
	merge(nums1, m, nums2, n);
	for (int i = 0; i < m + n; i++)
	{
		printf("%d ", nums1[i]);

	}
	return 0;
}