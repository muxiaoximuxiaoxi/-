
/*
最大连续bit数
功能 : 求一个byte数字对应的二进制数字中1的最大连续数，例如3的二进制为00000011，最大连续2个1

	输入 : 一个byte型的数字

	输出 : 无

	返回 : 对应的二进制数字中1的最大连续数

	输入描述 :
输入一个byte数字



输出描述 :
输出转成二进制之后连续1的个数

示例1
输入
3
输出
2
*/ 
#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

#define N 32
int main() {
	int n;
	cin >> n;
	int m = n;
	int temp = 0;
	int maxnum = INT_MIN;
	int count = 0;
	for (int i = 0;i < 32;++i) {
		temp = m % 2;
		if (temp == 1) {
			++count;
		}
		else {
			if (count > maxnum) {
				maxnum = count;
				count = 0;
			}
		}
		m = m / 2;
	}
	cout << maxnum;
	system("pause");
}

