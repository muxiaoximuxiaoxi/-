
/*
�������bit��
���� : ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1

	���� : һ��byte�͵�����

	��� : ��

	���� : ��Ӧ�Ķ�����������1�����������

	�������� :
����һ��byte����



������� :
���ת�ɶ�����֮������1�ĸ���

ʾ��1
����
3
���
2
*/ 
#include<iostream>
#include<limits.h>
#include<stdlib.h>
using namespace std;

#define N 32
int main() {
	int n;
	cin >> n;
	int m = n;
	int temp = 0;
	int maxnum = INT_MIN;
	int count = 0;
	for (int i = 0;i < 32;++i) {
		temp = m % 2;
		if (temp == 1) {
			++count;
		}
		else {
			if (count > maxnum) {
				maxnum = count;
				count = 0;
			}
		}
		m = m / 2;
	}
	cout << maxnum;
	system("pause");
}

