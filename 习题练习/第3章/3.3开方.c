#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//�Ӽ�������һ��С��1000��������
//Ҫ����������ƽ��������ƽ�����������������������������֡�
int main() {
	int n = 0, m = 0;
	scanf("%d", &n);
	while (n <= 0 && n >= 1000) {
		printf("�����������������룡\n");
		scanf("%d", &n);
	}
	m = sqrt(n);
	printf("%d\n", m);
	system("pause");
}
