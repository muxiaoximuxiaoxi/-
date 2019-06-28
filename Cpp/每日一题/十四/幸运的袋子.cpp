/*幸运的袋子 
一个袋子里面有n个球，每个球上面都有一个号码(拥有相同号码的球是无区
别的)。如果一个袋子是幸运的当且仅当所有球的号码的和大于所有球的号码
的积。
例如：如果袋子里面的球的号码是{1, 1, 2, 3}，这个袋子就是幸运的，
因为1 + 1 + 2 + 3 > 1 * 1 * 2 * 3
你可以适当从袋子里移除一些球(可以移除0个,但是别移除完)，
要使移除后的袋子是幸运的。现在让你编程计算一下你可以获得的多少
种不同的幸运的袋子。
输入描述:
第一行输入一个正整数n(n ≤ 1000)
第二行为n个数正整数xi(xi ≤ 1000)
输出描述:
输出可以产生的幸运的袋子数
示例1
输入
3
1 1 1
输出
2*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int cont = 0;
void ContOne(int, vector<int>, int, int, int); //（1的个数，非1数，当前位数, 和, 积）
int main(void)
{
    int n, numb, OneCont(0);        //OneCont用来记录1的总个数
    vector<int> list;
    cin >> n;
    while (n--)
    {
        cin >> numb;
        if (numb > 1)
            list.push_back(numb);
        else
            OneCont++;
    }
    cont = OneCont - 1; //将纯1数组先计算出来
    if (!list.empty())
    {
        sort(list.begin(), list.end()); //对数组排序
        for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
    }
    cout << cont << endl;
    return 0;
}
void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
{
    for (int i = nowBit; i < list.size(); i++) //迭代计算和与积
    {
        sum += list[i], mult *= list[i];
        if (sum <= mult) //如果不符合，回溯至上一位
            break;
        else
            cont++;
        ContOne(OneNub, list, i + 1, sum, mult);
        sum -= list[i], mult /= list[i]; //回到上一位后需要恢复数值
        while (i < list.size() - 1 && list[i] == list[i + 1])
            i++;  //寻找不重复
    }
}
