#include<stdio.h>
#include<stdlib.h>
int main() {
	int str[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int max = -32768;
	for (int i = 0; i < 10; i++) {
		if (str[i] > max) {
			max = str[i];
		}
		else {
			max = max;
		}
	}
	printf("max=%d\n", max);
	system("pause");
}
