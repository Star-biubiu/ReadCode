/*
    实现一个简化的printf函数，它能够处理%d、%f、%s和%c格式码。
        根据ANSI标准的原则，其他格式码的行为是未定义的。
        你可以假定已经存在函数print_integer和print_float，用于打印这些类型的值。
        对于另外两种类型的值，使用putchar来打印。
*/

#include <stdio.h>
#include <stdarg.h>

void usr_printf( char const str[], ... );

int main(void)
{
    int num1 = 9;
    float num2 = 3.2;
    char str1 = 'a';
    char str2[] = "abcdefg";
    usr_printf("num1 = %d\n", num1);
    usr_printf("num2 = %f\n", num2);
    usr_printf("str1 = %c\n", str1);
    usr_printf("str1 = %s\n", str2);
        
    return 0;
}

void usr_printf( char const str[], ... ) {
    char ch;
    char *str_ch;
    va_list var_arg;                                                // 声明一个va_list类型变量

    va_start(var_arg, str);                                         // 将va_list类型变量指向第一个可变参数
    while( (ch = *str++) != '\0') {
        if ( ch != '%' ) {
            putchar(ch);
            continue;
        }
        else {
            switch ( *str != '\0' ? *str++ : '\0' ) {
                case 'd':
                    // print_integer(va_arg(var_arg, int));
                    putchar(va_arg(var_arg, int) + '0');        // 只能10以内
                    break;
                case 'f':
                    // print_float(va_arg(var_arg, double));    // float 参数提升为 double
                    printf("%f", va_arg(var_arg, double));
                    break;
                case 'c':
                    putchar(va_arg(var_arg, int));              // char 参数提升为 int
                    break;
                case 's':
                    str_ch = va_arg(var_arg, char*);
                    while( *str_ch != '\0' ) 
                        putchar(*str_ch++);
                    break;
                default:
                    break;
            }
        }
    }
    
    va_end(var_arg);                                                // 访问最后一个可变参数
}

