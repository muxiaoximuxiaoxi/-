/*
乒乓球筐
nowcoder有两盒（A、B）乒乓球，有红双喜的、有亚力亚的……
现在他需要判别A盒是否包含了B盒中所有的种类，
并且每种球的数量不少于B盒中的数量，该怎么办呢？

输入描述:
输入有多组数据。
每组数据包含两个字符串A、B，代表A盒与B盒中的乒乓球，
每个乒乓球用一个大写字母表示，即相同类型的乒乓球为相同的大写字母。
字符串长度不大于10000。

输出描述:
每一组输入对应一行输出：如果B盒中所有球的类型在A中都有，
并且每种球的数量都不大于A，则输出“Yes”；否则输出“No”。
示例1
输入
ABCDFYE CDE
ABCDGEAS CDECDE
输出
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
