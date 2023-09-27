/*
    一个整数如果只能被它本身和1整除，它就被称为质数(prime)。
    请编写一个程序，打印出1～100之间的所有质数。
*/

#include <stdio.h>
void cout_prime(int num);

int main(void)
{
    int i, prime;
    
    for (i = 2; i <= 100; i++)  // 1不是质数
        cout_prime(i);

    return 0;
}

void cout_prime(int num) {
    int tmp = num - 1;
    while (tmp > 1) {
        if (num % tmp == 0)
            break;
        tmp--;
    }
    if (tmp == 1) 
        printf("%d ", num);
}
