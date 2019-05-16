//输出一个整数的每一位。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	printf("请输入你想输出的整数：");
	int x = 0;
	scanf("%d", &x);
	while (x) {
		printf("%d\n", x % 10);
		x /= 10;
	}
	system("pause");
}
