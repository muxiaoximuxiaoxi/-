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
	printf("���ֵΪ%d\t", a);
	printf("��ֵ֮Ϊ%d\t", b);
	printf("��СֵΪ%d\n", c);
	system("pause");
}
