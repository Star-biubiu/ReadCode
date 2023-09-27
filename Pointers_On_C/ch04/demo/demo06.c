/*
    请编写一个函数，它从一个字符串中提取一个子字符串。函数的原型应该如下：
        int substr( char dst[], char src[], int start, int len );
    函数的任务是从src数组起始位置向后偏移start个字符的位置开始，最多复制len个非NUL字符到dst数组。
    在复制完毕之后，dst数组必须以NUL字节结尾。函数的返回值是存储于dst数组中的字符串的长度。
    如果start所指定的位置越过了src数组的尾部，或者start或len的值为负，那么复制到dst数组的是个空字符串
*/

#include <stdio.h>
#include <string.h>

int substr(char dst[], char src[], int start, int len);

int main(void)
{
    char dst[10], src[10] = "012345678";
    int start = 11, len = 4, num;
    num = substr(dst, src, start, len);
    printf("dst[len: %d] = %s", num, dst);

    return 0;
}

int substr(char dst[], char src[], int start, int len) {
    int index_dst, index_src, n_src = 0;

    while (src[n_src])
        n_src++;

    if (start < 0 || len < 0 || start >= n_src) {
        dst[0] = '\0';
        return 1;
    }
    else {
        for (index_dst = 0, index_src = start; index_dst < len; index_dst++) {
                dst[index_dst] = src[index_src];
                if (src[index_src] != '\0')
                    index_src++;
                else
                    break;
        }
        return index_dst;
    }
}

/*   另一种答案
int substr(char dst[], char src[], int start, int len) {
    int d = 0, s = 0;
    if (start >= 0 && len > 0) {
        for (s; s < start && src[s] != '\0'; s++)
            ;
        
        while (len > 0 && src[s] != '\0') {
            dst[d++] = src[s++];
            len--;
        }
    }
    dst[d] = '\0';
    return d;
}
*/