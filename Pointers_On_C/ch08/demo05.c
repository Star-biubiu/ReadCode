/*
    如果A是个x行y列的矩阵，B是个y行z列的矩阵，把A和B相乘，其结果将是另一个x行z列的矩阵C。
    这个矩阵的每个元素是由下面的公式决定的：
        Ci,j = Σ(k = 1 -> y) (Ai, k × Bk, j)
    例如：
        2   -6       4  -2  -4  -5       50  14  -44 -52
        3   5    ×   -7 -3  6   7    =   -23 -21 18  20
        1   -1                           11  1   -10 -12
    结果矩阵中14这个值是通过2×-2加上-6×-3得到的。

    编写一个函数，用于执行两个矩阵的乘法。函数的原型应该如下：
        void matrix_multiply( int *m1, int *m2, int *r,
                                int x, int y, int z );
    m1是一个x行y列的矩阵，m2是一个y行z列的矩阵。这两个矩阵应该相乘，结果存储于r中，它是一个x行z列的矩阵。
    记住，你应该对公式作些修改，以适应C语言下标从0而不是1开始这个事实！
*/

#include <stdio.h>
#include <stdlib.h>   // 动态内存头文件
#include <assert.h>

void matrix_multiply(int* m1, int* m2, int* r,
    int x, int y, int z);
void matrix_multiply_answer(int *a, int *b, int *r, int x, int y, int z);       // 答案做法


int matrix_sum_array(int* m1, int* m2, int y, int z, int i, int j);     // 采用固定长度的临时数组
int matrix_sum_molloc(int* m1, int* m2, int y, int z, int i, int j);    // 采用动态内存

int main(void)
{
    int A[3][2] = { {2, -6}, {3, 5}, {1, -1} };
    int B[2][5] = { {4, -2, -4, -5, 1}, {-7, -3, 6, 7, 1} };
    int C[3][5];
    int D[3][5];
    int i, j;
    matrix_multiply_answer(*A, *B, *C, 3, 2, 5);
    matrix_multiply_answer(*A, *B, *D, 3, 2, 5);
    for (i = 0; i < 3; i++)
        for (j = 0; j < 5; j++) {
            printf("C[%d][%d] = %d\n", i, j, C[i][j]);
            printf("D[%d][%d] = %d\n", i, j, D[i][j]);
        }

    return 0;
}

void matrix_multiply(int* m1, int* m2, int* r,
    int x, int y, int z) {
    int i, j, temp = 0;
    for (i = 1; i <= x; i++)
        for (j = 1; j <= z; j++)
            *r++ = matrix_sum_molloc(m1, m2, y, z, i, j);
}

int matrix_sum_array(int* m1, int* m2, int y, int z, int i, int j) {
    int row, col, num, sum = 0;
    int matrix_row[100] = { 0 };
    int matrix_col[100] = { 0 };
    for (num = 0, row = (i - 1) * y; row < ((i - 1) * y + y); row++)                 // A的行
        matrix_row[num++] = *(m1 + row);
    for (num = 0, col = j - 1; col < ((y - 1) * z + j); col += z)                    // B的列
        matrix_col[num++] = *(m2 + col);
    for (num = 0; num < y; num++)
        sum += matrix_row[num] * matrix_col[num];

    return sum;
}

int matrix_sum_molloc(int* m1, int* m2, int y, int z, int i, int j) {
    int row, col, num, sum = 0;
    int* matrix_row = (int*)malloc(y * sizeof(int));
    assert(matrix_row != NULL);                     // 断言不为空指针

    int* matrix_col = (int*)malloc(y * sizeof(int));
    assert(matrix_col != NULL);                     // 断言不为空指针

    for (num = 0, row = (i - 1) * y; row < ((i - 1) * y + y); row++)                 // A的行
        *matrix_row++ = *(m1 + row);
    for (num = 0, col = j - 1; col < ((y - 1) * z + j); col += z)                    // B的列
        *matrix_col++ = *(m2 + col);

    matrix_row -= y;                                                                 // 将 matrix_row 指针还原
    matrix_col -= y;                                                                 // 将 matrix_col 指针还原
    for (num = 0; num < y; num++)
        sum += *matrix_row++ * *matrix_col++;

    return sum;
}


void matrix_multiply_answer(int *a, int *b, int *r, int x, int y, int z) {
    register int *m1p, *m2p;
    for (int i = 0; i < x; i ++ ) {         // 遍历 a 的行
        for (int j = 0; j < z; j ++) {      // 遍历 b 的列

            m1p = a + i * y;                // 选择 a 矩阵的第 i 行元素。跳过前 i*y 个元素
            m2p = b + j;                    // 选择 b 矩阵的第 j 列元素。跳过前 j 个元素即可
            *r = 0;                         // 当前位置清空

            for (int k = 0; k < y; k ++) {  // y 次乘积之和为当前位置元素值大小，
                *r += *m1p * *m2p;
                m1p++;                      // 每次加 1 个到下一列
                m2p += z;                   // 每次跳过 z 个到下一行
            }

            r++;                            // 且为行主序遍历，每次 r ++ 即可
        }
    }
}
