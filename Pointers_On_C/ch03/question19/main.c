#include <stdio.h>
#include "other.c"

// 代码块外，设属性为internal 只能访问本文件的变量
// static int X = 10;
// static int Y = 20;

// 使用extern声明 不能进行初始化
// extern int X;
// extern int Y;

int X = 10;
int Y = 20;

int main(void)
{
    // 代码块内，设存储类型为static 且无法链接到其它文件
    // static int X = 10;
    // static int Y = 20;
    int rest;
    rest = max();

    printf("%d",rest);

    return 0;
}
