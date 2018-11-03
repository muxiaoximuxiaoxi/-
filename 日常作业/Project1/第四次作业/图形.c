#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
	int i = 1;
	for ( i = 1; i <= 7; i++){
		for (int j = 7; j >i; j--) {
			printf(" ");
		}
		for (int k = 1; k < 2*i; k++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= 7; i++) {
		for (int j = 1; j <=i; j++) {
			printf(" ");
		}
		for (int k = 13; k >(2*i); k--) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}
