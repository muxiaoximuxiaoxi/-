/*ͳ��ÿ�������ӵ�����
��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�
С���ӳ����������º�ÿ��������һֻ���ӣ��������Ӷ�������
��ÿ���µ���������Ϊ���٣�
/**
 * ͳ�Ƴ�����������
 *
 * @param monthCount �ڼ�����
 * @return ��������
 */
//	public static int getTotalCount(int monthCount)
//{
//	return 0;
//}
//��������:
//����int�ͱ�ʾmonth
//������� :
//�����������int��
//ʾ��1
//����
//9
//���
//34

#include<iostream>
#include<stdlib.h>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		if (n == 1 || n == 2)
			cout << 1;
		int f1 = 1;
		int f2 = 1;
		int f = 0;
		for (int i = 2;i < n;++i) {
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
		cout << f;
	}
	system("pasue");
}
