#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	double sum = 0;
	int n = 1;
	for (n = 1; n <= 100; n++) {
		sum = sum + (1 / n)* pow(-1, n); 
	}
	printf("%f\n",sum);
	system("pause");
}
