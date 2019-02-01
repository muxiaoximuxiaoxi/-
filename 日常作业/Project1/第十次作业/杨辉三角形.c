#include<stdio.h>
#include<stdlib.h>
#define NUM 10
int main() {
	int arr[NUM][NUM] = { 0 };
	int i = 0, j = 0;
	for (i = 0;i < NUM;i++) {
		arr[i][0] = 1;
		for (j = 0;j <= i;j++) {
			if (j == i) {
				arr[i][j] = 1;
			}
			else if (j > 0 && j < i) {
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
		}
	}
	for (i = 0;i < NUM;i++) {
		for (j = 0;j <= i;j++) {
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	system("pause");
}
