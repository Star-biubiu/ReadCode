/*
    编写一个程序，从标准输入读取几行输入。每行输入都要打印到标准输出上，前面要加上行号。
    在编写这个程序时要试图让程序能够处理的输入行的长度没有限制。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define GETCHAR 1
#define FGETS 1
#define BUFFER_MAX 100                  // 每一行的最大长度

int main( void )
{
    
// 使用getchar()函数每次回车都会将键盘数据输入到缓存区，每一行可以无限长，但无法实现换行（不能输入多行文本）
#if !GETCHAR
    int str, line, flag;
    flag = 1;
    line = 0;

    while( ( str = getchar() ) && str != EOF ) {
        if( flag == 1 ){
            flag = 0;
            line++;
            printf("%d ", line);
        }
        putchar(str);

        if( str == '\n' )
            flag = 1;
    }
#endif

// 使用fgets()函数可以实现换行（可以输入多行文本），但是每行的长度受到限制
#if FGETS
    char *buffer = NULL;                            // 动态分配的输入缓冲区
    size_t buffer_size = 0;                         // 当前缓存区大小
    size_t read_size = 0;                           // 已读取的字节数
    int line = 0;                                   // 整型类型   行数
    char strline[20];                               // 字符串类型 行数

    do{
        buffer = (char *)realloc(buffer, buffer_size + BUFFER_MAX);
        assert(buffer != NULL);                     // 断言不为空指针
        if (line == 0)                              // 主要原因是 buffer一开始没有初值，用strcat后第一行出现乱码
            strcpy(buffer, "");                     // 为buffer赋初值，防止第一行出现乱码

        line++;
        sprintf(strline, " %d ", line);             // 将行数 整型 -> 字符串
        read_size = strlen(buffer);                 // 计算buffer已经缓存的字节数
        strcat(buffer + read_size, strline);        // 在buffer末尾（fgets保存每行末尾换行符，故buffer末为新一行行首）加入行数
        read_size = strlen(buffer);                 // 更新buffer已经缓存的字节数
        buffer_size += BUFFER_MAX;                  // 更新buffer的缓存区大小
            // 把键盘输入保存到缓存区
    } while (fgets(buffer + read_size, BUFFER_MAX, stdin) != NULL && *(buffer + read_size) != EOF);

    fputs(buffer, stdout);                          // 把缓存区数据输出到显示器
    free(buffer);                                   // 释放内存

#endif

    return 0;
}
