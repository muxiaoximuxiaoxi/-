#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int a = 2;
	double sum = 0;
	int b = 0;
	for (int i = 0; i < 5; i++) {
		b += a * pow(10, i);
		sum += b;
	}
	printf("%f\n", sum);
	system("pause");
}
