/*
    正数n的平方根可以通过计算一系列近似值来获得，每个近似值都比前一个更加接近准确值。
    第一个近似值是1，接下来的近似值则通过下面的公式来获得：
                a_(i+1) = (a_i + n / a_i) / 2
    编写一个程序，读入一个值，计算并打印出它的平方根。如果你将所有的近似值都打印出来，你会发现这种方法获得准确结果的速度有多快。原则上，这种计算
    可以永远进行下去，它会不断产生更加精确的结果。但在实际中，由于浮点变量的精度限制，程序无法一直计算下去。当某个近似值与前一个近似值相等时，你
    就可以让程序停止继续计算了
*/

#include <stdio.h>

int main(void)
{
    int n;
    double current_n, next_n;
    puts("Input a value:");
    scanf("%d", &n);
    current_n = n;

    while (1) {
        next_n = (current_n + n / current_n) / 2;
        if (current_n - next_n < 0.00000001)
            break;
        current_n = next_n;
    }
    printf("value's square = %.8f", current_n);

    return 0;
}
