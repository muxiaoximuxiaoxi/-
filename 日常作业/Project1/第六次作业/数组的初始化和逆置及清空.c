#include<stdio.h>
#include<stdlib.h>
void Init(int a[],int n) {
	for (int i = 0; i < n; i++) {
		a[i] = i;
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void empty(int a[], int n) {
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		printf("%d\t", a[i]);
	}
	printf("\n");
}
void reverse(int a[], int n) {
	int low = 0;
	int high = n - 1;
	int temp = 0;
	for (int i = 0; i < n; i++){
	while(low < high) {
		temp = a[low];
		a[low] = a[high];
		a[high] = temp;
		low++;
		high--;
	}
		printf("%d\t", a[i]);
	}
	printf("\n");
}
int main() {
	int a[10];
	int n = 10;
	printf("��������г�ʼ��\n");
	Init(a, n);
	printf("\n");
	printf("��������\n");
	reverse(a, n);
	printf("\n");
	printf("�������\n");
	empty(a, n);
	printf("\n");
	system("pause");
}
