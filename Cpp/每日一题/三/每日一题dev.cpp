/*n�����г��ִ������ڵ��ڣ�n/2������
�������� :
ÿ������������� n���ո�ָ��n��������n������100��������һ���������ִ������ڵ���n / 2��


������� :
������ִ������ڵ���n / 2������
ʾ��1
����
3 9 3 2 5 6 7 3 2 3 3 3
���
3*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<math.h>

//ͨ����66.66% 
using namespace std;
int main() {
	string str;
	getline(cin, str);
	vector<int> v;
	v.resize(101);
	int n = 0;
	for (int i = 0;i < str.size();++i) {
		if ((str[i] != ' ') && (str[i] >= '0')) {
			v[n] = int (str[i] - '0');
			++n;
		}
	}                                                  
	int count = 1;
	int result = 0;
	for (int i = 0;i < n;++i) {
		for (int j = i+1;j < n;++j) {
			if (v[i] == v[j]) {
				++count;
				result = v[i];
			}
		}
		if (count >= (n / 2)) {
			cout << result;
		}
		count = 1;
	}
	system("pause");
}


/*
��һ��ͨ��
int main()
{
	string a;
	while (getline(cin, a))
	{
		int b[101] = { 0 };
		int j = 0;
		for (int i = a.length() - 1;i >= 0;)
		{
			int temp = 0;
			int count = -1;
			int flag = 0;
			while (a[i] != ' '&&i >= 0)
			{
				if (a[i] != '-')
				{
					count++;
					temp += (a[i] - 48)*pow(10, count);
				}
				else
					flag = 1;
				i--;
			}
			if (flag == 1)
				b[j] = temp * (-1);
			else
				b[j] = temp;
			j++;
			i--;
		}
		for (int i = 0;i < j;i++)
		{
			int count1 = 1, shuzi;
			for (int q = i + 1;q < j;q++)
			{
				if (b[i] == b[q])
				{
					count1++;
					shuzi = b[i];
				}
			}
			if (count1 >= j / 2)
				cout << shuzi << endl;
		}
	}
	return 0;
}
*/


/*
�ڶ��β�ͨ��
int main() {
	string str;
	getline(cin, str);
	vector<int> v;
	int n = 0;
	for (int i = 0;i < str.size();++i) {
		if ((str[i] != ' ') && (str[i] >= '0')) {
			v[n] = str[i];
			++n;
		}
	}
	int count = 0;
	int result = 0;
	for (int i = 0;i < str.size();++i) {
		if ((str[i] != ' ') && (str[i] >= '0')) {
			for (int j = 0;j < n;++j) {
				if (str[i] == v[j]) {
					++count;
					result = str[i];
				}
			}
		}
		if (count > (n / 2)) {
			cout << result;
		}
	}
}
*/
/*
��һ�β�ͨ��
int main() {
	int n = 0;
	cin >> n;
	if (n < 1) {
		return 0;
	}
	vector<int> v;
	for (int i = 0;i < n;++i) {
		cin >> v[i];
	}
	int temp = 0;
	int maxnum = 0;
	int maxtemp = 0;
	int i = 0;
	for (i = 0;i < n;++i) {
		for (int j = 0;j < n;++j) {
			if (v[i] == v[j])
				++temp;
		}
		if (temp > maxtemp) {
			maxnum = v[i];
			maxtemp = temp;
		}
		temp = 0;
	}
	cout << maxnum;
}*/







//��Ŀ����һ������һ���ַ���str������ַ���str�е�����������ִ�
//��������:
//�������������1������������һ���ַ���str�����Ȳ�����255��
//
//������� :
//��һ�������str��������������ִ���
//
//����
//abcd12345ed125ss123456789
//
//���
//123456789
/*
#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;
int main() {
	string str;
	getline(cin, str);
	string temp;
	string maxnumstr;
	int maxlength = 0;
	for (int i = 0;i < str.size();++i) {
		if ((str[i] <= '9') && (str[i] >= '0')) {
			while ((str[i] <= '9') && (str[i] >= '0')) {//Ŀ����
				//����һ�����������ַŵ�һ���µ��ַ�����
				temp += str[i++];
			}

			if (maxlength < temp.size()) {
				maxnumstr = temp;
				maxlength = temp.size();
			}
		}
		temp.clear();
	}
	cout << maxnumstr;
	system("pause");
}*/

