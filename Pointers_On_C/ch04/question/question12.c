/*
    能够被4整除的年份是闰年，但其中能够被100整除的却不是闰年，除非它同时能够被400整除。
    请编写一些语句，判断year这个年份是否为闰年，
    如果它是闰年，把变量leap_year设置为1，如果不是，把leap_year设置为0。
*/

#include <stdio.h>

int main(void)
{
    int year, leap_year;
    printf("Input year:\n");
    scanf("%d", &year);

    if ( (year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)) )
        leap_year = 1;
    else
        leap_year = 0;
    
    printf("leap_yaer = %d\n", leap_year);

    return 0;
}
