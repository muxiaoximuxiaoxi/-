/*
��������
�������������������

xcopy / s c : \ d : \��

�����������£�

����1��������xcopy

����2���ַ��� / s

����3���ַ���c : \

	����4 : �ַ���d : \

	���дһ��������������ʵ�ֽ������и�����������������



	��������

	1.�����ָ���Ϊ�ո�
	2.�����á������������Ĳ���������м��пո񣬲��ܽ���Ϊ���������
	����������������xcopy / s ��C : \program files�� ��d : \��ʱ��
	������Ȼ��4������3������Ӧ�����ַ���C : \program files��
	������C : \program��ע���������ʱ����Ҫ������ȥ�������Ų�����Ƕ�������
	3.����������
	4.������������֤��������ֲ�����Ҫ�������

��������:
����һ���ַ����������пո�

������� :
��������������ֽ��Ĳ�����ÿ����������ռһ��

ʾ��1
����
xcopy / s c : \\ d:\\
���
4
xcopy
/ s
c : \\
	d:\\
*/ 
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

int main() {
	string str1, str2;
	int i = 0, j = 0;
	getline(cin, str1);
	vector<string> v;
	v.resize(10);
	str2 = "";
	for (i = 0;i <= str1.size();++i) {
		if (str1[i] != ' '&&str1[i]!='\0') {
			str2 += str1[i];
		}
		else {
			v[j] = str2;
			++j;
			str2 = "";
		}
	}
	cout << j << endl;
	for (int i = 0;i < j;++i) {
		cout << v[i] << endl;
	}
	system("pause");
}

