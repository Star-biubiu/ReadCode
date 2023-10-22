/*
        单位矩阵(identity matrix)就是一个正方形矩阵，它除了主对角线的元素值为1以后，其余元素的值均为0。例如：
            1 0 0
            0 1 0
            0 0 1
        就是一个3×3的单位矩阵。
        编写一个名叫identity_matrix的函数，它接受一个10×10整型矩阵为参数，并返回一个布尔值，提示该矩阵是否为单位矩阵。
        
        修改前一个问题中的identity_matrix函数，它可以对数组进行扩展，从而能够接受任意大小的矩阵参数。
        函数的第1个参数应该是一个整型指针，你需要第2个参数，用于指定矩阵的大小。  默认是方阵
*/

#include <stdio.h>

#define Ture  1
#define Flase 0
int identity_matrix( int *matrix, int idex );

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
    matrix[3][4] = 2;
    flag = identity_matrix(*matrix, 10);            // 传递指向最内层元素的地址
    printf("matrix is %d\n", flag);

    return 0;
}
 
// 利用内存连续的特性对多维数组进行操作，例如数组为 matrix[10][10] 则 *(*(matrix + 0) + 9) = matrix[0][9] *(*(matrix + 0) + 10) = matrix[1][0]
// 注意，二维数组必须先通过*(matrix + 0)指向最内层第一个元素的地址 此时进行*(matrix + 0) + n才是元素间的地址移动，matrix + n是数组间的移动
//      高维数组同理，如三维数组 即**matrix指向最内层第一个元素的地址
int identity_matrix( int *matrix_inner, int idex ) { // matrix_inner = *matrix matrix_inner指向第二维元素的地址
    int i, j, num = 0;
    for(i = 0; i < idex; i++) 
        for(j = 0; j < idex; j++) {
            // printf("matrix[%d][%d] = %d\n", i, j, *(matrix_inner++));
            if( (i == j && 1 != *matrix_inner) ||
                (i != j && 0 != *matrix_inner) )
                return Flase;
            matrix_inner++;
        }
    return Ture;
}
