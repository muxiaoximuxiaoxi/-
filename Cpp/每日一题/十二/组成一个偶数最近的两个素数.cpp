/*
查找组成一个偶数最接近的两个素数
任意一个偶数（大于2）都可以由2个素数组成，
组成偶数的2个素数有很多种情况，本题目要求输出组
成指定偶数的两个素数差值最小的素数对
输入描述:
输入一个偶数
输出描述:
输出两个素数
示例1
输入
20
输出
7
13*/
#include<list>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
//思路很简单，若想求和为n，从最接近n/2的中间朝两边找即可。
class SSVec
{
public:
    SSVec() : ss() {
        ss.push_back(1);
        ss.push_back(2);
        ss.push_back(3);
    }
     
    void adjust(int n) {
    if (n < ss.back())
        return;
 
    auto b = ss.back();
    for (int i = b + 1; i <= n; ++i) {
        bool flag = true;
        for (int j = 2; j*j <= i; ++j) {
            if (!(i%j)) {
                flag = false;
                break;
            }
        }
        if (flag)
            ss.push_back(i);
        }
    }
     
    pair<int, int> findSSPair(int n) {
        auto i = find_if(ss.begin(), ss.end(), [&n](const int &i)->bool { return n / 2 <= i; });
        auto left = i, right = i;
        while (true) {
            if (*left + *right == n) return make_pair(*left, *right);
            if (*left + *right > n) --left;
            if (*left + *right < n) ++right;
        }
    }
 
private:
    list<int> ss;
};
 
int main(int argc, char **argv) {
    int n;
    SSVec s;
    while (cin >> n) {
        s.adjust(n);
        auto p = s.findSSPair(n);
        cout << p.first << endl;
        cout << p.second << endl;
    }
 
    return 0;
}
