
/*Fibonacci����
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i - 1] + F[i - 2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N������
�����Ϊһ��Fibonacci����ÿһ������԰ѵ�ǰ����X��ΪX - 1
����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����

�������� :
����Ϊһ��������N(1 �� N �� 1, 000, 000)

������� :
	���һ����С�Ĳ�����ΪFibonacci��"
	ʾ��1
	����
	15
	���
	2
#include<iostream>
#include<math.h>
using namespace std;
int main() {
	int N, f0 = 0, f1 = 1, f = 0;
	cin >> N;
	while (N > f) {
		f = f0 + f1;
		f0 = f1;
		f1 = f;
	}
	\\��N==15ʱ������ѭ��ʱ��f=25,f0=13,f1=25;
	cout << min(f - N, N - f0);
}
*/
/*�Ϸ����������ж�
����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ����
�������Ŵ���
����������
"(()())", 6
���أ�true
����������
"()a()()", 7
���أ�false
����������
"()(()()", 7
���أ�false

class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here

		int count = 0;
		for (int i = 0;i < n;++i) {
			if (A[i] == '(') {
				count += 1;
			}
			if (A[i] == ')') {
				count -= 1;
			}
		}
		if (count == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};
*/
