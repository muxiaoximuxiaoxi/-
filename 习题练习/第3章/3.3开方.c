#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//从键盘输入一个小于1000的正数，
//要求输入他的平方根，如平方根不是整数，则输入其整数部分。
int main() {
	int n = 0, m = 0;
	scanf("%d", &n);
	while (n <= 0 && n >= 1000) {
		printf("输入有误，请重新输入！\n");
		scanf("%d", &n);
	}
	m = sqrt(n);
	printf("%d\n", m);
	system("pause");
}
