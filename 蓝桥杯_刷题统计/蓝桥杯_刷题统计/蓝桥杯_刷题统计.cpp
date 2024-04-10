#define  _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    long long a, b, n, i;
    scanf("%lld%lld%lld", &a, &b, &n);
    long long num = 0, count = 0;
    long long sum = a * 5 + b * 2;
    int n_y = n % sum;
    long long ans = (n / sum) * 7;
    int arr[7] = { a,a,a,a,a,b,b };
    if (n_y == 0)
    {
        printf("%lld", ans);
    }
    else
    {
        for (i = 0; i < 7; i++)
        {
            num += arr[i];
            if (num >= n_y)
            {
                break;
            }
        }
        printf("%lld", ans + i + 1);
    }
    return 0;
}