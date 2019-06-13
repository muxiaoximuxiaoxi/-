/*
找出字符串中第一个只出现一次的字符
输入描述:
输入一个非空字符串
输出描述 :
输出第一个只出现一次的字符，如果不存在输出 - 1
示例1
输入
asdfasdfo
输出
o*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str;
	while (cin >> str) {
		string s = "";
		unsigned int i = 0;
		for (i = 0;i < str.size();++i) {
			if (str.find(str[i]) == str.rfind(str[i])) {
				cout << str[i] << endl;
				break;
			}
		}
		if (i == str.size()) {
			int a = -1;
			cout << a << endl;
		}
	}
}
