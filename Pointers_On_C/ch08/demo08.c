/*
    皇后是国际象棋中威力最大的棋子。在下面所示的棋盘上，皇后可以攻击位于箭头所覆盖位置的所有棋子。

    我们能不能把8个皇后放在棋盘上，它们中的任何一个都无法攻击其余的皇后？这个问题被称为八皇后问题。
    你的任务是编写一个程序，找到八皇后问题的所有答案，看看一共有多少种答案。

    如果你采用一种叫做回溯法(backtracking)的技巧，就很容易编写出这个程序。
    编写一个函数，把一个皇后放在某行的第1列，然后检查它是否与棋盘上的其他皇后互相攻击。
    如果存在互相攻击，函数把皇后移到该行的第2列再进行检查。如果每列都存在互相攻击的局面，函数就应该返回。
    但是，如果皇后可以放在这个位置，函数接着应该递归地调用自身，把一个皇后放在下一行。
    当递归调用返回时，函数再把原先那个皇后移到下一列。当一个皇后成功地放置于最后一行时，函数应该打印出棋盘，显示8个皇后的位置。
*/

#include<stdio.h>
#include<math.h>

#define MAX_ARRAY 20
#define False   0
#define True    1

int rank[MAX_ARRAY];                                    // 皇后位置存储数组(静态变量，默认为0) 最大值为 MAX_ARRAY
int vis[MAX_ARRAY];                                     // 皇后状态存储数组(静态变量，默认为0) 最大值为 MAX_ARRAY
int n, cnt=0;

void dfs(int pos) {                                     // 递归回溯法

	if( pos == n + 1 ) {                                // 递归边界条件, 直到执行 n行 退出(行从1开始 到n+1结束)
		cnt++;
		int i, j;
		for(i = 1; i < n + 1; i++) {
			for(j = 1; j < n + 1; j++) {
				if(rank[i] == j)
					printf("* ");
				else	
					printf("# ");
			}
			printf("\n");
		}
		printf("\n");

		return ;
	}

    int i, flag;
	for( i = 1; i < n + 1; i++ ) {                      // 枚举每行 (棋盘为n行n列 行从1开始 到n+1结束) 	行
		if(vis[i] == False) {                           
			flag = True;								// 第i行未放置皇后, 标志位置1

			for( int j = 1; j < pos; j++ ) {            // 枚举 第pos列 之前的皇后 					   列
				// 判断是否处于同一右斜线，可以总结规律: 两位置的行号加上列号相等	
				// 判断是否处于同一左斜线，可以总结规律: 两位置的行号减上列号相等

				if( abs(pos-j) == abs(i-rank[j]) ) {    // 判断是否处于同一斜线
					flag = False;						// 处于同一斜线, 标志位置0
					break;
				}
			}

			if( flag ) {
				rank[pos] = i;                          // pos列在i行 
				vis[i] = True;
				dfs(pos + 1); 
				vis[i] = False;
			}
		}
	}
}

int main(void)
{
	scanf("%d", &n);
	dfs(1);
	printf("solution numbers = %d", cnt);

	return 0;
} 
