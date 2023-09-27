/*
    10．编写一些语句，从标准输入读取一个整型值，然后打印一些空白行，空白行的数量由这个值指定。
*/

#include <stdio.h>

int main(void)
{
    int num;
    printf("Input a number:\n");
    scanf("%d", &num);
    
    while( num-- ){
        printf("%d\n", num);
    }

    return 0;
}