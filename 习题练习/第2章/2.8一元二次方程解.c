#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int a = 1;
	int b = 2;
	int c = 1;
	int m = 0;
	double x1 = 0;
	double x2 = 0;
	m = b * b - 4 * a*c;
	if (m < 0) {
		printf("�ö��κ�����ʵ����\n");
	}
	else if (m == 0) {
		printf("�ö��κ�����2����ͬ��ʵ����\n");
		x1 = (-b - pow(m, 1.0 / 2)) / 2 * a;
		x2 = (-b + pow(m, 1.0 / 2)) / 2 * a;
		printf("x1Ϊ%f x2Ϊ%f\n", x1, x2);
	}
	else {
		printf("�ö��κ�����2����ͬ��ʵ����\n");
		x1 = (-b - pow(m, 1.0 / 2)) / 2 * a;
		x2 = (-b + pow(m, 1.0 / 2)) / 2 * a;
		printf("x1Ϊ%f x2Ϊ%f\n", x1, x2);
	}
	system("pause");
}
