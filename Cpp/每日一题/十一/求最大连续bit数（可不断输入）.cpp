/*���������bit�� 
����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�������������
����3�Ķ�����Ϊ00000011���������2��1  
����: һ��byte�͵�����   
���: ��    
����: ��Ӧ�Ķ�����������1�����������
��������:
����һ��byte����
�������:
���ת�ɶ�����֮������1�ĸ���
ʾ��1
����
3
���
2*/
#include<iostream>
#include<limits.h>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		int temp = 0;
		int max_count = INT_MIN;
		while (n > 0) {
			temp = n % 2;
			if (temp == 1)
				++count;
			if (count > max_count)
				max_count = count;
			if (temp == 0)
				count = 0;
			n /= 2;
		}
		cout << max_count << endl;
	}
}
