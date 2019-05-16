//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i = 0,n = 0;
	int a[30] = { 0 };
	printf("请输入你想转换的数：\n");
	scanf("%d", &n);
	while (n) {
		a[i] = n % 2;
		i += 1;
		n /= 2;
	}
	for (;i >= 0;i--) {
		if (i % 2 == 0) {//因为数组是从0开始计数的，故a[0]应为奇数位 a[1]为偶数位
			printf("奇数位:%d",a[i]);
		}
		else {
			printf("偶数位:%d", a[i]);
		}
		printf("\n");
	}
	printf("由高位向低位\n");
	system("pause");
}
