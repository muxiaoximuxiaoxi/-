#pragma once
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main() {
	int i = 100;
	int j = 2;
	for (i = 100; i <= 200; i++) {
		for (j = 2; j < i; j++) {
			if (i%j == 0)
				break;
		}
		if (j == i)
			printf("%6d\t", i);
	}
	system("pause");
	return 0;
}