/*
�绰����
��ͼ��һ���绰�ľŹ�����������һ�����ֶ�ӦһЩ��ĸ������ڹ�����ҵϲ���ѵ绰������Ƴ����Լ���˾�������Ӧ�����繫˾��Help Desk������4357����Ϊ4��ӦH��3��ӦE��5��ӦL��7��ӦP�����4357����HELP��ͬ��TUT - GLOP�ʹ���888 - 4567��310 - GINO����310 - 4466��
NowCoder�ս������󣬲���ϰ��������������ʽ�����ڸ���һ���绰�����б��������ת����������ʽ�ĺ��룬��ȥ���ظ��Ĳ��֡�

�������� :
��������������ݡ�

ÿ�����ݵ�һ�а���һ��������n��1��n��1024����

������n�У�ÿ�а���һ���绰���룬�绰����������ַ��� - �������ֺʹ�д��ĸ��ɡ�
û���������ֵ����ַ��������ų����ַ��󳤶�ʼ��Ϊ7�������绰����ֻ��7λ����


������� :
��Ӧÿһ�����룬�����ֵ�˳��������ظ��ı�׼������ʽ�绰���룬����xxx - xxxx����ʽ��

ÿ���绰����ռһ�У�ÿ������֮�����һ��������Ϊ�������
ʾ��1
����
12
4873279
ITS - EASY
888 - 4567
3 - 10 - 10 - 10
888 - GLOP
TUT - GLOP
967 - 11 - 11
310 - GINO
F101010
888 - 1200
- 4 - 8 - 7 - 3 - 2 - 7 - 9 -
487 - 3279
4
UTT - HELP
TUT - GLOP
310 - GINO
000 - 1213
���
310 - 1010
310 - 4466
487 - 3279
888 - 1200
888 - 4567
967 - 1111

000 - 1213
310 - 4466
888 - 4357
888 - 4567*/
#include<iostream>
#include<string>
#include<set>

using namespace std;

int main()
{
	string num = "22233344455566677778889999";
	int n;//��������
	while (cin >> n)
	{
		string s;
		set<string> result;//����һ��set�����������Ϳ���ʹ��������
		int count = 0;
		for (int i = 0;i < n;++i)
		{
			cin >> s;
			count = 0;
			string temp = "";
			for (int j = 0;j < s.size();++j)
			{
				if ((s[j] >= 'A') && (s[j] <= 'Z'))
				{
					temp += num[s[j] - 'A'];
					++count;
					if (count == 3)
						temp += '-';
				}
				else if ((s[j] >= '0') && (s[j] <= '9'))
				{
					temp += s[j];
					++count;
					if (count == 3)
						temp += '-';
				}
			}
			result.insert(temp);
		}
		for (auto e : result)

			cout << e << endl;



		cout << endl;

	}
	return 0;
}

/* 
#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	string s;
	int length;
	string NUM = "22233344455566677778889999";
	while (cin >> length)
	{
		set<string> data;
		int cnt;
		while (cin >> s)
		{
			cnt = 0;
			string res;

			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] >= 'A'&&s[j] <= 'Z')
				{
					res += NUM[s[j] - 'A'];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
				else if (s[j] >= '0'&&s[j] <= '9')
				{
					res += s[j];
					cnt++;
					if (cnt == 3)
						res += "-";
				}
			}
			data.insert(res);
		}

		for (auto e : data)
			cout << e << endl;
		cout << endl;
	}
	return 0;
}
*/
