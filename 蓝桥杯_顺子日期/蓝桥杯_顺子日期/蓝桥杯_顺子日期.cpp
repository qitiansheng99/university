#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int i, j, k;
    int ans = 0;
    for (i = 1; i <= 12; i++)
    {
        for (j = 1; j <= month[i]; j++)
        {
            int arr[8] = { 2,0,2,2,i / 10,i % 10,j / 10,j % 10 };
            for (k = 0; k < 6; k++)
            {
                if (arr[k] + 1 == arr[k + 1])
                {
                    if (arr[k] + 2 == arr[k + 2])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}