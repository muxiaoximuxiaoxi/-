/*
小易来到了一条石板路前，每块石板上从1挨着编号为：1、2、3.......
这条石板路要根据特殊的规则才能前进：对于小易当前所在的编号为K的 
石板，小易单次只能往前跳K的一个约数(不含1和K)步，即跳到K+X(X为K
的一个非1和本身的约数)的位置。 小易当前处在编号为N的石板，他
想跳到编号恰好为M的石板去，小易想知道最少需要跳跃几次可以到达。
例如：
N = 4，M = 24：
4->6->8->12->18->24
于是小易最少需要跳跃5次，就可以从4号石板跳到24号石板
输入描述:
输入为一行，有两个整数N，M，以空格隔开。 
(4 ≤ N ≤ 100000) (N ≤ M ≤ 100000)
输出描述:
输出小易最少需要跳跃的步数,如果不能到达输出-1
示例1
输入
4 24
输出
5*/
// 程序通过率为80%，并不能AC
//对于N=676, M=12948情况，贪婪算法求解为13步，而动态规划算法求解为10步。
// 贪婪算法并不一定能得到最优解，但是一个可行的，较好的解。
#include <iostream>
using namespace std;

int stepSearch(int N, int M) {
    if (N > M) {
        return -1;
    }
    if (N == M) {
        return 0;
    }
    int res = 0;
    for (int i = 2; i<N; i++) {
        if (i*(N / i) == N) {
            res++;
            if (stepSearch(N + N/i, M) != -1) {
                res += stepSearch(N + N/i, M);
                return res;
            }
            else {
                res--;
            }
        }
    }
    return -1;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        cout << stepSearch(N, M) << endl;
    }
    return 0;
}
