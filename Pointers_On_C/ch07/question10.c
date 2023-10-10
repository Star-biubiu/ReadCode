/*
在你的系统中，进入递归形式的菲波那契函数，并在函数的起始处增加一条语句，它增加一个全局整型变量的值。
	现在编写一个main函数，把这个全局变量设置为0并计算Fibonacci(1)。
	重复这个过程，计算Fibonacci(2)至Fibonacci(10)。
	在每个计算过程中分别调用了几次Fibonacci函数（用这个变量值表示）？
	这个全局变量值的增加和菲波那契数列本身有没有任何关联？
	基于上面这些信息，你能不能计算出Fibonacchi(11)、Fibonacci(25)和Fibonacci(50)分别调用了多少次Fibonacci函数？
*/

#include <stdio.h>

long long calls;

long long Fibonacci(int num);

int main(void)
{
    int num;
    printf("Input a number(num >= 1):\n");
    scanf("%d", &num);

    while (num > 0) {
        calls = 0;
        printf("Fibonacci(%d) = %lld\t", num, Fibonacci(num));
        printf("calls = %lld\n", calls);
        num--;
    }
        

    return 0;
}

long long Fibonacci(int num) {
    calls++;
    if (num ==1 || num == 2)
        return 1;
    else 
        return Fibonacci( num - 1 ) + Fibonacci( num - 2 );
}

