#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 16;
	int b = 12;
	int m = a;
	int n = b;
	int r = 1;
	while (r!= 0) {
		r = m % n;
		if (r != 0) {
			m = n;
			n = r;
		}
	}
	printf("%d��%d�����Լ��Ϊ%d\n", a, b, n);
	system("pause");
}
