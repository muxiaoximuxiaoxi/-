//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С�
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int i = 0,n = 0;
	int a[30] = { 0 };
	printf("����������ת��������\n");
	scanf("%d", &n);
	while (n) {
		a[i] = n % 2;
		i += 1;
		n /= 2;
	}
	for (;i >= 0;i--) {
		if (i % 2 == 0) {//��Ϊ�����Ǵ�0��ʼ�����ģ���a[0]ӦΪ����λ a[1]Ϊż��λ
			printf("����λ:%d",a[i]);
		}
		else {
			printf("ż��λ:%d", a[i]);
		}
		printf("\n");
	}
	printf("�ɸ�λ���λ\n");
	system("pause");
}
