#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//��һ����������Ҫ��
//��������Ǽ�λ����
//�ڷֱ����ÿһλ���֣�
//�۰����������λ���֣�����ԭ��Ϊ321��Ӧ���123.
int CountDigitPlace(int n) {
	int count = 1;
	int m = n;
	while (m > 9) {
		m = m / 10;
		++count;
	}
	return count;
}
void ReseverPrint(int n) {
	while (n > 9) {
		printf("%d ", n % 10);
		n /= 10;
	}
	printf("%d\n", n);
}
int Print(int n) {
	if (n > 9) {
		Print(n / 10);
	}
	printf("%d ", n % 10);
}
int main() {
	int n = 0;
	int count = 0;
	printf("����һ����\n");
	scanf("%d", &n);
	count = CountDigitPlace(n);
	printf("����%dλ��\n",count);
	printf("˳�����Ϊ��\n");
	Print(n);
	printf("\n");
	printf("�������Ϊ��\n");
	ReseverPrint(n);
	system("pause");
}
