#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//�����ҹ�����������ֵ����������Ϊ9%�����дһ���������10����ҹ�����������ֵ����������������ٰٷֱȣ�

//ע�ͣ�����㹫ʽΪ

//p = (1 + r)n
//������rΪ�������ʣ�nΪ������pΪ��������ȵı�����
int main() {
	double p = 0, r = 0.09;
	int n = 10;
	p = pow(1 + r, n);
	printf("%f\n", p);
	system("pause");
}
