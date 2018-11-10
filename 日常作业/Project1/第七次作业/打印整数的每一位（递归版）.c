#pragma once
#include<stdio.h>
#include<stdlib.h>
int print(int n) {
	if (n >9) {
		print(n / 10);
	}
		printf("%d ", n%10);
}
int main() {
	int n = 123;
	print(n);
	printf("\n");
	system("pause");
}
