#include<stdio.h>
#include<stdlib.h>
int main() {
	int n = 15;
	if (n % 3 == 0 && n % 5 == 0) {
		printf("%d�ܱ�3��5����\n",n);
	}
	else {
		printf("%d���ܱ�3��5����\n",n); 
	}
	system("pause");
}
