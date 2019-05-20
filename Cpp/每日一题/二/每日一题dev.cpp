/*
题目：牛牛定义排序子序列为一个数组中一段连续的子序列, 并且这段
子序列是非递增或者非递减排序的。牛牛有一个长度为n的整数数组A, 
他现在有一个任务是把数组A分为若干段排序子序列, 牛牛想知道他
最少可以把这个数组分为几段排序子序列。
如样例所示, 牛牛可以把数组a划分为[1, 2, 3]和[2, 2, 1]两个排序子序列,
至少需要划分为2个排序子序列, 所以输出
2
输入描述：
输入的第一行为一个正整数n(1 ≤ n ≤ 10 ^ 5)
第二行包括n个整数a_i(1 ≤ a_i ≤ 10 ^ 9), 表示数组a的每个数字。
输出描述：
输出一个整数表示牛牛可以将a最少划分为多少段排序子序列
示例1 :
输入
6
1 2 3 2 2 1
输出
2*/



#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
using namespace std;

//通过率100%
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

//通过率10%
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











//将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数
//后变为：beijing. like I
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

