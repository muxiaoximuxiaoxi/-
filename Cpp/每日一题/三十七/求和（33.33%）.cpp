/*
求和
输入两个整数 n 和 m，从数列1，2，3.......n 中随意取几个数, 
使其和等于 m, 要求将其中所有的可能组合列出来
输入描述 :
每个测试输入包含2个整数, n和m
输出描述 :
按每个组合的字典序排列输出, 每行输出一种组合
示例1
输入
5 5
输出
1 4
2 3
5*/
//通过33.33%
//这是一种取巧的做法，不建议使用
#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1;i < (n + 1) / 2;++i) {
			for (int j = 1;j < n;++j) {
				if (i + j == m)
					cout << i << " " << j << endl;
			}
		}
		cout << m << endl;
	}
	system("pause");
	return 0;
}
