/*
    等边三角形的三条边长度都相等，但等腰三角形只有两条边的长度是相等的。如果三角形的三条边长度都不等，那就称为不等边三角形。
    请编写一个程序，提示用户输入三个数，分别表示三角形三条边的长度，然后由程序判断它是什么类型的三角形。
    提示：除了边的长度是否相等之外，程序是否还应考虑一些其他的东西？
        三角形定义：两边之和大于第三边
*/

#include <stdio.h>

int main(void)
{
    double a[3], temp;
    puts("Input tree numbers:");
    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);
    if (a[0] <= 0 || a[1] <=0 || a[2] <= 0)
        puts("Input Error");
    for (int i = 0; i < 2; i++) {
        if (a[i] > a[i + 1]){
            temp = a[i];
            a[i] = a[i + 1];
            a[i + 1] = temp; 
        }
    }

    if(a[0] + a[1] <= a[2])
        puts("Not triangle");
    else if(a[0] == a[2])
        puts("equation3");
    else if(a[0] == a[1] || a[1] == a[2])
        puts("equation2");
    else
        puts("equation0");

    return 0;
}


