// write your code here cpp
/*
������
һֻ���������ÿ���ܲ���һ̥���ӡ�ÿֻС���ӵĳ�������һ�졣 ĳ��������һֻС���ӣ����ʵ�N���Ժ�������õ�����ֻ���ӡ�

��������:
�������ݰ������飬ÿ��һ�У�Ϊ����n(1��n��90)��


�������:
��Ӧ�����n���м�ֻ����(����û��������������)��
ʾ��1
����
1
2
���
1
2*/
#include<vector>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<long long> v;
        //if(n)
            v.push_back(1);
        long long m1=1;
        long long m2=0;
        long long m=0;
        for(int i=2;i<=n;++i)
        {
            m=m1+m2;
            m1=m2;
            m2=m;
            v.push_back(m);
        }
        long long count=0;
        for(auto e:v)
            count+=e;
        cout<<count<<endl;
    }
    return 0;
}
