/*С�׵�����֮·
С�׾���������������Ϸ.��һ��, ������һ�������������Ϸ, 
���Ľ�ɫ�ĳ�ʼ����ֵΪ a.�ڽ�������һ��ʱ����, ��������������n������, 
ÿ������ķ�����Ϊb1, b2, b3...bn.��������Ĺ��������biС�ڵ���С��
�ĵ�ǰ����ֵc, ��ô���������ɴ�ܹ���, �� ��ʹ���Լ�������ֵ����bi;
���bi����c, ����Ҳ�ܴ�ܹ���, ����������ֵֻ������bi ��c�����Լ��.
��ô��������, ��һϵ�еĶ�����, С�׵���������ֵΪ���� ?
�������� :
	����ÿ������, ��һ������������n(1��n < 100000)��ʾ�����������a��ʾС�׵ĳ�ʼ����ֵ.
	�ڶ���n������, b1, b2...bn(1��bi��n)��ʾÿ������ķ�����
	������� :
����ÿ������, ���һ��.ÿ�н�����һ������, ��ʾС�׵���������ֵ
ʾ��1
����
����
3 50 50 105 200 5 20 30 20 15 40 100
���
����
110
205*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int Get(int m, int n)
{
	if (n == 0)
		return m;

	int temp = m % n;
	m = n;
	n = temp;
	return Get(m, n);
}
int main()
{
	int n, N;//n��ʾС�ָ���
	//N��ʾС�׵�ǰ����ֵ
	while (cin >> n >> N)
	{
		while (n > 0)
		{
			int count = 0;
			cin >> count;
			N = N + ((N < count) ? Get(count, N) : count);
			n--;
		}
		cout << N << endl;
	}
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int Get(int n, int m) {
//	int a = n;
//	int b = m;
//	if (a < b)
//		swap(a, b);
//	int maxnum = INT_MIN;
//	for (int i = a;i>1;--i) {
//		if (a%i == 0 && b%i == 0)
//			if (i > maxnum)
//				maxnum = i;
//	}
//	return maxnum;
//}
//
//int main() {
//	int n, N;
//	while (cin >> n >> N) {
//		vector<int> v(N);
//		for (int i = 0;i < n;++i)
//			cin >> v[i];
//		int count = N;
//		int m = 0;
//		for (int i = 0;i < n;++i) {
//			m = v[i];
//			if (count < m)
//				m = Get(count, m);
//			count += m;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//}
