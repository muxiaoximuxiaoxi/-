/*n个数中出现次数大于等于（n/2）的数
输入描述 :
每个测试输入包含 n个空格分割的n个整数，n不超过100，其中有一个整数出现次数大于等于n / 2。


输出描述 :
输出出现次数大于等于n / 2的数。
示例1
输入
3 9 3 2 5 6 7 3 2 3 3 3
输出
3*/
#include<iostream>
#include<string>
#include<stdlib.h>
#include<vector>
#include<math.h>

//通过率66.66% 
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
第一次通过
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
第二次不通过
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
第一次不通过
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







//题目描述一：读入一个字符串str，输出字符串str中的连续最长的数字串
//输入描述:
//个测试输入包含1个测试用例，一个字符串str，长度不超过255。
//
//输出描述 :
//在一行内输出str中里连续最长的数字串。
//
//输入
//abcd12345ed125ss123456789
//
//输出
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
			while ((str[i] <= '9') && (str[i] >= '0')) {//目的是
				//把者一段连续的数字放到一个新的字符串中
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

