#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int n = 0;
	printf("请输入你想打印的乘法表的行列数：\n");
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i>=j)
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
	system("pause");
}

