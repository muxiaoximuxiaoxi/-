//#define _CRT_SECURE_NO_WARNINGS
//#include<stdlib.h>
//#include<stdio.h>
////дһ���������ز����������� 1 �ĸ���
////���磺 15 0000 1111 4 �� 1
////����ԭ�ͣ�
////int count_one_bits(unsigned int value)
////{
////	// ���� 1��λ�� 
////}
//
int count_one_bits(unsigned int value) {
	int count = 0;
	while (value) {
		if (value % 2 == 1) {
			++count;
		}
		value /= 2;
	}
	return count;
}
int main() {
	int x = 0;
	int ret = 0;
	printf("����������Ҫ�������Ϊ��������ʽ�� 1 �ĸ�����\n");
	scanf("%d", &x);
	ret = count_one_bits(x);
	printf("%d�ڶ�������ʽ�� 1 �ĸ���Ϊ%d��\n", x, ret);
	system("pause");
}
