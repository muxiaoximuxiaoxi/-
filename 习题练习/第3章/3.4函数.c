#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//有一个函数：
//y=x(x<1)
//y=2*x-1(x >= 1 && x < 10)
//3*x-11(x>=10)
//写程序，整入x的值，输出y相应的值。
int main() {
	int x = 0, y = 0;
	printf("输入x\n");
	scanf("%d", &x);
	if (x < 1) {
		printf("x=%d\n", x);
		printf("y=%d\n", x);
	}
	else if (x >= 1 && x < 10) {
		printf("x=%d\n", x);
		printf("y=%d\n", 2 * x - 1);
	}
	else {
		printf("x=%d\n", x);
		printf("y=%d\n", 3 * x - 11);
	}
	system("pause");
}
