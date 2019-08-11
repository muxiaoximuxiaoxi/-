/*
有假币
居然有假币！ 现在猪肉涨了，但是农民的工资却不见涨啊，没钱怎么买猪肉啊。nowcoder这就去买猪肉，结果找来的零钱中有假币！！！可惜nowcoder 一不小心把它混进了一堆真币里面去了。只知道假币的重量比真币的质量要轻，给你一个天平（天平两端能容纳无限个硬币），请用最快的时间把那个可恶的假币找出来。

输入描述:
1≤n≤2^30,输入0结束程序。


输出描述:
最多要称几次一定能把那个假币找出来？
示例1
输入
3
12
0
输出
1
3*/
// write your code here cpp
#include<iostream>

using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0)
            break;
        int count=0;
        while(n>=2)
            //当n==1时不会进入循环
        {
            if(n%3)
                //不可以整除取最坏的结果，取(n/3+1)个金币
                n=n/3+1;
            else
                //可以整除直接取(n/3)个金币
                n/=3;
            ++count;
        }
        cout<<count<<endl;
    }
    return 0;
}
