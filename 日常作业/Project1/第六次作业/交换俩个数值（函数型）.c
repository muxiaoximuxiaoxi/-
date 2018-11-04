#include<stdio.h>
#include<stdlib.h>
void ExchangeTwoNum(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
int main() {
	int x = 10;
	int y = 20;
	ExchangeTwoNum(&x,&y);
	printf("x=%d y=%d\n", x, y);
	system("pause");
}
