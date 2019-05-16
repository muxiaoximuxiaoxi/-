//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int m = 0, n = 0, q = 0, count = 0;
	printf("请输入你俩个数字：");
	scanf("%d %d", &m, &n);
	q = m ^ n;
	while (q) {
		if (q % 2 == 1) {
			++count;
		}
		q /= 2;
	}
	printf("%d与%d在转换成二进制数之后不同数的个数为%d\n", m, n, count);
	system("pause");
}
