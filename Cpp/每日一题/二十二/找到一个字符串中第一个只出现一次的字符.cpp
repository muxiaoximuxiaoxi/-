/*
�ҳ��ַ����е�һ��ֻ����һ�ε��ַ�
��������:
����һ���ǿ��ַ���
������� :
�����һ��ֻ����һ�ε��ַ��������������� - 1
ʾ��1
����
asdfasdfo
���
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
