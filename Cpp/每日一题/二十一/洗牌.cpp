/*
洗牌
洗牌在生活中十分常见，现在需要写一个程序模拟洗牌的过程。
现在需要洗2n张牌，从上到下依次是第1张，第2张，第3张一直到第2n张。
首先，我们把这2n张牌分成两堆，左手拿着第1张到第n张（上半堆），
右手拿着第n + 1张到第2n张（下半堆）。接着就开始洗牌的过程，
先放下右手的最后一张牌，再放下左手的最后一张牌，接着放下右手的
倒数第二张牌，再放下左手的倒数第二张牌，直到最后放下左手的第一张牌。
接着把牌合并起来就可以了。 例如有6张牌，最开始牌的序列
是1, 2, 3, 4, 5, 6。首先分成两组，左手拿着1, 2, 3；右手拿着4, 5, 6。
在洗牌过程中按顺序放下了6, 3, 5, 2, 4, 1。把这六张牌再次合成一组牌之后
，我们按照从上往下的顺序看这组牌，就变成了序列1, 4, 2, 5, 3, 6。 
现在给出一个原始牌组，请输出这副牌洗牌k次之后从上往下的序列。
输入描述 :
第一行一个数T(T ≤ 100)，表示数据组数。对于每组数据，
第一行两个数n, k(1 ≤ n, k ≤ 100)，接下来一行有2n个数a1, a2, ..., 
a2n(1 ≤ ai ≤ 1000000000)。表示原始牌组从上到下的序列。
输出描述 :
对于每组数据，输出一行，最终的序列。数字之间用空格隔开，不要在行末输出多余的空格。
示例1
输入
3 3 1 1 2 3 4 5 6 3 2 1 2 3 4 5 6 2 2 1 1 1 1
输出
1 4 2 5 3 6 1 5 4 3 2 6 1 1 1 1
*/
//数组版
#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int T, n, k;
	cin >> T;
	while (T--)
	{
		cin >> n >> k;
		int num = 2 * n;
		vector<int> table(num);
		for (int i = 0; i < num; ++i)
			cin >> table[i];
		while (k--)
		{
			vector<int> n1(table.begin(), table.end());
			for (int i = 0; i < n; ++i)
			{
				table[2 * i] = n1[i];
				table[2 * i + 1] = n1[i + n];
			}
		}
		for (int i = 0; i < num - 1; ++i)
			cout << table[i] << " ";
		cout << table[num - 1] << endl;
	}
	return 0;
}

//#include<iostream>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int main() {
//	int T, n, k;
//	cin >> T;
//	while (--T) {
//		cin >> n >> k;
//		int m = 2 * n;
//		vector<int> v(m);
//		for (int i = 0;i < m;++i)
//			cin >> v[i];
//		vector<int> arr(m);
//		while (--k) {
//			//vector<int> arr(m);
//			for (int i = 0;i < n;++i) {
//				arr[2 * i] = v[i];
//				arr[2 * i + 1] = v[i + n];
//			}
//		}
//		for (int i = 0;i < m;++i) {
//
//			if (i == m - 1) {
//				cout << arr[i];
//				return 0;
//			}
//			cout << arr[i] << " ";
//		}
//		system("pause");
//	}
//}
//栈版
//#include<iostream>
//#include<stack>
//#include<vector>
//#include<stdlib.h>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		/*vector<int> v;
//		for(int i=0;i<n;++i){
//			cin>>v[i];
//		}*/
//		stack<int> s;
//		for (int i = 0;i < n;++i) {
//			int m;
//			cin >> m;
//			s.push(m);
//		}
//		stack<int> s1;
//		stack<int> s2;
//		for (int i = 0;i < n / 2;++i) {
//			int m = s.top();
//			s1.push(m);
//		}
//		for (int i = n / 2;i < n;++i) {
//			int m = s.top();
//			s2.push(m);
//		}
//		int count = n;
//		for (int i = 0;i < n;++i) {
//			if (i % 2 == 0)
//				s1.pop();
//			else s2.pop();
//			if (count != 0)
//				cout << " ";
//		}
//	}
//	system("pause");
//}
//队列版
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//int main() {
//	int n;
//	while (cin >> n) {
//		vector<int> v;
//		for (int i = 0;i < n;++i) {
//			cin >> v[i];
//		}
//		queue<int> q;
//		for (int i = 0;i < n;++i) {
//			q.push(v[i]);
//		}
//		queue<int> q1;
//		queue<int> q2;
//		int k;
//		for (int i = 0;i < n / 2;++i) {
//			k = (int)q.pop();
//			q2.push(k);
//		}
//		for (int j = n / 2;j < n;++j) {
//			k = (int)q.pop();
//			q2.push(k);
//		}
//		int count = n;
//		for (int i = 0;i < n;++i) {
//			if (i % 2 == 0)
//				q1.pop();
//			else
//				q2.pop();
//			if (count != 0)
//				cout << " ";
//		}
//	}
//}
