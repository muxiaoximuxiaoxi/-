#include<stdio.h>
#include<stdlib.h>
void JudgeLeapYear(int *a) {
	int n = *a;
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0) {
		printf("%d������\n", n);
	}
	else {
		printf("%d��������\n", n);
	}
}
int main() {
	int a = 1999;
	JudgeLeapYear(&a);
	system("pause");
	}
