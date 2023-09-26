/*
    字符的范围有多大？有哪些不同的整数类型？它们的范围又是如何?
*/

#include <stdio.h>
#include <limits.h>

int main(void) 
{
    // char
    printf("SCHAR_MAX(signed) = %d\n", SCHAR_MAX);
    printf("SCHAR_MIN(signed) = %d\n", SCHAR_MIN);
    printf("UCHAR_MAX(unsigned) = %d\n", UCHAR_MAX);
    printf("\n");
    // short int 
    printf("SHRT_MAX(signed) = %d\n", SHRT_MAX);
    printf("SHRT_MIN(signed) = %d\n", SHRT_MIN);
    printf("USHRT_MAX(unsigned) = %d\n", USHRT_MAX);
    printf("\n");
    // int 
    printf("INT_MAX(signed) = %d\n", INT_MAX);
    printf("INT_MIN(signed) = %d\n", INT_MIN);
    printf("UINT_MAX(unsigned) = %X\n", UINT_MAX);
    printf("\n");
    
    // long int 
    printf("LONG_MAX(signed) = %d\n", LONG_MAX);
    printf("LONG_MIN(signed) = %d\n", LONG_MIN);
    printf("ULONG_MAX(unsigned) = %X\n", ULONG_MAX);

    return 0;
}