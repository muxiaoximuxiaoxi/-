/*���м������ʵ���
���ַ����е����е��ʽ��е��š�
˵����
1��ÿ����������26����д��СдӢ����ĸ���ɣ�
2���ǹ��ɵ��ʵ��ַ�����Ϊ���ʼ������
3��Ҫ���ź�ĵ��ʼ������һ���ո��ʾ�����ԭ�ַ�������
�ڵ��ʼ��ж�������ʱ������ת����Ҳֻ�������һ���ո�������
4��ÿ�������20����ĸ��
�������� :
����һ���Կո����ָ��ľ���
������� :
������ӵ�����
ʾ��1
����
I am a student
���
student a am I*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string s;
	while (getline(cin, s)) 
	{
		vector<string> v;
		string temp = "";
		for (int i = 0;i < s.size();++i)
		{
			if (((s[i] >= 'a') && (s[i] <= 'z'))
				|| ((s[i] >= 'A') && (s[i] <= 'Z')))
				temp += s[i];
			else
			{
				if (temp.size() > 0)
					v.push_back(temp);
				temp = "";
			}
		}
		if (temp.size() > 0)
			v.push_back(temp);

		for (int i = v.size() - 1;i > 0;i--)

			cout << v[i] << " ";

		cout << v[0] << endl;
	}
	return 0;
}

