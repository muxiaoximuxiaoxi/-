/*
��Ŀ��ţţ��������������Ϊһ��������һ��������������, �������
�������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, 
��������һ�������ǰ�����A��Ϊ���ɶ�����������, ţţ��֪����
���ٿ��԰���������Ϊ�������������С�
��������ʾ, ţţ���԰�����a����Ϊ[1, 2, 3]��[2, 2, 1]��������������,
������Ҫ����Ϊ2������������, �������
2
����������
����ĵ�һ��Ϊһ��������n(1 �� n �� 10 ^ 5)
�ڶ��а���n������a_i(1 �� a_i �� 10 ^ 9), ��ʾ����a��ÿ�����֡�
���������
���һ��������ʾţţ���Խ�a���ٻ���Ϊ���ٶ�����������
ʾ��1 :
����
6
1 2 3 2 2 1
���
2*/



#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
using namespace std;

//ͨ����100%
int main() {
	int n;
	while (cin >> n) {
		vector<int> v(n);
		for (int i = 0;i < n;i++) {
			cin >> v[i];
		}
		int i = 0;
		int res = 0;
		while (i < n - 1) {
			while (i < n - 1 && v[i] == v[i + 1])
				i++;
			if (i<n - 1 && v[i]>v[i + 1]) {
				res++;
				while (i < n - 1 && v[i] >= v[i + 1])
					i++;
				i++;
			}
			else if (i < n - 1 && v[i] < v[i + 1]) {
				res++;
				while (i < n - 1 && v[i] <= v[i + 1])
					i++;
				i++;
			}
		}
		if (i == n - 1)
			cout << res + 1 << endl;
		else
			cout << res << endl;
	}
	return 0;
}

//ͨ����10%
/*
int main() {
	int n = 0;
	cin >> n;
	vector<int> v;
	v.resize(n);
	for (int i = 0;i < n;++i) {
		cin >> v[i];
	}
	int result = 0;
	for (int i = 1;i < n - 1;++i) {
		if (((v[i - 1] <= v[i]) && (v[i] >= v[i + 1]))
			|| ((v[i - 1] >= v[i]) && (v[i] <= v[i + 1]))) {
			++result;
		}
		if (i != n %2==0) {
			++i;
		}
	}
	
	cout << result << endl;
	system("pause");
    
}*/











//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. ��������
//���Ϊ��beijing. like I
//#include<stdlib.h>
//#include <iostream>
//#include <stack>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main() {
//	string str1;
//	stack<string> s;
//	while (cin >> str1) {
//		s.push(str1);
//		string str2 = str1;
//		if (*(str2.rbegin()) == '.') {
//			break;
//		}
//	}
//	cout << s.top();
//	s.pop();
//	while (!s.empty()) {
//		cout << ' ' << s.top();
//
//		s.pop();
//	}
//	system("pause");
//	return 0;
//}

