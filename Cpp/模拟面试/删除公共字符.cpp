/* 
ɾ�������ַ�
���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����ɡ�Thy r stdnts.��

��������:
ÿ�������������2���ַ���


�������:
���ɾ������ַ���
ʾ��1
����
They are students. 
aeiou
���
Thy r stdnts.*/
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,str;
    getline(cin,s);
    getline(cin,str);
    string::iterator it=str.begin();
    while(it!=str.end())
    {
        for(size_t i=0;i<s.size();++i)
        {
            if(s[i]==*it)
                s.erase(i,1);
        }
        ++it;
    }
    cout<<s<<endl;
    return 0;
}
