/*
    请编写一个函数，删除一个字符串的一部分。函数的原型如下：
        int del_substr( char *str, char const *substr )
    函数首先应该判断substr是否出现在str中:
        如果它并未出现，函数就返回0；
        如果出现，函数应该把str中位于该子串后面的所有字符复制到该子串的位置，从而删除这个子串，然后函数返回1。
        如果substr多次出现在str中，函数只删除第1次出现的子串。函数的第2个参数绝不会被修改。
            举个例子，假定str指向ABCDEFG。如果substr指向FGH、CDF或XABC，函数应该返回0，str未作任何修改。
            但如果substr指向CDE，函数就把str修改为指向ABFG，方法是把F、G和结尾的NUL字节复制到C的位置，然后函数返回1。
            不论出现什么情况，函数的第2个参数都不应该被修改。
    和上题的程序一样：
    a．你不应该使用任何用于操纵字符串的库函数（如strcpy, strcmp，等）。
    b．函数中的任何地方都不应该使用下标引用。
    一个值得注意的是，空字符串是每个字符串的一个子串，在字符串中删除一个空子串字符串不会产生变化。

    1. 先进行字符串的模式匹配   返回匹配的末尾
    2. 再进行删除
*/

#include <stdio.h>

int del_substr( char *str, char const *substr );        // 字符串模式匹配
char *match_substr( char *str, char const *substr );    

int main(void)
{
    int sign = -1;
    char source_str[] = "ABCDEFG";
    char chars1[] = "FGH", chars2[] = "CDE";       
    
    if( sign = del_substr(source_str, chars1) )
        printf("str = %s\n", source_str);
    else
        printf("source_str have not %s\n", chars1);

    if( sign = del_substr(source_str, chars2) )
        printf("str = %s\n", source_str);
    else
        printf("source_str have not %s\n", chars2);

    return 0;
}

char *match_substr( char *str, char const *substr ) {
    while ( *substr != '\0' ) 
        if ( *str++ != *substr++ )
            return NULL;                            // 不匹配，退出，返回NULL
    return str;                                     // 返回substr后的第一个字符地址
}

int del_substr( char *str, char const *substr ) {
    char *temp;

    while ( *str != '\0' ) {
        temp = match_substr(str, substr);
        if (temp != NULL)                           // 匹配成功，跳出循环   传递指针变量也是传递一个指针变量的拷贝，即地址的拷贝
            break;
        str++;                                      // 不匹配，指向下一个地址
    }
    if ( *str == '\0')                              // 字符串结束仍不匹配
        return 0;
    else                                            // 匹配成功
        while ( *str != '\0' )
            *str++ = *temp++;                       // 将后续字符添加到原substr开始的位置
    return 1;
}