/*�����ִ�����
��Ŀ���⣺
���������ַ�������󹫹��ִ��ĳ��ȣ��ַ������ִ�Сд
��ϸ������
�ӿ�˵��
ԭ�ͣ�
int getCommonStrLength(char * pFirstStr, char * pSecondStr);
���������
char * pFirstStr //��һ���ַ���
char * pSecondStr//�ڶ����ַ���
�������� :
���������ַ���
������� :
���һ������
ʾ��1
����
asdfas werasdfaswer
���
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
