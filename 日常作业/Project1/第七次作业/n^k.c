#pragma once
#include<stdio.h>
#include<stdlib.h>
//��дһ������ʵ��n^k��ʹ�õݹ�ʵ��
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
