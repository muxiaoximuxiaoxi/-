#include<stdio.h>
#include<stdlib.h>
int main() {
	int n = 15;
	if (n % 3 == 0 && n % 5 == 0) {
		printf("%d能被3和5整除\n",n);
	}
	else {
		printf("%d不能被3和5整除\n",n); 
	}
	system("pause");
}
