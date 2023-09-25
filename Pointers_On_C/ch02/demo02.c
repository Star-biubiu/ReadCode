/*
    编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确地成对出现。注意：你不必担心注释内部、字符串常量内部和字符常量形式的花括号
    花括号只多不少 认为左括号永远正确
*/

#include <stdio.h>

int main(void)
{
    int ch, bracket, sign;
    sign = 1;
    bracket = 0;

    while( (ch = getchar()) != EOF ){
        if( ch == '{' )              // 左括号总是正确
            bracket++;
        if( ch == '}' )
            if( bracket == 0)
            {
                perror("bracket ERROR");
                sign = 0;
                break;
            }
            else
                bracket--;
    }
    if( bracket != 0 || sign == 0 )
        perror("False");
    else
        printf("Ture");
    return 0;
}
