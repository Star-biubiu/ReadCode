/*
    编写一个函数，从一个字符串中去除多余的空格。函数的原型应该如下：
            void deblank( char string[] );
    当函数发现字符串中如果有一个地方由一个或多个连续的空格组成，就把它们改成单个空格字符。注意当你遍历整个字符串时要确保它以NUL字符结尾。
*/

#include <stdio.h>
#include <string.h>

void deblank(char string[]);

int main(void)
{
    char str[100];
    printf("Input string[100]:\n");
    fgets(str, 100, stdin);
    deblank(str);
    printf("%s", str);

    return 0;
}

void deblank(char string[]){
    char *str1 = string, *str2;
    if (*str1 != '\0') {
        str2  = string + 1;
        for (int i = 0; *(str2 + i) != '\0'; i++) {
            if ( *(str1 + i) == ' ' && *(str2 + i) == ' ') {
                strcpy(str1 + i, str2 + i);
                i--;
            }
        }
    }
}

/*  更好
void deblank(char a[]) {
    for (int i = 0, j = 0; a[i] != '\0'; ) {
        int flag = 0;
        while (a[i] != '\0' && a[i] == ' ')   // 跳过所有空格 i++++++
            flag = 1, i++;
        if (flag)
            a[j++] = ' ';                     // 下一位设为空格
        a[j++] = a[i++];  // a[j] = a[i]  j = j+1 i = i+1  // 再下位存非空格值
    }
}
*/

#if 0
// 答案代码
void deblank(char *string)
{
    char *dest;
    char *src;
    int ch;
    /*
** Set source and destination pointers to beginning of the string, then
** move to 2nd character in string.
*/
    src = string;
    dest = string++;
    /*
** Examine each character from the source string.
*/
    while ((ch = *src++) != NUL)
    {
        if (is_white(ch))
        {
            /*
** We found white space. If we’re at the beginning of
** the string OR the previous char in the dest is not
** white space, store a blank.
*/
            if (src == string || !is_white(dest[–1]))
                *dest++ = ’ ’;
        }
        else
        {
            /*
** Not white space: just store it.
*/
            *dest++ = ch;
        }
    }
    *dest = NUL;
}
int is_white(int ch)
{
    return ch == ’ ’ || ch == ’\t’ || ch == ’\v’ || ch == ’\f’ || ch == ’\n’ || ch == ’\r’;
}
#endif