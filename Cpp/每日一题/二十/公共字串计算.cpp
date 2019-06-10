/*公共字串计算
题目标题：
计算两个字符串的最大公共字串的长度，字符不区分大小写
详细描述：
接口说明
原型：
int getCommonStrLength(char * pFirstStr, char * pSecondStr);
输入参数：
char * pFirstStr //第一个字符串
char * pSecondStr//第二个字符串
输入描述 :
输入两个字符串
输出描述 :
输出一个整数
示例1
输入
asdfas werasdfaswer
输出
6*/
#include<iostream>
#include<string>

using namespace std;

int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1.size() > str2.size())
			swap(str1, str2);
		string result = "";
		for (int i = 0;i < str1.size();++i) {
			for (int j = i;j < str2.size();++j) {
				string temp = str1.substr(i, j - i + 1);
				if ((int)str2.find(temp) < 0)
					break;
				else {
					if (temp.size() > result.size())
						result = temp;
				}
			}
		}
		int n = result.size();
		cout << n << endl;
	}
}
