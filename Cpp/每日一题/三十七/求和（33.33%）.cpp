/*
���
������������ n �� m��������1��2��3.......n ������ȡ������, 
ʹ��͵��� m, Ҫ���������еĿ�������г���
�������� :
ÿ�������������2������, n��m
������� :
��ÿ����ϵ��ֵ����������, ÿ�����һ�����
ʾ��1
����
5 5
���
1 4
2 3
5*/
//ͨ��33.33%
//����һ��ȡ�ɵ�������������ʹ��
#include<iostream>
#include<stdlib.h>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		for (int i = 1;i < (n + 1) / 2;++i) {
			for (int j = 1;j < n;++j) {
				if (i + j == m)
					cout << i << " " << j << endl;
			}
		}
		cout << m << endl;
	}
	system("pause");
	return 0;
}
