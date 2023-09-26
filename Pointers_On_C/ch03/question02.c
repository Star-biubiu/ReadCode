/*
    浮点型的范围有多大？
*/

#include <stdio.h>
#include <float.h>

int main(void) 
{
    // float
    printf("FLT_MAX = %E\n", FLT_MAX);
    printf("FLT_MIN = %E\n", FLT_MIN);
    printf("\n");
    // double 
    printf("DBL_MAX = %E\n", DBL_MAX);
    printf("DBL_MIN = %E\n", DBL_MIN);
    printf("\n");
    // long double
    printf("LDBL_MAX = %E\n", LDBL_MAX);
    printf("LDBL_MIN = %E\n", LDBL_MIN);
    printf("\n");

    return 0;
}