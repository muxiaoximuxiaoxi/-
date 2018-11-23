#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//给一个正整数，要求：
//①求出它是几位数；
//②分别输出每一位数字；
//③按逆序输出各位数字，例如原数为321，应输出123.
int CountDigitPlace(int n) {
	int count = 1;
	int m = n;
	while (m > 9) {
		m = m / 10;
		++count;
	}
	return count;
}
void ReseverPrint(int n) {
	while (n > 9) {
		printf("%d ", n % 10);
		n /= 10;
	}
	printf("%d\n", n);
}
int Print(int n) {
	if (n > 9) {
		Print(n / 10);
	}
	printf("%d ", n % 10);
}
int main() {
	int n = 0;
	int count = 0;
	printf("输入一个数\n");
	scanf("%d", &n);
	count = CountDigitPlace(n);
	printf("它是%d位数\n",count);
	printf("顺序输出为：\n");
	Print(n);
	printf("\n");
	printf("逆置输出为：\n");
	ReseverPrint(n);
	system("pause");
}
