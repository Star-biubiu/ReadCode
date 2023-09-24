/*
    编写一个程序，一行行地读取输入行，直至到达文件尾。算出每行输入行的长度，然后把最长的那行打印出来。为了简单起见，
    你可以假定所有的输入行均不超过1000个字符。
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_MAX 1000                         // 缓存区最大长度

int main(void)
{
    int max = 0, temp;
    char buffer[BUFFER_MAX];                    // 定义缓存区
    char str_max[BUFFER_MAX];                   // 定义最长字符数组

    while ( (fgets(buffer, BUFFER_MAX, stdin) != NULL) && buffer[0] != EOF) {
        temp = strlen(buffer);                  // 注意，strlen不计算NUL，但是会计算空白
        if (max < temp) {
            max = temp;
            strcpy(str_max, buffer);            // strcpy可实现字符串之间的赋值
        }
    }

    printf("max = %d\nstr=%s\n", max, str_max);

    return 0;
}

