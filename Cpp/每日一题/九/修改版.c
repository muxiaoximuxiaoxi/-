/*
请编写一个函数（允许增加子函数），计算n x m的棋盘格子
（n为横向的格子数，m为竖向的格子数）沿着各自边缘线从左上角
走到右下角，总共有多少种走法，要求不能走回头路，即：只能往右
和往下走，不能往左和往上走。

输入描述 :
输入两个正整数



输出描述 :
返回结果

示例1
输入
2
2
输出
6
*/
//通过率100%
#include<iostream>
using namespace std;

int Countnum(int m, int n) {
	if (m == 0 || n == 0)
		return 1;
	else
		return Countnum(m - 1, n) + Countnum(m, n - 1);
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		//输入改为循环了
		cout << Countnum(m, n) << endl;
	}
	return 0;
}


//明明运算结果都相同但就是过不了
#include<iostream>
using namespace std;
/*思路：
用递归来做，将右下角看做原点(0, 0)，左上角看做坐标(m, n)，
下图所示：

从(m, n)— > (0, 0)就分两步走：
往右走一步：f(m, n - 1)— > (0, 0) 
加上下走一步：f(m - 1, n)— > (0, 0)
注意：但凡是触碰到边界，也就是说f(x, 0)或者f(0, x)都
只有一条直路可走了，这里的x是变量哈。
f(m, n) = f(m, n - 1) + f(m - 1, n)
按照这种思想，算法就很简单了，
*/
int Countnum(int m, int n) {
	if (m == 0 || n == 0)
		return 1;
	else
		return Countnum(m - 1, n) + Countnum(m, n - 1);
}

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	int num = Countnum(m, n);
	cout << num;
	return 0;
}

/*另类加法
请编写一个函数，将两个数字相加。不得使用 + 或其他算数运算符。

给定两个int A和B。请返回A＋B的值

测试样例：
1, 2
返回：3
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int a = 0, b = 0;
		while (B != 0) {
			a = A ^ B;
			b = (A&B) << 1;
			A = a;
			B = b;
		}
		return A;
	}
};

*/
