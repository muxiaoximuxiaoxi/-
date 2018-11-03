#include<stdio.h>
#include<stdlib.h>
int main() {
	int i = 0,max=0;
	int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (i = 0; i < 10; i++){
		if (max < a[i]) {
			max = a[i];
		}
		else {
			max = max;
	}
		
	//system("pause");
}printf("max=%d", max);
} 
