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
		printf("该二次函数无实数根\n");
	}
	else if (m == 0) {
		printf("该二次函数有2个相同的实数根\n");
		x1 = (-b - pow(m, 1.0 / 2)) / 2 * a;
		x2 = (-b + pow(m, 1.0 / 2)) / 2 * a;
		printf("x1为%f x2为%f\n", x1, x2);
	}
	else {
		printf("该二次函数有2个不同的实数根\n");
		x1 = (-b - pow(m, 1.0 / 2)) / 2 * a;
		x2 = (-b + pow(m, 1.0 / 2)) / 2 * a;
		printf("x1为%f x2为%f\n", x1, x2);
	}
	system("pause");
}
