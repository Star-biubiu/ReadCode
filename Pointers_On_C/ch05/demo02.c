/*
    编写一个程序，从标准输入读取字符，并把它们写到标准输出中。所有非字母字符都完全按照它的输入形式输出，字母字符在输出前进行加密。
    加密方法很简单：每个字母被修改为在字母表上距其13个位置（前或后）的字母。
        例如，A被修改为N，B被修改为O，Z被修改为M，以此类推。注意大小写字母都应该被转换。
        提示：记住字符实际上是一个较小的整型值这一点可能对你有所帮助。
*/

#include <stdio.h>

int encrypt(int ch, int base);

int main(void)
{
    int ch;

    while ( (ch = getchar()) != EOF) {
        if ( (ch >= 'A' && ch <= 'Z') ) {
            // ch = encrypt(ch, 'A');
            if (ch + 13 > 'Z')
                ch -= 13;
            else
                ch += 13;
        }
        else if ( (ch >= 'a' && ch <= 'z') ) {
            // ch = encrypt(ch, 'a');
            if (ch + 13 > 'z')
                ch -= 13;
            else
                ch += 13;
        }
        putchar(ch);
    }

    return 0;
}

int encrypt(int ch, int base) {
    ch -= base;         // 得到字符与A或a的差值
    ch += 13;           // 变成该字符后的第13个字符
    ch %= 26;           // 处理溢出情况，很巧妙 比如是该字符是第14个字符，加13后变成27，超过26个字符，对26求余即可得到正确结果
    return ch + base;   // 加上差值
}