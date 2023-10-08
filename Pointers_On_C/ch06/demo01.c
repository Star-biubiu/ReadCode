/*
    请编写一个函数，它在一个字符串中进行搜索，查找所有在一个给定字符集合中出现的字符。这个函数的原型应该如下：
        char *find_char( char const *source, char const *chars );

    它的基本想法是查找source字符串中匹配chars字符串中任何字符的第1个字符，函数然后返回一个指向source中第1个匹配所找到的位置的指针。
    如果source中的所有字符均不匹配chars中的任何字符，函数就返回一个NULL指针。
    如果任何一个参数为NULL，或任何一个参数所指向的字符串为空，函数也返回一个NULL指针。
        举个例子，假定source指向ABCDEF。
        如果chars指向XYZ、JURY或QQQQ，函数就返回一个NULL指针。
        如果chars指向XRCQEF，函数就返回一个指向source中C字符的指针。
        参数所指向的字符串是绝不会被修改的。
        碰巧，C函数库中存在一个名叫strpbrk的函数，它的功能几乎和这个你要编写的函数一模一样。
        但这个程序的目的是让你自己练习操纵指针，所以：
            a．你不应该使用任何用于操纵字符串的库函数（如strcpy, strcmp, index等）。
            b．函数中的任何地方都不应该使用下标引用
*/

#include <stdio.h>

char *find_char( char const *source, char const *chars );

int main(void)
{
    char *source_str = "ABCDEF";
    char *chars1 = "XYZ", *chars2 = "XRCQEF";       


    char *str1 = find_char(source_str, chars1);     // 不能对NULL进行解引用
    printf("source_str1 = %p\n", source_str);
    char *str2 = find_char(source_str, chars2);     // 不能对NULL进行解引用
    printf("source_str2 = %p\n", source_str);

    if (str1 != NULL)                               // 不能对NULL进行解引用
        printf("str1 = %c\n", *str1);
    else
        printf("str1 is NULL\n");
    
    if (str2 != NULL)                               // 不能对NULL进行解引用
        printf("str2 = %c\n", *str2);
    else
        printf("str2 is NULL\n");
    
    return 0;
}

char *find_char( char const *source, char const *chars ) {
    char const *ptr;

    if ( source == NULL || chars == NULL)
        return NULL;

    while ( *source != '\0') {
        for ( ptr = chars; *ptr != '\0'; ) {
            if ( *ptr++ == *source)
                return (char *)source;          // source是const修饰，返回const限定的变量，必须显式进行强制类型转换成 非const的类型
        }
        source++;
    }
}