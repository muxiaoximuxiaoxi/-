/*
��������������������1�ĸ���
��ʵ�����½ӿ�
public   static   int  findNumberOf1(int num)

{
	//  ��ʵ��  

	return  0;

} Ʃ�磺����5 ��5�Ķ�����Ϊ101�����2
�漰֪ʶ�㣺
�������� :
����һ������
������� :
����������������1�ĸ���
ʾ��1
����
5
���
2
*/
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int count = 0;
		int m = 0;
		while (n != 0) {
			m = n % 2;
			n /= 2;
			if (m == 1) {
				++count;
			}
		}
		cout << count << endl;
	}
}
