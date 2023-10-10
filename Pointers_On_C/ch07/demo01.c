/*
    Hermite Polynomials（厄密多项式）是这样定义的：
            n <= 0 : 1
    Hn(x)   n < 2  : 2x
            n >= 2 : 2xHn-1(x) - 2(n-1)Hn-2(x)
    
    例如，H3(2)的值是40。请编写一个递归函数，计算Hn(x)的值。你的函数应该与下面的原型匹配：
            int hermite( int n, int x)
*/

#include <stdio.h>

int hermite( int n, int x);

int main(void)
{
    int n, x;
    printf("Input two number[n, x]:\n");
    scanf("%d %d", &n, &x);

    printf("hermite(%d, %d) = %d\n", n, x, hermite(n, x));
        
    return 0;
}

int hermite( int n, int x) {
    if (n <= 0)
        return 1;
    else if (n < 2)
        return 2 * x;
    else
        return 2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x);
}

