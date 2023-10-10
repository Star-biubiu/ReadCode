/*
    两个整型值M和N（M、N均大于0）的最大公约数可以按照下面的方法计算：
                M % N = 0:          N
    gcd(M, N)   
                M % N = R, R > 0:   gcd( N, R )
    请编写一个名叫gcd的函数，它接受两个整型参数，并返回这两个数的最大公约数。
    如果这两个参数中的任何一个不大于零，函数应该返回零
*/

#include <stdio.h>

int gcd( int M, int N);

int main(void)
{
    int M, N;
    printf("Input two number[M, N]:\n");
    scanf("%d %d", &M, &N);

    printf("gcd(%d, %d) = %d\n", M, N, gcd(M, N));
        
    return 0;
}

int gcd( int M, int N) {
    if (M <= 0 || N <= 0)
        return 0;
    else if ( 0 == M % N )
        return N;
    else
        return gcd(N, M % N);

    // return N > 0 ? gcd( N, M % N ) : N;
}

