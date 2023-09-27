/*
    新闻记者都受过训练，善于提问谁？什么？何时？何地？为什么？
    请编写一些语句，如果变量which_word的值是1，就打印who；如果值为2，打印what，依次类推。
    如果变量的值不在1到5的范围之内，就打印don’t know。 
*/

#include <stdio.h>

int main(void)
{
    int num;
    printf("Input num:\n");
    scanf("%d", &num);

    switch (num) {
        case 1:
            puts("who");
            break;
        case 2:
            puts("what");
            break;
        case 3:
            puts("when");
            break;
        case 4:
            puts("where");
            break;
        case 5:
            puts("why");
            break;
        default:
            puts("don't know");
            break;
    }

    return 0;
}