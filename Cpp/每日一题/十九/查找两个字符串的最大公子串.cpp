/*
���������ַ���a, b�е�������Ӵ�
���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ���
���Ǹ���
�������� :
���������ַ���
������� :
�����ظ����ֵ��ַ�
ʾ��1
����
abcdefghijklmnop
abcsafjklmnopqrstuvw
���
jklmnop
*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		if (str1.length() > str2.length())
			swap(str1, str2);//ʼ����strΪ�̴�
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
