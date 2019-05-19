//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//#include<algorithm>
//牛牛举办了一次编程比赛, 参加比赛的有3*n个选手, 每个选手都有一个水平值a_i.
////现在要将这些选手进行组队, 一共组成n个队伍, 即每个队伍3人.
////牛牛发现队伍的水平值等于该队伍队员中第二高水平值。
//using namespace std;
//int main() {
//	int n = 0;
//	cin >> n;
//	int sum = 0;
//	vector<int> v(n * 3);
//	for (int i = 0;i < n * 3;++i) {
//		cin >> v[i];
//	}
//	sort(v.begin(), v.end());
//	for (int i = n;i <= (n * 3) - 2;i += 2) {
//		sum += v[i];
//	}
//	cout << sum << endl;
//	system("pause");
//	return 0;
//}

//输入两个字符串，从第一字符串中删除第二个字符串中所有的字符。
//例如，输入”They are students.”和”aeiou”，
//则删除之后的第一个字符串变成”Thy r stdnts.”
#include<iostream>
#include<stdlib.h>
#include<string>
#include<vector>
using namespace std;
int main() {
	string str1, str2;
	getline(cin, str1);
	getline(cin, str2);
	string::iterator it = str2.begin();
	while (it != str2.end()) {
		for (int i = 0;i < str1.size();++i) {
			if (str1[i] == *it) {
				str1.erase(i, 1);
			}
		}
		++it;
	}
	cout << str1 << endl;
	system("pause");
}












//int main() {
//	string str1, str2;
//	getline(cin, str1);
//	getline(cin, str2);
//	string::iterator it = str2.begin();
//	while (it != str2.end())
//	{
//		for (int i = 0; i < str1.size(); i++)
//		{
//			if (str1[i] == *it)
//			{
//				str1.erase(i, 1);
//			}
//		}
//		it++;
//	}
//	cout << str1 << endl;
//	system("pause");
//}

