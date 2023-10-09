/*
    编写函数reverse_string，它的原型如下：
        void reverse_string( char *string );
    函数把参数字符串中的字符反向排列。
    请使用指针而不是数组下标，不要使用任何C函数库中用于操纵字符串的函数。
        提示：不需要声明一个局部数组来临时存储参数字符串。
*/

#include <stdio.h>

void reverse_string( char *string );

int main(void)
{
    int sign = -1;
    char source_str[] = "ABCDEFGH";

    printf("%s\n", source_str);
    reverse_string(source_str);
    printf("%s\n", source_str);

    return 0;
}

void reverse_string( char *string ) {
    char *str = string, temp_ch;

    while ( *str++ != '\0' ); str = str - 2;    // str指针指向字符串最后一个字符 -2： -1回到NUL 再-1回到最后一个字符
    while ( string < str ) {                    // string++   str--  string < str时交换完成
        temp_ch = *string;                      // 临时变量存储字符
        *string++ = *str;                       // 交换字符
        *str-- = temp_ch;                       // 交换字符
    }
}