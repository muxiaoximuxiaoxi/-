/*����������
��C / C++ת��Java�ĳ���Ա��һ��ʼ�ϰ�ߵľ��Ǳ���������ʽ�ĸı䡣C���Է��ʹ���»��߷ָ�������ʣ����硰hello_world������Java�����һ�ֽ������������Ĺ��򣺳��׸��������⣬���е��ʵ�����ĸ��д�����硰helloWorld����
���������ĳ���Ա���Զ�ת����������
�������� :
��������������ݡ�
ÿ������һ�У�����һ��C���Է��ı�������ÿ�����������Ȳ�����100��
������� :
��Ӧÿһ�����ݣ������������Ӧ��������������
ʾ��1
����
hello_world
nice_to_meet_you
���
helloWorld
niceToMeetYou*/
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		for (int i = 0;i < s.size();++i)
		{
			if (s[i] == '_')
				//cout<<s[i];
				s[i + 1] -= 'a' - 'A';
			else
			{
				cout << s[i];
			}
		}
		cout << endl;
	}
	return 0;
}
