#include<stdio.h>
//#include<stdlib.h>
int main() {
	int a[3] = { 10,20,-30 };
	int max = -32768;
	int i = 0;
	for (i = 0; i < 3; i++) {
		if (max < a[i]) {
			max = a[i];
		}
		else {
			max = max;
		}
	}
	printf("max=%d\n",max );
	//	system("pause");
}
