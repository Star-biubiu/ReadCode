/*
    美国联邦政府使用下面这些规则计算1995年每个公民的个人收入所得税：
    如果你的含税收入大于    但不超过        你的税额为        超过这个数额的部分
    $0                    $23,350         15%              $0
    23,350                56,550          $3,502.50+28%    23,350
    56,550                117,950         12,798.50+31%    56,550
    117,950               256,500         31,832.50+36%    117,950
    256,500               —               81,710.50+39.6%  256 500
    为下面的函数原型编写函数定义：
        float single_tax( float income );
    参数income表示应征税的个人收入，函数的返回值就是income应该征收的税额。
*/

#include <stdio.h>
#include <float.h>

static float income_list[] = {0, 23350, 56550, 117950, 256500, FLT_MAX};
static float tax_base[] = {0, 3502.50, 12795.50, 31832.50, 81710.50};
static float tax_percentage[] = {0.15, 0.28, 0.31, 0.36, 0.396};

float single_tax( float income );

int main(void)
{
    float income, tax;
    printf("Input your income:\n");
    scanf("%f", &income);
    tax = single_tax(income);
    printf("Your tax = %f:\n", tax);

    return 0;
}

float single_tax( float income ) {
    int i;
    // for( i = 1; income >= income_list[i++]; )     // 不论比较结果i都会自增 比实际值大2
    /*
        如：income = income_list[1]时：
            income = income_list[1] i = 2
            income < income_list[2]     此时 i = 3
    */ 
    for( i = 1; income >= income_list[i]; i++) ;     // 成功加1 比实际值大1
    i--;
    return tax_base[i] + tax_percentage[i] * ( income - income_list[i] );
}
