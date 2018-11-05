#include<stdio.h>
#include<stdlib.h>
int main() {
	int temp = 0;
	int a = 20;
	int b = 10;
	temp = a;
	a = b;
	b = temp;
	printf("a=%d b=%d\n", a, b);
	system("pause");
}
