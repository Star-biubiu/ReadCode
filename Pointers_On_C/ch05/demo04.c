/*
    编写一组函数，实现位数组。函数的原型应该如下：
        void set_bit( char bit_array[], unsigned bit_number );
        void clear_bit( char bit_array[], unsigned bit_number );
        void assign_bit( char bit_array[], unsigned bit_number, int value );
        void test_bit( char bit_array[], unsigned bit_number );
    每个函数的第1个参数是个字符数组，用于实际存储所有的位。第2个参数用于标识需要访问的位。函数的调用者必须确保这个值不要太大，以至于超出数组的边界。
    第1个函数把指定的位设置为1
    第2个函数则把指定的位清零
    如果value的值为0 第3个函数则把指定的位清零, 否则设置为1。
    至于最后一个函数，如果参数中指定的位不是0，函数就返回真，否则返回假.
*/

#include <stdio.h>

void set_bit( char bit_array[], unsigned bit_number );
void clear_bit( char bit_array[], unsigned bit_number );
void assign_bit( char bit_array[], unsigned bit_number, int value );
int  test_bit( char bit_array[], unsigned bit_number );

int main(void)
{
    int flag;
    char str[]="0110100000000000";
    printf("str\t\t =\t %s\n", str);

    set_bit(str, 0);
    printf("set_bit\t\t =\t %s\n", str);

    clear_bit(str, 1);
    printf("clear_bit\t =\t %s\n", str);

    assign_bit(str, 2, 0);
    printf("assign_bit\t =\t %s\n", str);

    flag = test_bit(str, 4);
    printf("test_bit\t =\t %d\n", flag);

    return 0;
}

#if 0  
        // 错误答案 bit_array[bit_number]是字符类型，如'1'值不是1，实际是49 = 0b00110001 
        // 因此不能简单的用bit_array[bit_number] |= 1 << bit_number;进行位操作
void set_bit( char bit_array[], unsigned bit_number ) {
    bit_array[bit_number] |= 1 << bit_number;
}

void clear_bit( char bit_array[], unsigned bit_number ) {
    bit_array[bit_number] &= ~(unsigned)(1 << bit_number);
}

void assign_bit( char bit_array[], unsigned bit_number, int value ) {
    if (value == 0) 
        clear_bit(bit_array, bit_number);
    else
        set_bit(bit_array, bit_number);
}

int test_bit( char bit_array[], unsigned bit_number ) {
    if ( bit_array[bit_number] & 1 )
        return 1;
    else 
        return 0;
}
#endif

#if 1
void set_bit( char bit_array[], unsigned bit_number ) {
    bit_array[bit_number] = '1';
}

void clear_bit( char bit_array[], unsigned bit_number ) {
        bit_array[bit_number] = '0';
}

void assign_bit( char bit_array[], unsigned bit_number, int value ) {
    if (value == 0) 
        clear_bit(bit_array, bit_number);
    else
        set_bit(bit_array, bit_number);
}

int test_bit( char bit_array[], unsigned bit_number ) {
    if ( bit_array[bit_number] != '0' )
        return 1;
    else 
        return 0;
}
#endif