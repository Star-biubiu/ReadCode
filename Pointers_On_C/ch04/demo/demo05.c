/*
    编写一个程序，从标准输入一行一行地读取文本，并完成如下任务：
    如果文件中有两行或更多行相邻的文本内容相同，那么就打印出其中一行，其余的行不打印。
    你可以假设文件中的文本行在长度上不会超过128个字符（127个字符加上用于终结文本行的换行符）。
    考虑下面的输入文件。

This is the first line.
Another line.
And another.
And another.
And another.
And another.
Still more.
Almost done now --
Almost done now --
Another line.
Still more.
Finished!

    假定所有的行在尾部没有任何空白（它们在视觉上不可见，但它们却可能使邻近两行在内容上不同），根据这个输入文件，程序应该产生下列输出：
                                And another.
                                Almost done now --

    所有内容相同的相邻文本行有一行被打印。注意“Another line.”和“Still more.”并未被打印，因为文件中它们虽然各占两行，但相同文本行的位置并不相邻。
    提示：使用gets函数读取输入行，使用strcpy函数来复制它们。有一个叫做strcmp的函数接受两个字符串参数并对它们进行比较。
    如果两者相等，函数返回0，如果不等，函数返回非零值
*/

#include <stdio.h>
#include <string.h>

#define BUFFER_MAX 128

int main(void)
{
    int flag = 0;
    char last_buffer[BUFFER_MAX];
    char current_buffer[BUFFER_MAX];

    if (gets(last_buffer) != NULL)     // 先输入一行
        while (gets(current_buffer) != NULL) {
            if (strcmp(last_buffer, current_buffer) != 0)  // 两行不相等
            {
                strcpy(last_buffer, current_buffer);
                flag = 0;
            }
            else if (flag == 0)                           // 相等，且上一行不相等
            {
                flag = 1;
                printf("-----> %s\n", current_buffer);
                // strcpy(last_buffer, current_buffer);  // 不需要，这两个数组相等
            }
        }

    return 0;
}

