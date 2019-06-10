/*
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
输入描述 :
输入N个字符
输出描述 :
输出该字符串反转后的字符串
示例1
输入
abcd
输出
dcba
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		reverse(str.begin(), str.end());
		cout << str << endl;
	}
}
//#include<iostream>
//#include<string>
//
//using namespace std;
//
//int main() {
//	string str;
//	while (cin >> str) {
//		string::iterator it1 = str.begin();
//		string::iterator it2 = str.end();
//		while (it1 != it2) {
//			swap(it1, it2);
//			++it1;
//			--it2;
//		}
//		cout << str << endl;
//	}
//}
