/*二进制插入
有两个32位整数n和m，请编写算法将m的二进制数位插入到n的二进制的
第j到第i位,其中二进制的位数从低位数到高位且以0开始。
给定两个数int n和int m，
同时给定int j和int i，意义如题所述，请返回操作后的数，
保证n的第j到第i位均为零，且m的二进制位数小于等于i - j + 1。

测试样例：
1024，19，2，6
返回：1100
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return n | m;
	}
};
*/
/*
查找组成一个偶数最近的两个素数
任意一个偶数（大于2）都可以由2个素数组成，
组成偶数的2个素数有很多种情况，本题目要求
输出组成指定偶数的两个素数差值最小的素数对
输入描述 :
输入一个偶数

输出描述 :
输出两个素数

示例1
输入
20
输出
7
13
*/ 
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int i)
{
	for (int j = 2; j <= sqrt(i * 1.0); j++) {
		if (i % j == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	int Prime1, Prime2;
	while (cin >> n) {
		if (n < 2)
			return 1;
		else {
			for (int i = 1; i <= n / 2;i++) {
				if (isPrime(i) && isPrime(n - i)) {
					Prime1 = i;
					Prime2 = n - i;
				}
			}
			cout << Prime1 << endl;
			cout << Prime2 << endl;
		}
	}
	return 0;
}

