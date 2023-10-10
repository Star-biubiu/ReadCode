/*
    编写一个名叫max_list的函数，它用于检查任意数目的整型参数并返回它们中的最大值。
    参数列表必须以一个负值结尾，提示列表的结束。
*/

#include <stdio.h>
#include <stdarg.h>

int max_list( int num, ... );

int main(void)
{
    int num; 
    printf("max = %d\n", max_list(num, 145, 2484, 32, 415, 5, 64, 7, -1));
        
    return 0;
}

int max_list( int num, ... ) {
    int max = 0;
    int temp_value;
    va_list var_arg;                                                // 声明一个va_list类型变量
    va_start(var_arg, num);                                         // 将va_list类型变量指向第一个可变参数

    for (num = 0; (temp_value = va_arg(var_arg, int)) >= 0; num++)  // 读取当前变量值，并指向下一个变量      
        if ( max < temp_value ) 
            max = temp_value;
    
    va_end(var_arg);                                                // 访问最后一个可变参数
    printf("num = %d\t", num + 1);                                  // 补上最后一个-1

    return max;
}

