#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//��3������a��b��c���ɼ������룬�������������
int main() {
	int a = 0, b = 0, c = 0,temp=0;
	scanf("%d %d %d", &a, &b, &c);
	if (a > b) {
	}
	else {
		temp = a;
		a = b;
		b = temp;
	}
	if (a > c) {
	}
	else {
		temp = a;
		a = c;
		c = temp;
	}
	if (b > c) {
	}
	else {
		temp = b;
		b = c;
		c = temp;
	}
	printf("���ֵΪ%d\n", a);
	system("pause");
}
