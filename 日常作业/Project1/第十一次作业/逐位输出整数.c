//���һ��������ÿһλ��
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	printf("���������������������");
	int x = 0;
	scanf("%d", &x);
	while (x) {
		printf("%d\n", x % 10);
		x /= 10;
	}
	system("pause");
}
