/*
    编写函数copy_n，它的原型如下所示：
            void copy_n( char dst[], char src[], int n );
    这个函数用于把一个字符串从数组src复制到数组dst，但有如下要求：必须正好复制n个字符到dst数组中，不能多，也不能少。
    如果src字符串的长度小于n，你必须在复制后的字符串尾部补充足够的NUL字符，使它的长度正好为n。
    如果src的长度长于或等于n，那么你在dst中存储了n个字符后便可停止。此时，数组dst将不是以NUL字符结尾。
    
    注意调用copy_n时，它应该在dst[0]至dst[n-1]的空间中存储一些东西，但也只局限于那些位置，这与src的长度无关。
    如果你计划使用库函数strncpy来实现你的程序，祝贺你提前学到了这个知识。
    但在这里，我的目的是让你自己规划程序的逻辑，所以你最好不要使用那些处理字符串的库函数。 不使用string.h的函数
*/

#include <stdio.h>

void copy_n(char dst[], char src[], int n);
void cat_n(char dst[], char src[], int n);

int main(void)
{
    // char dst[100], src[100];
    // int n;
    // puts("\nInput dst[100]:");
    // scanf("%s",dst);
    // puts("\nInput src[100]:");
    // scanf("%s",src);
    // puts("\nInput n:");
    // scanf("%d", &n);

    char dst[5], src[10] = "012345678";
    int n = 5;
    copy_n(dst, src, n);
    printf("\ndst = %s", dst);

    return 0;
}


// 写错了，这个是实现strncat
void cat_n(char dst[], char src[], int n) {
    // 形参声明为数组，将被视为指向该数组的指针。使用sizeof实际上返回的是指针的大小
    // 不能用int n_dst = sizeof(dst);
    int n_dst = 1; 
    int n_src = 1;
    while (dst[n_dst - 1])
        n_dst++;
    while (src[n_src - 1])
        n_src++;

    char *p = dst + n_dst - 1;      // 0 + n -1 指针指向dst的NUL字符地址

    
    if (n_src < n)
        for (int i = 0; i < n; i++)
            if(i < n_src)
                *(p + i) = src[i];
            else
                *(p + i) = 0;
    
    else
        for (int i = 0; i < n; i++)
            *(p + i) = src[i];
}

void copy_n(char dst[], char src[], int n) {
    // 果src字符串的长度小于n，你必须在复制后的字符串尾部补充足够的NUL字符，使它的长度正好为n。
    // 如果src的长度长于或等于n，那么你在dst中存储了n个字符后便可停止。此时，数组dst将不是以NUL字符结尾。
    int index_dst, index_src;
    for (index_dst = 0, index_src = 0; index_dst < n; index_dst++) {
        dst[index_dst] = src[index_src];
        if (src[index_src] != 0)
            index_src++;
    }
}