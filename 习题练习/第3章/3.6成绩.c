#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A'����B����
//��C'����D������E'��90������Ϊ��A'��80~89��Ϊ��B����
//70~79��Ϊ��C����60~69��Ϊ��D'��60������Ϊ��E��
int main() {
	int n = 0;
	printf("������ɼ�\n");
	scanf("%d", &n);
	while (n < 0 || n>100) {
		printf("�����������������룡\n");
		scanf("%d", &n);
	}
	printf("����ĳɼ�Ϊ%d\n", n);
	switch(n / 10) {
		case 9:
			printf("�ɼ�ΪA\n");
			break;
		case 8:
			printf("�ɼ�ΪB\n");
			break;
		case 7:
			printf("�ɼ�ΪC\n");
			break;
		case 6:
			printf("�ɼ�ΪD\n");
			break;
		default:
			printf("�ɼ�ΪE\n");
			break;
	}
	system("pause");
}
