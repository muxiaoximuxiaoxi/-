#include<stdio.h>
#include<stdlib.h>
int main() {
	int i;
	int a[4] = { 1,2,3,4 };
	int b[4] = { 5,6,7,8 };
	int c[4] = { 0,0,0,0 };
	for (int i = 0; i < 4; i++) {
		c[i] = a[i];
		a[i] = b[i];
		b[i] = c[i];
	}
	for (int i = 0; i < 4; i++) {
		printf("%d\t", a[i]);
	}
	printf("\n");
	for (int i = 0; i < 4; i++) {
		printf("%d\t", b[i]);
	}	
	printf("\n");
	system("pause");
}
