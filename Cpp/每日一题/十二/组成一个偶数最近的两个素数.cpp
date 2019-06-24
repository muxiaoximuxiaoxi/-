/*
�������һ��ż����ӽ�����������
����һ��ż��������2����������2��������ɣ�
���ż����2�������кܶ������������ĿҪ�������
��ָ��ż��������������ֵ��С��������
��������:
����һ��ż��
�������:
�����������
ʾ��1
����
20
���
7
13*/
#include<list>
#include<iostream>
#include<algorithm>
#include<utility>
using namespace std;
//˼·�ܼ򵥣��������Ϊn������ӽ�n/2���м䳯�����Ҽ��ɡ�
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
