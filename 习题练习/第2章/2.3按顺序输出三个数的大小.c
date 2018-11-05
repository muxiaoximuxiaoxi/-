#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 10;
	int b = 20;
	int c = -10;
	int temp = 0;
	if (a > b) {
		a = a;
	}
	else {
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {
		a = a;
	}
	else {
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
		b = b;
	}
	else {
		temp = b;
		b = c;
		c = temp;
	}
	printf("最大值为%d\t", a);
	printf("次之值为%d\t", b);
	printf("最小值为%d\n", c);
	system("pause");
}
