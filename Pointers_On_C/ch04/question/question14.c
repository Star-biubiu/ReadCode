/*
    假定由一个“程序”来控制你，而且这个程序包含两个函数：
            eat_hamberger()用于让你吃汉堡包，hungry()函数根据你是否饥饿返回真值或假值。
    请编写一些语句，允许你在饥饿感得到满足之前爱吃多少汉堡包就吃多少。 
*/

#include <stdio.h>

#define NUM 100
int eat_hamberger(int *hamberger);
int hungry(int sign);

int main(void)
{   
    int num = 0;
    int *hamberger = &num;      // 指针要初始化后才能用

    while (hungry(eat_hamberger(hamberger)));

    printf("hamberger = %d", *hamberger - 1);
    return 0;
}

int eat_hamberger(int *hamberger){
    return (*hamberger)++;          // 返回hamberger 但是之后hamberger会+1
}

int hungry(int sign){
    return sign >= NUM ? 0 : 1;
}