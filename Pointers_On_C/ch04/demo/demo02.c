/*
    一个整数如果只能被它本身和1整除，它就被称为质数(prime)。
    请编写一个程序，打印出1～100之间的所有质数。
    
    提示：最小的因子不可能大于它的平方根
    如果i能被j整除那么存在k，使 i = j * k。
    如果 j 大于 i 的平方根，那么 k 必定小于 i 的平方根 -> 所以此时的j是包含k的，这样就重复计算了
    因此，只要计算小于 i / j的部分
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
    int flag = 1;
    for (int tmp = 2; tmp <= num / tmp; tmp++)
        if (num % tmp == 0) {
            flag = 0;
            break;
        }
        
    if (flag) 
        printf("%d ", num);
}
