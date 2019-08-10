// write your code here cpp
/*
养兔子
一只成熟的兔子每天能产下一胎兔子。每只小兔子的成熟期是一天。 某人领养了一只小兔子，请问第N天以后，他将会得到多少只兔子。

输入描述:
测试数据包括多组，每组一行，为整数n(1≤n≤90)。


输出描述:
对应输出第n天有几只兔子(假设没有兔子死亡现象)。
示例1
输入
1
2
输出
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
