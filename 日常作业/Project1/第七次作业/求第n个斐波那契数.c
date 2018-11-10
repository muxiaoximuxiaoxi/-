#pragma once
#include<stdio.h>
#include<stdlib.h>
//递归和非递归分别实现求第n个斐波那契数。
int Recursion(int n) {
	if (n <= 2) {
		return 1;
	}
	else { 
        return Recursion(n-1) + Recursion(n - 2);
	}
}
int NoRecursion(int n) {
	int a = 1;
	int b = 1;
	int c = 0;
	if(n<=2){
		return 1;
	}
	while (n > 2) {
		c = a + b;
		a = b;
		b = c;
		n--;
	}
	return c;
}
int main() {
	int n = 10;
	printf("%d\n", Recursion(n));
	printf("%d\n", NoRecursion(n));
	system("pause");
}
