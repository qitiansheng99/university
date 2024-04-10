#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int n, num = 0, j = 0;
    scanf("%d", &n);
    while (n)
    {
        num += (n % 10) * (int)pow(9, j);
        n = n / 10;
        j++;
    }
    printf("%d", num);
    return 0;
}