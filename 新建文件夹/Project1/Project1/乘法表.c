#pragma once
#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 1;
	int j = 9;
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++)
			if (i >= j)
				printf("%d*%d=%d\t", i, j, i*j);
		printf("\n");
	}
	system("pause");
	return 0;
}