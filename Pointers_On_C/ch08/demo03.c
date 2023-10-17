/*
        单位矩阵(identity matrix)就是一个正方形矩阵，它除了主对角线的元素值为1以后，其余元素的值均为0。例如：
            1 0 0
            0 1 0
            0 0 1
        就是一个3×3的单位矩阵。
        编写一个名叫identity_matrix的函数，它接受一个10×10整型矩阵为参数，并返回一个布尔值，提示该矩阵是否为单位矩阵。
*/

#include <stdio.h>
#include <float.h>

int identity_matrix( int matrix[][10] );

int main(void)
{
    int i, j, flag;
    int matrix[10][10];
    for(i = 0; i < 10; i++) 
        for(j = 0; j < 10; j++)
            if(i == j) 
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
    // matrix[3][4] = 2;
    flag = identity_matrix(matrix);
    printf("matrix is %d\n", flag);

    return 0;
}

int identity_matrix( int matrix[][10] ) {
    int i, j;
    for(i = 0; i < 10; i++) 
        for(j = 0; j < 10; j++)
            if(i == j && matrix[i][j] != 1) 
                return 0;
            else if (i != j && matrix[i][j] != 0) 
                return 0;
               
    return 1;
}
