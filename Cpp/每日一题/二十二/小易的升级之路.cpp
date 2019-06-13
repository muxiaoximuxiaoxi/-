/*小易的升级之路
小易经常沉迷于网络游戏.有一次, 他在玩一个打怪升级的游戏, 
他的角色的初始能力值为 a.在接下来的一段时间内, 他将会依次遇见n个怪物, 
每个怪物的防御力为b1, b2, b3...bn.如果遇到的怪物防御力bi小于等于小易
的当前能力值c, 那么他就能轻松打败怪物, 并 且使得自己的能力值增加bi;
如果bi大于c, 那他也能打败怪物, 但他的能力值只能增加bi 与c的最大公约数.
那么问题来了, 在一系列的锻炼后, 小易的最终能力值为多少 ?
输入描述 :
	对于每组数据, 第一行是两个整数n(1≤n < 100000)表示怪物的数量和a表示小易的初始能力值.
	第二行n个整数, b1, b2...bn(1≤bi≤n)表示每个怪物的防御力
	输出描述 :
对于每组数据, 输出一行.每行仅包含一个整数, 表示小易的最终能力值
示例1
输入
复制
3 50 50 105 200 5 20 30 20 15 40 100
输出
复制
110
205*/
#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int Get(int m, int n)
{
	if (n == 0)
		return m;

	int temp = m % n;
	m = n;
	n = temp;
	return Get(m, n);
}
int main()
{
	int n, N;//n表示小怪个数
	//N表示小易当前防御值
	while (cin >> n >> N)
	{
		while (n > 0)
		{
			int count = 0;
			cin >> count;
			N = N + ((N < count) ? Get(count, N) : count);
			n--;
		}
		cout << N << endl;
	}
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int Get(int n, int m) {
//	int a = n;
//	int b = m;
//	if (a < b)
//		swap(a, b);
//	int maxnum = INT_MIN;
//	for (int i = a;i>1;--i) {
//		if (a%i == 0 && b%i == 0)
//			if (i > maxnum)
//				maxnum = i;
//	}
//	return maxnum;
//}
//
//int main() {
//	int n, N;
//	while (cin >> n >> N) {
//		vector<int> v(N);
//		for (int i = 0;i < n;++i)
//			cin >> v[i];
//		int count = N;
//		int m = 0;
//		for (int i = 0;i < n;++i) {
//			m = v[i];
//			if (count < m)
//				m = Get(count, m);
//			count += m;
//		}
//		cout << count << endl;
//	}
//	system("pause");
//}
