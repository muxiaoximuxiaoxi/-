#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main() {
	int str[100] = { 0,0,0,0,0,0, };
		int i = 0;
	for (i = 0; i < 3; i++) {
		printf("����������:\n");
		scanf("%s", str);
		if (strcmp(str, "123456") == 0) {
			break;
		}
	}
	if (i >= 3) {
		printf("������������Դ����Σ��˳�����\n");
	}
	else {
		printf("��¼�ɹ�������\n");
	}
	system("pause");
}
