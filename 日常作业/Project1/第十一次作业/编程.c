//���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ��
//�������� :
//1999 2299
//������� : 7
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int m = 0, n = 0, q = 0, count = 0;
	printf("���������������֣�");
	scanf("%d %d", &m, &n);
	q = m ^ n;
	while (q) {
		if (q % 2 == 1) {
			++count;
		}
		q /= 2;
	}
	printf("%d��%d��ת���ɶ�������֮��ͬ���ĸ���Ϊ%d\n", m, n, count);
	system("pause");
}
