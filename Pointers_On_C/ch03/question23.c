/*
				名字	类型	存储类型	链接属性	作用域	             初始化为
				a	    int	    static	   external	  x可以访问，y不能访问	   1
				b	    char	static	   none	      x和y都可以访问	      2
				c	    int	    auto	   none	      x的局部变量	          3
				d	    float	static	   none	      x的局部变量 	          4

*/

#include <stdio.h>

void y(void){
    static char b = 2;
    printf("yb = %d\n", b);
    // printf("ya = %d\n", a);      // a为文件作用域，作用域从声明处到文件尾
}

int a = 1;

void x(void){
    static char b = 2;
    printf("xb = %d\n", b);
    int c = 3;
    printf("xa = %d\n", a);
    printf("xc = %d\n", c);
    static float d = 4;
    printf("xd = %f\n", d);
}

int main(void)
{
    y();
    x();

    return 0;
}
