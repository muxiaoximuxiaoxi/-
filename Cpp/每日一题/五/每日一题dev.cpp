/*
ͳ�ƻ���

�����Ĵ�����һ�������ͷ�����һ�����ַ���������
��level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������
ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A
���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ
�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ����
�����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����
λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
���磺
A = ��aba����B = ��b����������4�ְ�B����A�İ취��
* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
* ����ĸ��b��֮�� : "abba" �ǻ���
* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
�������������Ĵ�Ϊ2

�������� :
ÿ���������ݹ����С�
��һ��Ϊ�ַ���A
�ڶ���Ϊ�ַ���B
�ַ������Ⱦ�С��100��ֻ����Сд��ĸ


������� :
���һ�����֣���ʾ���ַ���B�����ַ���A֮�󹹳�һ�����Ĵ��ķ�����
ʾ��1
����
aba
b
���
2
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

bool IsTrue(string s) {
	for (int i = 0;i < (s.size() / 2);++i) {
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}
	return true;
}
int main() {
	string A, B;
		getline(cin, A);
		getline(cin, B);
		int count = 0;
		int c = 0;
		for (int now = 0;now <= A.size();++now) {
			//��now==0ʱ��B����Aǰ
			//��now==A.size()ʱ��B����A��
			string str = "";
			for (int i = 0;i < now;++i) {
				str += A[i];
			}
			for (int i = 0;i < B.size();++i) {
				str += B[i];
			}
			for (int i = now;i < A.size();++i) {
				str += A[i];
			}
			if (IsTrue(str)) {
				++count;
			}
		}
			
	cout <<count<<endl;
	system("pause");
}
*/




/*
��������

һ�������� N ��Ԫ�أ�����������������͡� ���磺[-1, 2, 1]������������������Ϊ[2, 1]�����Ϊ 3

�������� :
	����Ϊ���С� ��һ��һ������n(1 <= n <= 100000)����ʾһ����n��Ԫ�� �ڶ���Ϊn��������ÿ��Ԫ��, ÿ����������32λint��Χ�ڡ��Կո�ָ���


	������� :
���������������к�����ֵ��
ʾ��1
����
3 
- 1 2 1
���
3
����Ҫ���������
#include <iostream>
#include <limits.h>
using namespace std;
int main()
{
	int num = 0;
	cin >> num;
	int curMax = 0;
	int max = INT_MIN;
	for(int i = 0; i < num; i++)
	{
		int temp = 0;
		cin >> temp;
		curMax += temp;
		if(curMax > max)
		{
			max = curMax;
		}
		if(curMax < 0)
		{
			curMax = 0;
		}
	}
	cout << max << endl;
}


��Ҫ���������
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<limits.h>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0;i < n;++i) {
		cin >> v[i];
	}
	int sum = 0;
	int maxnum = INT_MIN;
	for (int j = 0;j < n;++j) {
		sum += v[j];
		if (sum > maxnum) {
			maxnum = sum;
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	cout << maxnum;
	system("pause");
}
*/
