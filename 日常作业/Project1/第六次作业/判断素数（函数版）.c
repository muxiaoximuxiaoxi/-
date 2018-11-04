#include<stdio.h>
#include<stdlib.h>
void JugeOddNum(int *a) {
	int n = *a;
	int i = 1;
	for (i = 2; i < n; i++) {
		if (n%i == 0) 
			break;
	}
	if (i == n) {
		printf("%d是素数\n", n);
	}
	else
	{
		printf("%d不是素数\n", n);
	}
}
int main() {
	int a = 119;
	JugeOddNum(&a);
	system("pause");
}
