/*
    编写一个程序，它由3个函数组成，每个函数分别保存在一个单独的源文件中。
    函数increment接受一个整型参数，它的返回值是该参数的值加1,increment函数应该位于文件increment.c中。
    第2个函数称为negate，它也接受一个整型参数，它的返回值是该参数的负值（例如，如果参数是25，函数返回25；如果参数是612，函数返回612）。
    最后一个函数是main，保存于文件main.c中，它分别用参数10, 0和10调用另外两个函数，并打印出结果。
*/

int increment(int a){
    return ++a;
}
