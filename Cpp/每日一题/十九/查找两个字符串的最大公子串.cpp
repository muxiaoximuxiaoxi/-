/*
查找两个字符串a, b中的最长公共子串
查找两个字符串a, b中的最长公共子串。若有多个，输出在较短串中最先出现
的那个。
输入描述 :
输入两个字符串
输出描述 :
返回重复出现的字符
示例1
输入
abcdefghijklmnop
abcsafjklmnopqrstuvw
输出
jklmnop
*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1.length() > str2.length())
			swap(str1, str2);//始终让str为短串
		string result = "";
		for (int i = 0;i < str1.length();++i) {
			for (int j = i;j < str2.length();++j) {
				string temp = str1.substr(i, j - i + 1);
				if ((int)str2.find(temp) < 0)
					break;
				else {
					if (temp.length() > result.length())
						result = temp;
				}
			}
		}
		cout << result << endl;
	}
}
