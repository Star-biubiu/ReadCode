/*
    为下面这个函数原型编写函数定义：
        int ascii_to_integer( char *string );

    这个字符串参数必须包含一个或多个数字，函数应该把这些数字字符转换为整数并返回这个整数。
    如果字符串参数包含了任何非数字字符，函数就返回零。
    请不必担心算术溢出。
        提示：这个技巧很简单——你每发现一个数字，把当前值乘以10，并把这个值和新数字所代表的值相加。
*/

#include <stdio.h>

int ascii_to_integer( char *string );

int main(void)
{
    char str[10];                       // 字符数组一定要定义成char类型
    printf("Input one str[10]:\n");
    scanf("%s", str);

    printf("ascii_to_integer = %d\n", ascii_to_integer(str));
        
    return 0;
}

int ascii_to_integer( char *string ) {
    int digit = 0;

    while( *string != '\0' ) {
        if ( *string < '0' || *string > '9' )
            return 0;
        else
            digit = digit * 10 + (*string++ - '0');     // 可不加括号，结果不变，但是(*string++ - '0')含义更清晰
    }
    return digit;
}

