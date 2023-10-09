/*
    请编写函数
                unsigned int reverse_bits( unsigned int value );
    这个函数的返回值是  把value的二进制位模式从左到右变换一下后的值。
    例如，
        在32位机器上，25这个值包含下列各个位：
                00000000000000000000000000011001
    函数的返回值应该是 2550136832，它的二进制位模式是：
                10011000000000000000000000000000
    编写函数时要注意不要让它依赖于你的机器上整型值的长度。
*/

#include <stdio.h>

unsigned int reverse_bits( unsigned int value );

int main(void)
{
    unsigned int num;
    unsigned int new_num;

    printf("Input num:\n");
    scanf("%d", &num);

    new_num = reverse_bits(num);
    printf("0X%8X\n", num);
    printf("0X%8X\n", new_num);

    return 0;
}

unsigned int reverse_bits( unsigned int value ) {
    unsigned int new_vlue = 0;

                            // 编写函数时要注意不要让它依赖于你的机器上整型值的长度。
    unsigned int i = 1;     // i进行左移，只要i不等于0，就仍在限定长度内
    for (i = 1; i != 0; i <<= 1) {
        new_vlue <<= 1;
        if ( value & 1 ) {  // value最后一位等于1
            new_vlue |= 1;  // new_vlue最后一位置1
        }
        value >>= 1;
    }
    return new_vlue;  
}