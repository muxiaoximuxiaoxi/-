/*
д��һ�����򣬽���һ���ַ�����Ȼ��������ַ�����ת����ַ��������磺
�������� :
����N���ַ�
������� :
������ַ�����ת����ַ���
ʾ��1
����
abcd
���
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
