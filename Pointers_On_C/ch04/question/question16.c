/*
    编写一些语句，根据变量precipitating和temperature的值打印当前天气的简单总结。
    如果precipitating为	而且temperature是	那就打印
    Ture	           <32                 snowing
                       >=32	               raining
    false	           <60	               cold
                       >=60                warm             
*/

#include <stdio.h>

int main(void)
{   
    int precipitating, temperature;
    printf("Input precipitating and temperature\n");
    scanf("%d %d", &precipitating, &temperature);

    switch (precipitating) {
        case 1:
            if (temperature < 32)
                printf("snowing");
            else
                printf("raining");
            break;
        case 0:
            if (temperature < 60)
                printf("cold");
            else
                printf("warm");
            break;
        default:
            printf("Input Error");
            break;
    }

    return 0;
}