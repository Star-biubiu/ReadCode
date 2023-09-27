/*
    编写一些语句，用于对一些已经读入的值进行检验和报告。如果x小于y，打印单词WRONG。同样，如果a大于或等于b，也打印WRONG。在其他情况下，打印RIGHT。
*/

#include <stdio.h>

int main(void)
{
    int x, y, a, b;
    printf("Input x y a b\n");
    scanf("%d %d %d %d", &x, &y, &a, &b);

    if ( (x < y) || (a >= b) ) 
        printf("WRONG");
    else
        printf("RIGHT");

    return 0;
}