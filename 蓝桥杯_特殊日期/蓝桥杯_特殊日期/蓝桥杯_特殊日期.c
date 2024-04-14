#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    // 请在此输入您的代码
    int month1[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int month2[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
    int day, month, year;
    int ans = 0;
    for (year = 2000; year <= 1999999; year++)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            for (month = 1; month <= 12; month++)
            {
                for (day = 1; day <= month2[month]; day++)
                {
                    if (year % month == 0 && year % day == 0)
                    {
                        ans++;
                    }
                }
            }
        }
        else
        {
            for (month = 1; month <= 12; month++)
            {
                for (day = 1; day <= month1[month]; day++)
                {
                    if (year % month == 0 && year % day == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    printf("%d", ans + 1);
    return 0;
}