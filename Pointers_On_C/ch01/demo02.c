/*
    编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。
    在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。
*/
#include <stdio.h>

int main(void)
{
    int str, line, flag;
    flag = 1;
    line = 0;

    while ((str = getchar()) && str != EOF) {
        if (flag == 1){
            flag = 0;
            line++;
            printf("%d ", line);
        }
        putchar(str);

        if (str == '\n')
            flag = 1;
    }

    return 0;
}
