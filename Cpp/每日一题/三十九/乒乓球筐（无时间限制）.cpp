/*
ƹ�����
nowcoder�����У�A��B��ƹ�����к�˫ϲ�ġ��������ǵġ���
��������Ҫ�б�A���Ƿ������B�������е����࣬
����ÿ���������������B���е�����������ô���أ�

��������:
�����ж������ݡ�
ÿ�����ݰ��������ַ���A��B������A����B���е�ƹ����
ÿ��ƹ������һ����д��ĸ��ʾ������ͬ���͵�ƹ����Ϊ��ͬ�Ĵ�д��ĸ��
�ַ������Ȳ�����10000��

�������:
ÿһ�������Ӧһ����������B�����������������A�ж��У�
����ÿ�����������������A���������Yes�������������No����
ʾ��1
����
ABCDFYE CDE
ABCDGEAS CDECDE
���
Yes
No*/
// write your code here cpp
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        int count=0;
        for(int i=0;i<s2.size();++i)
        {
            for(int j=0;j<s1.size();++j)
            {
                if(s2[i]==s1[j])
                {
                    ++count;
                    s1[j]='a';
                    s2[i]='b';
                }
                    
            }
        }
        if(count==s2.size())
            cout<<"Yes"<<endl;
        else 
            cout<<"No"<<endl;
    }
    return 0;
}
