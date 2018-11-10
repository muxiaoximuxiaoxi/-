#pragma once
#include<stdio.h>
#include<stdlib.h>
int RecursiveFactorial(int n) {
	if (n <= 1) {
		return 1;
	}
	else {
		return n * RecursiveFactorial(n - 1);
	}
}
int NoRecursiveFactorial(int n) {
	int m = 1;
	for (n; n >= 1; n--) {
		m *= n;
	}
	return m;
}
int main() {
	int n = 10;
	int m1 = 0;
	int m2 = 0;
	m1=RecursiveFactorial(n);
	m2 = NoRecursiveFactorial(n);
	printf("%d\n", m1);
	printf("%d\n", m2);
	system("pause");
}
