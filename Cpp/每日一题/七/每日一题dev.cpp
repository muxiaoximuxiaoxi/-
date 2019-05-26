
/*Fibonacci数列
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i - 1] + F[i - 2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想
让其变为一个Fibonacci数，每一步你可以把当前数字X变为X - 1
或者X + 1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。

输入描述 :
输入为一个正整数N(1 ≤ N ≤ 1, 000, 000)

输出描述 :
	输出一个最小的步数变为Fibonacci数"
	示例1
	输入
	15
	输出
	2
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int N, f0 = 0, f1 = 1, f = 0;
	cin >> N;
	while (N > f) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	\\当N==15时，结束循环时，f=25,f0=13,f1=25;
	cout << min(f - N, N - f0);
}
*/
/*合法括号序列判断
对于一个字符串，请设计一个算法，判断其是否为一个合法的括号串。
给定一个字符串A和它的长度n，请返回一个bool值代表它是否为一个合
法的括号串。
测试样例：
"(()())", 6
返回：true
测试样例：
"()a()()", 7
返回：false
测试样例：
"()(()()", 7
返回：false

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		int count = 0;
		for (int i = 0;i < n;++i) {
			if (A[i] == '(') {
				count += 1;
			}
			if (A[i] == ')') {
				count -= 1;
			}
		}
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
*/
