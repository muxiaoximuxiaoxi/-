/*
���дһ�����������������Ӻ�����������n x m�����̸���
��nΪ����ĸ�������mΪ����ĸ����������Ÿ��Ա�Ե�ߴ����Ͻ�
�ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·������ֻ������
�������ߣ���������������ߡ�

�������� :
��������������



������� :
���ؽ��

ʾ��1
����
2
2
���
6
*/
//ͨ����100%
#include<iostream>
using namespace std;

int Countnum(int m, int n) {
	if (m == 0 || n == 0)
		return 1;
	else
		return Countnum(m - 1, n) + Countnum(m, n - 1);
}

int main() {
	int m, n;
	while (cin >> m >> n) {
		//�����Ϊѭ����
		cout << Countnum(m, n) << endl;
	}
	return 0;
}


//��������������ͬ�����ǹ�����
#include<iostream>
using namespace std;
/*˼·��
�õݹ������������½ǿ���ԭ��(0, 0)�����Ͻǿ�������(m, n)��
��ͼ��ʾ��

��(m, n)�� > (0, 0)�ͷ������ߣ�
������һ����f(m, n - 1)�� > (0, 0) 
��������һ����f(m - 1, n)�� > (0, 0)
ע�⣺�����Ǵ������߽磬Ҳ����˵f(x, 0)����f(0, x)��
ֻ��һ��ֱ·�����ˣ������x�Ǳ�������
f(m, n) = f(m, n - 1) + f(m - 1, n)
��������˼�룬�㷨�ͺܼ��ˣ�
*/
int Countnum(int m, int n) {
	if (m == 0 || n == 0)
		return 1;
	else
		return Countnum(m - 1, n) + Countnum(m, n - 1);
}

int main() {
	int m, n;
	cin >> m;
	cin >> n;
	int num = Countnum(m, n);
	cout << num;
	return 0;
}

/*����ӷ�
���дһ��������������������ӡ�����ʹ�� + �����������������

��������int A��B���뷵��A��B��ֵ

����������
1, 2
���أ�3
class UnusualAdd {
public:
	int addAB(int A, int B) {
		// write code here
		int a = 0, b = 0;
		while (B != 0) {
			a = A ^ B;
			b = (A&B) << 1;
			A = a;
			B = b;
		}
		return A;
	}
};

*/
