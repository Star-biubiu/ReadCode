/*
    编写一个函数，把一个给定的值存储到一个整数中指定的几个位。
    它的原型如下：
        int store_bit_field(int original_value,
                            int value_to_store,
                            unsigned starting_bit,
                            unsigned ending_bit
                            )；
    假定整数中的位是从右向左进行编号。因此，起始位的位置不会小于结束位的位置。
    为了更清楚地说明，函数应该返回下列值：
    原 始 值    需要存储的值    起 始 位    结 束 位    返 回 值
    0x0         0x1           4           4          0x10
    0000 0000   0000 0001                            0001 0000

    0xffff      0x123         15          4          0x123f
    0xffff      0x123         13          9          0xc7ff
   15       8 7       0  15       8 7       0  15       8 7       0
    1111 1111 1111 1111   0000 0001 0010 0011   0001 0010 0011 1111
    1111 1111 1111 1111   0000 0001 0010 0011   1100 0111 1111 1111
    提示：把一个值存储到一个整数中指定的几个位分为5个步骤。以上表最后一行
    为例：
        1．创建一个掩码(mask)，它是一个值，其中需要存储的位置相对应的那几个位设置为1。此时掩码为  0011 1110 0000 0000
        2．用掩码的反码对原值执行AND操作，将那几个位设置为0。原值1111111111111111，操作后变为    1100 0001 1111 1111
        3．将新值左移，使它与那几个需要存储的位对齐。新值0000 0001 0010 0011(0x123)，左移后变为0000 0110 0000 0000
        4．把移位后的值与掩码进行位AND操作，确保除那几个需要存储的位之外的其余位都设置为0。进行这个操作之后，值变为0000 0110 0000 0000。
        5．把结果值与原值进行位OR操作，结果为1100011111111111（0xc7ff），也就是最终的返回值。
    在所有任务中，最困难的是创建掩码。你一开始可以把~0这个值强制转换为无符号值，然后再对它进行移位
*/

#include <stdio.h>

int store_bit_field(int original_value,     // 原始值
                    int value_to_store,     // 存储值
                    unsigned starting_bit,  // 起始位
                    unsigned ending_bit     // 终止位
                    );

int main(void)
{
    int original_value = 0xffff, value_to_store = 0x123, value;
    unsigned starting_bit = 13, ending_bit = 9;
    value = store_bit_field(original_value, value_to_store, starting_bit, ending_bit);
    printf("value\t = \t0x%x\n", value);

    return 0;
}

int store_bit_field(int original_value,     // 原始值
                    int value_to_store,     // 存储值
                    unsigned starting_bit,  // 起始位
                    unsigned ending_bit     // 终止位
                    ) {
    // 1. 创建一个掩码(mask)
    unsigned mask = 0, store = 0;
    int temp, num_bit;
    num_bit = starting_bit - ending_bit;

    for (int i = ending_bit; i <= starting_bit; i++)
        mask |= 1 << i;
    printf("mask\t = \t0x%x\n", mask);                  // 0x3e00   0011 1110 0000 0000

    // 2. 用掩码的反码对原值执行AND操作
    mask = ~mask;                                       // 掩码的反码
    printf("~mask\t = \t0x%x\n", mask);                 // 0xc1ff   1100 0001 1111 1111
    
    temp = original_value & mask;
    printf("value\t = \t0x%x\n", temp);                 // 0xc1ff   1100 0001 1111 1111

    // 3. 将新值左移，使它与那几个需要存储的位对齐
    for (int i = 0; i <= num_bit; i++)
        store |= 1 << i;
    printf("store__\t = \t0x%x\n", store);              // 0x1f     0000 0000 0001 1111   
    value_to_store = value_to_store & store;
    printf("store\t = \t0x%x\n", value_to_store);       // 0x3      0000 0000 0000 0011
    value_to_store <<= ending_bit;
    printf("store\t = \t0x%x\n", value_to_store);       // 0x600    0000 0110 0000 0000

    // 4. 把移位后的值与掩码进行位AND操作
    value_to_store = value_to_store & (~mask);          // 0x600
    printf("store\t = \t0x%x\n", value_to_store);


    // 5. 把结果值与原值进行位OR操作
    temp = temp | value_to_store;

    return temp;
}


#if 0
int store_bit_field(int original_value, int value_to_store, unsigned starting_bit, unsigned ending_bit) {
    unsigned mask;
    /*
** Validate the bit parameters. If an error is found, do nothing. This
** is not great error handling.
*/
    if (starting_bit < INT_BITS && ending_bit < INT_BITS && starting_bit >= ending_bit) {
        /*
** Construct the mask, which is unsigned to ensure that we get a
** logical, not arithmetic shift.
*/
        mask = (unsigned)-1;
        mask >>= INT_BITS - (starting_bit - ending_bit + 1);
        mask <<= ending_bit;
        /*
** Clear the field in the original value.
*/
        original_value &= ~mask;
        /*
** Shift the value to store to the right position
*/
        value_to_store <<= ending_bit;
        /*
** Mask excess bits off of the value, and store it.
*/
        original_value |= value_to_store & mask;
    }
    return original_value;
}
#endif