/*�����Ʋ���
������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶ�
��j����iλ,���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
����������int n��int m��
ͬʱ����int j��int i�����������������뷵�ز����������
��֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1��

����������
1024��19��2��6
���أ�1100
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		m <<= j;
		return n | m;
	}
};
*/
/*
�������һ��ż���������������
����һ��ż��������2����������2��������ɣ�
���ż����2�������кܶ������������ĿҪ��
������ָ��ż��������������ֵ��С��������
�������� :
����һ��ż��

������� :
�����������

ʾ��1
����
20
���
7
13
*/ 
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

bool isPrime(int i)
{
	for (int j = 2; j <= sqrt(i * 1.0); j++) {
		if (i % j == 0)
			return false;
	}
	return true;
}

int main() {
	int n;
	int Prime1, Prime2;
	while (cin >> n) {
		if (n < 2)
			return 1;
		else {
			for (int i = 1; i <= n / 2;i++) {
				if (isPrime(i) && isPrime(n - i)) {
					Prime1 = i;
					Prime2 = n - i;
				}
			}
			cout << Prime1 << endl;
			cout << Prime2 << endl;
		}
	}
	return 0;
}

