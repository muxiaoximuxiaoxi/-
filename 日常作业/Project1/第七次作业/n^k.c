#pragma once
#include<stdio.h>
#include<stdlib.h>
//编写一个函数实现n^k，使用递归实现
int nk(int n,int k) {
	if (k == 0) {
		return 1;
	}
	else {
		return n*nk(n, k - 1);
	}
}
int main() {
	int n = 2;
	int k = 3;
	printf("%d\n", nk(n, k));
	system("pause");
}
